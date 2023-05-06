/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpercent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:15:47 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/09 16:18:12 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	print_percent(t_printf *spec, va_list vargs, int *cnt)
{
	char	*s;

	(void) vargs;
	if (!ft_strnew(&s, "%") || !flags_percent(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}
