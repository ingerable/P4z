#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h
#include "genererTableau.h"

long long N; // nbr d'elements dans le tableau
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
	//printf("%d\n Nombre d'écritures : ",writings );
	//printf("%d\n Nombre de comparaisons : ",cmpr );
  //printf("\n");
}

void fusion(long *A,long debut, long milieu, long fin)
{
	long ng = milieu - debut +1; // longueur tableau g
	long nd = fin - milieu; // longueur tableau d
	long ag[ng];
  long ad[nd];
	long indG = 0; // indice tableau G
	long indD = 0; //indice tableau d
	long l = debut;

  memcpy(ag, &A[debut],ng*sizeof(long));
  memcpy(ad, &A[milieu+1],nd*sizeof(long));

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
			A[l]=ag[indG];
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
		TriFusion(A,milieu+1,fin);
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

int partitionOpti(long *A, long debut, long fin)
{
	long pivot = rand()%(fin);
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

void triRapideOpti(long *A, long debut, long fin)
{
	long q;
	if(debut<fin)
	{
		q=partitionOpti(A,debut,fin);
		triRapideOpti(A,debut,q-1);
		triRapideOpti(A,q+1,fin);
	}
}

void afficher_tableau(long *tableau)
{
	int i;
	for (i=0; i<N; i++) {
		printf("%ld ",tableau[i]);
	}
}

int main(int argc, char *argv[] )
{
  if(argc !=4)
  {
    printf("%s\n","Usage <nbr elements tableau> <type tri> <type tableaux>");
  }else{

    srand(time(NULL));
    N = atoll(argv[1]);
    long *tab; //type de tableaux


    if(strcmp(argv[3],"croissant")==0)
    {
      tab = generer_tableau_trie_croissant(N);
    }else if(strcmp(argv[3],"decroissant")==0)
    {
      tab = generer_tableau_trie_decroissant(N);
    }else if(strcmp(argv[3],"unique")==0)
    {
      tab = generer_tableau_valeur_unique(N);
    }else if(strcmp(argv[3],"aleatoire")==0)
    {
      tab = generer_tableau(N);
    }else if(strcmp(argv[3],"aleatoireProche")==0)
    {
      tab = generer_tableau_trie_aleatoire_proche(N);
    }else if(strcmp(argv[3],"aleatoireEtendue")==0)
    {
      tab = generer_tableau_trie_aleatoire_etendu(N);
    }else if(strcmp(argv[3],"triPartiel")==0)
    {
      tab = generer_tableau_trie_partiel(N);
    }
    //afficher_tableau(tab);

    if(strcmp(argv[2],"insertion")==0)
    {
      insert(tab);
    }
    else if(strcmp(argv[2],"fusion")==0)
    {
      TriFusion(tab, 0, N-1);
    }
    else if(strcmp(argv[2],"rapide")==0)
    {
      triRapide(tab,0,N-1);
    }else if(strcmp(argv[2],"rapideOpti")==0)
    {
      triRapideOpti(tab,0,N-1);
    }


  }
	return 0;
}
