/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_subshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:40:00 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/16 15:06:16 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_sig_int(void)
{
	ft_putstr("\n", 1);
	exit(2);
}

static void	_sig_handler(int signum)
{
	if (signum == SIGINT)
		_sig_int();
}

//	signal most likely during a heredoc...

void	sig_subshell(void)
{
	struct sigaction	siga;

	ft_memset(&siga, 0, sizeof(struct sigaction));
	siga.sa_handler = &_sig_handler;
	if (sigaction(SIGINT, &siga, 0) == -1)
		fatal("sigaction", strerror(errno));
	siga.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &siga, 0) == -1)
		fatal("sigaction", strerror(errno));
}
