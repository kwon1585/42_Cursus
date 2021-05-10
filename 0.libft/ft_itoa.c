/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:55:27 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/10 11:02:50 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_length(int n)
{
	int			rtn;
	long long	n1;

	rtn = 0;
	n1 = n;
	if (n < 0)
	{
		n1 *= -1;
		rtn++;
	}
	else if (n == 0)
		return (1);
	while (n1)
	{
		rtn++;
		n1 /= 10;
	}
	return (rtn);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*rtn;
	long long	n1;

	len = get_length(n);
	rtn = malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (0);
	*(rtn + len--) = 0;
	n1 = n;
	if (n < 0)
	{
		n1 = n1 * -1;
		*rtn = '-';
	}
	while (n1 >= 10)
	{
		*(rtn + len--) = n1 % 10 + 48;
		n1 = n1 / 10;
	}
	*(rtn + len) = n1 + 48;
	return (rtn);
}
