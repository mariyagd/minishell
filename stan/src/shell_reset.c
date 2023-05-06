/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:46:27 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/14 14:55:12 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_reset(t_shell *sh)
{
	if (sh->_input)
		ft_del(&sh->_input);
	sh->_ptr = 0;
	assert(sh->_cmdgrp == 0);
}
