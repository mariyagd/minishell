/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_syntax_errors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:00:31 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/19 12:01:40 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	check_multiple_operators_error(int i, int num, char c)
{
	if (i > num)
	{
		if (is_chevron(c))
			print_syntax_error_dchar(c);
		else if (is_pipeline(c))
			print_syntax_error_char(c);
		return (0);
	}
	return (1);
}

int	count_metachar(char *s, char c, int num)
{
	int	i;

	i = 1;
	while (s[i] && s[i] == c)
		i++;
	if (!check_multiple_operators_error(i, num, c))
		return (0);
	while (s[i] && is_blank(s[i]))
		i++;
	if (is_operator(s[i]) && !is_pipeline(c))
	{
		c = s[i];
		if (is_chevron(c) && is_chevron(s[i + 1]))
			return (print_syntax_error_dchar(c), 0);
		else
			print_syntax_error_char(c);
		return (0);
	}
	else if (s[i] == '\0')
		return (print_syntax_error_str("newline"), 0);
	return (1);
}

int	check_quotes_errors(char *s, char c, int *i)
{
	int	j;

	j = *i + 1;
	while (s[j] && s[j] != c)
		j++;
	if (s[j] != c)
	{
		print_syntax_error_char(c);
		return (0);
	}
	(*i)++;
	while (s[*i] && s[*i] != c)
		(*i)++;
	return (1);
}

int	check_pipeline_errors(char *s, int i, char c, int num)
{
	int	j;

	j = 0;
	while (s[j] && is_blank(s[j]))
		j++;
	if (s[j] == c)
	{
		print_syntax_error_char(c);
		return (0);
	}
	if (!count_metachar(&s[i], c, num))
		return (0);
	return (1);
}

/*
 * syntax_error_check function:
 * GOAL - before token splitting, check for syntax error;
 * 		  if errors -> print an error message and set exit status to 258
 *
 * Inside the while loop:
 *	- if it finds a quote -> call check_quotes_errors function
 *	  
 *	  check_quotes_errors function:
 *	  	- verifies if quotes are closed or not.
 *	  	- all metacharcters loose their special meaning inside quotes.
 *	  	  If a metacharcter is found inside quotes, 
 *	  	  it is considered as a regular character.
 *	  	- if quotes are unclosed, the function prints error message 
 *	  	  and sets the exit status to 258
 *  
 *  - if it finds a chevron (<, >) -> call the count_metachar function
 *  - if it finds a pipeline (|) -> call the check_pipeline_errors function
 * 	  
 * 	  check_pipeline_errors function:
 * 	  - verifies if there is a pipeline at the beginning of the line (ex. |word)
 * 	  - verifies if there is a pipeline at the end of the line (ex. word|)
 * 	  - if one of these conditions is true, the function prints error message
 * 	    and sets the exit status to 258
 * 	  - else, the function calls the count_metachar function
 *
 * 	  count_metachar function:
 * 	  	- verifies whether there are too many metacharacters (ex. >>>, |||)
 * 	  	- verifies if there are two operators in a row (ex. ><, ||, >|, ><|)
 * 	  	- verfies if there is a \0 after a metacharacter (ex. >\0, |\0)
 * 	  If one of these conditions is true, the function prints error message
 * 	  and sets the exit status to 258
 *
 * 	- if an error occurs while looping, 
 * 	the function frees the string and returns 0
 *
 * 	NOTE: char *s is the string that was previously malloced 
 * 		  in the main function by readline
*/

//DE MARIYA:
//ICI J'AI DU CREER UNE FONCTION SUPPLEMENTAIRE PARCE QUE 
//J'AI DU TRAITE UN CAS SPECIFIQUE CONCERNANT PIPELINE
//J'AI EGALEMENT FREE LA STRING S SI UNE ERREUR SE PRODUIT
//LA STRING S EST EN FAIT LA LINE DE READLINE
int	syntax_error_check(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (is_quote(s[i]))
		{
			if (!check_quotes_errors(s, s[i], &i))
				return (free(s), 0);
		}
		else if ((is_lchevron(s[i]) && !count_metachar(&s[i], '<', 2)) || \
				(is_rchevron(s[i]) && !count_metachar(&s[i], '>', 2)))
			return (free(s), 0);
		else if (is_pipeline(s[i]) && !check_pipeline_errors(s, i, '|', 1))
			return (free(s), 0);
		i++;
	}
	return (1);
}
