/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipcal.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:53:22 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/01/25 12:48:55 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IPCAL_H
# define IPCAL_H
# define BUFFER_SIZE 1024
# define IP_V4_BLOCK_SIZE 4
# define MAX_DOT_COUNT 3
# define MAX_V4_NUM_LENGTH 3
# define CLASS_E 240
# define PRIVATE_MIN_CLASS_A 167772160
# define PRIVATE_MAX_CLASS_A 184549375
# define PRIVATE_MIN_CLASS_B 2886729728
# define PRIVATE_MAX_CLASS_B 2887778303
# define PRIVATE_MIN_CLASS_C 3232235520
# define PRIVATE_MAX_CLASS_C 3232301055
# define FULL_IP_VALUE 4294967295
# define CHARACTER_LENGTH 8
# define MAX_CHARACTER_VALUE 255
# define MAX_IP_V4_LENGTH 15
# define MAX_IP_V4_BIT_LENGTH 32
# define MAX_IP_V6_LENGTH 23
# define MAX_IP_V6_BIT_LENGTH 128
# define SUBNET_BIT_LENGTH 2
# define IP_V4 255
# define IP_V6 65535
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

extern unsigned char	g_subnet_bit;
extern unsigned int		g_ip;
extern unsigned int		g_c_mask;
extern int				g_auto_flag;
/*
** ipcal.c
*/
void				ft_show_prompt();
/*
** ipcal_info.c
*/
void				ft_show_default_ip_class();
int					ft_show_ip();
unsigned char		ft_get_default_ip_class();
unsigned int		ft_get_subnet_mask();
void				ft_show_subip_exception();
int					ft_show_tail_subnet();
void				ft_show_subnet_mask();
void				ft_show_subnet_addr();
void				ft_show_value_iptype(unsigned int arg);
void				ft_show_subhost_addr();
unsigned int		ft_get_sub_broadcast_addr(void);
void				ft_show_sub_broadcast_addr();
void				ft_show_useable_subhost_range();
void				ft_show_private();
void				ft_show_bool(int value);
/*
** ipcal_itoa.c
*/
void				ft_reverse(char *str);
char				ft_numericlen(ssize_t num);
size_t				ft_to_unsigned(ssize_t num);
char				*ft_m_itoa(ssize_t num);
/*
** ipcal_atoi.c
*/
ssize_t				ft_atoi(char *a);
/*
** ipcal_error.c
*/
void				ft_default_error(char *error_code);
void				ft_messaged_error(char error_code, char *messages);
void				ft_show_error_code(char error_code);
/*
** ipcal_check_form.c
*/
int					ft_command(char *buff);
int					ft_input_router(char *buff);
int					ft_check_form(char *buff);
int					ft_input_checker(char *buff);
/*
** ipcal_utils.c
*/
size_t				ft_strlen(char *str);
size_t				ft_strclen(char *str, char c);
size_t				ft_strlcat(char *dest, char *src, size_t length);
void				ft_bzero(char *dst, size_t length);
int					ft_isspace(char c);
char				ft_tolower(char c);
char				ft_isnumeric(char c);
char				ft_isupper(char c);
char				ft_islower(char c);
char				ft_isalpha(char c);
char				ft_ishexrange(char c);
int					ft_compare(char *src, char *cmp);
void				ft_tolower_s(char *c);
char				*ft_strchr(char *src, char c);
void				ft_addr_swap(char **s1, char **s2);
int					ft_isspace_not_nl(char c);
void				ft_show_string(char *dst);
void				ft_show_number(ssize_t num);
int					ft_show_useable_range_by_mask(int flag_count);
/*
** ipcal_readfile.c
*/
void				ft_show_whole_file(char *file_name);
int					ft_show_file_data(char *file_name, int index);
void				ft_show_file_data_with_f(
												char *file_name,
												void (*f)(int index));
/*
** ipcal_get_next_line.c
*/
int					ft_get_next_line(int fd, char **dest);

# define PASS 0
# define UNDEFINED_E 0
# define EMPTY_E 1
# define WRONG_E 2
# define TYPE_E 3
# define RANGE_E 4
# define LENGTH_E 5
# define A_CLASS_EXCEPTION_E 7
# define SUBNET_E 8
# define SUBNET_SIZE_E 9
# define COMMAND_E 10
# define ZERO_E 11
# define DE_CLASS_NEED_ADRESS_BIT_E 12
# define MASK_RANGE_E 13
#endif
