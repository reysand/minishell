/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:23 by fhelena           #+#    #+#             */
/*   Updated: 2021/01/26 20:00:36 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/errno.h>
#include <signal.h>
#include <string.h>

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
	int		i;

	cmd = ft_strsplit(line, ' ');
	i = get_matrix_size(cmd);
	cmd[i] = (void *)0;
	free(line);
	return (cmd);
}

int		executor(char **cmd)
{
	int	res;
	int	i;

	i = 0;
	res = execve(cmd[i], cmd, (void *)0);
	i = get_matrix_size(cmd);
	free_matrix(cmd, i);
	return (res);
}

int		main(void)
{
	char	**cmd;
	char	*line;
	int		res;

	line = (void *)0;
	while (!line || ft_strcmp(line, "exit") != 0)
	{
		ft_printf_fd(STDERR_FILENO, "%s", PROMPT);
		if ((res = get_next_line(STDIN_FILENO, &line)) != 1)
		{
			ft_printf("exit\n");
			return (EXIT_SUCCESS);
		}
		ft_printf("[GNL: %d] %s\n", res, line);
		cmd = parser(line);
		res = executor(cmd);
		if (res == -1)
			ft_printf("[MINISHELL: %d] %s\n", res, strerror(errno));
	}
	return (EXIT_SUCCESS);
}
