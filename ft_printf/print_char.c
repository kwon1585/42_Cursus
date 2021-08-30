/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 21:37:51 by dokwon            #+#    #+#             */
/*   Updated: 2021/08/30 22:46:34 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap, t_check *check)
{
	char	print;

	print = va_arg(ap, int);
	if (check->conversion == 'c')
		ft_putchar(&print);
	return (1);
}
