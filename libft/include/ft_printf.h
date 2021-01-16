/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:14:54 by fhelena           #+#    #+#             */
/*   Updated: 2020/10/27 20:44:23 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "ft_printf_structs.h"

int			ft_printf(const char *format, ...);
int			ft_printf_fd(int fd, const char *format, ...);
void		ptf_init(t_flags *data);
int			flags_parser(const char *str, t_flags *data, va_list ap, int type);

/*
** Special functions for formatting, counting, etc.
*/

long double	ft_power(long long nb, int power);
void		print_sign(t_flags *data, int minus);
int			get_width(t_flags *data, int len, char type);
void		print_prec(t_flags *data, int prec, char type);
void		print_width(t_flags *data, int width, char type);
char		*ptf_itoa_base(long long value, int base, const char *b, char flag);

/*
** Types parsers
*/

void		ptr_parse(t_flags *data, va_list ap);
void		int_parse(t_flags *data, va_list ap);
void		oct_parse(t_flags *data, va_list ap);
void		hex_parse(t_flags *data, va_list ap);
void		hexx_parse(t_flags *data, va_list ap);
void		uint_parse(t_flags *data, va_list ap);
void		char_parse(t_flags *data, va_list ap);
void		float_parse(t_flags *data, va_list ap);
void		string_parse(t_flags *data, va_list ap);
void		percent_parse(t_flags *data, va_list ap);

#endif
