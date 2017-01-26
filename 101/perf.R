perf <- read.table("perf.dat", header=TRUE)

ggplot(data=perf, aes(x=taille,y=exectime)) + geom_point() + geom_smooth()

ggplot(data=perf, aes(x=taille,y=rechercher)) + geom_point() + geom_smooth() + geom_point(aes(y=generer_tableau),color="red") + geom_smooth(aes(y=generer_tableau),color="red")

ggplot(data=perf, aes(x=taille,y=rechercher)) + geom_point() + geom_smooth() + geom_point(data=perfv1,color="red") + geom_smooth(data=perfv1,color="red")

> perf <- read.table("perf.dat", header=TRUE)
> perfV1 <- perf[perf$exe == 'recherche',]
> perfV0 <- perf[perf$exe == 'rechercheV0',]
> ggplot(data=perfV0, aes(x=taille,y=rechercher)) + geom_point() + geom_smooth() + geom_point(data=perfV1,color="red") + geom_smooth(data=perfV1,color="red")
