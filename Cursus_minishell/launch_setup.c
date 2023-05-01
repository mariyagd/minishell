
#include "minishell.h"

int	launch_setup(int ac, char **envp)
{
	if (ac != 1)
		return (-1);
	signal(SIGINT, handler_ctr_c);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGQUIT, handler_ctr_d); //
	g_term.envp = envp;
	g_term.env = NULL;
	if (init_struct_env() == -1)
		return (-1);
	return (1);
}
/*
    int launch_setup(int ac, char **envp)
    Cette ligne définit la fonction "launch_setup", qui prend un entier "ac"
	et un double pointeur vers un caractère "vice" comme arguments
	et renvoie une valeur de type entier. 

    si (ac != 1)
    Cette ligne vérifie si la valeur de "ac" n'est pas égal à 1.
	Si cette condition est true, la fonction retourne -1. 

    return (-1);
    Cette ligne renvoie la valeur de l'entier -1 si la condition précédente est vraie. 

    signal(SIGINT, handler_ctr_c);
    Cette ligne met en place un gestionnaire de signal
	pour le signal d'interruption (SIGINT). Il associe le signal avec la fonction
	"handler_ctr_c". 

    signal(SIGQUIT, SIG_IGN);
    Cette ligne met en place un gestionnaire de signal
	pour le signal de fin (SIGQUIT) et l'ignore en l'associant avec
	le "SIG_IGN" constante. 

    g_term.envp = envp;
    Cette ligne affecte la valeur de la "vice" paramètre une variable globale
	appelée "g_term.envp". 

    g_term.env = NULL;
    Cette ligne initialise une variable globale appelée "g_term.env" à NULL. 

    si (init_struct_env() == -1)
    Cette ligne appelle une fonction appelée "init_struct_env"
	et vérifie si elle retourne -1. Si cette condition est true,
	la fonction retourne -1. 

    return (1);
    Cette ligne renvoie la valeur entière 1
	si aucune des conditions précédentes sont remplies. 

Dans l'ensemble, cette fonction définit les gestionnaires de signaux
pour l'interrompre et arrêter de signaux, attribue la valeur d'un paramètre
à une variable globale, initialise une autre variable globale, et appelle
une fonction.
*/ 
