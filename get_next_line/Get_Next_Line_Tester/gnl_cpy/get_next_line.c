/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:55:01 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/13 00:36:51 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	cpy_data(char **line, char *buf, int enter, int end)
{
	int		rtn = 0;
	char	*tmp;

	rtn = -1;
	if (enter >= 0)
	{
		*(buf + enter) = 0;
		rtn = SUCCESS;
	}
	else if (end >= 0)
	{
		*(buf + end) = 0;
		rtn = END_OF_FILE;
	}
	tmp = ft_strjoin(*line, buf);
	*line = tmp;
	free(tmp);
	return (rtn);
}


int			get_next_line(int fd, char **line)
{
	int		rtn;
	char	*buf;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (ERROR);
	rtn = -1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (rtn < 0)
	{
		if (read(fd, buf, BUFFER_SIZE) <= 0)
		{
			free(buf);
			return (ERROR);
		}
		rtn = cpy_data(line, buf, ft_strchri(buf, '\n'), ft_strchri(buf, EOF));
	}
	free(buf);
	return (rtn);
}
