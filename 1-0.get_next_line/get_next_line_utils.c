/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:55:18 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/18 20:13:08 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int i;

	i = 0;
	while (i < n && (dst || src))
	{
		*((unsigned char *)dst + i) = *((unsigned const char *)src + i);
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (*(s + index))
		index++;
	return (index);
}

int		ft_strchri(const char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char)c;
	while (*(s + i) == c || *(s + i))
	{
		if (*(s + i) == c)
			return (i);
		i++;
	}
	return (-1);
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

void	*ft_calloc(size_t count, size_t size)
{
	int		mul;
	void	*p;

	p = (void *)malloc(size * count);
	if (!p)
		return (0);
	mul = size * count;
	while (mul)
		*((unsigned char *)p + --mul) = 0;
	return (p);
}
