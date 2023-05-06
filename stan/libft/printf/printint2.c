/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:07:15 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/13 18:05:27 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	print_int_intmax_t(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[21];
	char	*s;

	spec->arg.as_intmax_t = va_arg(vargs, intmax_t);
	ft_lltoa(spec->arg.as_intmax_t, buf);
	if (!ft_strnew(&s, buf) || !flags_int(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

int	print_int_size_t(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[21];
	char	*s;

	spec->arg.as_size_t = va_arg(vargs, size_t);
	ft_lltoa(spec->arg.as_size_t, buf);
	if (!ft_strnew(&s, buf) || !flags_int(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

int	print_int_ptrdiff_t(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[21];
	char	*s;

	spec->arg.as_ptrdiff_t = va_arg(vargs, ptrdiff_t);
	ft_lltoa(spec->arg.as_ptrdiff_t, buf);
	if (!ft_strnew(&s, buf) || !flags_int(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

int	print_int_int(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[21];
	char	*s;

	spec->arg.as_int = va_arg(vargs, int);
	if (spec->arg.as_int == 0 && spec->precision && spec->_precision == 0)
		buf[0] = 0;
	else
		ft_lltoa(spec->arg.as_int, buf);
	if (!ft_strnew(&s, buf) || !flags_int(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}
