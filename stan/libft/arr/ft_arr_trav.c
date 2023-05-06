/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_trav.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:16:58 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/22 23:18:41 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

void	ft_arr_trav(t_arr *a, t_fn1 f)
{
	size_t	i;

	i = -1;
	while (++i < a->nelem)
		(*f)(a->data + (i * a->unit));
}
