
#include "minishell.h"

char	*env_var(char *env)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (env[i] && env[i] != '=')
		i++;
	i++;
	while (env[i + len])
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	len = 0;
	while (env[i + len])
	{
		res[len] = env[i + len];
		len++;
	}
	res[len] = '\0';
	return (res);
}
/*
   C'est la définition de la fonction pour  env_var.
   Il faut un char pointeur nommé env comme paramètre,
   et retourne un  char pointeur.
   
   Ces lignes initialiser deux entiers i et  len à 0,
   et déclarer un pointeur de caractère  res sans l'initialiser.
   
   Cette  while boucle trouve la position de la première  = caractère de la
   env chaîne en itère jusqu'à ce que la fin de la chaîne
   ou un  = personnage est atteint.
   Après la boucle, i est incrémenté à aller au-delà du  = caractère.
   
   Cette  while boucle trouve la longueur de la partie de la valeur
   de la variable d'environnement par itération sur elle jusqu'à la fin de la
   chaîne est atteint.
   L'  len variable est utilisé pour garder la trace de la longueur.
   
   Ce code alloue dynamiquement de la mémoire pour le res pointeur
   pour stocker la partie de la valeur de la variable d'environnement.
   La taille de l'allocation est len + 1 qui inclut l'espace
   pour les caractères de valeur et un terminateur null.
   Si l'allocation de mémoire échoue,  NULL est retourné.
   
   Ces lignes de copier la partie de la valeur de la variable d'environnement
   de  env pour res.
   L'  while boucle de copies de chaque caractère de la valeur jusqu'à la fin
   de la chaîne est atteint.
   Après la boucle, un terminateur null est ajouté à la fin de la chaîne. 

La fonction renvoie la res pointeur contenant la partie de la valeur
de la variable d'environnement.
*/
