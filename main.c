/** Alex Barféty
Jeu de la vie - contient uniquement la fonction main !
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <openssl/md5.h>

#include "plane.h"
#include "nextStepComputation.h"
#include "hash.h"

int main (int argc, char *argv[])
{
	int stop = 0, begin = 0, currentPlane = 0, nb = 0 ;
	int gamePlane[2][DIMENSION][DIMENSION] ;
	unsigned int hash_history[HISTORY_DIM][MD5_DIGEST_LENGTH] ;
	unsigned int hashcode[MD5_DIGEST_LENGTH] ;
	
	srand(time(NULL)) ; //initialisation du compteur aléatoire.
	initGamePlane(gamePlane[0], DIMENSION) ; //On crée le plan du jeu initial.
	while (!stop)
	{
		nb++ ;
		system("clear") ; //On "efface" la console.
		printf("\n\nNouvelle génération :") ;
		//On affiche le plan actuel.
		printGamePlan(gamePlane[currentPlane], DIMENSION) ;
		//getchar() ; //On mets une pause entre chaque génération.
		system("sleep 0.02") ; //Petite pause pour voir ce qu'il se passe.
		//On calcule le hashcode du plan courant.
		hash(hashcode, gamePlane[currentPlane], DIMENSION) ; //On change l'appel de la fonction, il est plus facile de modifier un tableau s'il est passé en paramètre de la fonction
		//On cherche le hash dans l'historique.
		if ((begin = findHashInHistory(hashcode, hash_history, nb)) != -1)
		{
			printf("\nCycle repéré qui commence à la %dème itération.\n", begin) ;
			stop = 1 ;
		}
		else //Pas de cylce trouvé.
		{
			//Ajout du Hashcode dans l'historique.
			addHashInHistory(hashcode, hash_history, nb) ;
			//Calcul de la génération suivante.
			nextStep(gamePlane, DIMENSION, currentPlane) ;
			currentPlane = (currentPlane+1)%2 ;
		}
		if (nb == HISTORY_DIM) //si on arrive à la limite de l'historique.
		{
			printf("\nPas de cycle repéré... arrêt à la %de dimension.\n", HISTORY_DIM) ;
			stop = 1 ;
		}
	}
	return 0 ;
}