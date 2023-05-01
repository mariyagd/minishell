
#include "minishell.h"

void	handler_ctr_c(int code)
{
	int	i;

	i = 0;
	(void)code;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay(); //on en a pas besoin?
	//exit(1);
}
/*
	void handler_ctr_c(int code)
    Cette ligne définit la fonction "handler_ctr_c"
	qui prend un entier en paramètre "code" et renvoie void. 

    int i;
    Cette ligne déclare une variable de type entier qui s'appelle "je". 

    i = 0;
    Cette ligne initialise le "je" de la variable à 0. 

    (void)du code;
    Cette ligne jette le "code" paramètre void,
	qui est utilisé pour supprimer les avertissements du compilateur
	pour les paramètres inutilisés. 

    printf("\n");
    Cette ligne imprime un caractère de saut de ligne à la console. 

    rl_replace_line("", 0);
    Cette ligne remplace la ligne de texte dans la bibliothèque
	Readline de la mémoire tampon de ligne avec une chaîne vide
	et d'une longueur de 0. 

    rl_on_new_line();
    Cette ligne déplace le curseur sur une nouvelle ligne dans la bibliothèque
	Readline de la mémoire tampon de ligne. 

    rl_redisplay(); - pas besoin !!!
    Cette ligne affiche à nouveau la ligne de texte dans la bibliothèque
	Readline de la mémoire tampon de ligne, qui est maintenant une chaîne vide.

	exit(1)
	avec exit(1) ctrl+c marche	

Dans l'ensemble, cette fonction est un gestionnaire de signal
pour le signal d'interruption (SIGINT) qui est déclenché lorsque l'utilisateur
appuie sur Ctrl+C. Lorsque le signal est pris, il efface la ligne de texte
dans le Readline tampon et imprime un caractère de saut de ligne à la console
*/
