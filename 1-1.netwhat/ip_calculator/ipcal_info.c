/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipcal_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:27:00 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/01/25 12:50:04 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ipcal.h"

unsigned int			ip_reverse(unsigned int value)
{
	unsigned int		convert;
	unsigned int		ip_temp;
	int					loop;

	loop = 0;
	convert = 0;
	ip_temp = value;
	while (loop++ < IP_V4_BLOCK_SIZE)
	{
		convert <<= CHARACTER_LENGTH;
		convert |= (ip_temp & MAX_CHARACTER_VALUE);
		ip_temp >>= CHARACTER_LENGTH;
	}
	return (convert);
}

void					ft_show_private(void)
{
	unsigned int		convert;

	convert = ip_reverse(g_ip);
	if (PRIVATE_MIN_CLASS_A <= convert && convert <= PRIVATE_MAX_CLASS_A)
		ft_show_string(" [PRIVATE IP]");
	if (PRIVATE_MIN_CLASS_B <= convert && convert <= PRIVATE_MAX_CLASS_B)
		ft_show_string(" [PRIVATE IP]");
	if (PRIVATE_MIN_CLASS_C <= convert && convert <= PRIVATE_MAX_CLASS_C)
		ft_show_string(" [PRIVATE IP]");
}

unsigned int			ft_get_subnet_mask(void)
{
	unsigned int		result;
	int					loop;
	int					shift;

	result = 0;
	loop = 0;
	while (loop < MAX_IP_V4_BIT_LENGTH)
	{
		if (loop < g_subnet_bit)
		{
			shift = ((CHARACTER_LENGTH - (loop % CHARACTER_LENGTH) - 1)
						+ ((loop / CHARACTER_LENGTH) * CHARACTER_LENGTH));
			result |= (1 << shift);
		}
		loop++;
	}
	return (result);
}

int						ft_show_tail_subnet(void)
{
	write(1, "/", 1);
	ft_show_number(g_subnet_bit);
	if (g_subnet_bit < 10)
		return (2);
	return (3);
}

void					ft_show_subip_exception()
{
	unsigned int		subnet_mask;
	unsigned int		subnet_addr;
	unsigned int		broadcast;

	subnet_mask = ft_get_subnet_mask();
	subnet_addr = (subnet_mask & g_ip);
	broadcast = (subnet_mask ^ FULL_IP_VALUE);
	if (g_ip == subnet_mask)
		ft_show_string(" [invalid value] This is a Network address\0");
	if ((g_ip & broadcast) == broadcast)
		ft_show_string(" [invalid value] This is a Broadcast address\0");
}

void					show_ip_exception(void)
{
	char				ip_class;

	ip_class = ft_get_default_ip_class();
	if (ip_class == 3)
		write(1, " Multicast", 17);
	else if (ip_class == 4)
		write(1, " Reserved", 8);
}

void					ft_show_subnet_mask(void)
{
	unsigned int		subnet_mask;

	subnet_mask = ft_get_subnet_mask();
	ft_show_value_iptype(subnet_mask);
}

void					ft_show_subnet_addr(void)
{
	unsigned int		subnet_addr;

	subnet_addr = (ft_get_subnet_mask() & g_ip);
	ft_show_value_iptype(subnet_addr);
}

unsigned int			ft_get_sub_broadcast_addr(void)
{
	unsigned int		broadcast;
	unsigned int		subnet_mask;

	subnet_mask = ft_get_subnet_mask();
	broadcast = (subnet_mask ^ FULL_IP_VALUE);
	broadcast |= (subnet_mask & g_ip);
	return (broadcast);
}

void					ft_show_sub_broadcast_addr(void)
{
	unsigned int		broadcast;

	broadcast = ft_get_sub_broadcast_addr();
	ft_show_value_iptype(broadcast);
}

void					ft_show_subhost_addr(void)
{
	unsigned int		broadcast;
	unsigned int		host;

	broadcast = (ft_get_subnet_mask() ^ FULL_IP_VALUE);
	host = (g_ip & broadcast);
	ft_show_value_iptype(g_ip);
	ft_show_subip_exception();
}

void					show_range(unsigned int min, unsigned int max)
{
	unsigned int i_min;
	unsigned int i_max;

	i_min = (ip_reverse(min) + 1);
	min = ip_reverse(i_min);
	ft_show_value_iptype(min);
	write(1, " ~ ", 3);
	i_max = (ip_reverse(max) - 1);
	max = ip_reverse(i_max);
	ft_show_value_iptype(max);
	write(1, " (", 2);
	ft_show_number(i_max - i_min + 1);
	write(1, ")", 1);
}

void					ft_show_useable_subhost_range(void)
{
	unsigned int		mask;
	unsigned int		broadcast;
	unsigned char		default_ip_class_value;

	mask = ft_get_subnet_mask();
	broadcast = (mask ^ FULL_IP_VALUE);
	default_ip_class_value = (ft_get_default_ip_class() + 1) * CHARACTER_LENGTH;
	if (((g_ip & mask) == g_ip) || (g_ip == ft_get_sub_broadcast_addr()))
	{
		write(1, "none", 4);
		return ;
	}
	show_range((g_ip & mask), ((g_ip & mask) | broadcast));
}

int						ft_show_useable_range_by_mask(int flag_count)
{
	unsigned int		mask;
	int					index;
	int					mask_length;

	mask = 0;
	index = 0;
	mask_length = flag_count;
	if (30 < flag_count)
		return (MASK_RANGE_E);
	while (index++ < MAX_IP_V4_BIT_LENGTH)
	{
		mask <<= 1;
		mask |= (0 < flag_count--);
	}
	mask = ip_reverse(mask);
	write(1, "\nMask = ", 8);
	ft_show_value_iptype(mask);
	write(1, "/", 1);
	ft_show_number(mask_length);
	write(1, "\n", 2);
	show_range(0, (mask ^ FULL_IP_VALUE));
	write(1, "\n\n", 2);
	return (PASS);
}

unsigned char			ft_get_default_ip_class(void)
{
	unsigned char		ip_class;
	char				c;

	if (!g_ip)
		return ('N' - 'A');
	ip_class = (unsigned char)CLASS_E;
	c = 'E';
	while ((g_ip & ip_class) != ip_class)
	{
		ip_class <<= 1;
		c -= 1;
	}
	return (c - 'A');
}

void					ft_show_default_ip_class(void)
{
	unsigned char		c;

	c = ft_get_default_ip_class() + 'A';
	write(1, &c, 1);
}

int						ft_show_ip(void)
{
	int					loop;
	unsigned int		ip_temp;
	int					value;
	int					t_length;

	loop = 0;
	t_length = 3;
	ip_temp = g_ip;
	while (loop < IP_V4_BLOCK_SIZE)
	{
		value = ip_temp & MAX_CHARACTER_VALUE;
		ip_temp >>= CHARACTER_LENGTH;
		t_length += ft_numericlen(value);
		ft_show_number(value);
		if (loop < (IP_V4_BLOCK_SIZE - 1))
			write(1, ".", 1);
		loop++;
	}
	t_length += ft_show_tail_subnet();
	return (t_length);
}

void					ft_show_value_iptype(unsigned int arg)
{
	int					loop;
	int					value;

	loop = 0;
	while (loop < IP_V4_BLOCK_SIZE)
	{
		value = arg & MAX_CHARACTER_VALUE;
		arg >>= CHARACTER_LENGTH;
		ft_show_number(value);
		if (loop < (IP_V4_BLOCK_SIZE - 1))
			write(1, ".", 1);
		loop++;
	}
}

void					ft_show_bool(int value)
{
	if (value)
	{
		write(1, "ON ", 3);
		return ;
	}
	write(1, "OFF ", 3);
}