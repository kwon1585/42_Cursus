/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 05:38:30 by dokwon            #+#    #+#             */
/*   Updated: 2021/09/21 21:27:14 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_check(t_check *check)
{
	check->conversion = 0;
}

char	*check_format(t_check *check, char *format)
{
	init_check(check);
	format++;
	check->conversion = *(format++);
	return (format);
}
