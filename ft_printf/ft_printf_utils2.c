/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:48:50 by dokwon            #+#    #+#             */
/*   Updated: 2021/08/30 22:56:08 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (0);
	p = ft_memcpy(p, s1, ft_strlen(s1));
	ft_memcpy(p + ft_strlen(s1), s2, ft_strlen(s2));
	*(p + len) = '\0';
	return (p);
}

int	ft_nbrlen(unsigned long long n, int base)
{
	int	rtn;

	rtn = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		rtn++;
		n /= base;
	}
	return (rtn);
}

char	*ft_itoa(unsigned long long n)
{
	int			len;
	char		*rtn;

	len = ft_nbrlen(n, 10);
	rtn = malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (0);
	*(rtn + len--) = 0;
	while (n >= 10)
	{
		*(rtn + len--) = n % 10 + 48;
		n = n / 10;
	}
	*(rtn + len) = n + 48;
	return (rtn);
}
