#ifndef HASHH
#define HASHH

//Prototype des fonctions :
void hash (unsigned int hashcode[MD5_DIGEST_LENGTH], int gamePlane[DIMENSION][DIMENSION], int size) ;
int findHashInHistory (unsigned int hashcode[MD5_DIGEST_LENGTH],unsigned int hash_history[HISTORY_DIM][MD5_DIGEST_LENGTH], int fin) ;
void addHashInHistory (unsigned int hashcode[MD5_DIGEST_LENGTH],unsigned int hash_history[HISTORY_DIM][MD5_DIGEST_LENGTH],unsigned int nb) ;

#endif