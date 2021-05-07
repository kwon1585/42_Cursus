/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:37:17 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/07 21:52:28 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_i;
	size_t	src_i;
	size_t	cat_i;

	dst_i = 0;
	src_i = 0;
	while (*(dst + dst_i))
		dst_i++;
	cat_i = dst_i;
	while (*(src + src_i) && cat_i + 1 < dstsize)
		*(dst + cat_i++) = *(src + src_i++);
	*(dst + cat_i) = '\0';
	src_i = 0;
	while (*(src + src_i) != '\0')
		src_i++;
	if (dstsize < dst_i)
		return (src_i + dstsize);
	else
		return (src_i + dst_i);
}
