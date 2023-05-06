/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 04:24:51 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/16 00:16:19 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	finish(int exit_status, int verbose)
{
	termios_fini();
	ft_memtrash();
	rl_clear_history();
	if (verbose)
		ft_putstr("exit\n", 1);
	exit(exit_status);
	return (exit_status);
}
