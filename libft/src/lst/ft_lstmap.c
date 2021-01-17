/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:44:16 by fhelena           #+#    #+#             */
/*   Updated: 2021/01/17 19:28:15 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstdelitem(void *content, size_t content_size)
{
	if (content)
	{
		ft_bzero(content, content_size);
		free(content);
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;

	if (!lst || !f)
		return ((void *)0);
	if (!(list = (t_list *)ft_memalloc(sizeof(f(lst)))))
		return ((void *)0);
	list = f(lst);
	if (!(list->next = ft_lstmap(lst->next, f)) && lst->next)
	{
		ft_lstdelone(&list, &ft_lstdelitem);
		return ((void *)0);
	}
	return (list);
}
