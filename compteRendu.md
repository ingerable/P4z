### Compte rendu P4z 

## Application

Nous testons 3 algorithmes de trie différent : 

* TriFusion
* Tri par insertion
* Tri rapide

## Environnement de test

Laptot Asus Intel Core i7-5500U CPU @ 2.40Ghz x 4


## Méthode de test

Nous utilisons un script qui permet d'automatiser les tests. e script produit
une fichier de données variant selon les paramètres données au script.
Les paramètres étant les fonctions voulant êtres testées, le nombre de test 
et le ou les executables voulant être executés. La taille du tableau est generée 
de manière aléatoire dans le script.




## Résultats et analyses

Pour commencer nous avons tester le temps d'execution des 3 tri sur un tableau de valeurs aléatoires
de taille variable.

![exectime](./Graphs/3tri/Exectime.png)
![exectime](./Graphs/3tri/insertionFusionRapideMemoryCourbes.png)

On remarque que le temps d'éxecution du tri par insertion augmente proportionnellement 
à la taille du tableau tandis que le temps d'execution des 2 autres tri est constant et très faible
.


