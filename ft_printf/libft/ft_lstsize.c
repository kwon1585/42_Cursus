/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:43:15 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/10 13:46:18 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	rtn;

	if (!lst)
		return (0);
	rtn = 1;
	while (lst->next)
	{
		rtn++;
		lst = lst->next;
	}
	return (rtn);
}
