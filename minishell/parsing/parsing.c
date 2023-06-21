/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:00:49 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/21 09:53:55 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/*
 * FOR TESTING use this function: 
 	print_token(&token); 
*/
/*
void	print_token(t_token **head)
{
	int		i;
	t_token	*tmp;

	i = 0;
	if (!*head || !head)
		return ;
	tmp = *head;
	printf("----PARSING---\n");
	while (tmp)
	{
		if (tmp->id == L_CHEVRON)
			printf("L_CHEVRON  :");
		else if (tmp->id == R_CHEVRON)
			printf("R_CHEVRON  :");
		else if (tmp->id == PIPELINE)
			printf("PIPELINE   :");
		else if (tmp->id == WORD)
			printf("WORD       :");
		else if (tmp->id == APPEND)
			printf("APPEND     :");
		else if (tmp->id == HERE_DOC)
			printf("HERE_DOC   :");
		else if (tmp->id == DOLLAR)
			printf("DOLLAR     :");
		else if (tmp->id == DOLLAR_KEY_W)
			printf("DOLLAR KEY W:");
		else if (tmp->id == KEY_WORD)
			printf("KEY_WORD   :");
		while (tmp->content[i])
		{
			printf ("%c", tmp->content[i]);
			i++;
		}
		printf ("%c", tmp->content[i]);
		printf ("\n");
		i = 0;
		tmp = tmp->next;
	}
	printf("----END----\n");
}
*/
/*
 * parsing() function
 * GOAL: this is the main function of the parsing part of the minishell.
 * 		Each function returns 1 for success and 0 for failure.
 * 		Failure may occur if the syntax is incorrect or if malloc fails.
 * 
 * 1. Check for syntax errors 
 * 	(ex. operators at EOF, multiple operators, etc.)
 *
 * 	2. get_tokens() - splits the line into tokens 
 * 	   				  and stores them in a linked list.
 *		- Each token represents a word or metacharacter 
 *		 (a metacharacter is a  pipe or a redirection operator).
 *		- If a word contains a dollar sign, this function 
 *		  marks the token with a DOLLAR id. 
 *
 * 3. expansion() - recursivly expands the dollar sign in the token that was
 * 			        previously marked by get_tokens().
 * 		- If the dollar sign is within single quotes, it is ignored.
 * 		  (ex. '$HOME' -> '$HOME')
 * 		- If the dollar sign is followed by a word, that can be found 
 * 		  in the environnement variables, the word is expanded.
 * 		  (ex. $HOME -> /Users/mdanchev)
 * 		- If the dollar sign is followed by a word that cannot be found
 * 			-> the dollar and the word are trimmed.
 * 			(ex. $HOMEEE -> )
 * 		- If the dollar sign is followed by a question mark, the question mark
 * 		  is expanded.
 * 		   (ex. $? -> 0)
 * 		NOTE: After expansion, all tokens that were previously marked as DOLLAR
 * 			  are now marked as WORD. 
 * 4. quote_removing() - removes the quotes from the tokens in a recursive way.
 * 		- If a token is marked as WORD and contains quotes, 
 * 		  the quotes are removed.
 */

t_token	*parsing(char *line)
{
	t_token	*token;

	if (!syntax_error_check(line))
		return (NULL);
	token = get_tokens(line);
	if (!token)
		return (NULL);
	if (!here_doc(&token))
	{
		free_token(&token);
		return (NULL);
	}
	set_id_before_expansion(&token);
	if (!expansion(&token, token, 0))
		return (NULL);
	if (!quote_removing(&token, token, 0))
		return (NULL);
	return (token);
}
