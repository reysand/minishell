/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:06:34 by fhelena           #+#    #+#             */
/*   Updated: 2021/03/06 18:29:38 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_builtin(t_shell *shell)
{
	if (shell->cmd.args[1] && chdir(shell->cmd.args[1]) == -1)
	{
		shell->status = EXIT_FAILURE;
		ft_printf_fd(STDERR_FILENO, "%s: %s: ", PS0, shell->cmd.args[0]);
		ft_printf_fd(STDERR_FILENO, "%s: Fail\n", shell->cmd.args[1]);
	}
	else
	{
		shell->status = EXIT_SUCCESS;
	}
}
