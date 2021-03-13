/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:23 by fhelena           #+#    #+#             */
/*   Updated: 2021/03/13 19:34:13 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtins	g_builtins[] =
{
	{"cd", &cd_builtin},
	{"echo", &echo_builtin},
	{"env", &env_builtin},
	{"exit", &exit_builtin},
	{"setenv", &setenv_builtin},
	{"unsetenv", &unsetenv_builtin},
	{(void *)0, (void *)0}
};

static void	executor(t_shell *shell)
{
	pid_t	pid;
	int		status;
	int		i;

	i = 0;
	while (g_builtins[i].token)
	{
		if (ft_strcmp(shell->cmd.args[0], g_builtins[i].token) == 0)
		{
			g_builtins[i].f(shell);
			return ;
		}
		++i;
	}
	if (!(pid = fork()))
	{
		if ((execve(shell->cmd.args[0], shell->cmd.args, shell->envp)) == -1)
			ft_printf_fd(2, "%s: %s: %s\n", PS0, shell->cmd.args[0], ENOCMD);
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
		shell->status = _WEXITSTATUS(status);
	}
}

static void	parser(char *line, t_shell *shell)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
		{
			line[i] = ' ';
		}
		++i;
	}
	shell->cmd.args = ft_strsplit(line, ' ');
}

static void	init_shell(char **envp, t_shell *shell)
{
	shell->envp = envp;
	shell->line = (void *)0;
	shell->status = EXIT_SUCCESS;
}

int			main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	init_shell(envp, &shell);
	while (1)
	{
		ft_printf_fd(STDERR_FILENO, "%s", PS1);
		if (get_next_line(STDIN_FILENO, &shell.line) != 1)
		{
			ft_printf_fd(STDERR_FILENO, "exit\n");
			free(shell.line);
			exit(shell.status);
		}
		parser(shell.line, &shell);
		free(shell.line);
		if (shell.cmd.args[0])
		{
			executor(&shell);
		}
		free_matrix(shell.cmd.args);
	}
}
