#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h

//#define N 5

long *generer_tableau(long long unsigned int n);
long *generer_tableau_trie_croissant(long long unsigned int n);
long *generer_tableau_trie_decroissant(long long unsigned int n);
char testCroissance(long* tab, int N);
