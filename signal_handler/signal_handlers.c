/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:03:39 by mmakarov          #+#    #+#             */
/*   Updated: 2023/06/10 09:41:05 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/*
   Function that manages ctrl c, ctrl d and ctrl \

   ctrl + d -> doesn't send signals;
   SIGQUIT	-> ctrl +\
   SIGINT	-> ctrl + c -> exit status is 1
   SIGTSTP	-> ctrl + z
   SIGKILL -> from command line kill -SIGKILL [pid]
   SIGTERM -> from command line kill -SIGTERM [pid]
*/
static void	handler(int sig_code)
{
	if (sig_code == SIGINT)
	{
		printf("\n");
		g_shell->exit_status = 1;
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	here_doc_handler(int sig_code)
{
	(void)sig_code;
	ft_printf("> \n");
	exit(1);
}

void	here_doc_signal_handler(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(struct sigaction));
	init_sigset(&act.sa_mask);
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, 0);
	sigaction(SIGTSTP, &act, 0);
	act.sa_handler = here_doc_handler;
	sigaction(SIGINT, &act, 0);
}

void	child_signal_handler(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(struct sigaction));
	init_sigset(&act.sa_mask);
	act.sa_handler = SIG_DFL;
	sigaction(SIGTERM, &act, 0);
	sigaction(SIGKILL, &act, 0);
	sigaction(SIGQUIT, &act, 0);
	sigaction(SIGINT, &act, 0);
}

void	parent_signal_handler(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(struct sigaction));
	init_sigset(&act.sa_mask);
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, 0);
	sigaction(SIGTERM, &act, 0);
	sigaction(SIGTSTP, &act, 0);
	act.sa_handler = handler;
	sigaction(SIGINT, &act, 0);
}
