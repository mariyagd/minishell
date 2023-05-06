/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:16:25 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/19 22:50:06 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_copy(t_arr *env, char *environ[])
{
	size_t	i;
	char	*s;

	i = 0;
	while (environ[i])
	{
		s = ft_strdup(environ[i]);
		if (!s || !ft_arr_append(env, &s, 0))
			return (0);
		++i;
	}
	return (1);
}

static void	_shell_level(t_arr *env)
{
	char	*p;
	int		i;
	char	buf[12];

	p = env_get(env, "SHLVL");
	if (p)
	{
		if (!ft_atoi(p, &i) || !ft_itoa(++i, buf))
			return ;
		if (!env_set(env, "SHLVL", buf))
			enomem();
	}
}

static int	_env_dup(t_arr *env, char *environ[])
{
	char	*p;

	if (!ft_arr_init(env, ft_count_arr(environ), sizeof(char *))
		|| !_copy(env, environ))
		return (0);
	p = env_get(env, "PATH");
	if (p && !*p)
	{
		if (!env_set(env, "PATH", "/usr/local/bin:/usr/local/sbin:"
				"/usr/bin:/usr/sbin:/bin:/sbin:."))
			enomem();
	}
	_shell_level(env);
	return (1);
}

static int	_shell_init(t_shell *sh, char *environ[])
{
	if (!_env_dup(&sh->env, environ))
		return (0);
	return (1);
}

t_shell	*shell_new(char *environ[])
{
	t_shell	*sh;

	sh = ft_calloc(1, sizeof(t_shell));
	if (!sh || !_shell_init(sh, environ))
		enomem();
	return (sh);
}
