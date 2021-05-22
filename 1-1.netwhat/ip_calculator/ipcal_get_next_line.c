/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipcal_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:18:52 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/01/19 18:15:23 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ipcal.h"

int					dispose_string(char **string, char **dest, size_t length)
{
	char			*temp;
	size_t			r_length;

	if (!(*dest = (char *)malloc(length)))
		return (-1);
	ft_bzero(*dest, length);
	r_length = ft_strlen(*string) - length;
	if (!(temp = (char *)malloc(r_length + 1)))
	{
		free(*dest);
		return (-1);
	}
	ft_bzero(temp, r_length + 1);
	ft_strlcat(*dest, *string, length + 1);
	ft_strlcat(temp, (*string + length), r_length + 1);
	ft_addr_swap(&temp, string);
	free(temp);
	return (0);
}

size_t				build_string(int fd, char **string, size_t length)
{
	char			*temp;
	char			buff[BUFFER_SIZE];
	ssize_t			r_length;
	size_t			result;

	result = ft_strclen(*string, '\n');
	if (!result)
	{
		if (!(r_length = read(fd, buff, BUFFER_SIZE)))
			return (0);
		length += r_length;
		if (!(temp = (char *)malloc(length + 1)))
			return (-1);
		ft_bzero(temp, length + 1);
		ft_strlcat(temp, *string, length + 1);
		ft_strlcat(temp, buff, length + 1);
		ft_addr_swap(&temp, string);
		free(temp);
		return (build_string(fd, string, length));
	}
	return (result);
}

void				clear_storage(char **string)
{
	if (string)
	{
		**string = 0;
		string = NULL;
	}
}

int					ft_get_next_line(int fd, char **dest)
{
	static char		*string;
	size_t			result;
	size_t			length;

	if (fd < 0)
	{
		clear_storage(&string);
		return (-1);
	}
	if (!string)
	{
		if (!(string = (char *)malloc(BUFFER_SIZE + 1)))
			return (-1);
		ft_bzero(string, BUFFER_SIZE + 1);
	}
	if (((result = build_string(fd, &string, 0)) < 0))
		return (-1);
	length = result ? result : ft_strlen(string) + 1;
	if ((dispose_string(&string, dest, length) < 0))
		return (-1);
	return ((0 < result) ? 1 : result);
}
