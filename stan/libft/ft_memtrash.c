/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memtrash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:16:50 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 22:18:33 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memtrash(void)
{
	t_memlist	**m;
	t_memlist	*p;
	t_memlist	*next;

	m = ft_memlist();
	p = *m;
	while (p)
	{
		next = p->next;
		free(p);
		p = next;
	}
	*m = 0;
}
