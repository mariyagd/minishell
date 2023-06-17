/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_last_el.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:39:53 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/09 10:39:58 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	delete_last_el(t_list **a)
{
	t_list	*end;
	t_list	*prev;

	end = *a;
	prev = NULL;
	while (end->next)
	{
		prev = end;
		end = end->next;
	}
	prev->next = NULL;
	free (end);
}
