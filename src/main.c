/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:23 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/06 18:39:53 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_matrix_size(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		++i;
	}
	return (i);
}

char	**parser(char *line)
{
	char	**cmd;

	cmd = ft_strsplit(line, ' ');
	cmd[get_matrix_size(cmd)] = (void *)0;
	free(line);
	return (cmd);
}

int		executor(char **cmd, char **envp)
{
	int	ret;
	int	i;

	ret = 0;
	if (ft_strcmp(*cmd, "exit") == 0)
	{
		exit_builtin(EXIT_SUCCESS);
	}
	else if (ft_strcmp(*cmd, "echo") == 0)
	{
		echo_builtin(cmd);
	}
	else if (ft_strcmp(*cmd, "cd") == 0)
	{
		ret = cd_builtin(cmd[1]);
	}
	else
	{
		ret = execve(*cmd, cmd, envp);
	}
	i = get_matrix_size(cmd);
	free_matrix(cmd, i);
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
			ft_printf("exit\n");
			return (ret);
		}
		cmd = parser(line);
		if (*cmd && (ret = executor(cmd, envp)) != 0)
		{
			ft_printf("[MINISHELL: %d] %s\n", ret, strerror(errno));
		}
	}
	return (ret);
}
