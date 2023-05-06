/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_fini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:56:50 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 17:36:27 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	reinstall original termios settings

void	termios_fini(void)
{
	if (!isatty(STDIN_FILENO))
	{
		errno = 0;
		return ;
	}
	if (tcsetattr(STDIN_FILENO, TCSANOW, &g_shell->orig_termios) == -1)
		fatal("tcsetattr", strerror(errno));
}
