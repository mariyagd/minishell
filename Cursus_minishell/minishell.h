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
# include "libft/libft.h"

# define RED    "\x1b[31m"
# define BLU    "\x1B[34m"
# define BLU_2 "\e[1;34m"
# define GRN    "\x1B[32m"
# define YEL    "\x1B[33m"
# define MAG    "\x1B[35m"
# define CYN    "\x1B[36m"
# define WHT    "\x1B[37m"
# define RESET  "\x1B[0m"

typedef struct s_intra_red
{
	char				*file;
	char				*red;
}	t_intra_red;

typedef struct s_cmd
{
	char			*cmd;
	char			*path;
	t_intra_red		*red;
	char			**arg;
	char			*argument; //
	char			*pip;
	pid_t			pid;
	int				tub[2];
	struct s_cmd	*next;
	struct s_cmd	*prev;

}	t_cmd;

typedef struct str_env
{
	char	*key;
	char	*var;
}	t_env;

typedef struct s_term
{
	int		nb_node;
	char	**envp;
	char	*str_cmd;
	t_cmd	*cmd;
	t_env	*env;
	int		dernier_ret;
}	t_term;

// global variable
extern t_term g_term;

// prototypes
char	*env_key(char *env);
char	*env_var(char *env);
int	init_struct_env(void);
void	handler_ctr_c(int code);
void	handler_ctr_d(int code);
int	launch_setup(int ac, char **envp);

int	parsing_av(char *str);
char	**ft_splitpath(char *s, char c);

void	*free_tab(void **a_free);
int	free_all(int ret);

#endif
