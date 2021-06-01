/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:17:55 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/09 21:01:15 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*p;

	if (!s)
		return (0);
	else if (ft_strlen(s) <= start)
		size = 0;
	else if (ft_strlen(s + start) > len)
		size = len;
	else
		size = ft_strlen(s + start);
	p = (char *)malloc(sizeof(char) * size + 1);
	if (!p)
		return (0);
	p = ft_memcpy(p, s + start, size);
	*(p + size) = '\0';
	return (p);
}
