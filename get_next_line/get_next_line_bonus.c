/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:14:23 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/18 20:14:31 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	put_line(char **line, char *data)
{
	char	*tmp;

	if ((tmp = ft_strjoin(*line, data)) == 0)
		return (ERROR);
	free(*line);
	*line = tmp;
	return (0);
}

static int	make_line(char **line,
								char buf[][BUFFER_SIZE + 1], int fd, int index)
{
	char	*tmp;

	if ((tmp = ft_calloc(index + 1, sizeof(char))) == 0)
		return (ERROR);
	ft_memcpy(tmp, buf[fd], index);
	tmp[index++] = 0;
	if ((put_line(line, tmp)) == ERROR)
	{
		free(tmp);
		return (ERROR);
	}
	ft_memcpy(buf[fd], buf[fd] + index, BUFFER_SIZE);
	free(tmp);
	return (SUCCESS);
}

static int	clean_buf(char **line, int fd,
								char buf[][BUFFER_SIZE + 1], int size)
{
	int	clean;

	clean = 0;
	while (clean < BUFFER_SIZE)
		buf[fd][clean++] = 0;
	if (size < 0)
	{
		free(*line);
		*line = 0;
		return (ERROR);
	}
	else if (size == 0)
		return (END_OF_FILE);
	else
		return (1);
}

int			get_next_line(int fd, char **line)
{
	int			index;
	int			size;
	static char	buf[FD_MAX + 1][BUFFER_SIZE + 1];

	if (fd < 0 || fd > FD_MAX || !line || BUFFER_SIZE < 1)
		return (ERROR);
	if ((*line = ft_calloc(1, 1)) == 0)
		return (ERROR);
	while (1)
	{
		if (buf[fd][0])
			if ((index = ft_strchri(buf[fd], '\n')) >= 0)
				return (make_line(line, buf, fd, index));
			else
			{
				if (put_line(line, buf[fd]) == ERROR)
					return (ERROR);
				clean_buf(line, fd, buf, BUFFER_SIZE);
			}
		else if ((size = read(fd, buf[fd], BUFFER_SIZE)) <= 0)
			return (clean_buf(line, fd, buf, size));
	}
}
