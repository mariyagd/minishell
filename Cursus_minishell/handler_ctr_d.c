
#include "minishell.h"

void	handler_ctr_d(int code)
{
	int	i;

	i = 0;
	(void)code;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	exit(1);
}
