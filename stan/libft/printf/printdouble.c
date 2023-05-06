/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:03:45 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/15 19:58:30 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

static int	print_double_double_ee(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[128];
	char	*s;

	spec->arg.as_double = va_arg(vargs, double);
	if (!spec->precision)
		spec->_precision = 6;
	ft_dtoa_ee(spec->arg.as_double, spec->_precision, buf);
	if (!ft_strnew(&s, buf) || !flags_double(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

static int	print_double_double_e(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[128];
	char	*s;

	spec->arg.as_double = va_arg(vargs, double);
	if (!spec->precision)
		spec->_precision = 6;
	ft_dtoa_e(spec->arg.as_double, spec->_precision, buf);
	if (!ft_strnew(&s, buf) || !flags_double(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

static int	print_double_double(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[128];
	char	*s;

	spec->arg.as_double = va_arg(vargs, double);
	if (!spec->precision)
		spec->_precision = 6;
	ft_dtoa(spec->arg.as_double, spec->_precision, buf);
	if (!ft_strnew(&s, buf) || !flags_double(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

int	print_double(t_printf *spec, va_list vargs, int *cnt)
{
	if (ft_strchr("fF", spec->conversion))
	{
		if (*spec->length == 0)
			return (print_double_double(spec, vargs, cnt));
		if (!ft_strcmp(spec->length, "L"))
			return (0);
	}
	else if (ft_strchr("e", spec->conversion))
	{
		if (*spec->length == 0)
			return (print_double_double_e(spec, vargs, cnt));
		if (!ft_strcmp(spec->length, "L"))
			return (0);
	}
	else if (ft_strchr("E", spec->conversion))
	{
		if (*spec->length == 0)
			return (print_double_double_ee(spec, vargs, cnt));
		if (!ft_strcmp(spec->length, "L"))
			return (0);
	}
	return (0);
}
