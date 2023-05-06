/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:12:00 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 19:04:48 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_link(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		if (cmd->_io[i] != -1)
		{
			if (dup2(cmd->_io[i], i) == -1)
				return (error("dup2", strerror(errno)));
			fd_close(&cmd->_io[i]);
		}
	}
	return (1);
}
