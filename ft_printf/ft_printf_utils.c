/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 05:37:31 by dokwon            #+#    #+#             */
/*   Updated: 2021/08/30 22:49:50 by dokwon           ###   ########.fr       */
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
	size_t	i;

	i = 0;
	while (i < n && (dst || src))
	{
		*((unsigned char *)dst + i) = *((unsigned const char *)src + i);
		i++;
	}
	return (dst);
}
