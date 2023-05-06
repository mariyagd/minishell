/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuintoct2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:48 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/13 19:01:49 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	print_uint_size_t_oct(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[23];
	char	*s;

	spec->arg.as_size_t = va_arg(vargs, size_t);
	ft_ulltoa_oct(spec->arg.as_size_t, buf);
	if (!ft_strnew(&s, buf) || !flags_uint(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

int	print_uint_uint_oct(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[23];
	char	*s;

	spec->arg.as_uint = va_arg(vargs, unsigned int);
	if (spec->arg.as_uint == 0 && spec->precision && spec->_precision == 0)
		buf[0] = 0;
	else
		ft_ulltoa_oct(spec->arg.as_uint, buf);
	if (!ft_strnew(&s, buf) || !flags_uint(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}
