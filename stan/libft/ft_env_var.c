/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:55:13 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/02 01:28:22 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return a const pointer to right after the equal sign of wanted env var
// usage:  value = ft_env_var("PATH", envp);

#define MAXVARLEN	4096

char	*ft_env_var(const char *varname, char *env[])
{
	size_t	vsz;
	char	var[MAXVARLEN];
	size_t	i;

	if (!*varname || ft_strlen2(varname, &vsz) > MAXVARLEN - 2 || !env[0])
		return (0);
	ft_strcpy(var, varname);
	if (varname[vsz - 1] != '=')
	{
		var[vsz] = '=';
		var[vsz + 1] = 0;
	}
	i = -1;
	while (env[++i])
	{
		if (ft_startswith(env[i], var))
			return (ft_strchr(env[i], '=') + 1);
	}
	return (0);
}
