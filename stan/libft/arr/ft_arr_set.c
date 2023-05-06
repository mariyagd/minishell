/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:21:54 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/24 00:51:50 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

void	*ft_arr_set(t_arr *a, size_t idx, void *p, t_fn2 copyfunc)
{
	void	*dest;

	if (idx >= a->nelem)
		return (0);
	dest = a->data + (idx * a->unit);
	if (dest == p)
		return (dest);
	if (copyfunc)
		(*copyfunc)(dest, p);
	else
		ft_memcpy(dest, p, a->unit);
	return (dest);
}
