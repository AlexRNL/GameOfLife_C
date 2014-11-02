/**
Contient les fonctions qui gère le hash code (recherche et historique).
**/
#include <stdio.h>
#include <stdlib.h>
#include <openssl/md5.h>

#include "plane.h"
#include "nextStepComputation.h"
#include "hash.h"

//Fonction qui détermine le hash code d'un 'GamePlane' :
void hash (unsigned int hashcode[MD5_DIGEST_LENGTH], int gamePlane[DIMENSION][DIMENSION], int size)
{
	int i = 0 ;
	unsigned int newGP[DIMENSION*DIMENSION] = {0} ;
	for (i=0 ; i<DIMENSION*DIMENSION ; i++) //On convertit le tableau de deux dimensions en un tableau à deux dimensions.
	{
		newGP[i] = gamePlane[i/DIMENSION][i%DIMENSION] ;
	}
	MD5((char*) newGP, sizeof(int)*size*size, hashcode) ; //appel de la fonction de hashage.
}

//Fonction qui détermine si un hashcode est déjà dans l'historique et renvoie son rang :
int findHashInHistory (unsigned int hashcode[MD5_DIGEST_LENGTH],unsigned int hash_history[HISTORY_DIM][MD5_DIGEST_LENGTH], int fin)
{
	int i = 0, rank = 0, dif = 1 ;
	while (rank++<fin && dif) //On recherche dans tout l'historique et on s'arrête quand on est au bout ou quand on trouve un hashcode identique.
	{
		dif = 0 ; //On suppose que les hashcodes sont identiques.
		for (i=0 ; i<MD5_DIGEST_LENGTH ; i++) //On parcours le hashcode.
		{
			if (hashcode[i]!=hash_history[rank][i]) //à la première différence, on mets le dif à 1.
			{
				dif = 1 ;
			}
		}
	}
	if (rank >= fin)
	{
		return -1 ; //Si le rank est supérieur à la fin, ça veut dire qu'aucun hashcode ne corresponds.
	}
	else
	{
		return rank ;
	}
}

//Fonction qui ajoute le hashcode dans l'historique :
void addHashInHistory (unsigned int hashcode[MD5_DIGEST_LENGTH],unsigned int hash_history[HISTORY_DIM][MD5_DIGEST_LENGTH],unsigned int nb)
{
	int i ;
	for (i=0 ; i<MD5_DIGEST_LENGTH ; i++) //On copie l'hashcode dans le tableau de l'historique.
	{
		hash_history[nb][i] = hashcode[i] ;
	}
}
