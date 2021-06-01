/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:04:33 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/10 11:13:50 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*rtn;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	rtn = malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (0);
	*(rtn + len) = 0;
	while (i < len)
	{
		*(rtn + i) = f(i, *(s + i));
		i++;
	}
	return (rtn);
}
