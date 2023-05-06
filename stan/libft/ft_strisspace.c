/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:56:14 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/19 18:15:08 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return 1 if string is made of spaces only

int	ft_strisspace(const char *s)
{
	while (*s)
	{
		if (!ft_isspace(*s++))
			return (0);
	}
	return (1);
}
