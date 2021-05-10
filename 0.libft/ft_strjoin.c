/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:01:47 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/10 09:36:20 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
