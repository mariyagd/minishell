/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui_ex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:26:12 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/07 18:01:50 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// spec = 0;	// no special check
// spec |= 1;	// check for equal zero
// spec |= 2;	// check for > zero

int	ft_atoui_ex(const char *s, unsigned int *ret, int spec)
{
	char	*p;

	p = ft_atoui(s, ret);
	if (!p || *p)
		return (0);
	if (spec)
	{
		if ((spec & 1 && *ret == 0) || (spec & 2 && *ret > 0))
			return (0);
	}
	return (1);
}

int	ft_atoul_ex(const char *s, unsigned long *ret, int spec)
{
	char	*p;

	p = ft_atoul(s, ret);
	if (!p || *p)
		return (0);
	if (spec)
	{
		if ((spec & 1 && *ret == 0) || (spec & 2 && *ret > 0))
			return (0);
	}
	return (1);
}

int	ft_atosz_ex(const char *s, size_t *ret, int spec)
{
	char	*p;

	p = ft_atosz(s, ret);
	if (!p || *p)
		return (0);
	if (spec)
	{
		if ((spec & 1 && *ret == 0) || (spec & 2 && *ret > 0))
			return (0);
	}
	return (1);
}
