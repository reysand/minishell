/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:23 by fhelena           #+#    #+#             */
/*   Updated: 2021/01/25 14:53:08 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/errno.h>
#include <signal.h>
#include <string.h>

/*
** Description:
**
** NOTE:		(malloc){cmd,*cmd}
**
** TODO:		Return result of last command
*/

extern char **environ;

int		main(void)
{
	char	**cmd;
	char	*line;
	char	*tmp;
	int		res;
	int		i;

	line = (void *)0;
	i = 0;
	ft_printf("Environment variables:\n");
	while (environ[i])
	{
		ft_printf("envp[%d]: %s\n", i, environ[i]);
		++i;
	}
	ft_printf("\n");
	while (!line || ft_strcmp(line, "exit") != 0)
	{
		ft_printf_fd(STDERR_FILENO, "%s", PROMPT1);
		if ((res = get_next_line(STDIN_FILENO, &line)) != 1)
		{
			ft_printf("exit\n");
			return (EXIT_SUCCESS);
		}
		if (line[ft_strlen(line) - 1] == '\\')
		{
			line[ft_strlen(line) - 1] = ' ';
			ft_printf_fd(STDERR_FILENO, "%s", PROMPT2);
			tmp = line;
			get_next_line(STDIN_FILENO, &line);
			line = ft_strjoin(tmp, line);
		}
		ft_printf("\nOUTPUT: %d %s\n", res, line);
		cmd = ft_strsplit(line, ' ');
		i = 0;
		while (cmd[i])
		{
			ft_printf("%s\n", cmd[i]);
			++i;
		}
		cmd[i] = (void *)0;
		res = execve(cmd[0], cmd, (void *)0);
		if (res == -1)
			ft_printf("RES = %d %s\n", res, strerror(errno));
		free_matrix(cmd, i);
		free(line);
	}
	return (EXIT_SUCCESS);
}
