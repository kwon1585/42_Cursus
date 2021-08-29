/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 05:37:31 by dokwon            #+#    #+#             */
/*   Updated: 2021/07/28 00:42:06 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char *c)
{
	write(1, c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (*(s + index))
		index++;
	return (index);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (dst || src))
	{
		*((unsigned char *)dst + i) = *((unsigned const char *)src + i);
		i++;
	}
	return (dst);
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
