/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 03:51:29 by dokwon            #+#    #+#             */
/*   Updated: 2021/07/26 08:36:19 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hub(va_list ap, t_check *check)
{
	int		rtn;
	char	conv;

	rtn = 0;
	conv = check->conversion;
	if (conv == 'c')
	{
		char a = va_arg(ap, int);
		write(1, &a, 1);
	}
		
	/*
		rtn = print_char(ap, check);
	*/
	return (rtn);
}

int	pre_print(va_list ap, char *format)
{
	int		rtn;
	t_check	*check;

	rtn = 0;
	if (!(check = malloc(sizeof(t_check))))
		return (ERROR);
	while (*format)
	{
		if (*format == '%')
		{
			format = check_format(check, format);
			rtn += print_hub(ap, check);			
		}
		else
			rtn += ft_putchr(format++);
	}
	free(check);
	return (rtn);
}

int	ft_printf(const char *format, ...)
{
	int		rtn;
	va_list	ap;

	va_start(ap, format);
	rtn = pre_print(ap, (char *)format);
	va_end(ap);
	return (rtn);
}
