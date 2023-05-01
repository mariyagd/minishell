
#include "minishell.h"

int	init_struct_env(void)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (g_term.envp[j])
		j++;
	g_term.env = malloc(sizeof(t_env) * (j + 1));
	if (!g_term.env)
		return (-1);
	while (i < j)
	{
		g_term.env[i].key = env_key(g_term.envp[i]);
		g_term.env[i].var = env_var(g_term.envp[i]);
		if (!g_term.env[i].var || !g_term.env[i].key)
			return (-1);
		i++;
	}
	g_term.env[i].key = NULL;
	g_term.env[i].var = NULL;
	return (1);
}
/*  
	int init_struct_env(void)
    Cette ligne définit la fonction "init_struct_env"
	qui ne prend aucun paramètre et renvoie une valeur de type entier. 

    int j;
    Cette ligne déclare une variable de type entier appelé "j". 

    int i;
    Cette ligne déclare une autre variable de type entier qui s'appelle "je". 

    j = 0;
    Cette ligne initialise le "j" de la variable à 0. 

    i = 0;
    Cette ligne initialise le "je" de la variable à 0. 

    while (g_term.envp[j])
    Cette ligne commence une boucle qui va s'exécuter
	tant que la valeur de "g_term.envp[j]" n'est pas NULLE. 

    j++;
    Cette ligne incrémente le "j" à la variable. 

    g_term.env = malloc(sizeof(t_env) * (j + 1));
    Cette ligne alloue de la mémoire pour un tableau de "t_env" structures
	et attribue un pointeur vers cette mémoire "g_term.env" variable globale.
	La taille du bloc de mémoire est calculée en multipliant
	la taille d'un "t_env structure de la" le nombre d'éléments dans le tableau
	(qui est "j + 1"). 

    if (!g_term.env)
    Cette ligne vérifie si l'allocation de mémoire a été un succès
	(c'est à dire, si "g_term.env" n'est pas NULLE).
	Si l'allocation a échoué, la fonction retourne -1. 

    g_term.env[i].key = env_key(g_term.envp[i]);
    Cette ligne affecte la valeur du champ "clé" de "je"ème élément de la
	"g_term.env" tableau à la suite d'un appel à la fonction "env_key"
	avec le "je"ème élément de la "g_term.envp" tableau comme argument. 

    g_term.env[i].var = env_var(g_term.envp[i]);
    Cette ligne affecte la valeur de la "var" du "je"ème élément
	de la "g_term.env" tableau à la suite d'un appel à la fonction "env_var"
	avec le "je"ème élément de la "g_term.envp" tableau comme argument. 

    if (!g_term.env[i].var || !g_term.env[i].la clé)
    Cette ligne vérifie si la "clé" ou "var" du "je"ème élément de la
	"g_term.env" matrice est NULLE.
	Si le champ est NULL, la fonction retourne -1. 

    i++;
    Cette ligne incrémente le "je" à la variable. 

    g_term.env[i].key = NULL;
    Cette ligne affecte la valeur NULL pour le champ "clé" de "je"ème élément
	de la "g_term.env tableau. 

    g_term.env[i].var = NULL;
    Cette ligne affecte la valeur NULL à la "var" du "je"ème élément
	de la "g_term.env tableau. 

    return (1);
    Cette ligne renvoie la valeur entière de 1, indiquant que la fonction a été
	exécutée avec succès. 

Dans l'ensemble, cette fonction initialise le mondial "g_term.env" variable
par l'analyse de l'environnement les variables passées à ce programme
par le "vice" de paramètre.
Il le fait par l'allocation de la mémoire pour un tableau de "t_env" structures, 
en affectant les valeurs appropriées pour chaque structure "clé" 
et "var" champs, et mettre le dernier élément du champs à NULL.
Si aucune de ces mesures échouent, la fonction retourne -1. 
*/
