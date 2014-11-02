/**
Contient les fonctions qui gèrent les tableaux
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <openssl/md5.h>

#include "plane.h"
#include "nextStepComputation.h"
#include "hash.h"

//Fonction qui affiche le plan de jeu.
void printGamePlan (int plane[DIMENSION][DIMENSION], int size)
{
	int i = 0, j = 0 ;
	printf("\n") ;
	for (i=0 ; i<size+1 ; i++) //"Bord" supérieur.
	{
		printf("_") ;
	}
	printf("\n") ;
	for (i=0 ; i<size ; i++)
	{
		printf("|") ; // Coté gauche.
		for (j=0 ; j<size ; j++)
		{
			if(plane[i][j])
			{
				printf("*") ; //Cellule vivante.
			}
			else
			{
				printf(" ") ; //Cellule morte.
			}
		}
		printf("|\n") ; //Coté droit.
	}
	for (i=0 ; i<size+1 ; i++) //Bord inférieur.
	{
		printf("-") ;
	}
}

//Fonction qui initialise le plan de jeu.
void initGamePlane (int plane[DIMENSION][DIMENSION], int size)
{
	int i = 0, j = 0, nb = 0 ;
	for (i=0 ; i<size ; i++)
	{
		for (j=0 ; j<size ; j++)
		{
			nb = rand()%(100) + 1 ; //On détermine un nombre aléatoire entre 1 et 100.
			if (nb>PRC_FREE_CELL)
			{
				plane[i][j] = 1 ;
			}
			else
			{
				plane[i][j] = 0 ;
			}
		}
	}
	///Pour tester :
	//plane[1][1] = plane[0][1] = plane[2][1] = 1 ;
}