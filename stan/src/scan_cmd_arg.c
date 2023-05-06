/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_cmd_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:32:11 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/25 19:23:18 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*scan_cmd_arg(char **str, t_scan *scan)
{
	int		i;
	t_arr	new_arg;
	char	*ret;

	if (!ft_arr_init(&new_arg, 4, sizeof(char)))
		enomem();
	i = -1;
	while ((*str)[++i])
	{
		if (scan_quotes((*str)[i], scan))
			;
		else if (ft_strchr("|<> &", (*str)[i]) && !scan->within_double_quotes
			&& !scan->within_single_quotes)
			break ;
		else if (!ft_arr_append(&new_arg, &(*str)[i], 0))
			enomem();
	}
	*str += i;
	if (!ft_strdup2(new_arg.data, &ret))
		enomem();
	ft_arr_fini(&new_arg, 0);
	return (ret);
}
