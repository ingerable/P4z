#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h
#include "genererTableau.h"

#define N 200

int *generer_tableau(long long unsigned int n)
{
	int *tableau = malloc(n*sizeof(int));
	long long unsigned int i;

	for (i=0; i<n; i++) {
		tableau[i] = rand()%N;
	}

	return tableau;
}


int *generer_tableau_trie_croissant(long long unsigned int n)
{
  int *tableau = malloc(n*sizeof(int));
  long long unsigned int i;
  for (i=1; i<n; i++)
  {
    tableau[0] = rand()%N;
    tableau[i] = (rand()%N)+tableau[i-1];
    //printf("%ld ",tableau[i]);
  }
  return tableau;
}
