/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:11:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/23 15:27:09 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_is_nonl_flag(const char *s)
{
	if (!*s || *s++ != '-' || !*s || *s++ != 'n')
		return (0);
	if (ft_strlen(s) != ft_strspn(s, "n"))
		return (0);
	return (1);
}

static inline int	_finish(int no_nl)
{
	if (no_nl)
		return (0);
	ft_putchar('\n', STDOUT_FILENO);
	return (0);
}

int	builtin_echo(t_cmdgrp *cgrp, t_cmd *cmd)
{
	size_t	i;
	int		first_var;
	int		no_nl;
	char	*s;

	(void) cgrp;
	i = 0;
	first_var = 1;
	no_nl = 0;
	while (++i < cmd->args.nelem)
	{
		s = *(char **) ft_arr_get(&cmd->args, i);
		if (!first_var)
			ft_printf(" %s", s);
		else if (_is_nonl_flag(s))
			no_nl = 1;
		else
		{
			ft_putstr(s, STDOUT_FILENO);
			first_var = 0;
		}
	}
	return (_finish(no_nl));
}
