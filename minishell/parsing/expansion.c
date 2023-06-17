/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:13:21 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/08 13:54:14 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
/*
 * check_dollar() function:
 * GOAL: This function checks if the dollar is valid to expand.
 *
 * If a malloc error occurs, the function recieves ERROR_EXIT signal.
 * Otherwise, it returns the index of the next character to check.
 *
 * - If the current character is a dollar sign 
 *   and it is not within simple quotes, we will proceed to expansion
 *  - else, we increment i until we find a dollar or EOF
 *
 *   1. If the next character is a word, a question mark, or an underscore
 *   	(in othere words: a delimiter is a white space, a quote, 
 *   	 a dollar sign, a punctuation sign (except for ? and _) and not the EOF)
 *   		-> we will expand the dollar
 *   2. If the next character is a dollar sign, we loop through until 
 *   	the last dollar. 
 *   		- If the following character is a delimiter, we 
 *   	      will print all these dollars.
 *   	    - If the following character is a word, or ? or _, we will print
 *   	      all dollars, except for the last one.The last one will be expanded.
 *   3. If the next character is a quote, 
 *   	we will check if we need to trim the dollar.
 *   		- If the dollar is within double quotes -> we print the dollar;
 *   		- If the dollar is unquoted -> we trim the dollar.
 *   4. If the next character is EOF, we will print the dollar and mark 
 *      the token as WORD.
 */
int	check_dollar(t_token *curr, int i)
{
	while (curr->content[i])
	{
		if (is_dollar(curr->content[i]) && not_within_squotes(curr, i))
		{
			if (is_dollar_to_expand(curr, i))
				return (prepare_expand(curr, i));
			else if (is_dollar(curr->content[i + 1]))
				i = loop_dollars(curr->content, i);
			else if (is_quote(curr->content[i + 1]))
			{
				curr->res = trim_dollar(curr, i);
				if (curr->res == ERROR_EXIT)
					return (ERROR_EXIT);
				i += curr->res;
			}
			else if (curr->content[i + 1] == '\0')
				break ;
			else
				i++;
		}
		else
			i++;
	}
	curr->id = WORD;
	return (i);
}

static void	expansion_next_token(t_token **head, t_token *curr, int pos)
{
	pos = 0;
	if (curr->next)
	{
		curr = curr->next;
		expansion(head, curr, pos);
	}
}

/*
 * expansion() function:
 * GOAL: This function is called recursively to expand the tokens.
 *
 * If a malloc error occurs, the function recieves ERROR_EXIT 
 * and returns 0 for failure. Otherwise, it returns 1 for success.
 *
 * - If the token is marked as DOLLAR, 
 *	 we check if it is a valid dollar to expand with check_dollar().
 * - If the expansion leads to empty strings, we delete the token 
 *   with delete_token() and reset curr and pos.
 * - If the current token is not marked as DOLLAR,
 *   we call the next token in the function expansion_next_token().
 *
 * NOTE: 
 * if(!curr) 
 * { 
 * 		head = NULL, 
 * 		return (1); 
 * 	}
 * 	happens if the linked list is empty.
 * 	This means that the expansion of all tokens has led to empty strings.
 */

int	expansion(t_token **head, t_token *curr, int pos)
{
	if (curr)
	{
		if (curr->id == DOLLAR)
		{
			pos = check_dollar(curr, pos);
			if (pos == ERROR_EXIT)
				return (free_token(head), 0);
			if (curr->id == DELETE)
			{
				curr = delete_token(head);
				if (!curr)
				{
					head = NULL;
					return (1);
				}
				pos = 0;
			}
			expansion(head, curr, pos);
		}
		else
			expansion_next_token(head, curr, pos);
	}
	return (1);
}
