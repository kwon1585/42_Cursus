/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipcal_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:19:28 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/01/25 12:48:50 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ipcal.h"

void				ft_reverse(char *str)
{
	char			temp;
	size_t			length;
	size_t			half_length;

	length = ft_strlen(str);
	half_length = (length >> 1);
	while (half_length)
	{
		temp = str[length - half_length];
		str[length - half_length] = str[half_length - 1];
		str[half_length - 1] = temp;
		half_length--;
	}
}

char				ft_numericlen(ssize_t num)
{
	char			length;

	length = 1;
	if (num < 0)
		length++;
	while (9 < num)
	{
		length++;
		num /= 10;
	}
	return (length);
}

size_t				ft_to_unsigned(ssize_t num)
{
	size_t			result;

	result = (num < 0) ? -num : num;
	return (result);
}

char				*ft_m_itoa(ssize_t num)
{
	char			*result;
	char			*temp;
	char			num_length;
	size_t			num_temp;

	num_temp = (num < 0) ? -num : num;
	num_length = ft_numericlen(num_temp);
	num_length += (num < 0);
	if (!(result = (char *)malloc(num_length + 1)))
		return (NULL);
	temp = result;
	while (9 < num_temp)
	{
		*temp++ = (num_temp % 10) + '0';
		num_temp /= 10;
	}
	*temp++ = (num_temp) + '0';
	if (num < 0)
		*temp++ = '-';
	*temp = 0;
	ft_reverse(result);
	return (result);
}
