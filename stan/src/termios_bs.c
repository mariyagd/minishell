/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_bs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:17:11 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 17:36:27 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	disable/enable ctrl-\ (sigquit)
//	echoctl disabled

void	termios_bs(int enable)
{
	struct termios	st_t;

	if (!isatty(STDIN_FILENO))
	{
		errno = 0;
		return ;
	}
	ft_memcpy(&st_t, &g_shell->orig_termios, sizeof(struct termios));
	st_t.c_lflag &= ~ECHOCTL;
	if (enable)
		st_t.c_cc[VQUIT] = 034;
	else
		st_t.c_cc[VQUIT] = _POSIX_VDISABLE;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &st_t) == -1)
		fatal("tcsetattr", strerror(errno));
}
