/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:11 by fhelena           #+#    #+#             */
/*   Updated: 2021/02/17 12:46:27 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define STDIN_FILENO 0
# define STDOUT_FILENO 1
# define STDERR_FILENO 2
# define PS0 "minishell"
# define PS1 "minishell-0.1.2$ "

typedef struct	s_cmd
{
	char		**args;
	char		*program;
}				t_cmd;

typedef struct	s_shell
{
	t_cmd		cmd;
	char		**env;
	char		*shell;
	int			last_ret;
}				t_shell;

typedef struct	s_builtins
{
	char		*token;
	void		(*f)(t_shell *shell);
}				t_builtins;

void			echo_builtin(t_shell *shell);

/*
int				cd_builtin(char *path);
void			echo_builtin(char **string);
void			env_builtin(char **envp);
int				exit_builtin(int ret, char **string);
*/

#endif
