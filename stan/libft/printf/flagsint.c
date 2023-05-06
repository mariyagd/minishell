/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagsint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:15:48 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/08 20:18:48 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	flags_int(t_printf *spec, char **p)
{
	if (spec->precision && !spec_precision(spec, p))
		return (0);
	if (spec->plus && !spec_plus(spec, p))
		return (0);
	if (spec->space && !spec_space(spec, p))
		return (0);
	if (spec->field_width && !spec_field_width(spec, p))
		return (0);
	return (1);
}
