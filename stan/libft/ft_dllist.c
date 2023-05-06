/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:56:39 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/09 18:21:31 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dllist_pull(void *lst)
{
	t_dllist	*el;

	el = *(t_dllist **)lst;
	if (el)
	{
		if (el->next)
		{
			*(t_dllist **)lst = el->next;
			el->next->prev = 0;
		}
		else
			*(t_dllist **)lst = 0;
		el->next = 0;
		el->prev = 0;
	}
	return (el);
}

void	ft_dllist_push(void *lst, void *elem)
{
	t_dllist	**l;
	t_dllist	*el;

	l = (t_dllist **) lst;
	el = (t_dllist *) elem;
	if (*l)
		(*l)->prev = el;
	el->next = *l;
	el->prev = 0;
	*l = el;
}

void	ft_dllist_pushback(void *lst, void *elem, void *previous)
{
	t_dllist	*el;
	t_dllist	*prev;

	el = (t_dllist *) elem;
	prev = (t_dllist *) previous;
	if (prev)
		prev->next = el;
	else
		*(t_dllist **)lst = el;
	el->prev = prev;
	el->next = 0;
}

void	ft_dllist_take(void *lst, void *elem, void *previous)
{
	t_dllist	*el;
	t_dllist	*prev;

	el = (t_dllist *) elem;
	prev = (t_dllist *) previous;
	if (prev)
		prev->next = el->next;
	else
		*(t_dllist **)lst = el->next;
	if (el->next)
		el->next->prev = prev;
	el->prev = 0;
	el->next = 0;
}
