/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:06:34 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/06 12:35:57 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Description: Write arguments to the standard output
*/

int	echo_builtin(char **string)
{
	while (*string)
	{
		ft_printf("%s ", *string++);
	}
	ft_printf("\n");
	return (EXIT_SUCCESS);
}
