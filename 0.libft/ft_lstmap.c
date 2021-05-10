/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:26:17 by dokwon            #+#    #+#             */
/*   Updated: 2021/05/10 15:59:37 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		size;
	t_list	*rtn;
	t_list	*tmp;

	size = ft_lstsize(lst);
	if (!size)
		return (0);
	rtn = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (--size > 0)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&rtn, del);
			return (0);
		}
		ft_lstadd_back(&rtn, tmp);
		lst = lst->next;
	}
	return (rtn);
}
