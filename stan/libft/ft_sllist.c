/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sllist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:56:24 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/08 00:57:40 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_sllist_pull(void *lst)
{
	t_sllist	*el;

	el = *(t_sllist **)lst;
	if (el)
	{
		*(t_sllist **)lst = el->next;
		el->next = 0;
	}
	return (el);
}

void	ft_sllist_push(void *lst, void *el)
{
	t_sllist	*p;

	p = *(t_sllist **)lst;
	*(t_sllist **)lst = el;
	((t_sllist *)el)->next = p;
}

void	ft_sllist_take(void *lst, void *elem, void *previous)
{
	t_sllist	*el;
	t_sllist	*prev;

	el = (t_sllist *) elem;
	prev = (t_sllist *) previous;
	if (prev)
		prev->next = el->next;
	else
		*(t_sllist **)lst = el->next;
	el->next = 0;
}
