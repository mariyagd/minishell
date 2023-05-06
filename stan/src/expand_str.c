/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:13:43 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/26 00:58:02 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	do the magic variable expansion here

char	*expand_str(char *s)
{
	t_arr	new_string;
	char	*exp_str;

	assert(s);
	if (!ft_arr_init(&new_string, 128, sizeof(char)))
		enomem();
	add_arg_to_full_command(&new_string, s);
	if (!ft_strdup2(new_string.data, &exp_str))
		enomem();
	ft_arr_fini(&new_string, 0);
	return (exp_str);
}
