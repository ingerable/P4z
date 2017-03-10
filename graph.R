library(ggplot2)

perf <-read.table("test.dat", header=TRUE, fill=TRUE)
fusion <-perf[perf$tri=='insertion',]


png("insertionProcheEtendue.png")
i<-qplot(taille, exectime, data=perf, main="insertion sur tableaux croissants proche et etendue" ,geom="smooth", method="loess", color=tableau)
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

