/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:55:01 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/10 19:33:49 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	while (read(fd, buf, BUFFER_SIZE))
	{
	}
}
