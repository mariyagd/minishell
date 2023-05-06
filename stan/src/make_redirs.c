/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redirs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:10:14 by srapopor          #+#    #+#             */
/*   Updated: 2023/02/25 01:06:52 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_redirs(t_cmd *cmd)
{
	size_t	i;
	char	*exp;
	char	*tmp;
	t_redir	*redir;

	i = -1;
	while (++i < cmd->redirs.nelem)
	{
		redir = (t_redir *) ft_arr_get(&cmd->redirs, i);
		if (redir->tp != redir_heredoc)
		{
			exp = expand_str(redir->str);
			tmp = redir->str;
			redir->str = exp;
			ft_free(tmp);
		}
	}
}
