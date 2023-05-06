/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:27:56 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 01:19:26 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_startswith(const char *s, const char *prefix)
{
	if (!*s || !*prefix)
		return (0);
	while (*prefix && (*prefix == *s))
	{
		++prefix;
		++s;
	}
	if (*prefix)
		return (0);
	return (1);
}
