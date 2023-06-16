/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:16:33 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/16 20:37:42 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <curses.h>
# include <term.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/includes/libft.h"

# define RED    "\x1b[31m"
# define BLU    "\x1B[34m"
# define BLU_2 "\e[1;34m"
# define GRN    "\x1B[32m"
# define YEL    "\x1B[33m"
# define MAG   	"\e[1;35m"
# define CYN    "\x1B[36m"
# define WHT    "\x1B[37m"
# define RESET  "\x1B[0m"

# define WORD		1
# define PIPELINE	2
# define L_CHEVRON	3
# define R_CHEVRON	4
# define APPEND		5
# define HERE_DOC	6
# define DOLLAR		7
# define QUESTION	8
# define EXPAND		9
# define DELETE		10
# define EXPANDED	11
# define KEY_WORD	12
# define ERROR_EXIT	-1

//int	g_exit_status;

/* OK */
typedef struct s_env
{
	char			*var_name;
	char			*var_value;
	struct s_env	*next;
}	t_env;

typedef struct s_token
{
	char				*content;
	int					id;
	int					res;
	int					pos;
	struct s_token		*next;
}	t_token;

typedef struct s_cmd
{
	pid_t			pid;
	char			**cmd;
	char			**redir;
	char			*path;
	int				status;
	int				ffd_in;
	int				ffd_out;
	int				save_fdout;
	int				save_fdin;
	int				fd[2];
	int				res;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	t_env				*env;
	volatile int		exit_status;
	int					error_exit;
	char				**save_env;
//	int					heredoc_flag;
}	t_shell;

extern t_shell	*g_shell;

/*		HERE DOC*/
int		here_doc(t_token **head);
void	keyword_is_unquoted(char *key_word, int fd);
void	keyword_is_quoted(char *key_word, int fd);
void	write_in_heredoc_helper(char *key_word, int fd);
void	delete_all_heredocs(int nb);

/*		REDIRECTIONS */
int		make_redirections(t_cmd *cmd, int i);
void	restaure_fds(t_cmd *cmd, int i);
void	restaure_fdout(t_cmd *cmd);
void	restaure_fdin(t_cmd *cmd);
void	delete_here_doc(int i);
int		redir_fdout(t_cmd *cmd, char *redir_op, char *file_path);
int		redir_fdin(t_cmd *cmd, char *redir_op, char *file_path, int j);
int		append(t_cmd *cmd, char *file_path);

/*		UTILS */
void	free_before_exit(t_cmd **head);
void	free_and_exit_prog(t_cmd **head, int exit_code);
int		size_tab2d(char **s);

/*		EXECUTION */
void	execution(t_cmd **head);
int		copy_env_tab(void);
void	one_cmd(t_cmd *cmd);
void	pipex(t_cmd **head);
void	ft_exe(int i, int save_fdin, t_cmd *cmd);
void	kill_zombies(t_cmd **head, int flag);

/* 		EXECUTION BUILTINS */
int		cmd_is_builtin(char *s);
void	execute_builtin(t_cmd *cmd);
void	_pwd(void);
void	_env(t_cmd *cmd, t_env *env);
void	print_getcwd_error(char *s);
int		_echo(t_cmd *cmd);
void	ft_exit(t_cmd *cmd);
int		no_int_errors(char *str);
void	_cd(t_cmd *cmd);
void	_export(t_cmd *cmd);
int		check_if_var_exists(char *s);
int		check_if_valid_identifier(char *s, char *command);
void	print_export_unset_error(char *identifier, char *command);
void	_unset(t_cmd *cmd);

/*		EXECUTION BIN */
void	execute_bin(t_cmd *cmd);
int		search_path(t_cmd *cmd, char **env);
int		get_path(t_cmd *cmd);

/*		INIT t_cmd *cmd*/
t_cmd	*cmd_linked_list(t_token **token);
void	free_tab2d(char **s);
void	free_cmd(t_cmd **head);

/*		INIT cmd->redir*/
int		create_redir(t_token **token, t_cmd *cmd);

/*		INIT cmd->cmd */
int		create_cmd(t_token **token, t_cmd *cmd);

/*		EXPANSION (parsing_expansion.c)*/
int		expansion(t_token **token, t_token *curr, int pos);
int		check_dollar(t_token *curr, int i);
int		trim_dollar(t_token *curr, int pos);

/* 		EXPANSION (parsing_expansion_dollar_conditions.c)*/
int		is_dollar_to_expand(t_token *curr, int i);
int		not_within_squotes(t_token *curr, int pos);

/* 		EXPANSION (parsing_expansion_trim_dollar.c)*/
int		trim_dollar(t_token *curr, int pos);

/* 		EXPANSION (parsing_expansion_looping.c)*/
int		loop_dollars(char *s, int i);
int		loop_through(char *s, int i);

/* 		EXPANSION (parsing_expansion_expand_var_helper.c)*/
int		size_var(char *s);
int		check_var_exist(t_token *tmp);

/* 		EXPANSION (parsing_expansion_join_tokens.c)*/
int		join_tokens(t_token **new, t_token *curr);

/*		EXPANSION (parsing_expansion_helper.c)*/
int		prepare_expand(t_token *tmp, int i);
int		set_id_expansion(t_token *token);

/*		QUOTE REMOVING (parsing_quote_removing.c)*/
int		quote_removing(t_token **head, t_token *curr, int pos);
int		remove_q(t_token *curr, int pos);

t_token	*delete_token(t_token **head);
int		token_list_size(t_token	**head);

/*		PARSING - SYNTAX ERROR CHECK */
t_token	*parsing(char *line);
int		syntax_error_check(char *s);
int		check_pipeline_errors(char *s, int i, char c, int num);
int		check_quotes_errors(char *s, char c, int *i);	
int		count_metachar(char *s, char c, int num);
int		check_multiple_operators_error(int i, int num, char c);
void	print_syntax_error_char(char c);
void	print_syntax_error_dchar(char c);
void	print_syntax_error_str(char *s);

/* 		TOKEN EXTRACTION */
int		character_extraction(char *line, int ind);
int		token_extraction(char *line, int ind);
t_token	*get_tokens(char *line);
int		get_tokens_size(char *line, int *i);
t_token	*create_token_head(char *line, int i, int len, int *flag);

/* 		MALLOC ERROR PRINT MESSAGE */
void	malloc_error_print_message(char *s);
void	error_message(char *s);
void	error_message2(char *s1, char *s2);

/* 		TOKEN EXTRACTION - TOKEN LINKED LIST (token_routine_.c) */
t_token	*new_token(char *line, int start, int len);
void	set_id(t_token **head, t_token *token);
void	reset_token_id(t_token **head);
void	set_id_for_expansion(t_token **head);
int		token_linked_list(t_token **head, char *line, int start, int len);
int		link_token(t_token **head, t_token *new);
void	free_token(t_token **head);

/* 		IS SOMETHING (folder: is_smth) */
int		is_dollar(char c);
int		is_pipeline(char c);
int		is_chevron(char c);
int		is_lchevron(char c);
int		is_rchevron(char c);
int		is_operator(char c);
int		is_newline(char c);
int		is_white_space(char c);
int		is_blank(char c);
int		is_metacharacter(char c);
int		is_delimiter(char c);
int		is_word(char c);
int		is_double_quote(char c);
int		is_simple_quote(char c);
int		is_quote(char c);
int		is_question(char c);
int		is_punct(char c);
int		is_numeric(char *s);

/*		ENVIRONNEMENT */
t_env	*new_env(char *envp);
int		link_env(t_env **head, t_env *last);
char	*get_env_var_value(char *var_name);

/*		INIT GLOBAL VARIABLE */
int		init_shell(char **envp);
int		increment_shlvl(void);
void	free_shell(void);

/*		SIGNAL HANDLER */
void	init_sigset(sigset_t *set);
void	parent_signal_handler(void);
void	child_signal_handler(void);
//void	child_signal_handler(void /*t_cmd *cmd, int i*/);
void	here_doc_signal_handler(void);
void	pipex_signal_handler(void);

//int	parsing_av(char *str);
char	**ft_splitpath(char *s, char c);

/* GETENVP */
t_env	*get_envp(char **envp);
void	free_env(t_env **head);

#endif
