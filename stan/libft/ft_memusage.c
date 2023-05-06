/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memusage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:17:23 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 22:18:43 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_memusage(void)
{
	t_memlist	**lst;
	t_memlist	*p;
	size_t		tot;

	lst = ft_memlist();
	p = *lst;
	tot = 0;
	while (p)
	{
		tot += p->sz;
		p = p->next;
	}
	return (tot);
}
