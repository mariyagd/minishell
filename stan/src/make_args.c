/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:22:10 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/26 00:26:38 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_wildcards(t_arr *args)
{
	size_t	i;
	char	*s;

	i = 0;
	while (++i < args->nelem)
	{
		s = *(char **) ft_arr_get(args, i);
		if (*s == '*' && !ft_strcmp(s, "*"))
		{
			if (!wildcard(args, i))
				return (0);
			i = -1;
		}
	}
	return (1);
}

//	empty the args array and refill with that command string

static void	_split_full_command(char *s, t_arr *args)
{
	t_scan	scan;
	char	*new_arg;

	ft_memset(&scan, 0, sizeof(t_scan));
	ft_arr_fini(args, &ft_del);
	if (!ft_arr_init(args, 1, sizeof(char *)))
		enomem();
	while (*s)
	{
		if (ft_isspace(*s))
			++s;
		else
		{
			new_arg = scan_cmd_arg(&s, &scan);
			if (!ft_arr_append(args, &new_arg, 0))
				enomem();
		}
	}
}

//	returned value is not ignored...

int	make_args(t_cmd *cmd)
{
	char	*full_command;

	full_command = make_cmd(cmd);
	_split_full_command(full_command, &cmd->args);
	if (!_wildcards(&cmd->args))
		return (0);
	return (1);
}
