/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:11 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/04 19:24:25 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define STDIN_FILENO 0
# define STDOUT_FILENO 1
# define STDERR_FILENO 2
# define PROMPT "minishell-0.1.1$ "

void	free_matrix(char **matrix, int size);
void	exit_builtin(int status);
int		echo_builtin(char **string);

#endif
