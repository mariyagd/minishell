/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagsdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:08:54 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/14 01:35:39 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	flags_double(t_printf *spec, char **p)
{
	if (spec->hash && !spec_hash(spec, p))
		return (0);
	if (spec->plus && !spec_plus(spec, p))
		return (0);
	if (spec->space && !spec_space(spec, p))
		return (0);
	if (spec->field_width && !spec_field_width(spec, p))
		return (0);
	return (1);
}
