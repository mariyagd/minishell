# include "minishell.h"

int	parsing_av(char *str)
{
	g_term.cmd = malloc(sizeof(t_cmd));
	if (!g_term.cmd)
		return (-1);
	if (ft_strncmp("minishell$ ", str, 11) == 0)
		str += 10;
	g_term.cmd->arg = ft_splitpath(str, ' ');
	if (!g_term.cmd->arg)
		return (-1);

/* old

	int	j = 0;
	while (g_term.cmd->arg[j])
	{
		if (ft_strncmp("cd", g_term.cmd->arg[j], 2) == 0)
			g_term.cmd->cmd = g_term.cmd->arg[j];
		else if (ft_strncmp("|", g_term.cmd->arg[j], 1) == 0)
			g_term.cmd->red->red = g_term.cmd->arg[j];
		else
			g_term.cmd->arg[j] = g_term.cmd->argument;
		j++;
	}
*/

	int	k = 0;
	while (g_term.cmd->arg[k])
		printf("%s\n", g_term.cmd->arg[k++]); //TODO

	printf("%s\n", g_term.cmd->cmd);
//	printf("%s\n", g_term.cmd->red->red);

	//return ((is_cmd());
	return (1);
}

/*
int	is_cmd(void)
{
	int	j;
	
	j = 0;
	while (g_term.cmd->arg[j])
	{
		if (is_bin(g_term.cmd->arg) || is_builtin(g_term.cmd->arg[j]))
			return (1);
		j++;
	}
	return (0);
}

int	is_bin(void)
{
}

int	is_builtin(void)
{
	if (ft_strncmp("echo", g_term.cmd->arg[j], 4) == 0)
		return (1);
	if (ft_strncmp("cd", g_term.cmd->arg[j], 2) == 0)
		return (1);
	if (ft_strncmp("pwd", g_term.cmd->arg[j], 3) == 0)
		return (1);
	if (ft_strncmp("env", g_term.cmd->arg[j], 3) == 0)
		return (1);
	if (ft_strncmp("export", g_term.cmd->arg[j], 6) == 0)
		return (1);
	if (ft_strncmp("unset", g_term.cmd->arg[j], 5) == 0)
		return (1);
	if (ft_strncmp("exit", g_term.cmd->arg[j], 4) == 0)
		return (1);
	return (0);
}

*/
/*
   	g_term.cmd = malloc(sizeof(t_cmd))
   	initialisez la structure t_cmd et verifier si elle n'est pas vide

   	if (ft_strncmp("minishell$ ", str, 11) == 0)
   		str += 10
	ignorer le prompt, deplacer le pointeur sur le caractere apres "minishell$ "

	g_term.cmd->arg = ft_splitpath(str, ' ');
	diviser les parametres par l'espace et les mettre dans un char**
*/
