/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 21:01:05 by fhelena           #+#    #+#             */
/*   Updated: 2020/09/10 01:24:38 by fhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prec_parse(t_flags *data, char *s, int len)
{
	if (data->p_zero && len == 1 && s[0] == '0')
		return ;
	if (data->prec > len)
		print_prec(data, data->prec - len, 'x');
	ft_putstr_fd(s, data->fd);
	data->len += len;
}

static int	check_width(t_flags *data, int len, char type)
{
	int	width;

	width = 0;
	if (data->prec > len)
		width = get_width(data, data->prec, type);
	else
		width = get_width(data, len, type);
	return (width);
}

static void	width_parse(t_flags *data, char *s, char type)
{
	char	*prefix;
	int		len;
	int		width;

	len = ft_strlen(s);
	width = check_width(data, len, 'x');
	if (data->p_zero && len == 1 && s[0] == '0')
		width = data->width;
	if (width && data->sharp && !(len == 1 && s[0] == '0'))
		width -= 2;
	prefix = ((type == 'x') ? (ft_strdup("0x")) : (ft_strdup("0X")));
	if (data->sharp && !(len == 1 && s[0] == '0') && data->w_zero &&\
			!data->p_zero)
		ft_putstr_fd(prefix, data->fd);
	if (!data->min)
		print_width(data, width, type);
	if (data->sharp && !(len == 1 && s[0] == '0') && (!data->w_zero ||\
			data->p_zero))
		ft_putstr_fd(prefix, data->fd);
	if (data->sharp && !(len == 1 && s[0] == '0'))
		data->len += 2;
	free(prefix);
	prec_parse(data, s, len);
	if (data->min)
		print_width(data, width, 'x');
}

void		hexx_parse(t_flags *data, va_list ap)
{
	unsigned long long	x;
	char				*str;

	if (data->mod == M_LL)
		x = va_arg(ap, unsigned long long);
	else if (data->mod == M_L)
		x = va_arg(ap, unsigned long);
	else if (data->mod == M_H)
		x = (unsigned short)va_arg(ap, unsigned int);
	else if (data->mod == M_HH)
		x = (unsigned char)va_arg(ap, unsigned int);
	else
		x = (unsigned int)va_arg(ap, unsigned int);
	str = ptf_itoa_base(x, 16, "0123456789abcdef", 0);
	width_parse(data, str, 'x');
	free(str);
}

void		hex_parse(t_flags *data, va_list ap)
{
	unsigned long long	x;
	char				*str;

	if (data->mod == M_LL)
		x = va_arg(ap, unsigned long long);
	else if (data->mod == M_L)
		x = va_arg(ap, unsigned long int);
	else if (data->mod == M_H)
		x = (unsigned short)va_arg(ap, unsigned int);
	else if (data->mod == M_HH)
		x = (unsigned char)va_arg(ap, unsigned int);
	else
		x = va_arg(ap, unsigned int);
	str = ptf_itoa_base(x, 16, "0123456789ABCDEF", 0);
	width_parse(data, str, 'X');
	free(str);
}
