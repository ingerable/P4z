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

long *generer_tableau_trie_decroissant(long long unsigned int n)
{
  long *tableau = malloc(n*sizeof(long));
  long long unsigned int i;
	tableau[0]=rand();
  for (i=1; i<n; i++)
  {
    tableau[i] = tableau[i-1]-rand()%100;
  }
  return tableau;
}

long *generer_tableau_valeur_unique(long long unsigned int n)
{
	long *tableau = malloc(n*sizeof(long));
	long value = rand()%n;
	long long unsigned i;
	for (i=0; i<n; i++)
	{
		tableau[i] = value;
	}
	return tableau;
}

char testCroissance(long* tab, int N)
{
	char res = 0;
	for(int i=0; i<N;i++)
	{
		if(tab[i]>tab[i+1])
		{
			res = 1;
			printf("%ld\n",tab[i]);
		}
		else{
			printf("%ld\n",tab[i]);
		}
	}
	return res;
}
