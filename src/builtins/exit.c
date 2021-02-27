/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:06:34 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/27 16:36:51 by fhelena          ###   ########.fr       */
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
		if (ft_isdigit(str[i]))
			num = num * 10 + (int)(str[i++] - '0');
		else
			return (0);
	}
	if ((i == 1 && sign) || (sign == '-' && num - 1 > LLONG_MAX))
		return (0);
	if (num > LLONG_MAX && sign != '-')
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
	free_shell(shell);
	exit(shell->status);
}
