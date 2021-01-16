/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:23 by fhelena           #+#    #+#             */
/*   Updated: 2021/01/16 20:20:30 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_matrix(char **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		++i;
	}
	free(matrix);
}

/*
** Return result of last command
*/

int		main(void)
{
	char	**cmd;
	char	*line;
	int		res;
	int		i;

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
	free(line);
	free_matrix(cmd, i);
	return (EXIT_SUCCESS);
}
