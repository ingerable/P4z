# Script R 
# Exectutable avec R --no-save -f perf.R 

# Chargement des librairies
library(ggplot2)

# Chargement des données
perf <- read.table("perf.dat", header=TRUE)
insertionV0 <- perf[perf$exe == 'insertion',]


# Analyses de la version initiale
png("insertion.png")
i<-qplot(taille, exectime, data=insertionV0, main="insertion sur tableau valeurs aléatoires",
geom=c("point","smooth"))
print(i)
dev.off()





