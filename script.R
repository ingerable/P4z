# Script R 
# Exectutable avec R --no-save -f perf.R 

# Chargement des librairies
library(ggplot2)

# Chargement des données
perf <- read.table("decroissantFusion.dat", header=TRUE, fill=TRUE)
#insertion <- perf[perf$exe == 'insertion',]


# Analyses de la version initiale
png("fusionDecroissant.png")
i<-qplot(taille, exectime, data=perf, main="fusion sur tableau valeurs decroissantes",
geom="smooth", color = exe)
print(i)
dev.off()






