/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:55:01 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/12 15:11:32 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	cpy_data(char **line, char *buf, int enter, int end)
{
	static int	index = 0;
	char		*tmp;

	if (enter >= 0)
	{
		*(buf + enter) = 0;
		tmp = ft_strdup(buf);
		*line = tmp;
		return (SUCCESS);
	}
	else if (end >= 0)
	{
		*(buf + end) = 0;
		tmp = ft_strdup(buf);
		*line = tmp;
		return (END_OF_FILE);
	}
	ft_memcpy(*line + index, buf, BUFFER_SIZE);
	index += BUFFER_SIZE;
	return (-1);
}


int		get_next_line(int fd, char **line)
{
	int		rtn;
	char	*buf;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (ERROR);
	rtn = -1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (rtn < 0)
	{
		read(fd, buf, BUFFER_SIZE);
		rtn = cpy_data(line, buf, ft_strchri(buf, '\n'), ft_strchri(buf, EOF));
	}
	free(buf);
	return (rtn);
}
