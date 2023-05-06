/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:34:51 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/26 00:39:22 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

int	ft_arr_del(t_arr **a, t_fn1 delfunc)
{
	ft_arr_fini(*a, delfunc);
	ft_free(*a);
	*a = 0;
	return (0);
}
