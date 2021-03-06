/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:50:06 by fhelena           #+#    #+#             */
/*   Updated: 2021/01/17 19:45:02 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s || !(sub = (char *)ft_memalloc(len + 1)))
		return ((void *)0);
	sub = ft_strncpy(sub, (char *)(s + start), len);
	return (sub);
}
