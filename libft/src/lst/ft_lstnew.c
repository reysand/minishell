/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:44:49 by fhelena           #+#    #+#             */
/*   Updated: 2021/01/17 19:28:46 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if (!(list = (t_list *)ft_memalloc(sizeof(t_list))))
		return ((void *)0);
	if (!content)
	{
		list->content = (void *)0;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = (void *)ft_memalloc(content_size)))
		{
			free(list);
			return ((void *)0);
		}
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = (void *)0;
	return (list);
}
