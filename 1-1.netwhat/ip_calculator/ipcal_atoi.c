/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipcal_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:28:41 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/01/19 18:16:52 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ipcal.h"

ssize_t				ft_atoi(char *a)
{
	ssize_t			result;
	int				dir;

	result = 0;
	dir = 1;
	if (*a == '-')
	{
		dir = -1;
		a++;
	}
	while (ft_isnumeric(*a))
	{
		result *= 10;
		result += (*a++ - '0');
	}
	return (result * dir);
}
