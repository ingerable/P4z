#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h

//#define N 5

long *generer_tableau(long long unsigned int n);
long *generer_tableau_trie_croissant(long long unsigned int n);
long *generer_tableau_trie_decroissant(long long unsigned int n);
long *generer_tableau_valeur_unique(long long unsigned int n);
long *generer_tableau_trie_aleatoire_etendu(long long unsigned int n);
long *generer_tableau_trie_aleatoire_proche(long long unsigned int n);
char testCroissance(long* tab, int N);
