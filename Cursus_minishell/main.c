/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:36:22 by ymarival          #+#    #+#             */
/*   Updated: 2023/05/01 14:46:06 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_term g_term;

int	free_all(int ret)
{
	int	i;

	i = 0;
	while (g_term.env && g_term.env[i].key !=NULL)
	{
		g_term.env[i].key = free_tab((void **)&(g_term.env[i].key));
		g_term.env[i].var = free_tab((void **)&(g_term.env[i].var));
		i++;
	}
	rl_clear_history();
	if (g_term.env)
		g_term.env = free_tab((void**)&(g_term.env));
	return (ret);
}

int	main(int ac, char **av, char **envp)
{
	(void)av;
	if (launch_setup(ac, envp) == -1)
		return (-1);
	while (1)
	{
		g_term.str_cmd = NULL;
		g_term.str_cmd = readline(BLU_2"minishell$ "RESET);
		if (g_term.str_cmd == 0)
    	{
			free(g_term.str_cmd);
			rl_clear_history();
			return (free_all(-1));
    	}
		if (g_term.str_cmd[0])
		{
			add_history(g_term.str_cmd);
		//	if (launch() == -1)
		}
    
		parsing_av(g_term.str_cmd);
	}
	printf("%c\n", g_term.str_cmd[0]);
	return (1);
}
/* 
   C'est la signature de la fonction principale. Elle prend trois paramètres: 
   ac est un entier représentant le nombre d'arguments passés au programme, 
   av est un tableau de chaînes représentant les arguments,
   envp est un tableau de chaînes représentant du programme des variables d'environnement.
   
   Cette ligne supprime une variable inutilisée avertissement pour av car 
   						il n'est pas utilisé dans cette fonction.
   Cette ligne appelle la launch_setup fonction pour configurer l'environnement
   du shell, en passant les arguments de ligne de commande et les variables d'environnement.
   Si launch_setup retourne -1, indiquant une erreur, la fonction se termine
   avec une valeur de retour -1.
   
   C'est une boucle infinie qui ne cesse d'invite l'utilisateur à entrer une commande,
   lit l'entrée avec readline et les magasins de la chaîne résultante
   à la variable globale g_term.str_cmd.
   
   Le texte de l'invite est "minishell$ ", avec de la couleur mise en forme
   appliquée à l'aide de macros.
   Cette boucle ne contient pas de code pour l'exécution des commandes entrées
   par l'utilisateur, qui peuvent généralement être traitées séparément
   de la fonction ou des fonctions.
   
   C'est la fin de la main fonction.
   Elle renvoie la valeur 1 pour indiquer le succès de l'achèvement du programme.
 */
