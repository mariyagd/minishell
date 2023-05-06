/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_ambiguous.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:19:59 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/25 19:31:40 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_ambiguous(const char *str)
{
	int		i;
	t_scan	scan;

	ft_memset(&scan, 0, sizeof(t_scan));
	if (!str[0])
	{
		ft_putstr("error: ambiguous redirect\n", STDERR_FILENO);
		return (1);
	}
	i = -1;
	while (str[++i])
	{
		scan_quotes(str[i], &scan);
		if (str[i] == ' ' && !scan.within_double_quotes
			&& !scan.within_single_quotes)
		{
			ft_putstr("error: ambiguous redirect\n", STDERR_FILENO);
			return (1);
		}
	}
	return (0);
}
