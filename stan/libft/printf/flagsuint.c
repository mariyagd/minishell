/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagsuint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:45:49 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/08 20:19:52 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	flags_uint(t_printf *spec, char **p)
{
	if (spec->precision && !spec_precision(spec, p))
		return (0);
	if (spec->hash && !spec_hash(spec, p))
		return (0);
	if (spec->space && !spec_space(spec, p))
		return (0);
	if (spec->field_width && !spec_field_width(spec, p))
		return (0);
	return (1);
}
