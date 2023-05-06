/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:32:25 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/14 04:41:55 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

t_arr	*ft_arr_new(t_arr **a, size_t nelem, size_t unit)
{
	*a = ft_malloc(sizeof(t_arr));
	if (!*a)
		return (0);
	if (!ft_arr_init(*a, nelem, unit))
	{
		ft_free(*a);
		*a = 0;
		return (0);
	}
	return (*a);
}
