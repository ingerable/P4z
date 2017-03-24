library(ggplot2)

perf <-read.table("perfInsertionCroissantOpti.dat", header=TRUE, fill=TRUE)



#png("insertionProcheEtendue.png")
#i<-qplot(taille, exectime, data=perf, main="insertion sur tableaux croissants proche et etendue" ,geom="smooth", method="loess", color=tableau)
#print(i)
#dev.off()

png("optionOptimisation.png")
i<-qplot(taille, exectime, data=perf, main="tri insertion sur tableau croissant avec et sans option d'optimisation", geom="smooth", method="loess", color = exe, shape = tableau)
print(i)
dev.off()

