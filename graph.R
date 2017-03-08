library(ggplot2)

perf <-read.table("fusRapInsCroiss.dat", header=TRUE, fill=TRUE)

#png("fusionTabCroissant.png")
#i<-qplot(taille, exectime, data=perf, geom="smooth", method="loess")
#print(i)
#dev.off()

png("Memory3Croissant.png")
i<-qplot(taille, memory, data=perf, main="3 tri sur tableaux avec valeurs croissantes", geom="smooth", method="loess", color = exe)
print(i)
dev.off()

#png("Exectime3CroissantHisto.png")
#i<-qplot(taille, exectime, data=perf, main="3 tri sur tableaux avec valeurs croissantes", geom="histogram", bindwidth = 0.1, method="loess")
#print(i)
#dev.off()
