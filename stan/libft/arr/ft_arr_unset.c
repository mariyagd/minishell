/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:27:20 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/24 00:58:41 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

int	ft_arr_unset(t_arr *a, size_t idx, t_fn1 delfunc)
{
	void	*dest;

	if (idx >= a->nelem)
		return (0);
	dest = a->data + (idx * a->unit);
	if (delfunc)
		(*delfunc)(dest);
	if (idx != a->nelem - 1)
	{
		ft_memmove(dest, dest + a->unit, (a->nelem - idx - 1) * a->unit);
		ft_memset(a->data + ((a->nelem - 1) * a->unit), 0, a->unit);
	}
	else
		ft_memset(dest, 0, a->unit);
	--(a->nelem);
	return (1);
}
