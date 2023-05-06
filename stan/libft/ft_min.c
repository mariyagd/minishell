/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:10:38 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/25 22:40:02 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

long	ft_lmin(long a, long b)
{
	if (a <= b)
		return (a);
	return (b);
}

t_ulong	ft_ulmin(t_ulong a, t_ulong b)
{
	if (a <= b)
		return (a);
	return (b);
}
