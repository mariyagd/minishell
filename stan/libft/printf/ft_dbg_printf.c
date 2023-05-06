/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbg_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:52:54 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/05 14:55:33 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

#ifndef NDEBUG

int	ft_dbg_printf(const char *s, ...)
{
	va_list	vargs;
	int		cnt;

	va_start(vargs, s);
	cnt = ft_vdprintf(1, s, vargs);
	va_end(vargs);
	return (cnt);
}

#else

int	ft_dbg_printf(const char *s, ...)
{
	(void) s;
	return (0);
}

#endif
