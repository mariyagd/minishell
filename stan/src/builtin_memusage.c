/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_memusage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:55:50 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 00:57:47 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_memusage(t_cmdgrp *cgrp, t_cmd *cmd)
{
	(void) cgrp;
	(void) cmd;
	ft_printf("%zu\n", ft_memusage());
	return (0);
}
