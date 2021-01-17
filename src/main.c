/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:23 by fhelena           #+#    #+#             */
/*   Updated: 2021/01/17 20:31:01 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/errno.h>
#include <signal.h>

/*
** Description:
**
** NOTE:		(malloc){cmd,*cmd}
**
** TODO:		Return result of last command
*/

int		main(void)
{
	char	**cmd;
	char	*line;
	int		res;
	int		i;

	line = (void *)0;
	while (!line || ft_strcmp(line, "exit") != 0)
	{
		ft_printf_fd(STDERR_FILENO, "%s", PROMPT);
		if ((res = get_next_line(STDIN_FILENO, &line)) != 1)
		{
			ft_printf("exit\n");
			return (EXIT_SUCCESS);
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
