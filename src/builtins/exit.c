/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:06:34 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/25 18:15:21 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_msg(int err, t_shell *shell)
{
	char		**args;
	const char	*e_arg;
	const char	*e_num;

	e_arg = "too many arguments";
	e_num = "numeric argument required";
	args = shell->cmd.args;
	ft_printf_fd(STDERR_FILENO, "%s: ", PS0);
	if (err == -1)
	{
		shell->status = err;
		ft_printf_fd(STDERR_FILENO, "%s: %s: %s\n", args[0], args[1], e_num);
	}
	else if (err == 1)
	{
		shell->status = err;
		ft_printf_fd(STDERR_FILENO, "%s: %s\n", args[0], e_arg);
	}
}

/*
** Description: Cause the shell to exit with the exit status.
*/

void		exit_builtin(t_shell *shell)
{
	char	*temp;
	int		n;

	ft_printf_fd(STDERR_FILENO, "exit\n");
	if (shell->cmd.args[1])
	{
		n = ft_atoi(shell->cmd.args[1]);
		temp = ft_itoa(n);
		if (ft_strcmp(temp, shell->cmd.args[1]) != 0)
		{
			error_msg(-1, shell);
		}
		else if (shell->cmd.args[2])
		{
			error_msg(1, shell);
			free(temp);
			return ;
		}
		else
			shell->status = n;
		free(temp);
	}
	free_shell(shell);
	exit(shell->status);
}
