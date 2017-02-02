# Script R 
# Exectutable avec R --no-save -f perf.R 

# Chargement des librairies
library(ggplot2)

# Chargement des données
perf <- read.table("perf.dat", header=TRUE)
perfV0 <- perf[perf$exe == 'rechercheV0',]
perfV1 <- perf[perf$exe == 'rechercheV1',]
perfV2 <- perf[perf$exe == 'rechercheV2',]


# Analyses de la version initiale
png("data/exectime.V0.png")
ggplot(data=perfV0, aes(x=taille, y=exectime, color=exe)) + 
	geom_point() + geom_smooth() +
	ggtitle("Temps d'execution global en fonction de la taille")
dev.off()

png("data/memory.V0.png")
ggplot(data=perfV0, aes(x=taille,y=memory, color=exe)) + 
	geom_point() + geom_smooth() +
	ggtitle("Consommation mémoire en fonction de la taille")
dev.off()

png("data/functions.V0.png")
ggplot(data=perfV0, aes(x=taille,y=generer_tableau, color="generer_tableau")) + 
	geom_point() + geom_smooth() +
	geom_point(aes(y=afficher_tableau, color="afficher_tableau")) + geom_smooth(aes(y=afficher_tableau,color="afficher_tableau")) + 
	geom_point(aes(y=rechercher,color="rechercher")) + geom_smooth(aes(y=rechercher,color="rechercher")) +
	labs(color="Fonctions") +
	ggtitle("Temps d'execution des fonctions en fonction de la taille")
dev.off()

## Calculs statistiques
sink("data/V0.lm")
rbind(
c("exectime", 
	lm(exectime ~ taille, perfV0)$coefficients),
c("memory", 
	lm(memory ~ taille, perfV0)$coefficients),
c("generer_tableau", 
	lm(generer_tableau ~ taille, perfV0)$coefficients),
c("afficher_tableau", 
	lm(afficher_tableau ~ taille, perfV0)$coefficients),
c("rechercher", 
	lm(rechercher ~ taille, perfV0)$coefficients)
)
sink()


# Comparaison de rechercher entre V0 et V1 
png("data/rechercher.V0.V1.png")
ggplot(data=rbind(perfV0,perfV1), aes(x=taille,y=rechercher, color=exe)) + 
	geom_point() + geom_smooth() +
	ggtitle("Comparaison des temps d'execution de la fonction rechercher \n en fonction de la taille des versions V0 et V1")
dev.off()

ggplot(data=perfV0, aes(x=taille,y=rechercher)) + geom_point() + geom_smooth() + geom_point(data=perfV1) + geom_smooth(data=perfV1)


## Calculs statistiques
sink("data/rechercher.V0.V1.lm")
rbind(
c("V0", lm(rechercher ~ taille, perfV0)$coefficients),
c("V1", lm(rechercher ~ taille, perfV1)$coefficients)
)
sink()

	
# Comparaison de rechercher entre V0, V1 et V2
png("data/rechercher.V0.V1.V2.png")
ggplot(data=perf, aes(x=taille,y=rechercher,color=exe)) + 
	geom_point() + geom_smooth() +
	ggtitle("Comparaison des temps d'execution de la fonction rechercher \n en fonction de la taille des versions V0, V1 et V2")
dev.off()

## Calculs statistiques
sink("data/rechercher.V0.V1.V2.lm")
rbind(
c("V0", lm(rechercher ~ taille, perfV0)$coefficients),
c("V1", lm(rechercher ~ taille, perfV1)$coefficients),
c("V2", lm(rechercher ~ taille, perfV2)$coefficients)
)
sink()


# Comparaison des temps d'exécution globaux entre V0, V1 et V2
png("data/exectime.V0.V1.V2.png")
ggplot(data=perf, aes(x=taille,y=exectime,color=exe)) + 
	geom_point() + geom_smooth() +
	ggtitle("Comparaison des temps d'execution globaux \n en fonction de la taille des versions V0, V1 et V2")
dev.off()

## Calculs statistiques
sink("data/exectime.V0.V1.V2.lm")
rbind(
c("V0", lm(exectime ~ taille, perfV0)$coefficients),
c("V1", lm(exectime ~ taille, perfV1)$coefficients),
c("V2", lm(exectime ~ taille, perfV2)$coefficients)
)
sink()

