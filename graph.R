library(ggplot2)

perf <-read.table("perf.dat", header=TRUE)

png("fusionTabCroissant.png")
i<-qplot(taille, exectime, data=perf, geom="smooth", method="loess")
print(i)
dev.off()
