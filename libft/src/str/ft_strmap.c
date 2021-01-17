/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:49:02 by fhelena           #+#    #+#             */
/*   Updated: 2021/01/17 19:42:19 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*res;

	if (!s || !f)
		return ((void *)0);
	len = ft_strlen(s);
	if (!(res = ft_strnew(len)))
		return ((void *)0);
	res += len;
	s += len;
	while (len-- > 0)
		*--res = (*f)(*--s);
	return (res);
}
