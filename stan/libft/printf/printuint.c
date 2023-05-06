/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:20:32 by pmarquis          #+#    #+#             */
/*   Updated: 2022/10/29 15:29:19 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	print_uint(t_printf *spec, va_list vargs, int *cnt)
{
	if (spec->conversion == 'u')
		return (print_uint_dec(spec, vargs, cnt));
	if (spec->conversion == 'o')
		return (print_uint_oct(spec, vargs, cnt));
	if (spec->conversion == 'x')
		return (print_uint_hex(spec, vargs, cnt));
	if (spec->conversion == 'X')
		return (print_uint_hexx(spec, vargs, cnt));
	return (0);
}
