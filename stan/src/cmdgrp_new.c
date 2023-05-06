/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdgrp_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:06 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 18:50:05 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_cmdgrp_init(t_cmdgrp *cgrp)
{
	if (!ft_arr_init(&cgrp->cmds, 1, sizeof(t_cmd *)))
		return (0);
	return (1);
}

t_cmdgrp	*cmdgrp_new(void)
{
	t_cmdgrp	*cgrp;

	cgrp = ft_calloc(1, sizeof(t_cmdgrp));
	if (!cgrp)
		return (0);
	if (!_cmdgrp_init(cgrp))
	{
		ft_free(cgrp);
		return (0);
	}
	return (cgrp);
}
