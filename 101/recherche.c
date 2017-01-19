/**
 Recherche d'un entier alétoire dans un tableau de valeurs aléatoires
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALEUR 15000000

int *generer_tableau(long long unsigned int n) 
{
	int *tableau = malloc(n*sizeof(int));
	long long unsigned int i;

	for (i=0; i<n; i++) {
		tableau[i] = rand()%MAX_VALEUR;
	}

	return tableau;
}

void afficher_tableau(int *tableau, long long unsigned int n)
{
	long long unsigned int i;
	for (i=0; i<n; i++) {
		printf("%d ",tableau[i]);
	}
	printf("\n");

}

char rechercher(int *tableau, long long unsigned int n, int valeur) 
{
	long long unsigned int i;
	char trouve = 0;

	for (i=0; i<n; i++) {
		if (tableau[i] == valeur) {
			trouve=1;
		}
	}

	return trouve;
}


int main(int argc, char *argv[])
{
	int *tableau;
	int n, valeur;
	char trouve;

	if (argc<2) {
		printf("%s: opérande manquant\n",argv[0]);
		printf("Recherche une valeur aléatoire dans un tableau d'entier aléatoire de taille n\n");
		printf("Affiche letableau et renvoie 1 si la valeur est trouvée, 0 sinon\n");
		printf("Usage: %s n\n",argv[0]);
		exit(1);
	}

	unsigned int graine;
	if (argc>2) {
		graine = atoi(argv[2]);
	} else {
		graine = time(NULL);
	}

	srand(graine);

	n = strtoull(argv[1], (char **) NULL, 10);
	valeur = rand()%MAX_VALEUR;
	tableau = generer_tableau(n);

	afficher_tableau(tableau,n);

	trouve = rechercher(tableau, n, valeur);

    printf("Valeur trouve: %d\n",trouve);
}