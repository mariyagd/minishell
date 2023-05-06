/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:07:26 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/13 18:02:48 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

static int	print_int_char(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[21];
	char	*s;

	spec->arg.as_char = va_arg(vargs, int);
	ft_lltoa(spec->arg.as_char, buf);
	if (!ft_strnew(&s, buf) || !flags_int(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

static int	print_int_short(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[21];
	char	*s;

	spec->arg.as_short = va_arg(vargs, int);
	ft_lltoa(spec->arg.as_short, buf);
	if (!ft_strnew(&s, buf) || !flags_int(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

static int	print_int_longlong(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[21];
	char	*s;

	spec->arg.as_longlong = va_arg(vargs, long long);
	ft_lltoa(spec->arg.as_longlong, buf);
	if (!ft_strnew(&s, buf) || !flags_int(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

static int	print_int_long(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[21];
	char	*s;

	spec->arg.as_long = va_arg(vargs, long);
	ft_lltoa(spec->arg.as_long, buf);
	if (!ft_strnew(&s, buf) || !flags_int(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

int	print_int(t_printf *spec, va_list vargs, int *cnt)
{
	if (*spec->length == 0)
		return (print_int_int(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "hh"))
		return (print_int_char(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "h"))
		return (print_int_short(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "ll"))
		return (print_int_longlong(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "l"))
		return (print_int_long(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "j"))
		return (print_int_intmax_t(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "z"))
		return (print_int_size_t(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "t"))
		return (print_int_ptrdiff_t(spec, vargs, cnt));
	return (0);
}
