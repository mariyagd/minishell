/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdgrp_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:38:41 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 00:29:23 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// return the last cmd in the list (or create one)

t_cmd	*cmdgrp_cmd(t_cmdgrp *cgrp)
{
	t_cmd	*cmd;

	if (cgrp->cmds.nelem == 0)
	{
		cmd = cmd_new();
		if (!cmd || !ft_arr_append(&cgrp->cmds, &cmd, 0))
			enomem();
	}
	else
		cmd = *(t_cmd **) ft_arr_get(&cgrp->cmds, cgrp->cmds.nelem - 1);
	return (cmd);
}
