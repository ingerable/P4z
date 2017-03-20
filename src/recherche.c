#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxNbValeurs (20 * 1000)

int nbValeurs;
int valeurs[maxNbValeurs];

int compareEntiers(const void* a, const void* b)
{
return *((int*) a) - *((int*) b);
}
bool cherche(int cible)
{
int posGauche = 0;
int posDroite = nbValeurs - 1;
while (posGauche < posDroite)
{
int posMilieu = (posGauche + posDroite) / 2;
  if(cible <= valeurs[posMilieu])
    posDroite = posMilieu;
  else
    posGauche = posMilieu+1;
  }
return (cible == valeurs[posGauche]);
}
int main()
{
  scanf("%d", &nbValeurs);
  for (int index = 0; index < nbValeurs; index++)
  scanf("%d", &valeurs[index]);

  qsort(valeurs, nbValeurs, sizeof(int), compareEntiers);

  int nbRequetes;
  scanf("%d", &nbRequetes);
  for (int requete = 0; requete < nbRequetes; requete++)
  {
  int cible;
  scanf("%d", &cible);
  bool trouve = cherche(cible);
  (trouve) ? printf("1\n") : printf("0\n");
}

return 0;
}
