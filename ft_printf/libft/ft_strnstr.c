/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 02:44:06 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/09 03:38:36 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_ndl;

	i = 0;
	len_ndl = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + i) && i + len_ndl <= len)
	{
		if (*(haystack + i) == *needle)
			if (!ft_strncmp(haystack + i, needle, len_ndl))
				return ((char *)haystack + i);
		i++;
	}
	return (0);
}
