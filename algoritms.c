#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h
#include "genererTableau.h"

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
  printf("\n");
}

void fusion(long *A,long debut, long milieu, long fin)
{
	long ng = milieu - debut +1; // longueur tableau g
	long nd = fin - milieu; // longueur tableau d
	long *ag = malloc(ng*sizeof(long)); // declaration tableau ag
	long indG = 0; // indice tableau G
	long indD = 0; //indice tableau d
	long l = debut;
  long j = 0;
	for(long i = debut;i<=milieu;i++) // on remplit le tableau ag à partir de A[debut,millieu]
	{
		ag[j]=A[i];
    j++;
	}
  /*printf("%s %ld\n","taille ag",ng);
  for(int i=0;i<=ng;i++)
  {
    printf("%s %ld\n","ag[i] :",ag[i]);
  }*/
	long *ad = malloc(nd*sizeof(long)); // declaration tableau ad
	j=0;
	for(long i = milieu+1;i<=fin;i++)// on remplit le tableau ad à partir de A[millieu+1,fin]
	{
		ad[j]= A[i];
		j++;
	}
  /*printf("%s %ld\n","taille ad",nd);
  for(long i=0;i<=nd;i++)
  {
    printf("%s %ld\n","ad[i] :",ad[i]);
  }*/
	while(l<=fin)
	{
		if(indG==ng)
		{
			A[l]=ad[indD];
			indD++;
      //printf("%d\n", indD);
		}else if(indD==nd)
		{
			A[l]=ag[indG];
			indG++;
		}else if(ag[indG]<ad[indD])
		{
			A[l]=ad[indD];
      indG++;
		}else{
      //printf("%d\n", indD);
			A[l]=ad[indD];
      indD++;
		}
		l++;
	}
}

void TriFusion(long* A, long debut, long fin)
{
	if(debut < fin)
	{ //Si le tableau a plus d'un élément
		long milieu = (debut + fin)/2;
    //printf("%s %ld\n","debut : ",debut );
    //printf("%s %ld\n","fin :", fin );
    //printf("%s %ld\n","milieu :", milieu );
		TriFusion(A,debut,milieu);
		TriFusion(A,debut+1,fin);
		fusion(A,debut,milieu,fin);
	}
}

/*void triFusion(long* p, long ln){
  TriFusion(p, 0, ln -1 );
}*/

int partition(long *A, long debut, long fin)
{
	long pivot = A[fin];
	long i = debut;
	long j;
	long inter; // valeur intermédiaire
	for(j=debut;j<=fin-1;j++)
	{
		if(A[j]<=pivot)
		{
			inter=A[j];
			A[j]=A[i];
			A[i]=inter;
			i++;
		}
	}
	inter=A[fin];
	A[fin]=A[i];
	A[i]=inter;
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

void afficher_tableau(long *tableau)
{
	int i;
	for (i=0; i<N; i++) {
		printf("%ld ",tableau[i]);
	}
}

int main()
{
  srand(time(NULL));
  long *tab = generer_tableau(N);
  printf("non triée \n");
  afficher_tableau(tab);
  //insert(tab);
	TriFusion(tab, 0, N-1);
  //triRapide(tab,0,N-1);
  printf("\n");
  printf("triée :\n");
  afficher_tableau(tab);
	printf("\n");
	return 0;
}
