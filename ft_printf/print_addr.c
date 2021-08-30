/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:00:50 by dokwon            #+#    #+#             */
/*   Updated: 2021/08/30 18:39:00 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_hex(unsigned long long nb, char *print, int is_upper)
{
	if (nb >= 16)
	{
		to_hex(nb / 16, print, is_upper);
		to_hex(nb % 16, print, is_upper);
	}
	if (nb < 10)
	{
		while (*print)
			print++;
		*print = nb + 48;
	}
	else if (nb < 16)
	{
		while (*print)
			print++;
		*print = nb + is_upper;
	}
}

int	print_addr(va_list ap, t_check *check)
{
	int					rtn;
	int					len;
	char				*print;
	unsigned long long	addr;

	rtn = 0;
	addr = va_arg(ap, unsigned long long);
	len = ft_nbrlen(addr, 16);
	if (!(print = calloc(sizeof(char), len + 3)))
		return (ERROR);
	*print = '0';
	*(print + 1) = 'x';
	to_hex(addr, print, 87);
	if (check->conversion == 'p')
	{
		while (*print)
		{
			ft_putchar(print++);
			rtn++;
		}
	}
	free(print - rtn);
	return (rtn);
}
