/**
Contient les fonctions pour calculer la génération suivante
**/

#include <stdio.h>
#include <stdlib.h>
#include <openssl/md5.h>

#include "plane.h"
#include "nextStepComputation.h"
#include "hash.h"

//Fonction qui calcule le nombre de voisins d'une cellule du plan
int numberOfNeighbors (int gamePlane[DIMENSION][DIMENSION], int size, int i, int j)
{
	int topLine = 0, bottomLine = 0, leftColumn = 0, rightColumn = 0, neighbors = 0 ;
	
	topLine = i-1 ;
	if (topLine<0) //On calcule la ligne du dessus.
	{
		topLine = size-1 ;
	}
	leftColumn = j-1 ;
	if (leftColumn<0) //Celle de gauche.
	{
		leftColumn = size-1 ;
	}
	bottomLine = (i+1)%size ; //Celle du dessus.
	rightColumn = (j+1)%size ; //Et celle du dessous
	
	neighbors = gamePlane[topLine][leftColumn] ;
	neighbors = neighbors + gamePlane[topLine][j] ;
	neighbors = neighbors + gamePlane[topLine][rightColumn] ;
	neighbors = neighbors + gamePlane[i][leftColumn] ;
	neighbors = neighbors + gamePlane[i][rightColumn] ;
	neighbors = neighbors + gamePlane[bottomLine][leftColumn] ;
	neighbors = neighbors + gamePlane[bottomLine][j] ;
	neighbors = neighbors + gamePlane[bottomLine][rightColumn] ;
	return neighbors ;
}

//Fonction qui calcule la génération suivante.
void nextStep (int gamePlane[2][DIMENSION][DIMENSION], int size, int currentPlane)
{
	int i = 0, j = 0, neighbors = 0, nextPlane = 0 ;
	
	nextPlane = (currentPlane+1)%2 ;
	for (i=0 ; i<size ; i++)
	{
		for (j=0 ; j<size ; j++)
		{
			neighbors = numberOfNeighbors(gamePlane[currentPlane], size, i, j) ;
			//Destin de la cellule...
			if (gamePlane[currentPlane][i][j] ==1)
			{
				if (neighbors<2)
				{
					gamePlane[nextPlane][i][j] = 0 ;
				}
				else if (neighbors>3)
				{
					gamePlane[nextPlane][i][j] = 0 ;
				}
				else
				{
					gamePlane[nextPlane][i][j] = 1 ;
				}
			}
			else
			{
				if (neighbors == 3)
				{
					gamePlane[nextPlane][i][j] = 1 ;
				}
				else
				{
					gamePlane[nextPlane][i][j] = 0 ;
				}
			}
		}
	}
}