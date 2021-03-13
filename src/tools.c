/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:38:05 by fhelena           #+#    #+#             */
/*   Updated: 2021/03/13 18:54:05 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_matrix_size(char **matrix)
{
	int	size;

	size = 0;
	while (matrix[size])
	{
		++size;
	}
	return (size);
}
