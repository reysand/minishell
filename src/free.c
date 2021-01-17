/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:28:30 by fhelena           #+#    #+#             */
/*   Updated: 2021/01/17 15:36:18 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Description:	Freeing memory from the matrix
**
** NOTE:		(free){matrix,*matrix}
*/

void	free_matrix(char **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		++i;
	}
	free(matrix);
}
