/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interp_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 04:27:41 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/27 14:36:35 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	for debugging purposes...

int	interp_args(int argc, char *argv[])
{
	int		i;
	char	*p;

	i = -1;
	while (++i < argc)
	{
		if (!ft_strdup2(argv[i], &p))
			enomem();
		interp(p);
	}
	i = g_shell->retval;
	ft_memtrash();
	return (i);
}
