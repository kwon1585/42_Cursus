/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:55:36 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/13 00:30:14 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# define SUCCESS 1
# define END_OF_FILE 0
# define ERROR -1

int 	get_next_line(int fd, char **line);
int		ft_strchri(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, int n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
