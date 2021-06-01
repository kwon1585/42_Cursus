/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:24:53 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/07 16:08:15 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dst > src)
		while (len-- > 0)
			*((unsigned char *)dst + len) = *((unsigned const char *)src + len);
	else
		while (len-- > 0)
		{
			*((unsigned char *)dst + i) = *((unsigned const char *)src + i);
			i++;
		}
	return (dst);
}
