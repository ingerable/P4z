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


L'objectif de cet article sera d'estimer grossièrement la célérité d'un algorithme avant même de le lancer. Il s'agit du calcul de la complexité en temps d'un algorithme.
Nous travaillerons avec le langage C et le compilateur gcc.

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

## [Unix] Vérification de la mémoire utilisée

Linux, encore une fois propose une commande bien utile. Il s'agit de la commande base "ulimit" qui permet de fixer une limite pour certaines ressources. Ces limites seront appliquées à tout programme lancé à partir de ce shell.

Pour fixer une limite globale à l'utilisation de la mémoire :

- `ulimit -v taille_memoire`

où taille_memoire est une valeur en kilo-octets. Par exemple pour limiter à 16 Mo :

- `ulimit -v 16000`

Une erreur sera affichée si la mémoire du programme est insuffisante. On peut en effet se retrouver face à une erreur d'allocation, ou de segmentation.
Une autre option de ulimit `-s` consiste à fixer une limite pour la taille de la pile. Très utile lorsque le champs d'application du programme se concentre sur la récursivité.

- `ulimit -s taille_pile`

où taille_pile est en kilo-octets.
Enfin, l'option `-a` nous permet d'afficher toutes les limites qu'il est possible de fixer.

## Utilisation de 'diff' pour comparer des résultats

Encore une commande Linux qui nous sera très utile, il s'agit de `diff` :
En effet, le potentiel de `diff` se révelera lorsque l'on voudra comparer les résultats de deux algorithmes différents.
La commande ci-dessous affichera toutes les différences trouvées entre le fichier1 et le fichier2 :

- diff fichier1 fichier2

L'option `-q` de diff permet de cacher les différences, et nous indique seulement par un booléen si deux fichiers sont différents :

- diff -q fichier1 fichier2


L'option `-w` nous permet d'ignorer les différents qui sont des caractères d'espacement comme ' ', '\t', '\n' :

- diff -w fichier1 fichier2


On peut alors tester si les résultats générés par un programme correspondent bien aux résultats attendus. La commande suivante en découle tout naturellement :

- diff -q -w sortie_attendue votre_sortie

D'ailleurs, je soupçonne **très fortement** qu'une commande similaire ait été utilisée lors des TPs du module de graphes l'an dernier ;-)


## Etude de cas

### Problématique : La distance entre deux éléments adjacent interfère t-elle dans le temps d'exécution du tri ?

Nous avons un tableaux contenant des éléments de type long long unsigned int. La distance entre chaque élement adjacent est petite. Par exemple, nous avons : [0,1,0,1,0,1]. Nous avons maintenant un autre tableau, de même taille et la distance entre chaque élément est significative : [1, 1000000000, 1, 1000000000, 1, 1000000000].
La dernière étape est de trier ces deux tableaux avec le tri par insertion, le tri fusion ou le tri rapide au choix.

Est-il possible que le temps d'éxecution soit plus important pour le second tableau ?

### Eléments de réponse

Les algorithmes de tris tels que le tri par insertion, le tri rapide et le tri fusion sont appelés tris de comparaisons car ils trient les éléments sur leur ordre relatif par rapport aux autres éléments. Pas sur leur valeurs absolues. Du point de vu du tri rapide, tri fusion, ou du tri insertion les tableaux suivant sont parfaitement identiques :

[0, 1, 0, 1, 0] et [0, 1000000, 0, 1000000, 0].

En effet, il n'y a aucun moyen de savoir que 1000000 "est plus grand" que 1. Le nombre total d'opérations effectuées pour trier ces tableaux seront parfaitement identiques d'un tableau à l'autre. En fait, si l'on trie chacun de ces tableaux avec ces algorithmes de tri.
En fait, si l'on trie chaque tableau avec ces algorithmes et que l'on regarde les éléments se déplacer, on observera que les mouvements exécutés sont les mêmes.

Si l'on se place dans le contexte de trier des entiers qui correspondent à un seul mot machine, alors le coût d'un déplacement est indépendant de la valeur numérique stockée dans ce mot machine. Le coût de comparaison de ces éléments est probablement aussi le même. Il n'y a donc absolument aucune différence dans le temps nécessaire pour trier ces tableaux avec ces algorithmes. En témoigne la figure suivante :

<img src="Graphs/insertionProcheEtendue.png" alt="procheEtendu" >


S'il y a une différence, cela signifie que le processeur que vous utilisez peut comparer ou déplacer des nombres de tailles différentes dans des quantités de temps différentes. Pour autant que je sache, il n'existe pas d'architectures de processeurs qui le fassent.

Cependant, les algorithmes de tri comme le tri de comptage (counting sort) ou le tri par base (tri radix), qui n'appartiennent pas à la famille des tris de comparaison et dépendent de la taille des entiers que l'on traite pourraient prendre plus de temps pour trier ces tableaux. En effet, car ils travaillent soit un chiffre à la fois ou en les distribuant dans un tableau dont la taille dépend de la taille des nombres en questions. Dans ces cas, il est possible d'observer une différence entre les temps d'exécutions, à condition que l'algorithme employé ait bien été mis en œuvre.

## Un peu d'assembleur

Afin de comprendre tous les tenants et les aboutissants d'un programme, il est existe une option `-S` permettant d'afficher le code en assembleur généré par le compilateur. On peut donc observer ce que le microprocesseur va exécuter à chaque boucle. Exemple d'utilisation : `gcc monProgramme.c -S -O2`.

Les quatre registres de travail sont principalement utilisés pour stocker des résultats :

- **EAX** : registre accumulateur. Utilisé pour les opérations arithmétiques et le stockage de la valeur de retour des appels systèmes.
- **EDX** : registre de données (data register). Utilisé pour les opérations arithmétiques et les opérations d'entrée/sortie.
- **ECX** : registre compteur (counter register)
- **EBX** : registre de base (base register). Utilisé comme pointeur de donnée.

Prenons le code c du tri insertion :

```c
#include <stdio.h>

int main(int argc, char * argv []) {
  int A[5] = {19, 10, 8, 17, 9};
  int N = 5;
  int cmpr=0;
  int writings=0;
  for(int i=1;i<N;i++)
  {
    long key = A[i];
    long j = i;
    while(j>0 && A[j-1]>key)
    {
      A[j]=A[j-1];
      j=j-1;
      writings+=1;
    }
    A[j]=key;
    cmpr+=1;
  }
}
```

Code assembleur généré sans l'option O2 :

```assembly
.file	"insert.c"
.text
.globl	main
.type	main, @function
main:
.LFB0:
.cfi_startproc
pushq	%rbp
.cfi_def_cfa_offset 16
.cfi_offset 6, -16
movq	%rsp, %rbp
.cfi_def_cfa_register 6
movl	%edi, -68(%rbp)
movq	%rsi, -80(%rbp)
movl	$19, -64(%rbp)
movl	$10, -60(%rbp)
movl	$8, -56(%rbp)
movl	$17, -52(%rbp)
movl	$9, -48(%rbp)
movl	$5, -28(%rbp)
movl	$0, -4(%rbp)
movl	$0, -8(%rbp)
movl	$1, -12(%rbp)
jmp	.L2
.L6:
movl	-12(%rbp), %eax
cltq
movl	-64(%rbp,%rax,4), %eax
cltq
movq	%rax, -40(%rbp)
movl	-12(%rbp), %eax
cltq
movq	%rax, -24(%rbp)
jmp	.L3
.L5:
movq	-24(%rbp), %rax
subq	$1, %rax
movl	-64(%rbp,%rax,4), %edx
movq	-24(%rbp), %rax
movl	%edx, -64(%rbp,%rax,4)
subq	$1, -24(%rbp)
addl	$1, -8(%rbp)
.L3:
cmpq	$0, -24(%rbp)
jle	.L4
movq	-24(%rbp), %rax
subq	$1, %rax
movl	-64(%rbp,%rax,4), %eax
cltq
cmpq	-40(%rbp), %rax
jg	.L5
.L4:
movq	-40(%rbp), %rax
movl	%eax, %edx
movq	-24(%rbp), %rax
movl	%edx, -64(%rbp,%rax,4)
addl	$1, -4(%rbp)
addl	$1, -12(%rbp)
.L2:
movl	-12(%rbp), %eax
cmpl	-28(%rbp), %eax
jl	.L6
movl	$0, %eax
popq	%rbp
.cfi_def_cfa 7, 8
ret
.cfi_endproc
.LFE0:
.size	main, .-main
.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
.section	.note.GNU-stack,"",@progbits
```

Code assembleur généré avec l'option O2 :

```assembly
.file	"insert.c"
.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
.section	.text.startup,"ax",@progbits
.LHOTB0:
.p2align 4,,15
.globl	main
.type	main, @function
main:
.LFB3:
.cfi_startproc
xorl	%eax, %eax
ret
.cfi_endproc
.LFE3:
.size	main, .-main
.section	.text.unlikely
.LCOLDE0:
.section	.text.startup
.LHOTE0:
.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
.section	.note.GNU-stack,"",@progbits
```

Dans le cas du second programme, le compilateur a détecté qu'il était plus efficace de changer le comportement de notre programme initial. En effet, nous observons que cela ne correspond pas à ce que l'on avait écrit en ométtant l'option O2. Néanmoins, notre programme fonctionne correctement. Le compilateur, lorsque les options d'optimisation sont activées peut prendre certaines libertés et réaliser un certain nombre de manipulations sur notre programme lors de la transformation en code exécutable. Vous l'aurez compris, cela nous complexifie grandement la tâche dans notre quête de prédiction du temps d'exécution.

Premièrement, il faut garder à l'idée que les temps d'exécution des différentes instructions du micro-processeur ne sont pas tous les mêmes.
La fréquence d'un microprocesseur est définit par le nombre de cycles qu'il est capable d'exécuter en une seconde. Un microprocesseur ayant une fréquence de 1Ghz peut dont prétendre exécuter un milliard de cycles par seconde. A chaque cycle, le processeur exécute une phase de l'exécution d'une instruction, telle que : la **lire en mémoire**, la **décoder**, **écrire le résultat**, etc. Les processeurs actuels ont la capacité de manipuler diverses instructions en même temps, donc exécuter lors du même cycle, une phase de chacune des instructions qu'il est en train de traiter. Pour illustrer ce propos, le compilateur est apte à lire en mémoire l'instruction suivante au même moment que l'écriture du résultat de l'instruction courante !

Souvent le processeur nécessite plusieurs cycles processeurs pour exécuter entièrement une instruction, mais sur un certain nombre d'instructions consécutives, dont une partie de l'exécution est faite en parallèle, le temps moyen d'exécution d'une instruction peut être bien inférieur, et ne faire qu'un cycle, parfois même moins, mais parfois bien plus, selon le type d'instructions.

En conclusion, donner une estimation précise du temps d'éxecution d'un programme est en fait très compliqué : On pourrait penser qu'il suffit de compter le nombre d'instructions, mais cela est inexacte, toute simplement car différentes instructions demandent un temps différent. Ensuite, comme on a pu le constater le compilateur peut bouleverser le comportement de notre programme et par conséquent nous ne pouvons préméditer le nombre exacte d'instructions de notre programme après compilation.

En somme, le temps d'exécution des instructions dépend de nombreux facteurs, et on ne peut donner que des approximations. Nous pouvons néanmoins Pour se faire une idée des temps d'exécutions de différents types d'instruction, le plus simple reste donc l'expérimentation.


## Notion de complexité

Quelques exemples permettant d'estimer la complexité d'un algorithme.

```bash
total = 0
Pour compteur1 allant de 1 à N
   Pour compteur2 allant de 1 à N
      Pour compteur3 allant de 1 à N
         total = total + 1
```

Dans le pseudo-code présenté ci-dessus, trois boucles sont imbriquées, chacune allant jusqu'à N, soit **N*N*N** exécutions de la boucle la plus interne, donc une complexité de O(N<sup>3</sup>). Pour illustrer mon propos, si N est égal à 1000, la boucle la plus interne bouclera 1 milliard de fois.

```bash
total = 0
Pour compteur1 allant de 1 à N
   Pour compteur2 allant de 1 à N
     total = total + 1
Pour compteur3 allant de 1 à N
   total = total + 1
```

Ici, la boucle interne de la première partie va s'exécuter N<sup>2</sup> fois. La boucle de la deuxième partie va s'exécuter N fois. Une intuition naïve nous laisserait penser que la complexité est en O(N<sup>2</sup> + N). Cependant, pour une valeur très grande de N, N devient négligeable par rapport à N<sup>2</sup>, et le temps d'exécution approximativement proportionnel à N<sup>2</sup>. La complexité de l'algorithme est donc déterminée : **O(N<sup>2</sup>)**.

## Complexité en fonction de plusieurs variables

Nous testons maintenant des algorithmes en fonction de plusieurs variables. Ici, il s'agit des variables **N** et **P** :

```bash
total = 0
Pour compteur1 allant de 1 à N
   Pour compteur2 allant de 1 à P
      total = total + 1
```

La complexité est simple à determiner. En effet, il y a N*P itérations, la complexité en découle tout naturellement :
**O(N*P)**.

```bash
total = 0
Pour compteur1 allant de 1 à N * 2
   Pour compteur2 allant de 1 à N
     total = total + 1
Pour compteur3 allant de 1 à P
   total = total + 1
Pour compteur4 allant de 1 à 10
   total = total + 1
```

Le nombre d'itérations est égal à : **2*N2 + P + 10**. Comme précédemment, selon les valeurs de N ou P, 10 peut devenir négligeable, et n'est donc pas nécessaire à notre calcul de complexité. Par analogie, la constante multiplicative 2 est abandonnée.
Une fausse idée serait de penser que pour une certaine valeur de N, P devient négligeable devant O(N<sup>2</sup>). Cependant, on ne peut conjecturer sur la valeur de P, qui peut être bien plus grand que O(N<sup>2</sup>). On garde donc P dans la complexité obtenue : **O(N<sup>2</sup> + P)**.

```bash
total = 0
donnees est un tableau de N valeurs entières
Pour compteur1 allant de 1 à N
   valeur = donnee[compteur1]
   Pour compteur2 allant de 1 à valeur
      total = total + 1
```

Le nombre d'itérations de l'algorithme résulte du contenu de chacune des cases du tableau. Comme il nous est impossible de prédir la complexité pour chaque valeur du tableau, il nous faut déterminer la complexité dans le pire des cas. Une solution est de fixer une nouvelle variable P, représentant la valeur maximale pouvant être stockée dans le tableau. Dans le cas d'un tableau de **int** l'intervalle est : `–2,147,483,648` à `2,147,483,647`. Une fois cette variable specifiée, la complexité est alors être déterminée : **O(N*P)**.

## Résultats et analyses

Pour commencer, nous avons testé le temps d'exécution des 3 tris sur un tableau de valeurs générées aléatoirement et de type `long long unsigned int`
de taille variable.

![exectime](./Graphs/3tri/Exectime.png)

On remarque que le temps d'exécution du tri par insertion augmente proportionnellement
à la taille du tableau tandis que le temps d'execution des 2 autres tri est constant et très faible.

![memory](./Graphs/3tri/insertionFusionRapideMemoryCourbes.png)

 Néanmoins on peut voir que le tri fusion est celui qui utilise le plus de mémoire probablement à cause de la génération des sous tableaux puis de leurs fusions.
 En effet, le tri fusion étant implémenté de manière récursive, il sollicite énormément la pile.


![exectime](./Graphs/3tri/Exectime3Croissant.png)

Maintenant, on analyse le temps d'éxecution pour des tableaux qui ont des valeurs triées par ordre croissant.
On constate que le temps d'éxecution du tri rapide augmente proportionellement pour des tableaux triées par ordre croissant. Le tri rapide n'est donc pas efficace pour des tableaux triés par ordre croissant.


Jetons un coup d'oeil à la consommation de mémoire pour voir si elle aussi a augmenté pour le tri rapide.

![exectime](./Graphs/3tri/Memory3Croissant.png)

On voit que le tri rapide est celui qui utilise le plus de mémoire pour un tableau composé de valeurs croissantes.Le pivot étant le dernier élément du tableaux. Dans le cas du tableau croissant le pivot sera toujours l'élement le plus grand du sous tableau.

### Option -O2

Comme expliqué precedemment l'option -O permettrait de gagner du temps d'execution/compilation/ ou de réduire l'utilisation de mémoire. On peut voir les différents **flags** d'optimisation :

![flags](./compteRenduImages/optimizationFlag.png)

Nous allons tester le flag -O2 pour voir si nous le temps d'éxecution est réduit et si oui si la réduction du temps d'execution est vraiment notable. Nous avons donc génerer 2 executables l'un avec
le flag d'optimisation l'autre non. Nous avons choisi de tester le flag sur le tri insertion dans le pire et meilleur des cas, c'est à dire pour un tableau trié croissant et un tableau trié décroissants, résultat :

**Tableau decroissant - pire des cas** | **Tableau croissant - meilleur des cas** |
|---|---|---|---|---|
|![exectime](./Graphs/optionOptimisation/insertion/optionOptimisationDecroissant.png) | ![exectime](./Graphs/optionOptimisation/insertion/optionOptimisationInsertionCroissant.png) |


On voit clairement que pour le pire des cas la différence est très importante, on peut aussi noter que la courbe du temps d'éxecution de l'executable optimisé augmente moins vite que l'executable non optimisé.
Pareil pour le meilleur des cas mais la différence est plus modérée, néanmoins le flag d'optimisation est très efficace et à ne pas négliger. Lorsque l'on utilise un flag d'optimisation il faut avoir un but précis, les flags optimise un aspect spécifique (temps d'éxecution / mémoire).

## Tri Insertion

**Complexité** | **Pire des cas Θ(n<sup>2</sup>)** | **Moyenne  Θ(n<sup>2</sup>) ** | **Meilleur des cas $`Θ(n-1)`$ comparaisons et $`Θ(n)`$ affectations** |
|---|---|---|---|---|
| **Notes** | Dans le pire cas, lorsque le tableau est trié à l'envers (tableau préalablement trié de manière décroissante), on obtient en sortie | | Lorsque le tableau est déjà triée, on obtient en sortie  |
|**Courbes** | ![exectime](./Graphs/insertion/insertTousTableaux.png) |

Conclusion : Au cours de nos analyses et avec (un peu) l'aide du cours de M.ZIMMERMANN, on a pu remarquer une propriété intéressante du tri insertion. En effet, son efficacité est meilleur que les deux autres algortithmes si le tableau initial possède un certain ordre.
L'algorithme tirera en effet parti de tout ordre partiel présent dans le tableau. Avec sa simplicité d'implantation, cette propriété le promu tout naturellement pour "finir le travail" de méthodes plus lourdes comme le tri rapide ou le tri fusion.


## Tri Fusion

**Complexité** | **Pire des cas** | **Moyenne $`Θ(n*log(n))`$** | **Meilleur des cas** |
|---|---|---|---|---|
| **Notes** | Dans le pire cas, lorsque le tableau est trié à l'envers (tableau préalablement trié de manière décroissante), on obtient en sortie | | Lorsque le tableau est déjà triée, on obtient en sortie |
|**Courbes** | ![exectime](./Graphs/fusion/fusionTousTableaux.png) |


## Tri Rapide

**Complexité** | **Pire des cas $`Θ(n^2)`$** | **Moyenne $`Θ(n*log(n))`$** | **Meilleur des cas** |
|---|---|---|---|---|
| **Notes** | Dans le pire cas, lorsque le tableau est trié à l'envers (tableau préalablement trié de manière décroissante), on obtient en sortie | | Lorsque le tableau est déjà triée, on obtient en sortie |
|**Courbes** | ![exectime](./Graphs/rapide/rapideTousTableaux.png) |


## Conclusion Finale

Le temps d'exécution d'un programme est dépendant de nombreux paramètres tels que :

- Du type et de la fréquence du microprocesseur utilisé.
- Du langage utilisé et du compilateur choisi, ainsi que de ses réglages.
- Des données d'entrée
- De la complexité en temps de l'algorithme

Ces nombreux obstacles font qu'on ne peut obtenir qu'une approximation grossière du temps d'exécution. Le calcul de la complexité en temps nous pourvoit néanmoins un bon moyen pour comparer plusieurs algorithmes entre eux, avant même de les avoir implantés et testés.

Ce qu'il faut retenir ici, c'est qu'aucun des trois algorithmes n'est foncièrement meilleur qu'un autre. En effet, selon la situation,
la problèmatique, ou encore les enjeux derrière le programme, un des trois algorithmes sera à privilégier. Il faut alors avant de se
précipiter sur un algorithme de tri, étudier son comportement sous différents angles comme on l'a fait. Mon tableau d'entré est-il déjà trié
ou partiellement trié dans l'ordre croissant ? Est-il trié dans l'ordre décroissant ? Est-il trié aléatoirement ? Quelle taille  possède t-il ?
Combien de temps puis-je me permettre ? Et de mémoire ? Est-ce un petit tableau, un grand ou un moyen ? Dans ce cas, il faudra définir le terme "grand", "petit" et moyen en fonction du contexte et de la problématique donnée !
