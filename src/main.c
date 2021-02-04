/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:23 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/04 19:38:37 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>
#include <sys/errno.h>

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
	int	res;
	int	i;

	res = 0;
	//ft_printf_fd(STDERR_FILENO, "TEST: %s\n", *cmd);
	if (ft_strcmp(*cmd, "exit") == 0)
	{
		exit_builtin(EXIT_SUCCESS);
	}
	else if (ft_strcmp(*cmd, "echo") == 0)
	{
		//ft_printf("LOG: %s %s\n", *cmd, (*cmd + 4));
		echo_builtin(cmd);
	}
	else
	{
		res = execve(*cmd, cmd, envp);
	}
	i = get_matrix_size(cmd);
	free_matrix(cmd, i);
	return (res);
}

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_printf("[%d] = %s\n", i, matrix[i]);
		++i;
	}
	ft_printf("[%d] = %s\n", i, matrix[i]);
}

void	logs(int argc, char **argv, char **envp, char **apple)
{
	/*
	ft_printf("Arguments: [%d]\n", argc);
	*/
	(void)argc;
	
	/*
	print_matrix(argv);
	*/
	(void)argv;
	
	/*
	ft_printf("Environments variables (NOT POSIX):\n");
	print_matrix(envp);
	*/
	(void)envp;
	
	/*
	ft_printf("Path to executable file:\n");
	print_matrix(apple);
	*/
	(void)apple;
}

int		main(int argc, char **argv, char **envp, char **apple)
{
	char	**cmd;
	char	*line;
	int		res;

	logs(argc, argv, envp, apple);
	line = (void *)0;
	while (1)
	{
		ft_printf_fd(STDERR_FILENO, "%s", PROMPT);
		if ((res = get_next_line(STDIN_FILENO, &line)) != 1)
		{
			ft_printf("exit\n");
			return (EXIT_SUCCESS);
		}
		//ft_printf("[GNL: %d] %s\n", res, line);
		cmd = parser(line);
		if (*cmd && (res = executor(cmd, envp)) != 0)
		{
			ft_printf("[MINISHELL: %d] %s\n", res, strerror(errno));
		}
	}
	return (EXIT_SUCCESS);
}
