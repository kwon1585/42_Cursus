/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipcal_check_form.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:44:34 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/01/25 13:03:33 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ipcal.h"

void				set_type(int index)
{
	if (!index)
	{
		ft_show_value_iptype(g_ip);
		ft_show_private();
		ft_show_subip_exception(g_ip);
	}
	if (index == 1)
		ft_show_default_ip_class();
	if (index == 2)
		ft_show_subnet_mask();
	if (index == 2)
		write(1, "\n", 1);
	if (index == 3)
		ft_show_subnet_addr();
	if (index == 4)
		ft_show_useable_subhost_range();
	if (index == 5)
		ft_show_sub_broadcast_addr();
	if (index == 5)
		write(1, "\n", 1);
}

int					zero_error(void)
{
	g_ip = 0;
	g_subnet_bit = 0;
	return (ZERO_E);
}

int					range_error(void)
{
	g_ip = 0;
	return (RANGE_E);
}

int					check_ip_value(int *data, char *buff)
{
	int				index;

	index = 0;
	g_ip = 0;
	if (223 < data[1] && data[0] < IP_V4_BLOCK_SIZE + 1)
		return (DE_CLASS_NEED_ADRESS_BIT_E);
	while (index < IP_V4_BLOCK_SIZE)
	{
		if ((0 <= data[index + 1]) && (data[index + 1] <= IP_V4) && ++index)
			g_ip |= (data[index] << ((index - 1) * 8));
		else
			return (range_error());
		// {
		// 	g_ip = 0;
		// 	return (RANGE_E);
		// }
	}
	g_subnet_bit = (ft_get_default_ip_class() + 1) * 8;
	if (data[0] == IP_V4_BLOCK_SIZE + 1)
	{
		if ((0 < data[data[0]]) && (data[data[0]] < MAX_IP_V4_BIT_LENGTH))
			g_subnet_bit = data[data[0]];
		else
			return (SUBNET_SIZE_E);
	}
	if (!g_ip)
		return (zero_error());
		// return (ZERO_E);
	return (ft_input_checker(buff));
}

int					check_ip_form(char *buff)
{
	int				data[6];
	int				value;

	data[0] = 0;
	value = 0;
	while (*buff && !ft_isspace(*buff))
	{
		if (ft_isnumeric(*buff))
			value = value * 10 + (*buff++ - '0');
		else if (((*buff == '.') && (data[0] < 3))
				|| ((*buff == '/') && (data[0] == 3)))
		{
			(data[0])++;
			data[data[0]] = value;
			value = 0;
			buff++;
		}
		else
			return (TYPE_E);
	}
	(data[0])++;
	data[data[0]] = value;
	if (data[0] < IP_V4_BLOCK_SIZE)
		return (TYPE_E);
	return (check_ip_value(data, buff));
}

int					is_mask_flag_continue(int value, int *flag_count)
{
	int				bit_index;

	bit_index = CHARACTER_LENGTH - 1;
	while (0 <= bit_index)
	{
		if (((value >> bit_index) & 1))
			*flag_count = 1 + (*flag_count);
		else
			return (0);
		--bit_index;
	}
	return (1);
}

int					check_mask_form(char *buff)
{
	int				block_count;
	int				value;
	int				flag_count;

	block_count = 0;
	flag_count = 0;
	value = 0;
	while (*buff && !ft_isspace(*buff))
	{
		if (ft_isnumeric(*buff))
			value = value * 10 + (*buff++ - '0');
		else if ((*buff == '.') && (block_count < 3) && buff++)
		{
			block_count++;
			if (!(is_mask_flag_continue(value, &flag_count)))
				return (ft_show_useable_range_by_mask(flag_count));
			value = 0;
		}
		else
			return (TYPE_E);
	}
	if (++block_count < IP_V4_BLOCK_SIZE)
		return (TYPE_E);
	is_mask_flag_continue(value, &flag_count);
	return (ft_show_useable_range_by_mask(flag_count));
}

int					ft_subset(char *buff)
{
	unsigned char	subset;

	subset = 0;
	while (*buff && !ft_isspace(*buff))
	{
		if (ft_isnumeric(*buff))
			subset = subset * 10 + (*buff - '0');
		else
			return (SUBNET_SIZE_E);
		buff++;
	}
	if (0 < subset && subset < MAX_IP_V4_BIT_LENGTH)
	{
		g_subnet_bit = subset;
		return (ft_input_checker(buff));
	}
	return (SUBNET_SIZE_E);
}

int					ft_terminate(char *buff)
{
	if (ft_compare(buff, "bye\0"))
	{
		write(1, "Bye~ See U again.\n\n", 19);
		return (-1);
	}
	if (ft_compare(buff, "quit\0"))
	{
		write(1, "Terminate IP-calculator.\n\n", 26);
		return (-1);
	}
	if (ft_compare(buff, "exit\0"))
	{
		write(1, "Shall we meet again?\n\n", 22);
		return (-1);
	}
	return (0);
}

int					ft_whatform(char *buff)
{
	if (ft_compare(buff, "ip \0"))
		return (check_ip_form(buff + 3));
	if (ft_compare(buff, "help\0"))
	{
		ft_show_whole_file("./f_help");
		return (ft_input_checker(buff + 4));
	}
	if (ft_compare(buff, "mask \0"))
		return (check_mask_form(buff + 5));
	if (ft_compare(buff, "m \0"))
		return (check_mask_form(buff + 2));
	if (ft_compare(buff, "auto\n"))
	{
		g_auto_flag = !(g_auto_flag);
		return (ft_command(buff + 4));
	}
	if (ft_compare(buff, "status\0"))
	{
		if (!g_ip)
			return (ZERO_E);
		if (!g_auto_flag)
			ft_show_file_data_with_f("./f_status", set_type);
		return (ft_input_checker(buff + 6));
	}
	if (ft_compare(buff, "quit\0"))
		return (ft_terminate(buff));
	return (2);
}

int					ft_command(char *buff)
{
	if (ft_compare(buff, "h\0"))
	{
		ft_show_whole_file("./f_help");
		return (ft_command(++buff));
	}
	if (ft_compare(buff, "s\0"))
	{
		if (!g_ip)
			return (ZERO_E);
		if (!g_auto_flag)
			ft_show_file_data_with_f("./f_status", set_type);
		return (ft_command(++buff));
	}
	if (ft_compare(buff, "a\n"))
	{
		g_auto_flag = !(g_auto_flag);
		return (ft_command(++buff));
	}
	if (ft_compare(buff, "q\0"))
		return (ft_terminate("quit\0"));
	if (ft_compare(buff, "b\0"))
		return (ft_terminate("bye\0"));
	if (ft_compare(buff, "e\0"))
		return (ft_terminate("exit\0"));
	if (ft_isspace(*buff) || *buff == '\n')
		return (ft_input_checker(buff));
	return (COMMAND_E);
}

int					ft_input_checker(char *buff)
{
	while (ft_isspace_not_nl(*buff))
		buff++;
	if (ft_terminate(buff))
		return (-1);
	if (*buff == '-')
		return (ft_command(++buff));
	if (*buff == '/')
		return (ft_subset(++buff));
	if (ft_isalpha(*buff))
		return (ft_whatform(buff));
	if (ft_isnumeric(*buff))
		return (check_ip_form(buff));
	if (*buff == '\n')
		return (0);
	return (WRONG_E);
}

int					ft_check_form(char *buff)
{
	int				result;

	ft_tolower_s(buff);
	if ((result = ft_input_checker(buff)))
	{
		if (result < 0)
			return (-1);
		ft_show_error_code(result);
	}
	if (g_auto_flag)
		ft_show_file_data_with_f("./f_status", set_type);
	ft_show_prompt();
	return (0);
}
