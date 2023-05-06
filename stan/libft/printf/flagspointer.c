/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagspointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:23:31 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/08 20:42:48 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	flags_pointer(t_printf *spec, char **p)
{
	size_t	sz;

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
