/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:34:45 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/19 18:25:18 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// delete a pointer passed by reference

void	ft_del(void *p)
{
	char	**sp;

	sp = (char **) p;
	if (*sp)
	{
		ft_free(*sp);
		*sp = 0;
	}
}
