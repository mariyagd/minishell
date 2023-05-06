/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:46:58 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/26 00:25:27 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <libft.h>
# include <ft_arr.h>
# include <ft_getnext.h>
# include <ft_printf.h>

# define PS1	"Minishell--> "
# define HISTFILE	".minishell_history"

# ifndef PATH_MAX
#  define PATH_MAX	4096
# endif

/*
 *	lexer
 */

typedef enum e_toktype
{
	tok_invalid = -1,
	tok_var = 0,
	tok_input,
	tok_output,
	tok_heredoc,
	tok_append,
	tok_pipe,
	tok_lparen,
	tok_rparen,
	tok_and,
	tok_or,
	tok_semicolon,
	tok_ampersand
}	t_toktype;

typedef struct s_token
{
	t_toktype	tp;
	char		*data;
}	t_token;

/*
 *	syntax tree
 */

typedef enum e_ndtype
{
	nd_undef = 0,
	nd_cmd,
	nd_paren,
	nd_and,
	nd_or
}	t_ndtype;

typedef struct s_node		t_node;

typedef struct s_cmdgrp		t_cmdgrp;

struct s_node
{
	t_ndtype	tp;
	t_node		*parent;
	t_node		*left;
	t_node		*right;
	t_cmdgrp	*cmdgrp;
};

/*
 *	redirections
 */

typedef enum e_redirtp
{
	redir_undef = 0,
	redir_input,
	redir_output,
	redir_heredoc,
	redir_append
}	t_redirtp;

typedef struct s_redir
{
	t_redirtp	tp;
	char		*str;
}	t_redir;

/*
 *	commands
 */

typedef struct s_cmd
{
	t_arr	args;
	t_arr	redirs;
	int		_expect;
	char	*_arg0;
	char	*_full_cmd;
	int		_input_or_heredoc;
	int		_output_or_append;
	int		_input_fd;
	int		_heredoc_fd;
	int		_output_fd;
	int		_append_fd;
	int		_pipe[2];
	int		_io[2];
	int		_pid;
	int		_status;
}	t_cmd;

struct s_cmdgrp
{
	t_arr	cmds;
	int		_subshell;
};

/*
 *	scan strings
 */

typedef struct s_scan
{
	int	within_single_quotes;
	int	within_double_quotes;
}	t_scan;

/*
 *	shell info
 */

typedef struct s_shell
{
	t_arr				env;
	int					retval;
	struct sigaction	orig_sigint;
	struct sigaction	orig_sigquit;
	struct termios		orig_termios;
	char				*_input;
	char				*_ptr;
	t_cmdgrp			*_cmdgrp;
	int					_in_builtin;
}	t_shell;

extern
t_shell * g_shell;

/*
 *	variables
 */

typedef struct s_var
{
	char	*name;
	char	*value;
	int		has_equal;
}	t_var;

/*
 *	functions
 */

char		*abspath_find(const char *cmd);
void		add_arg_to_full_command(t_arr *new_string, char *str);
int			ast_check(const t_node *nd);
int			builtin_cd(t_cmdgrp *cgrp, t_cmd *cmd);
int			builtin_echo(t_cmdgrp *cgrp, t_cmd *cmd);
int			builtin_env(t_cmdgrp *cgrp, t_cmd *cmd);
int			builtin_exec(t_cmdgrp *cgrp, t_cmd *cmd);
int			builtin_exit(t_cmdgrp *cgrp, t_cmd *cmd);
int			builtin_export(t_cmdgrp *cgrp, t_cmd *cmd);
int			builtin_export_p(void);
int			builtin_memusage(t_cmdgrp *cgrp, t_cmd *cmd);
int			builtin_pwd(t_cmdgrp *cgrp, t_cmd *cmd);
int			builtin_unset(t_cmdgrp *cgrp, t_cmd *cmd);
int			cmd_builtin(const char *cmd);
void		cmd_del(void *command);
int			cmd_fildes(t_cmdgrp *cgrp, t_cmd *cmd, size_t num);
int			cmd_link(t_cmd *cmd);
t_cmd		*cmd_new(void);
int			cmd_redir(t_cmd *cmd);
int			cmd_redir_append(t_cmd *cmd, t_redir *redir);
int			cmd_redir_input(t_cmd *cmd, t_redir *redir);
int			cmd_redir_output(t_cmd *cmd, t_redir *redir);
int			cmd_valid(const t_cmd *cmd);
int			cmdgrp_add(t_cmdgrp *cgrp, t_token *tok);
t_cmd		*cmdgrp_cmd(t_cmdgrp *cgrp);
int			cmdgrp_del(t_cmdgrp **cgrp);
t_cmdgrp	*cmdgrp_new(void);
int			compare_hd(const char *line, const char *hd);
int			enomem(void);
char		*env_get(const t_arr *env, const char *varname);
size_t		env_indexof(const t_arr *env, const char *varname);
int			env_set(t_arr *env, const char *varname, const char *value);
int			env_unset(t_arr *env, const char *varname);
int			error(const char *title, const char *msg);
void		exec(t_node *root);
int			exec_builtin(t_cmdgrp *cgrp, t_cmd *cmd);
int			exec_cmd(t_cmdgrp *cgrp, t_cmd *cmd, size_t num);
int			exec_simple_builtin(t_cmdgrp *cgrp, t_cmd *cmd);
char		*expand_str(char *s);
int			fatal(const char *title, const char *msg);
int			fd_close(int *fd);
int			finish(int exit_status, int verbose);
void		histfile_add(const char *line);
void		histfile_load(void);
int			histfile_open(int append);
int			interp(const char *s);
int			interp_args(int argc, char *argv[]);
char		**last_command(void);
char		*make_arg0(t_cmd *cmd);
int			make_args(t_cmd *cmd);
char		*make_cmd(t_cmd *cmd);
void		make_redirs(t_cmd *cmd);
int			node_del(t_node **nd);
t_node		*node_new(const t_node *parent);
void		node_remove(t_node *nd, t_node *child, t_node **root);
void		node_subst(t_node *nd, t_node *nd2, int leftside, t_node **root);
int			open_file_hd(const char *eof);
int			open_file_ro(const char *path);
int			open_file_wa(const char *path);
int			open_file_wo(const char *path);
int			parse(t_token *tok, t_node **nd, t_node **root);
int			parse_cmd(t_node **nd, t_token *tok, t_node **root);
int			parse_logop(t_node **nd, t_token *tok, t_node **root);
int			parse_paren(t_node **nd, t_token *tok, t_node **root);
int			parse_undef(t_node **nd, t_token *tok);
char		*ps1(void);
int			redir_ambiguous(const char *str);
void		redir_fini(void *redirect);
char		*scan_cmd_arg(char **str, t_scan *scan);
int			scan_quotes(char c, t_scan *scan);
t_shell		*shell_new(char *environ[]);
void		shell_reset(t_shell *sh);
void		sig_mainproc(void);
void		sig_remove(void);
void		sig_subshell(void);
void		splash(void);
void		termios_bs(int enable);
void		termios_fini(void);
void		termios_init(void);
int			token_fini(t_token *tok);
char		*tokenize(const char *s, t_token *tok);
char		*tokenize_var(const char *s, t_token *tok);
char		*unbs(char **cmd);
int			var_fini(t_var *var);
int			var_init(t_var *var, const char *s);
int			var_valid(const t_var *var);
int			waitpids(const t_arr *cmds);
int			wildcard(t_arr *args, size_t idx);

# ifndef NDEBUG

void		ast_debug(const t_node *nd, int i);

# endif

#endif
