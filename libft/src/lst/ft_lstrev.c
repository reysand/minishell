/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:47:37 by fhelena           #+#    #+#             */
/*   Updated: 2021/01/17 19:36:10 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstrev(t_list *lst)
{
	t_list *prev;
	t_list *temp;
	t_list *next;

	prev = (void *)0;
	temp = lst;
	next = (void *)0;
	while (temp)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	return (prev);
}
