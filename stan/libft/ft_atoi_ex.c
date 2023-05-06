/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:26:12 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/07 18:00:28 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// spec = 0;	// no special check
// spec |= 1;	// check for equal zero
// spec |= 2;	// check for negative

int	ft_atoi_ex(const char *s, int *ret, int spec)
{
	char	*p;

	p = ft_atoi(s, ret);
	if (!p || *p)
		return (0);
	if (spec)
	{
		if ((spec & 1 && *ret == 0) || (spec & 2 && *ret < 0))
			return (0);
	}
	return (1);
}
