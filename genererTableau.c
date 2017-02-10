#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h
#include "genererTableau.h"
//#define N 150

long *generer_tableau(long long unsigned int n)
{
	long *tableau = malloc(n*sizeof(long));
	long long unsigned int i;

	for (i=0; i<n; i++) {
		tableau[i] = rand()%10000;
	}
	return tableau;
}


long *generer_tableau_trie_croissant(long long unsigned int n)
{
  long *tableau = malloc(n*sizeof(long));
  long long unsigned int i;
	printf("%s\n","en dehors du for" );
	tableau[0] = rand()%N;
  for (i=1; i<n; i++)
  {
    tableau[i] = (rand()%N)+tableau[i-1];
  }
  return tableau;
}
