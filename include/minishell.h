/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:11 by fhelena           #+#    #+#             */
/*   Updated: 2021/03/06 18:28:50 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "minishell_structs.h"
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>

/*
** Exit status
*/
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

/*
** File descriptors
*/
# define STDIN_FILENO 0
# define STDOUT_FILENO 1
# define STDERR_FILENO 2

/*
** Limits
*/
# define LLONG_MAX 9223372036854775807LL

/*
** Errors
*/
# define ENONUM "numeric argument required"
# define EARGS "too many arguments"
# define ENOCMD "command not found"

/*
** Shell
*/
# define PS0 "minishell"
# define PS1 "minishell-0.1.3$ "

void	free_matrix(char **matrix);
void	cd_builtin(t_shell *shell);
void	echo_builtin(t_shell *shell);
void	env_builtin(t_shell *shell);
void	exit_builtin(t_shell *shell);
void	setenv_builtin(t_shell *shell);
void	unsetenv_builtin(t_shell *shell);

#endif
