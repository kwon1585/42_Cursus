/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 04:00:11 by dokwon            #+#    #+#             */
/*   Updated: 2021/07/27 01:23:22 by dokwon           ###   ########.fr       */
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


int		ft_putchar(char *c);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_intlen(unsigned long long n);
char	*ft_itoa(unsigned long long n);


void	init_check(t_check *check);
char	*check_format(t_check *check, char *format);

int	print_char(va_list ap, t_check *check);
int	print_str(va_list ap, t_check *check);
int	print_addr(va_list ap, t_check *check);

int	pre_print(va_list ap, char *format);
int	ft_printf(const char *type, ...);

#endif
