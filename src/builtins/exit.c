/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:06:34 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/09 18:54:14 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_builtin(int ret, char **str)
{
	const char	*e_arg;
	const char	*e_num;
	int			i;

	e_arg = "too many arguments\n";
	e_num = "numeric argument required\n";
	ft_printf_fd(STDERR_FILENO, "exit\n");
	i = 1;
	if (str[i])
	{
		ret = ft_atoi(str[i]);
		if (ft_strcmp(ft_itoa(ret), str[i]) != 0)
		{
			ret = -1;
			ft_printf_fd(2, "%s: %s: %s: %s", SHELL, str[0], str[1], e_num);
		}
		else if (str[i + 1])
		{
			ret = 1;
			ft_printf_fd(STDERR_FILENO, "%s: %s: %s", SHELL, str[0], e_arg);
			return (ret);
		}
	}
	exit(ret);
}
