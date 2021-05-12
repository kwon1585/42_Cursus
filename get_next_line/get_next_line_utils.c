/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:55:18 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/12 15:14:45 by dokwon           ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s1);
	p = (char *)malloc(len * sizeof(const char) + 1);
	if (!p)
		return (0);
	p = ft_memcpy(p, s1, len + 1);
	return (p);
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
