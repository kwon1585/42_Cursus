/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 23:14:44 by dokwon            #+#    #+#             */
/*   Updated: 2021/07/26 23:59:01 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list ap, t_check *check)
{
	int		rtn;
	char	*print;	

	rtn = 0;
	print = va_arg(ap, char *);
	if (!print)
		print = "(null)";
	if (check->conversion == 's')
	{
		while (*print)
		{
			rtn += ft_putchar(print);
			print++;
		}
	}
	return (rtn);
}
