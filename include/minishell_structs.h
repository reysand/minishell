/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:07:11 by fhelena           #+#    #+#             */
/*   Updated: 2021/03/06 17:47:47 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef struct	s_cmd
{
	char		**args;
}				t_cmd;

typedef struct	s_shell
{
	t_cmd		cmd;
	char		**env;
	char		*line;
	int			status;
}				t_shell;

typedef struct	s_builtins
{
	char		*token;
	void		(*f)(t_shell *shell);
}				t_builtins;

#endif
