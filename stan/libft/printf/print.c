/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:22:33 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/13 05:03:21 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	print(t_printf *spec, va_list vargs, int *cnt)
{
	if (spec->conversion == '%')
		return (print_percent(spec, vargs, cnt));
	if (ft_strchr("di", spec->conversion))
		return (print_int(spec, vargs, cnt));
	if (ft_strchr("ouxX", spec->conversion))
		return (print_uint(spec, vargs, cnt));
	if (ft_strchr("cC", spec->conversion))
		return (print_char(spec, vargs, cnt));
	if (ft_strchr("sS", spec->conversion))
		return (print_string(spec, vargs, cnt));
	if (spec->conversion == 'p')
		return (print_pointer(spec, vargs, cnt));
	if (spec->conversion == 'n')
		return (print_count(spec, vargs, cnt));
	if (ft_strchr("eEfFgGaA", spec->conversion))
		return (print_double(spec, vargs, cnt));
	return (0);
}

#ifndef NDEBUG

void	specdebug(t_printf *spec)
{
	ft_printf("spec = {\n"
		"hash    = %d,\n"
		"zero    = %d,\n"
		"minus   = %d,\n"
		"space   = %d,\n"
		"plus    = %d,\n"
		"apostr  = %d,\n"
		"upper_i = %d,\n"
		"f_width = %d,\n"
		"precisi = %d,\n"
		"_precis = %d,\n"
		"length  = '%s',\n"
		"convers = %c\n"
		"}\n",
		spec->hash, spec->zero, spec->minus, spec->space, spec->plus,
		spec->apostrophe, spec->upper_i, spec->field_width, spec->precision,
		spec->_precision, spec->length, spec->conversion);
}

#endif
