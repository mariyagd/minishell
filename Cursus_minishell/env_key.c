
#include "minishell.h"

char	*env_key(char *env)
{
	int		i;
	char	*res;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (env[i] && env[i] != '=')
	{
		res[i] = env[i];
		i++;
	}
	res[i] = env[i];
	res[++i] = '\0';
	return (res);
}

/*
   C'est la définition de la fonction pour env_key. 
   Il faut un char pointeur nommé env comme paramètre,
   et retourne un char pointeur.
   
   Ces lignes initialiser un entier i de 0 et de déclarer
   un pointeur de caractère  res sans l'initialiser.
   
   Cette while boucle trouve la position de la première = caractère
   de la env chaîne en itère jusqu'à ce que la fin de la chaîne
   ou un = personnage est atteint. Après la boucle,
   i est incrémenté à aller au-delà du  = caractère.
   
   Ce code alloue dynamiquement de la mémoire pour le res pointeur
   pour stocker la partie clé de la variable d'environnement.
   L' i + 1 qui inclut l'espace pour les personnages principaux
   et un terminateur null. Si l'allocation de mémoire échoue,
   NULL est retourné.
   
   Ces lignes de copier la partie clé de la variable d'environnement
   à partir de ` env pour res.
   L'while boucle de copies de chaque caractère de la clé
   jusqu'à ce que le  = personnage est atteint.
   Après la boucle, l'  = caractère est copié, i est incrémenté,
   et un terminateur null est ajouté à la fin de la chaîne. 

La fonction renvoie la res pointeur contenant la partie clé de la variable
d'environnement.
 */
