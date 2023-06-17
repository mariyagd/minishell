/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:16:06 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/09 11:52:36 by marvin           ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*ptr;

	ptr = *lst;
	if (!del)
		return ;
	while (ptr != NULL)
	{
		temp = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = temp;
	}
	*lst = NULL;
}
