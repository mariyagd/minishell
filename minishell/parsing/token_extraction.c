/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_extraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:00:21 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/09 11:44:31 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/*
 * character_extraction function:
 * GOAL: Extract an operator character from char *line and return its size.
 *  - if the operator is >> or <<, return 2
 *  - else the operator is |, < or >, return 1
 */

int	character_extraction(char *line, int ind)
{
	if ((line[ind] == '>' && line[ind + 1] == '>') || \
		(line[ind] == '<' && line[ind + 1] == '<'))
		return (2);
	return (1);
}

/* 
 * word_extraction function: 
 * GOAL: Extract a word from char *line and return its size.
 *
 * A word may contain:
 * 	- quoted operators |, <, >, >>, <<
 * 	- quotes (single or double)
 * 	- dollar sign $
 *
 * A word is delimited by:
 * 	- unquoted white spaces (space, tab and newline)
 * 	- unquoted operators |, <, >, >>, <<
 */

int	word_extraction(char *line, int ind)
{
	int		start;
	char	c;

	start = ind;
	while (is_word(line[ind]) && line[ind])
	{
		if (is_quote(line[ind]))
		{
			c = line[ind];
			ind++;
			while (line[ind] && line[ind] != c)
				ind++;
		}
		ind++;
	}
	return (ind - start);
}

/* JE DOIS UTILISER L'ADRESSE DE i POUR MODIFIER SA VALEUR */
int	get_tokens_size(char *line, int *i)
{
	int	len;

	len = 0;
	while (is_blank(line[*i]))
		(*i)++;
	if (is_word(line[*i]))
		len = word_extraction(line, *i);
	else if (is_operator(line[*i]))
		len = character_extraction(line, *i);
	return (len);
}

/* 
 * Ici on utilise l'adresse de flag pour modifier 
 * sa valeur et economiser une ligne de code
 * */

t_token	*create_token_head(char *line, int i, int len, int *flag)
{
	t_token	*head;

	head = new_token(line, i, len);
	if (!head)
		return (NULL);
	*flag = 1;
	head->pos = 0;
	set_id(&head, head);
	return (head);
}
/*
 * get_tokens function:
 * GOAL: Extract tokens from char *line in a t_token structure
 * 		 and return them as tokens in a linked list.
 * 
 * Inside the while loop while(line[i])
 * 	- ignore blanks (space and tab)
 * 	- if there is a token, stock its size in len 
 * 	  using the get_tokens_size function
 * 	- if len is 0, it means that there is no token left (end of line)
 *	- if there is no head yet, the flag is 0.
 *	- create a head with the create_token_head function
 * 	  and set the flag to 1	
 *	- if there is a head, create a new token and link it to the list
 *	  with the function token_linked_list
 *	- if token_linked_list fails, it prints the error message 
 *	  and returns 0 to indicate an error.
 *	  the get_tokens function frees the line and the linked list of token.
 *
 * NOTE:
 *	new_token and token_linked_list functions
 *	are developed in token_routine.c
*/

//DE MARIYA:
//POUR RACCOURCIR CETTE FONCTION J'AI CREE DEUX FONCTIONS SUPPLEMENTAIRES
//QUI SONT DANS CE FICHIER CI-DESSUS:
//	- get_tokens_size
//	- create_token_head
t_token	*get_tokens(char *line)
{
	int			i;
	int			len;
	int			flag;
	t_token		*head;

	i = 0;
	flag = 0;
	head = NULL;
	while (line[i])
	{
		len = get_tokens_size(line, &i);
		if (len == 0)
			break ;
		if (!flag)
		{
			head = create_token_head(line, i, len, &flag);
			if (!head)
				return (free(line), NULL);
		}
		else
			if (!token_linked_list(&head, line, i, len))
				return (free_token(&head), free(line), NULL);
		i += len;
	}
	return (free(line), head);
}
