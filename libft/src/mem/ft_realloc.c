/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:47:06 by fhelena           #+#    #+#             */
/*   Updated: 2021/01/17 19:35:38 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void *newptr;

	if (!ptr)
	{
		if (!(newptr = ft_memalloc(size)))
			return ((void *)0);
		return (newptr);
	}
	if (!size)
	{
		free(ptr);
		return ((void *)0);
	}
	if (!(newptr = ft_memalloc(size)))
	{
		free(ptr);
		return ((void *)0);
	}
	ft_memcpy(newptr, ptr, size);
	ft_memdel(ptr);
	return (newptr);
}
