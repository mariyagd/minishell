/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:11:25 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/10 12:25:14 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	free_token(t_token **head)
{
	t_token	*ptr;
	t_token	*tmp;

	if (!head || !*head)
		return ;
	ptr = *head;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = tmp->next;
		free(tmp->content);
		free(tmp);
	}
	*head = NULL;
	head = NULL;
}

/*
 * new_token function:
 * GOAL: Create a t_token node.
 *	- malloc of the structure t_token
 *	- if malloc fails, malloc_error_print_message function 
 *	  will print the error message and set the exit status to 1
 *	- extract the token in token->content with ft_substr 
 *	- if ft_substr fails, malloc_error_print_message function
 *	  will print the error message and set the exit status to 1
 *	  and new_token function will free the current token
 *	- set token->id to 0 (default value)
 *	- set token->next to NULL
*/
t_token	*new_token(char *line, int start, int len)
{
	t_token	*token;

	token = NULL;
	token = malloc(sizeof(t_token));
	if (!token)
	{
		malloc_error_print_message(strerror(errno));
		return (NULL);
	}
	token->content = ft_substr(line, start, len);
	if (!token->content)
	{
		malloc_error_print_message(strerror(errno));
		return (free_token(&token), NULL);
	}
	token->next = NULL;
	return (token);
}

/*
 * link_token function:
 * GOAL: Link a t_token node to the end of a linked list.
 * 	- protection: if the node was not created, return 0 (error)
 * 	- find the end: start from the head and loop through it
 */

int	link_token(t_token **head, t_token *new)
{
	t_token	*ptr;
	int		pos;

	pos = 0;
	if (!new)
		return (0);
	ptr = *head;
	while (ptr)
	{
		if (!ptr->next)
			break ;
		ptr = ptr->next;
		pos++;
	}
	ptr->next = new;
	new->pos = pos + 1;
	set_id(head, new);
	return (1);
}

/*
 * token_linked_list function:
 * GOAl: Create a linked list of tokens defined as a t_token structure
 * 	- protection: if head was not created, don't do anything
 *	- create a t_token node with new_token function
 *		- len was found during parsing 
 *		  in get_tokens function from parsing_token_extraction.c file
 *	- if there was a malloc problem,return 0 (error)
 *	  	(new_token function prints the error message 
 *	  	 and set the exit status to 1;
 *	  	 get_tokens function will free the linked list and the line)
 *	- link t_token nodes with link_token function
 *	- if there was a problem while linking, return 0 (error)
 *	  	(get_tokens function will free the linked list and the line)
*/

//DE MARIYA:
//ICI J'AI SUPPRIME LES FREE LORSQU'ON RETOURNE 0 POUR ERREUR
//CAR J'AI REMARQUE QU'ON FREE UNE DEUXIEME FOIS DANS GET_TOKENS
//JE ME SUIS DIT ALORS D'UTILISER CETTE FONCTION COMME UN INDICATEUR
//DE FLAG POUR SAVOIR SI ON DOIT FREE OU PAS DANS GET_TOKENS
int	token_linked_list(t_token **head, char *line, int start, int len)
{
	t_token	*new;

	if (!head)
		return (1);
	new = new_token(line, start, len);
	if (!new)
		return (0);
	if (!link_token(head, new))
		return (0);
	return (1);
}
