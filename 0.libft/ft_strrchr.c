/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 02:37:12 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/09 18:32:03 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	c = (unsigned char)c;
	i = ft_strlen(s) + 1;
	while (i-- > 0)
		if (*(s + i) == c)
			return ((char *)s + i);
	return (0);
}
