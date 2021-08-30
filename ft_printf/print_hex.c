/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:06:00 by dokwon            #+#    #+#             */
/*   Updated: 2021/08/30 18:32:22 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(va_list ap, t_check *check)
{
	int				rtn;
	int				len;
	unsigned int	num;
	char			*print;

	rtn = 0;
	num = va_arg(ap, unsigned int);
	len = ft_nbrlen(num, 16);
	if (!(print = calloc(sizeof(char), len + 1)))
		return (ERROR);
	if (check->conversion == 'x')
		to_hex(num, print, 87);
	else if (check->conversion == 'X')
		to_hex(num, print, 55);
	while (*print)
    {
        ft_putchar(print++);
        rtn++;
    }
	free(print - rtn);
	return (rtn);
}

