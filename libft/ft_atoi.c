/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 03:43:03 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/09 04:07:49 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	ans;
	long long	sign;
	char		*st;

	ans = 0;
	sign = 1;
	st = (char *)str;
	while (*st == ' ' || *st == '\n' || *st == '\t'
			|| *st == '\r' || *st == '\v' || *st == '\f')
		st++;
	if (*st == '-' || *st == '+')
		if (*(st++) == '-')
			sign = -1;
	while (*st >= '0' && *st <= '9')
	{
		ans = ans * 10 + (*(st++) - 48);
		if (ans * sign > 2147483647)
			return (-1);
		else if (ans * sign < -2147483648)
			return (0);
	}
	return (ans * sign);
}
