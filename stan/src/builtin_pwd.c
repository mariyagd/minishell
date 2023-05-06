/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:11:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/26 15:29:52 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(t_cmdgrp *cgrp, t_cmd *cmd)
{
	char	path[PATH_MAX];

	(void) cgrp;
	(void) cmd;
	if (!getcwd(path, PATH_MAX))
		return (1 + error("getcwd", strerror(errno)));
	ft_printf("%s\n", path);
	return (0);
}
