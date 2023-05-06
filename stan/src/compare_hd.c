/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_hd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:57:03 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/24 23:28:53 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	used to compare heredoc string with input line

int	compare_hd(const char *line, const char *hd)
{
	size_t	s1;
	size_t	s2;

	if (!ft_startswith(line, hd))
		return (0);
	if (ft_strlen2(line, &s1) == ft_strlen2(hd, &s2))
		return (1);
	if (s1 == s2 + 1 && ft_endswith(line, "\n"))
		return (1);
	return (0);
}
