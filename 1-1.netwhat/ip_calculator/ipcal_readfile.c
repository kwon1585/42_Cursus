/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipcal_readfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:01:18 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/01/25 13:01:28 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ipcal.h"

int					get_indexed_data(int fd, int index, char **dest)
{
	char			*temp;

	while (0 < index)
	{
		if ((ft_get_next_line(fd, &temp)) < 0)
			return (-1);
		free(temp);
		index--;
	}
	if ((ft_get_next_line(fd, &temp)) < 0)
		return (-1);
	ft_addr_swap(&temp, dest);
	free(temp);
	return (1);
}

int					ft_show_file_data(char *file_name, int index)
{
	int				fd;
	int				result;
	char			*dest;
	char			*temp;

	dest = NULL;
	if (!file_name)
		return (-1);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (-1);
	result = get_indexed_data(fd, index, &dest);
	close(fd);
	if (result)
	{
		temp = dest;
		while (*temp)
			write(1, temp++, 1);
		write(1, "\n", 1);
		free(dest);
	}
	ft_get_next_line(-1, NULL);
	return (result);
}

void				ft_show_file_data_with_f(char *file_name,
											void (*f)(int index))
{
	int				result;
	int				index;
	int				fd;
	char			*dest;
	char			*temp;

	index = 0;
	if (!file_name)
		return ;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return ;
	dest = NULL;
	write(1, "\n", 1);
	while ((result = ft_get_next_line(fd, &dest)))
	{
		temp = dest;
		while (*temp != '\n')
			write(1, temp++, 1);
		f(index++);
		write(1, "\n", 1);
		free(dest);
		dest = NULL;
	}
	free(dest);
	ft_get_next_line(-1, NULL);
	write(1, "\n", 1);
}

void				ft_show_whole_file(char *file_name)
{
	int				fd;
	size_t			length;
	char			buff[BUFFER_SIZE + 1];

	fd = open(file_name, O_RDONLY);
	while (0 < (length = read(fd, buff, BUFFER_SIZE)))
	{
		buff[length] = 0;
		length = 0;
		while (buff[length])
		{
			write(1, &(buff[length]), 1);
			length++;
		}
	}
	write(1, "\n", 1);
	write(1, "\n", 1);
	close(fd);
}
