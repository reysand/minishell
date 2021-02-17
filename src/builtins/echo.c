/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:06:34 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/17 14:59:54 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

/*
** Description: Write arguments to the standard output
*/

void	echo_builtin(t_shell *shell)
{
	int	opt_n;
	int	i;

	i = 1;
	opt_n = 0;
	if (ft_strcmp(shell->cmd.args[i], "-n") == 0)
	{
		opt_n = 1;
		++i;
	}
	while (shell->cmd.args[i])
	{
		ft_printf("%s ", shell->cmd.args[i]);
		//dprintf(1, "%s ", shell->cmd.args[i]);
		//write(1, shell->cmd.args[i], ft_strlen(shell->cmd.args[i]));
		//write(1, " ", 1);
		++i;
	}
	if (!opt_n)
	{
		ft_printf("\n");
	}
	shell->last_ret = EXIT_SUCCESS;
	return ;
}
