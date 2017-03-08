library(ggplot2)

perf <-read.table("rap3.dat", header=TRUE, fill=TRUE)


png("rapideTousTableaux.png")
i<-qplot(taille, memory, data=perf, main="Tri rapide tableaux croissants decroissants aléatoire non triés utilisation mémoire" ,geom="smooth", method="loess", color=exe)
print(i)
dev.off()

#png("Memory3Unique.png")
#i<-qplot(taille, memory, data=perf, main="memoire 3 tri sur tableaux avec valeurs unique", geom="smooth", #method="loess", color = exe)
#print(i)
#dev.off()

#png("HistoMemoryUnique.png")
#i<-ggplot(data=perf, aes(perf$exectime)) + geom_histogram()
#print(i)
#dev.off()

