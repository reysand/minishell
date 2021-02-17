/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:23 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/17 13:43:38 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtins	g_builtins[] =
{
	{"echo", &echo_builtin}
};

void		executor(t_shell *shell)
{
	int	i;

	i = 0;
	if (ft_strcmp(shell->cmd.program, g_builtins[i].token) == 0)
	{
		g_builtins[i].f(shell);
	}
	else
	{
		ft_printf_fd(STDERR_FILENO, "command not found\n");
	}
}

/*
static int	executor(char **cmd, char **envp)
{
	pid_t	pid;
	int		status;
	int		ret;

	ret = 0;
	if (ft_strcmp(*cmd, "exit") == 0)
		ret = exit_builtin(ret, cmd);
	else if (ft_strcmp(*cmd, "echo") == 0)
		echo_builtin(cmd);
	else if (ft_strcmp(*cmd, "env") == 0)
		env_builtin(envp);
	else if (ft_strcmp(*cmd, "cd") == 0)
		ret = cd_builtin(cmd[1]);
	else if (ft_strcmp(*cmd, "setenv") == 0)
		env_builtin(envp);
	else if (ft_strcmp(*cmd, "unsetenv") == 0)
		env_builtin(envp);
	else
	{
		if ((pid = fork()) == 0)
		{
			ft_printf("[log] pid = %d\n", pid);
			ret = execve(*cmd, cmd, envp);
		}
		else
		{
			ft_printf("[log] pid = %d\n", pid);
			waitpid(pid, &status, 0);
			ft_printf("[log] status = %d\n", status);
		}
	}
	return (ret);
}
*/

void		print_shell(t_shell shell)
{
	int	i;

	ft_printf_fd(3, "[shell] %s\n", shell.shell);
	i = 0;
	while (shell.env[i])
	{
		ft_printf_fd(3, "[env %d] %s\n", i, shell.env[i]);
		++i;
	}
	ft_printf_fd(3, "[program] %s\n", shell.cmd.program);
	i = 0;
	while (shell.cmd.args[i])
	{
		ft_printf_fd(3, "[args %d] %s\n", i, shell.cmd.args[i]);
		++i;
	}
	ft_printf_fd(3, "[ret] %d\n", shell.last_ret);
}

void		parser(char *line, t_shell *shell)
{
	shell->cmd.args = ft_strsplit(line, ' ');
	shell->cmd.program = shell->cmd.args[0];
}

void		init_shell(char **envp, t_shell *shell)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		++i;
	}
	if (!(shell->env = (char **)malloc((i + 1) * sizeof(char *))))
	{
		return ;
	}
	i = 0;
	while (envp[i])
	{
		shell->env[i] = ft_strdup(envp[i]);
		++i;
	}
	shell->env[i] = (void *)0;
	shell->shell = ft_strdup(PS0);
	shell->last_ret = EXIT_SUCCESS;
}

int			main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*line;

	(void)argc;
	(void)argv;
	(void)envp;
	ft_printf_fd(3, "\n====================================================\n");
	init_shell(envp, &shell);
	line = (void *)0;
	while (1)
	{
		ft_printf_fd(STDERR_FILENO, "%s", PS1);
		if (get_next_line(STDIN_FILENO, &line) != 1)
		{
			free(line);
			ft_printf_fd(STDERR_FILENO, "exit\n");
			return (shell.last_ret);
		}
		parser(line, &shell);
		print_shell(shell);
		executor(&shell);
		free(line);
	}
	return (shell.last_ret);
}
