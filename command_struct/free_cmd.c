/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:34:50 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/10 16:29:22 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	free_tab2d(char **s)
{
	int	i;

	if (!s || !*s)
		return ;
	i = 0;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

void	free_cmd(t_cmd **head)
{
	t_cmd	*ptr;
	t_cmd	*tmp;

	if (!head || !*head)
		return ;
	ptr = *head;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free_tab2d(tmp->cmd);
		free_tab2d(tmp->redir);
		tmp->cmd = NULL;
		tmp->redir = NULL;
		free(tmp);
	}
	*head = NULL;
}
