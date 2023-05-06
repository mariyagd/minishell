/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unbs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:22:57 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/25 02:16:15 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	remove leading backslash

char	*unbs(char **cmd)
{
	char	*p;

	assert(*cmd);
	if (**cmd == '\\')
	{
		p = *cmd;
		if (!ft_strdup2(&(*cmd)[1], cmd))
			enomem();
		ft_free(p);
	}
	return (*cmd);
}
