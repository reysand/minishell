/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:06:34 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/21 18:45:25 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Description: Cause the minishell to exit with last status or with number
** which exit program gets as single numeric argument.
*/

void	exit_builtin(t_shell *shell)
{
	char		**args;
	const char	*e_arg;
	const char	*e_num;

	args = shell->cmd.args;
	e_arg = "too many arguments\n";
	e_num = "numeric argument required\n";
	ft_printf_fd(STDERR_FILENO, "exit\n");
	if (args[1])
	{
		shell->last_ret = ft_atoi(args[1]);
		if (ft_strcmp(ft_itoa(shell->last_ret), args[1]) != 0)
		{
			shell->last_ret = -1;
			ft_printf_fd(2, "%s: %s: %s: %s", PS0, args[0], args[1], e_num);
		}
		else if (args[2])
		{
			shell->last_ret = 1;
			ft_printf_fd(STDERR_FILENO, "%s: %s: %s", PS0, args[0], e_arg);
			return ;
		}
	}
	exit(shell->last_ret);
}
