/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:43:14 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/07 15:20:54 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (dst || src))
	{
		*((unsigned char *)dst + i) = *((unsigned const char *)src + i);
		if (*((unsigned const char *)src + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
