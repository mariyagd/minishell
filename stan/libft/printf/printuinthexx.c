/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuinthexx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:31:01 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/13 18:56:00 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

static int	print_uchar_hexx(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[17];

	spec->arg.as_uchar = va_arg(vargs, unsigned int);
	ft_ulltoa_hexx(spec->arg.as_uchar, buf);
	return (print_final_buf(buf, cnt, spec->fd));
}

static int	print_ushort_hexx(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[17];

	spec->arg.as_ushort = va_arg(vargs, unsigned int);
	ft_ulltoa_hexx(spec->arg.as_ushort, buf);
	return (print_final_buf(buf, cnt, spec->fd));
}

static int	print_ulonglong_hexx(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[17];

	spec->arg.as_ulonglong = va_arg(vargs, unsigned long long);
	ft_ulltoa_hexx(spec->arg.as_ulonglong, buf);
	return (print_final_buf(buf, cnt, spec->fd));
}

static int	print_ulong_hexx(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[17];

	spec->arg.as_ulong = va_arg(vargs, unsigned long);
	ft_ulltoa_hexx(spec->arg.as_ulong, buf);
	return (print_final_buf(buf, cnt, spec->fd));
}

int	print_uint_hexx(t_printf *spec, va_list vargs, int *cnt)
{
	if (*spec->length == 0)
		return (print_uint_uint_hexx(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "hh"))
		return (print_uchar_hexx(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "h"))
		return (print_ushort_hexx(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "ll"))
		return (print_ulonglong_hexx(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "l"))
		return (print_ulong_hexx(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "z"))
		return (print_size_t_hexx(spec, vargs, cnt));
	return (0);
}
