/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 04:00:11 by dokwon            #+#    #+#             */
/*   Updated: 2021/07/26 06:55:17 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

#define ERROR -1

typedef struct	s_check
{
	char		conversion;
}				t_check;


void	init_check(t_check *check);
char	*check_format(t_check *check, char *format);

int	ft_putchr(char *c);

int	pre_print(va_list ap, char *format);
int	ft_printf(const char *type, ...);

#endif
