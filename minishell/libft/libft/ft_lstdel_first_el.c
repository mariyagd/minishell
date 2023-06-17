/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_first_el.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:39:43 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/09 10:40:03 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	delete_first_el(t_list **a)
{
	t_list	*tmp;

	tmp = (*a)->next;
	free (*a);
	*a = tmp;
}
