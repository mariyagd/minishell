/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:34:16 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/11 20:45:44 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	returned string is const and belongs to the env array

char	*env_get(const t_arr *env, const char *varname)
{
	size_t	i;

	i = env_indexof(env, varname);
	if (i == (size_t) -1)
		return (0);
	return (ft_env_var(varname, env->data));
}
