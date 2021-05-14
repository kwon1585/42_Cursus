/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:55:01 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/14 01:31:27 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#define FD_MAX 50

static void	make_line(char **line, char *data)
{
	char	*tmp;

	tmp = ft_strjoin(*line, data);
	free(*line);
	*line = tmp;
}


int			get_next_line(int fd, char **line)
{
	int			clean;
	int			index;
	int			size;
	char		*tmp;
	static char	buf[FD_MAX][BUFFER_SIZE + 1] = {0, };

	if (fd < 0 || fd > FD_MAX || !line || BUFFER_SIZE < 1)
		return (ERROR);
	tmp = ft_calloc(1, 1);
	*line = tmp;
	while (1)
	{
		if (buf[fd][0])
		{
			if ((index = ft_strchri(buf[fd], '\n')) >= 0)
			{
				tmp = ft_calloc(index + 1, sizeof(char));
				ft_memcpy(tmp, buf[fd], index);
				tmp[index++] = 0;
				make_line(line, tmp);
				ft_memcpy(buf[fd], buf[fd] + index, BUFFER_SIZE);
				free(tmp);
				return (SUCCESS);
			}
			else
			{
				make_line(line, buf[fd]);
				clean = 0;
				while (clean < BUFFER_SIZE)
					buf[fd][clean++] = 0;
			}
		}
		else
			if ((size = read(fd, buf[fd], BUFFER_SIZE)) == 0)
			{	
				buf[fd][0] = 0;
				return (END_OF_FILE);
			}
	}
	return (ERROR);
}
