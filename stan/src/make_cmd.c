/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:38:46 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/26 00:22:41 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*_emptycmd(t_cmd *cmd)
{
	assert(cmd->_full_cmd == 0);
	if (!ft_strdup2("", &cmd->_full_cmd))
		enomem();
	return (cmd->_full_cmd);
}

//	unroll all args into one string, possibly empty
//	returned string is stored, dont compute it twice

char	*make_cmd(t_cmd *cmd)
{
	t_arr	new_string;
	size_t	i;
	char	*s;

	if (cmd->_full_cmd)
		return (cmd->_full_cmd);
	if (cmd->args.nelem == 0)
		return (_emptycmd(cmd));
	if (!ft_arr_init(&new_string, 128, sizeof(char)))
		enomem();
	i = -1;
	while (++i < cmd->args.nelem)
	{
		s = *(char **) ft_arr_get(&cmd->args, i);
		add_arg_to_full_command(&new_string, s);
		if (i != cmd->args.nelem - 1 && !ft_arr_append(&new_string, " ", 0))
			enomem();
	}
	if (!ft_strdup2(new_string.data, &cmd->_full_cmd))
		enomem();
	ft_arr_fini(&new_string, 0);
	return (cmd->_full_cmd);
}
