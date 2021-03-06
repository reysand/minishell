/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:51:15 by fhelena           #+#    #+#             */
/*   Updated: 2020/12/11 13:32:36 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTS_H
# define FT_PRINTF_STRUCTS_H

# include <stdarg.h>

# define M_H 1
# define M_HH 2
# define M_L -1
# define M_LL -2
# define M_BL -3

typedef struct		s_flags
{
	int				fd;
	int				len;
	int				prec;
	int				width;
	char			mod;
	unsigned char	min:1;
	unsigned char	plus:1;
	unsigned char	flag:1;
	unsigned char	star:1;
	unsigned char	sharp:1;
	unsigned char	space:1;
	unsigned char	w_zero:1;
	unsigned char	p_zero:1;
}					t_flags;

typedef	struct		s_type
{
	char			value;
	void			(*f)(t_flags *data, va_list ap);
}					t_type;

#endif
