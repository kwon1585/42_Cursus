/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:55:01 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/13 01:59:13 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	cpy_data(char **line, char *buf, int enter, int end)
{
	int		rtn = 0;
	char	*tmp;

}


int			get_next_line(int fd, char **line)
{
	int		size;
	int		index;
	char	*buf;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (ERROR);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while ((size = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[BUFFER_SIZE] = 0;
		if ((index = ft_strchri(buf, '\n')) >= 0)
			return (print_line(size, buf, index));
		else if (size < BUFFER_SIZE)
			return (print_line(size, buf , size);

		
		rtn = cpy_data(line, buf, ft_strchri(buf, '\n'), ft_strchri(buf, EOF));
	}
	free(buf);
	return (ERROR);
}
