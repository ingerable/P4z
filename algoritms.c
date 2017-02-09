#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h
#include "genererTableau.h"
#define N 200

void insert(long* A)
{
  int cmpr=0;
  int writings=0;
  for(int i=1;i<N;i++)
  {
    long key = A[i];
    long j = i;
    while(j>0 && A[j-1]>key)
    {
      A[j]=A[j-1];
      j=j-1;
      writings+=1;
    }
    A[j]=key;
    cmpr+=1;
  }
	printf("%d\n Nombre d'écritures : ",writings );
	printf("%d\n Nombre de comparaisons : ",cmpr );
	printf("%d\n Nombre d'élements : ", N);
}

void fusion(long *A,long debut, long milieu, long fin)
{
	long ng = milieu - debut +1; // longueur tableau g
	long nd = fin - milieu; // longueur tableau d
	long ag[ng]; // declaration tableau ag
	int indG=0; // indice tableau G
	int indD=0; //indice tableau d
	int l = debut;
	for(int i = debut;i<=milieu;i++) // on remplit le tableau ag à partir de A[debut,millieu]
	{
		ag[i]=A[i];
	}
	long ad[nd]; // declaration tableau ad
	int j=0;
	for(int i = milieu+1;i<=fin;i++)// on remplit le tableau ad à partir de A[millieu+1,fin]
	{
		ad[j]= A[i];
		j++;
	}
	while(l<=fin)
	{
		if(indG==ng)
		{
			A[l]=ad[indD];
			indD++;
		}else if(indD==nd)
		{
			A[l]=ag[indG];
			indG++;
		}else if(ag[indG]<ad[indD])
		{
			A[l]=ad[indD];
		}else{
			A[l]=ad[indD];
		}
		l++;
	}
}

void triFusion(long *A, long debut, long fin)
{
	if(debut < fin)
	{ //Si le tableau a plus d'un élément
		long milieu = (debut + fin)/2;
		triFusion(A,debut,milieu);
		triFusion(A,debut+1,fin);
		fusion(A,debut,milieu,fin);
	}
}

int partition(long *A, long debut, long fin)
{
	long pivot = A[fin];
	long i = debut;
	long j;
	long inter; // valeur intermédiaire
	for(j=debut;j<fin-1;j++)
	{
		if(A[j]<pivot)
		{
			inter=A[j];
			A[j]=A[i];
			A[i]=inter;
			i++;
		}
	}
	inter=A[fin];
	A[fin]=A[i];
	A[fin]=inter;
	return i;
}

void triRapide(long *A, long debut, long fin)
{
	long q;
	if(debut<fin)
	{
		q=partition(A,debut,fin);
		triRapide(A,debut,q-1);
		triRapide(A,q+1,fin);
	}
}

void afficher_tableau(int *tableau)
{
  printf("%s\n", "Tableau trié :");
	int i;
	for (i=0; i<N; i++) {
		printf("%d ",tableau[i]);
	}
}

int main()
{
  srand(time(NULL));
  int *tab = generer_tableau_trie_croissant(15000);
  //insert(tab);
	//fusion(tab, 0, N);
  printf("\n");
  afficher_tableau(tab);
	printf("\n");
	return 0;
}
