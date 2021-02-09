/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:06:34 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/09 14:17:58 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_err(int ret, char *str)
{
	const char	*e_arg;
	const char	*e_num;

	e_arg = "too many arguments\n";
	e_num = "numeric argument required\n";
	if (ret == -1)
	{
		ft_printf_fd(STDERR_FILENO, "%s: exit: %s: %s", PROMPT_ERR, str, e_num);
	}
	else if (ret == 1)
	{
		ft_printf_fd(STDERR_FILENO, "%s: exit: %s: %s", PROMPT_ERR, str, e_arg);
	}
}

int			exit_builtin(int ret, char **string)
{
	int	i;

	i = 1;
	ft_printf_fd(STDERR_FILENO, "exit\n");
	if (string[i])
	{
		ret = ft_atoi(string[i]);
		if (ft_strcmp(ft_itoa(ret), string[i]) != 0)
		{
			ret = -1;
			print_err(ret, string[i]);
		}
		else if (string[i + 1])
		{
			ret = 1;
			print_err(ret, string[i]);
			return (ret);
		}
	}
	exit(ret);
}
