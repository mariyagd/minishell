/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sigset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:27:55 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/06 12:25:31 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	init_sigset(sigset_t *set)
{
	sigemptyset(set);
	sigaddset(set, SIGINT);
	sigaddset(set, SIGQUIT);
	sigaddset(set, SIGTERM);
	sigaddset(set, SIGTSTP);
	sigaddset(set, SIGKILL);
}
