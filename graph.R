library(ggplot2)

perf <-read.table("fusRapInsUnique.dat", header=TRUE, fill=TRUE)

#png("fusionTabCroissant.png")
#i<-qplot(taille, exectime, data=perf, geom="smooth", method="loess")
#print(i)
#dev.off()

#png("Memory3Unique.png")
#i<-qplot(taille, memory, data=perf, main="memoire 3 tri sur tableaux avec valeurs unique", geom="smooth", #method="loess", color = exe)
#print(i)
#dev.off()

#png("HistoMemoryUnique.png")
#i<-ggplot(data=perf, aes(perf$exectime)) + geom_histogram()
#print(i)
#dev.off()

