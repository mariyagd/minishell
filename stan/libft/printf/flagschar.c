/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagschar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:47:13 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/11 22:19:28 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	flags_char(t_printf *spec, char **p)
{
	if (spec->field_width > 1)
	{
		if (spec->minus)
		{
			if (!_rightpadd(p, ' ', spec->field_width - 1))
				return (0);
		}
		else
		{
			if (!_leftpadd(p, ' ', spec->field_width - 1))
				return (0);
		}
	}
	return (1);
}
