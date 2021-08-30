/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:59:03 by dokwon            #+#    #+#             */
/*   Updated: 2021/08/30 18:03:08 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_str_u(va_list ap)
{
	char			*print;
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	print = ft_itoa(num);
	return (print);
}

char	*get_str_di(va_list ap)
{
	char	*print;
	char	*tmp;
	long	num;
	int		is_minus;

	is_minus = 0;
	num = va_arg(ap, int);
	if (num < 0)
	{
		is_minus = 1;
		num *= -1;
	}
	tmp = ft_itoa(num);
	if (is_minus)
	{
		print = ft_strjoin("-", tmp);
		free(tmp);
		return (print);
	}
	return (tmp);
}

int	print_dec(va_list ap, t_check *check)
{
	int		rtn;
	char	*print;

	rtn = 0;
	if (check->conversion == 'u')
		print = get_str_u(ap);
	else
		print = get_str_di(ap);
    while (*print)
    {
        rtn += ft_putchar(print);
		print++;
    }
	free(print - rtn);
	return (rtn);
}
