/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 05:37:31 by dokwon            #+#    #+#             */
/*   Updated: 2021/07/27 01:18:43 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char *c)
{
	write(1, c, 1);
	return (1);
}

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

int		get_length(unsigned long long n)
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

char	*ft_itoa(unsigned long long n)
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
