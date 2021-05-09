/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:20:38 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/09 22:29:54 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		j;

	if (!s1 || !set)
		return (0);
	i = -1;
	j = ft_strlen(s1);
	while (++i < j)
		if (!ft_strchr(set, *(s1 + i)))
			break ;
	if (i == j)
		return ("");
	while (--j >= i)
		if (!ft_strchr(set, *(s1 + j)))
			break ;
	p = malloc(sizeof(char) * (j - i + 2));
	if (!p)
		return (0);
	p = ft_memcpy(p, s1 + i, j - i + 1);
	*(p + j - i + 1) = '\0';
	return (p);
}
