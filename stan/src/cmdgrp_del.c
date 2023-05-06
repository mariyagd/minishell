/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdgrp_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:53:42 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 02:03:10 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_cmdgrp_fini(t_cmdgrp *cgrp)
{
	ft_arr_fini(&cgrp->cmds, &cmd_del);
}

int	cmdgrp_del(t_cmdgrp **cgrp)
{
	assert(*cgrp);
	_cmdgrp_fini(*cgrp);
	ft_free(*cgrp);
	*cgrp = 0;
	return (0);
}
