/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipcal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:11:44 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/01/20 13:10:45 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ipcal.h"

void				ft_default_error(char *error_code)
{
	const char		*default_error = "ERROR: error_code = [%d]\n\0";

	while (*default_error)
	{
		if (*default_error == '%')
		{
			while (*error_code)
				write(1, error_code++, 1);
			default_error += 2;
		}
		else
			write(1, default_error++, 1);
	}
}

void				ft_messaged_error(char error_code, char *messages)
{
	char			*flag;

	flag = messages;
	while (error_code--)
	{
		while (*flag && *flag != '\n')
			flag++;
		if (*flag == '\n')
			flag++;
	}
	if (!(*flag))
		flag = messages;
	write(1, "> ", 2);
	while (*flag != '\n' && *flag)
		write(1, flag++, 1);
	write(1, "\n", 1);
}

void				ft_show_error_code(char error_code)
{
	char			*error_char;

	if (!(ft_show_file_data("./f_error_code", error_code)))
	{
		error_char = ft_m_itoa(error_code);
		ft_default_error(error_char);
		free(error_char);
	}
}
