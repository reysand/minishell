/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:23 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/09 14:55:25 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		executor(char **cmd, char **envp)
{
	int		ret;

	ret = 0;
	if (ft_strcmp(*cmd, "exit") == 0)
		ret = exit_builtin(ret, cmd);
	else if (ft_strcmp(*cmd, "echo") == 0)
		echo_builtin(cmd);
	else if (ft_strcmp(*cmd, "cd") == 0)
		ret = cd_builtin(cmd[1]);
	else if (ft_strcmp(*cmd, "env") == 0)
		env_builtin(envp);
	else
		ret = execve(*cmd, cmd, envp);
	ft_strdel(cmd);
	return (ret);
}

int		main(int argc, char **argv, char **envp)
{
	char	**cmd;
	char	*line;
	int		ret;

	(void)argc;
	(void)argv;
	ret = 0;
	line = (void *)0;
	while (1)
	{
		ft_printf_fd(STDERR_FILENO, "%s", PROMPT);
		if (get_next_line(STDIN_FILENO, &line) != 1)
		{
			ft_printf_fd(STDERR_FILENO, "exit\n");
			return (ret);
		}
		cmd = ft_strsplit(line, ' ');
		free(line);
		if (*cmd && (ret = executor(cmd, envp)) != 0)
			ft_printf("[MINISHELL: %d] %s\n", ret, strerror(errno));
	}
	return (ret);
}
