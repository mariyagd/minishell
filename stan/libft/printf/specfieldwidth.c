/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specfieldwidth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:59:41 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/14 17:04:48 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	spec_field_width(t_printf *spec, char **p)
{
	size_t	sz;
	char	c;

	if (spec->field_width > (int)ft_strlen2(*p, &sz))
	{
		if (spec->minus)
		{
			if (!_rightpadd(p, ' ', spec->field_width - sz))
				return (0);
		}
		else
		{
			if (spec->zero && (spec->conversion == 'f' || !spec->precision))
				c = '0';
			else
				c = ' ';
			if (!_leftpadd(p, c, spec->field_width - sz))
				return (0);
		}
	}
	return (1);
}
