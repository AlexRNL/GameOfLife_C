#ifndef PLANEH
#define PLANEH

///Quelques constantes symboliques :
//Pourcentage de cellule libres, dimension du tableau, et dimension de l'historique
#define PRC_FREE_CELL 66
#define DIMENSION 50
#define HISTORY_DIM 100000

//Prototype des fonctions de plane.c :
void printGamePlan (int plane[DIMENSION][DIMENSION], int size) ;
void initGamePlane (int plane[DIMENSION][DIMENSION], int size) ;

#endif