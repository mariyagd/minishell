/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specplus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:17:10 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/14 01:37:19 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	spec_plus(t_printf *spec, char **p)
{
	(void) spec;
	if (**p != '-')
	{
		if (!ft_prepend(p, "+"))
			return (0);
	}
	return (1);
}
