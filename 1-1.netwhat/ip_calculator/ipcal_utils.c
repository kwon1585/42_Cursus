/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipcal_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:56:29 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/01/19 19:32:34 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ipcal.h"

void				ft_addr_swap(char **s1, char **s2)
{
	char			*temp;

	temp = *s2;
	*s2 = *s1;
	*s1 = temp;
}

size_t				ft_strlen(char *str)
{
	return (ft_strclen(str, '\0') - 1);
}

size_t				ft_strclen(char *str, char c)
{
	size_t			length;

	length = 1;
	while (*str != c)
	{
		if (!(*str))
			return (0);
		length++;
		str++;
	}
	return (length);
}

size_t				ft_strlcat(char *dest, char *src, size_t length)
{
	size_t			result;

	result = 0;
	if (!dest || !src)
		return (0);
	if (length < 1)
		return (ft_strlen(src));
	while (*dest && length)
	{
		result++;
		length--;
		dest++;
	}
	while (1 < length && *src)
	{
		result++;
		length--;
		*dest++ = *src++;
	}
	*dest = 0;
	return (result);
}

void				ft_show_string(char *src)
{
	while (*src)
		write(1, src++, 1);
}

void				ft_show_number(ssize_t num)
{
	char			*result;
	char			*temp;

	if (!(result = ft_m_itoa(num)))
		return ;
	temp = result;
	while (*temp)
		write(1, temp++, 1);
	free(result);
}

void				ft_bzero(char *dst, size_t length)
{
	while (length--)
		dst[length] = 0;
}

int					ft_isspace_not_nl(char c)
{
	return (c == ' ' || (11 <= c && c <= 13) || c == 9);
}

int					ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

void				ft_tolower_s(char *c)
{
	while (*c)
	{
		*c = ft_tolower(*c);
		c++;
	}
}

char				ft_tolower(char c)
{
	return (('A' <= c && c <= 'Z') ? c - 'A' + 'a' : c);
}

char				ft_isnumeric(char c)
{
	return ('0' <= c && c <= '9');
}

char				ft_isupper(char c)
{
	return ('A' <= c && c <= 'Z');
}

char				ft_islower(char c)
{
	return ('a' <= c && c <= 'z');
}

char				ft_isalpha(char c)
{
	return (ft_isupper(c) || ft_islower(c));
}

char				ft_ishexrange(char c)
{
	char			temp;

	temp = ft_tolower(c);
	return (ft_isnumeric(c) || ('a' <= temp && temp <= 'f'));
}

char				*ft_strchr(char *src, char c)
{
	if (!src)
		return (NULL);
	while (*src != c)
	{
		if (!(*src))
			return (NULL);
		src++;
	}
	return (src);
}

int					ft_compare(char *src, char *cmp)
{
	if (!cmp || !src)
		return (0);
	while (*cmp)
	{
		if (*src == *cmp)
		{
			src++;
			cmp++;
		}
		else
			return (0);
	}
	return (1);
}
