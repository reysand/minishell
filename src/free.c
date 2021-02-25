/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:49:07 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/25 18:52:14 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->cmd.args[i])
	{
		free(shell->cmd.args[i]);
		++i;
	}
	free(shell->cmd.args);
}
