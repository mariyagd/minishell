/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:39:56 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/16 00:29:35 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	return 1 if cmd is complete: has one argument, or redirection
//	+ is not expecting more info

int	cmd_valid(const t_cmd *cmd)
{
	if (cmd->_expect || (cmd->args.nelem == 0 && cmd->redirs.nelem == 0))
		return (0);
	return (1);
}
