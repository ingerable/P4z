### Compte rendu P4z

## Application

Nous testons 3 algorithmes de tri différents :

* Tri insertion
* Tri Fusion
* Tri rapide

## Environnement de test

Laptop Asus Intel Core i7-5500U CPU @ `2.40Ghz` x 4


## Méthode de test

Nous utilisons un script qui permet d'automatiser les tests. Le script produit
un fichier de données variant selon les paramètres données au script.
Les paramètres étant les fonctions voulant êtres testées, le nombre de tests
et le ou les executables voulant être executés. La taille du tableau est generée
de manière aléatoire dans le script.

## Préliminaires

La complexité est un champs d'études vaste et passionnant. Il peut-être étudié en philosophie, en biologie, en mathématiques, et bien-sûr en informatique. Elle confère des propriétés intéressantes, et surtout indispensables à tout programmeur soucieux de créer des programmes optimisés, efficaces et rapides. Dans cet article, nous offrons au lecteur un prélude à la complexité d'un point de vu mathématiques théorique. Puis, dans un second temps, nous nous concentrerons
sur la partie informatique pratique. Le plan en découle intrasèquement :

- Introduction
- Notation Big O et petit aparté mathématiques
- Temps d'exécution d'un programme
- Temps d'exécution d'une instruction et assembleur
- Notion de complexité
- Complexité en fonction de plusieurs variables
- Conclusion et ouverture vers d'autres possibilités

Il est usuel d'écrire des programmes sans étudier en amont et en omettant (souvent) volontairement certains paramètres pourtant essentiels à son fonctionnement :

- Le type et la fréquence du microprocesseur utilisé,
- Le langage utilisé et le compilateur choisi, ainsi que de ses réglages,
- Les données d'entrée,
- La complexité en temps de l'algorithme

Nous voilà maintenant fin prêt. C'est parti !

## Introduction

Un algorithme est une série d'opérations qui permet de fournir une solution à une problématique préalablement donnée.
Il est parfois fastidieux de trouver une solution. Mais il peut-être encore plus fastidieux de dénicher un algorithme qui fournit une solution rapidement.
Sur différent sites de challenge de programation, une limite de temps est imposée : la durée maximale autorisée d'exécution de votre programme. Si votre code ne satisfait pas une réponse dans cette limite pour un test donné, ce test est considéré comme étant un échec, même si avec plus de temps, votre programme aurait pu satisfaire une réponse juste. Toute la difficulté est donc de faire en sorte que votre programme soit suffisamment vif.

## Ligne de commande de compilation C/C++

`g++ -Wall -O2 -o output.exe tri.cpp`

Nous allons ici donner quelques conseils ou « tricks » propres au langage C ou C++ et leur compilateur associé gcc. Ce sont de bonnes pratiques à privilégier lorsque l'on travaille dans un environnement nécessitant rigueur et performance.
L'option `-Wall` du compilateur gcc active un maximum de warnings, ce qui permet de minorer le nombre de bugs potentiels. Il est plus que fortement déconseillé de travailler avec un code qui produit des warnings.
L'option `-O2` (c'est un 'O' et non un '0') permet un temps de compilation plus efficace ainsi qu'une génération de code plus performant. On peut gagner un facteur 2 ou 3 en vitesse dans certain cas.

## Mesurer le temps d'exécution

Sous environnement Linux, pour jauger le temps d'exécution d'un programme on utilisera la commande `time` suivante :
**time monprogramme.out**

Cette commande affichera les trois lignes suivantes :

```shell
real 0m0.572s
user 0m0.404s
sys  0m0.666s
```

- Le temps `real` correspond au temps qui s'est consumé, depuis le début et la fin de l'exécution d'un programme. Il est assujeti à de nombreux facteurs externes tels que par exemple les programmes extrinsèques exécutés au même moment par la machine.

- Le temps `user` cadre avec le temps que le processeur a passé à exécuter les instructions d'un programme, sans compter les appels systèmes tels que malloc, printf, scanf etc.

- Le temps `sys` cadre avec le temps que le processeur a passé à exécuter les appels systèmes, autrement dit il s'agit du temps utilisé par des fonctions systèmes comme malloc, printf ou scanf.

Celui qui nous intéresse dépend des besoin et du contexte. Souvent on ne porte attention que sur le temps "user" ou le total du temps "user" et "sys".

## [Unix] Vérifier la mémoire utilisée

## Résultats et analyses

Pour commencer, nous avons testé le temps d'exécution des 3 tris sur un tableau de valeurs générées aléatoirement et de type "long long unsigned int"
de taille variable.

![exectime](./Graphs/3tri/Exectime.png)

On remarque que le temps d'exécution du tri par insertion augmente proportionnellement
à la taille du tableau tandis que le temps d'execution des 2 autres tri est constant et très faible.

![memory](./Graphs/3tri/insertionFusionRapideMemoryCourbes.png)

 Néanmoins on peut voir que le tri fusion est celui qui utilise le plus de mémoire probablement à cause de la génération des sous tableaux puis de leurs fusions.
 En effet, le tri fusion étant implémenté de manière récursive, il sollicite énormément la pile.


![exectime](./Graphs/3tri/Exectime3Croissant.png)

Cette fois ci on analyse le temps d'éxecution pour des tableaux qui ont des valeurs triées par ordre croissant.
On constate que le temps d'éxecution du tri rapide augmente proportionellement pour des tableaux triées par ordre croissant. Le tri rapide n'est donc pas efficace pour des tableaux triés par ordre croissant.


Jetons un coup d'oeil à la consommation de mémoire pour voir si elle aussi a augmenté pour le tri rapide.

![exectime](./Graphs/3tri/Memory3Croissant.png)

On voit que le tri rapide est celui qui utilise le plus de mémoire pour un tableau composé de valeurs croissantes.Le pivot étant le dernier élément du tableaux. Dans le cas du tableau croissant le pivot sera toujours l'élement le plus grand du sous tableau.



##Tri Insertion

**Complexité** | **Pire des cas** | **Moyen** | **Meilleur des cas** | 
|---|---|---|---|---|
| **Notes** | Dans le pire cas, lorsque le tableau est trié à l'envers (tableau préalablement trié de manière décroissante), on obtient en sortie | | Lorsque le tableau est déjà triée, on obtient en sortie | 
|**Courbes** | ![exectime](./Graphs/insertion/insertTousTableaux.png)  | ![exectime](./Graphs/insertion/insertTousTableaux.png) | ![exectime](./Graphs/insertion/insertTousTableaux.png)

Conclusion : Au cours de nos analyses et avec (un peu) l'aide du cours de M.ZIMMERMANN, on a pu remarquer une propriété intéressante du
tri insertion. En effet, son efficacité est meilleur que les deux autres algortithmes si le tableau initial possède un certain ordre.
L'algorithme tirera en effet parti de tout ordre partiel présent dans le tableau. Avec sa simplicité d'implantation,
cette propriété le promu tout naturellement pour "finir le travail" de méthodes plus lourdes comme le tri rapide ou le tri fusion.


##Tri Fusion

**Complexité** | **Pire des cas** | **Moyen** | **Meilleur des cas** | 
|---|---|---|---|---|
| **Notes** | Dans le pire cas, lorsque le tableau est trié à l'envers (tableau préalablement trié de manière décroissante), on obtient en sortie | | Lorsque le tableau est déjà triée, on obtient en sortie | 
|**Courbes** | ![exectime](./Graphs/fusion/fusionTousTableaux.png) | ![exectime](./Graphs/fusion/fusionTousTableaux.png) | ![exectime](./Graphs/fusion/fusionTousTableaux.png) |


##Tri Rapide

**Complexité** | **Pire des cas** | **Moyen** | **Meilleur des cas** | 
|---|---|---|---|---|
| **Notes** | Dans le pire cas, lorsque le tableau est trié à l'envers (tableau préalablement trié de manière décroissante), on obtient en sortie | | Lorsque le tableau est déjà triée, on obtient en sortie | 
|**Courbes** | ![exectime](./Graphs/rapide/rapideTousTableaux.png) | ![exectime](./Graphs/rapide/rapideTousTableaux.png) | ![exectime](./Graphs/rapide/rapideTousTableaux.png) |


Utilisation : `./a.exe -n fonction`

## Ajouts possibles

Pour faciliter l'automatisation et la rapidité des tests nous aurions pu mettre en place un système d'arguments en ligne de commande pour selectionner le tri et le tableau voulant être testé. Nous n'avons pas eu le temps de comparer les différentes comparaisons et écritures. Tester d'autres algorithmes peut être interéssant (tri à bulles...). Nous avons mis en place 3 type de tableaux mais il aurait été possible de trouver d'autres types de tableaux plus particuliers.

Plan du futur compte rendu :

Introduction

Efficacité d'un programme

Nombre d'opérations d'un algorithme

Complexité d'un algorithme

Complexité et temps de calcul

Notation O()
Conclusion

## Conclusion Finale

Ce qu'il faut retenir ici, c'est qu'aucun des trois algortithmes n'est foncièrement meilleur qu'un autre. En effet, selon la situation,
la problèmatique, ou encore les enjeux derrière le programme, un des trois algorithmes sera à privilégier. Il faut alors avant de se
précipiter sur un algorithme de tri, étudier son comportement sous différents angles comme on l'a fait. Mon tableau d'entré est-il déjà trié
ou partiellement trié dans l'ordre croissant ? Est-il trié dans l'ordre décroissant ? Est-il trié aléatoirement ? Quelle taille  possède t-il ?
Combien de temps puis-je me permettre ? Et de mémoire ? Est-ce un petit tableau, un grand ou un moyen ? Dans ce cas, il faudra définir le
terme "grand", "petit" et moyen en fonction du contexte et de la problématique donnée !
