/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:00:50 by dokwon            #+#    #+#             */
/*   Updated: 2021/07/27 01:21:33 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_addr(va_list ap, t_check *check)
{
	int					rtn;
	char				*print;
	unsigned long long	addr;

	addr = va_arg(ap, unsigned long long);
	print = ft_itoa(addr);
	print = ft_strjoin("0x", print);
	if (check->conversion == 'p')
	{
		while (*print)
		{
				ft_putchar(print);
			print++;
		}
	}
	return (rtn);
}
