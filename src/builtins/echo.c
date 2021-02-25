/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:06:34 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/25 17:21:41 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

/*
** Description: Write arguments to the standard output
** Any characters between '' and "" writes without changes; only between ""
** works shielding. If text outside "" or '' its divided by single space
** character. One " or ' must handling by shell, for minishell this feature is
** bonus.
*/

void	echo_builtin(t_shell *shell)
{
	int	opt_n;
	int	i;

	i = 1;
	opt_n = 0;
	if (shell->cmd.args[i] && ft_strcmp(shell->cmd.args[i], "-n") == 0)
	{
		opt_n = 1;
		++i;
	}
	if (!opt_n)
	{
		ft_printf("\n");
	}
	shell->status = EXIT_SUCCESS;
	return ;
}
