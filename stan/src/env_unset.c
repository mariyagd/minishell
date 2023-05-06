/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:36:11 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/11 21:03:30 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_unset(t_arr *env, const char *varname)
{
	size_t	i;

	i = env_indexof(env, varname);
	if (i == (size_t) -1)
		return (1);
	if (!ft_arr_unset(env, i, 0))
		return (0);
	return (1);
}
