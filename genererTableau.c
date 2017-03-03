#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h
#include "genererTableau.h"

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
	tableau[0] = rand()%n;
  for (i=1; i<n; i++)
  {
    tableau[i] = (rand()%n)+tableau[i-1];
  }
  return tableau;
}
