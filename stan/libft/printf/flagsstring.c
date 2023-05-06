/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagsstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:10:22 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/14 17:08:53 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	flags_string(t_printf *spec, char **p)
{
	size_t	sz;

	if (spec->precision && !spec_precision(spec, p))
		return (0);
	if (spec->field_width && spec->field_width > (int)ft_strlen2(*p, &sz))
	{
		if (spec->minus)
		{
			if (!_rightpadd(p, ' ', spec->field_width - sz))
				return (0);
		}
		else
		{
			if (!_leftpadd(p, ' ', spec->field_width - sz))
				return (0);
		}
	}
	return (1);
}
