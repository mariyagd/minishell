/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:29:33 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 00:50:50 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ps1(void)
{
	char		*ps1;
	static char	buf[32];
	char		*p;

	ft_putstr("\e[0m", 1);
	ps1 = ft_env_var("PS1", g_shell->env.data);
	if (!ps1 || !*ps1 || ft_strisspace(ps1))
	{
		p = ft_stpcpy(buf, "\e[1m(");
		ft_itoa(g_shell->retval, p);
		ft_strcat(p, ")" PS1 "\e[0m");
		ps1 = buf;
	}
	return (ps1);
}
