/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:06:34 by fhelena           #+#    #+#             */
/*   Updated: 2021/03/06 18:37:08 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Write arguments to the standard output
*/

void	echo_builtin(t_shell *shell)
{
	int	opt_n;
	int	i;

	i = 1;
	opt_n = 0;
	while (shell->cmd.args[i])
	{
		if (ft_strcmp(shell->cmd.args[i], "-n") == 0)
		{
			opt_n = 1;
		}
		else
		{
			ft_printf("%s", shell->cmd.args[i]);
			if (shell->cmd.args[i + 1])
				ft_printf(" ");
		}
		++i;
	}
	if (!opt_n)
	{
		ft_printf("\n");
	}
	shell->status = EXIT_SUCCESS;
}
