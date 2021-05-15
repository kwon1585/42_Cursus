/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:55:36 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/15 15:13:32 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <sys/wait.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

# define SUCCESS 1
# define END_OF_FILE 0
# define ERROR -1
# define FD_MAX 2156

int 	get_next_line(int fd, char **line);
int		ft_strchri(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, int n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);

#endif
