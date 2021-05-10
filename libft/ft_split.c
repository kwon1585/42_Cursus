/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 08:59:05 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/10 09:43:45 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**to_free(char **str, int i)
{
	while (--i >= 0)
		free(*(str + i));
	free(str);
	return (0);
}

int		find_start(char const *s, char c)
{
	int i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
			break ;
		i++;
	}
	return (i);
}

int		find_end(char const *s, char c)
{
	int i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			break ;
		i++;
	}
	return (i);
}

int		count_split(char const *s, char c)
{
	int	index;
	int	change;
	int	rtn;

	index = 0;
	change = 0;
	rtn = 0;
	while (*(s + index))
	{
		if (*(s + index) != c && !change)
		{
			change = 1;
			rtn++;
		}
		else if (*(s + index) == c && change)
			change = 0;
		index++;
	}
	return (rtn);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		cnt;
	int		start;
	int		end;
	char	**rtn;

	if (!s)
		return (0);
	i = 0;
	end = 0;
	cnt = count_split(s, c);
	if (!(rtn = malloc(sizeof(char *) * (cnt + 1))))
		return (0);
	*(rtn + cnt) = 0;
	while (i < cnt)
	{
		start = end + find_start(s + end, c);
		end = start + find_end(s + start, c);
		*(rtn + i) = malloc(sizeof(char) * (end - start + 1));
		if (!*(rtn + i))
			return (to_free(rtn, i));
		ft_memcpy(*(rtn + i), s + start, end - start);
		*(*(rtn + i++) + end - start) = 0;
	}
	return (rtn);
}
