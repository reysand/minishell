/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:23 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/21 18:13:50 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtins	g_builtins[] =
{
	{"echo", &echo_builtin},
	{"exit", &exit_builtin}
};

static void	executor(t_shell *shell)
{
	int	i;

	i = 0;
	while (g_builtins[i].token)
	{
		if (ft_strcmp(shell->cmd.program, g_builtins[i].token) == 0)
		{
			g_builtins[i].f(shell);
			break ;
		}
		else
		{
			++i;
		}
	}
	if (!(g_builtins[i].token))
	{
		ft_printf_fd(2, "%s: %s: command not found\n", PS0, shell->cmd.program);
	}
}

static void	print_shell(t_shell shell)
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

static void	parser(char *line, t_shell *shell)
{
	shell->cmd.args = ft_strsplit(line, ' ');
	shell->cmd.program = shell->cmd.args[0];
}

static void	init_shell(char **envp, t_shell *shell)
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

	(void)argc;
	(void)argv;
	(void)envp;
	ft_printf_fd(3, "\n====================================================\n");
	init_shell(envp, &shell);
	shell.line = (void *)0;
	while (1)
	{
		ft_printf_fd(STDERR_FILENO, "%s", PS1);
		if (get_next_line(STDIN_FILENO, &shell.line) != 1)
		{
			free(shell.line);
			ft_printf_fd(STDERR_FILENO, "exit\n");
			return (shell.last_ret);
		}
		parser(shell.line, &shell);
		print_shell(shell);
		executor(&shell);
		free(shell.line);
	}
	return (shell.last_ret);
}
