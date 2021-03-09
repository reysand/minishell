/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:06:34 by fhelena           #+#    #+#             */
/*   Updated: 2021/03/09 17:46:18 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_msg(int err, t_shell *shell)
{
	char		**args;

	args = shell->cmd.args;
	ft_printf_fd(STDERR_FILENO, "%s: ", PS0);
	if (err == -1)
	{
		shell->status = err;
		ft_printf_fd(STDERR_FILENO, "%s: %s: %s\n", args[0], args[1], ENONUM);
	}
	else if (err == 1)
	{
		shell->status = err;
		ft_printf_fd(STDERR_FILENO, "%s: %s\n", args[0], EARGS);
	}
}

/*
** Long long decimal-number test
*/

static int	ft_isnum(char *str)
{
	long long	num;
	int			sign;
	int			i;

	sign = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		sign = (int)str[i++];
	num = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && sign == '-')
		{
			num = num * 10 - (int)(str[i++] - '0');
		}
		else if (ft_isdigit(str[i]))
		{
			num = num * 10 + (int)(str[i++] - '0');
		}
		else
			return (0);
	}
	if ((sign != '-' && num < 0) || (sign == '-' && num > 0))
		return (0);
	return (1);
}

/*
** Cause the shell to exit with the exit status.
*/

void		exit_builtin(t_shell *shell)
{
	ft_printf_fd(STDERR_FILENO, "exit\n");
	if (shell->cmd.args[1])
	{
		if (!ft_isnum(shell->cmd.args[1]))
		{
			error_msg(-1, shell);
		}
		else if (shell->cmd.args[2])
		{
			error_msg(1, shell);
			return ;
		}
		else
		{
			shell->status = ft_atoi(shell->cmd.args[1]);
		}
	}
	free_matrix(shell->cmd.args);
	exit(shell->status);
}
