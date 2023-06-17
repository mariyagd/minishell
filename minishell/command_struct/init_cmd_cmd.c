/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:36:56 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/10 13:12:42 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	copy_cmd_helper(t_token *ptr, t_cmd *cmd, int i)
{
	cmd->cmd[i] = ft_strdup(ptr->content);
	if (!cmd->cmd[i])
	{
		malloc_error_print_message("ft_strdup failed");
		return (0);
	}
	return (1);
}

/*
 * copy_cmd() function
 *
 * GOAL: This function copies the commande in cmd->cmd.
 * 
 * Returned values: 
 * 		If a malloc error occurs, the function returns 0.
 * 		Else, it returns 1 for success.
 *
 * Procedure:
 * 	- A command can only be a token that has been marked as WORD.
 * 	- The first word in the sequence is the command name,
 * 	  and all words that follow are command arguments.
 * 	- A redirection operato takes always one argument. So if the current 
 * 	  token is marked as a metacharacter,we move two tokens forward.
 * 	  (ptr = ptr->next->next)
 * 	- copy_cmd_helper() is called. This function does:
 * 		 - If the current token is the first encountered token marked as WORD,
 * 		   a simple strdup is made.
 */
/*
static t_token	*get_next_ptr(t_token *ptr)
{
	if (ptr->id == L_CHEVRON || ptr->id == R_CHEVRON || \
			ptr->id == APPEND)
		ptr = ptr->next->next;
	else if (ptr->id == HERE_DOC)
	{
		if (!ptr->next)
			return (NULL);
		else if (ptr->next->id == KEY_WORD && ptr->next->next)
			ptr = ptr->next->next;
		else
			return (NULL);
	}
	return (ptr);
}*/

static int	copy_cmd(t_token **token, t_cmd *cmd)
{
	t_token	*ptr;
	int		i;

	ptr = *token;
	i = 0;
	while (ptr && ptr->id != PIPELINE)
	{
		if (ptr->id == WORD)
		{
			if (!copy_cmd_helper(ptr, cmd, i))
				return (0);
			i++;
		}
		ptr = ptr->next;
	}
	cmd->cmd[i] = NULL;
	return (1);
}

static int	get_cmd_size(t_token **token)
{
	t_token	*ptr;
	int		i;

	i = 0;
	ptr = *token;
	while (ptr && ptr->id != PIPELINE)
	{
		if (ptr->id == WORD)
			i++;
		ptr = ptr->next;
	}
	return (i);
}

/*
 * create_cmd() function
 * GOAL: create char **cmd of the t_cmd cmd structure.
 *
 * Returned values:
 * 	-> 1 for succes
 * 	-> 0 for malloc failure
 *
 * Procedure:
 * 1. Get the size the we need to malloc with get_cmd_size() function
 * 		-> if size == 0 -> there is no command
 * 		-> cmd->cmd is NULL since t_cmd *cmd was generated with calloc
 * 		-> so we simply return
 * 2. Malloc size + 1 for the NULL
 * 3. Copy the command in the cmd->cmd with copy_cmd() function
 */

int	create_cmd(t_token **token, t_cmd *cmd)
{
	int	i;
	int	res;

	i = get_cmd_size(token);
	if (i == 0)
		return (1);
	cmd->cmd = malloc(sizeof(char *) * (i + 1));
	if (!cmd->cmd)
	{
		malloc_error_print_message(strerror(errno));
		return (0);
	}
	res = copy_cmd(token, cmd);
	if (!res)
		return (0);
	return (1);
}
