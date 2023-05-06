/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_indexof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:46:59 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 22:22:53 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MAXVARLEN	4096

size_t	env_indexof(const t_arr *env, const char *varname)
{
	char	var[MAXVARLEN];
	size_t	i;
	char	*s;

	ft_strcpy(var, varname);
	ft_strcatchr(var, '=', 1);
	i = -1;
	while (++i < env->nelem)
	{
		s = *(char **) ft_arr_get(env, i);
		if (ft_startswith(s, var))
			return (i);
	}
	return (-1);
}
