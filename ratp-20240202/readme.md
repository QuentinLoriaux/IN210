# TP 1 : ratp

Décommenter la ligne 64 de main.c (#define questions) pour avoir les tests correspondants aux questions du TP.

Utiliser make mrproper pour nettoyer
utiliser make doAll pour compiler, executer et générer result.html

## Q1 :
Pour comparer des flottants, il est nécessaire de mettre un seuil de précision car la précision n'est pas infinie (les flottants sont stockés sur un nombre fini de bits) et chaque calcul introduit une petite erreur. On vérifie donc que

|expected-actual| < epsilon

## Q2 :

Il vaut mieux utiliser utiliser un assert_float_equal avec un epsilon inférieur à 0.01 (centime) car computeprice renvoie un prix flottant et la seule chose que l'on peut donc faire, c'est comparer des flottants.

Cependant, l'objectif de ce deuxième test n'est pas précisé alors je ne sais pas exactement ce qui est attendu.

## 3 :

Il y a 2 conditions indépendantes : 
- touriste ou non
- plus vieux que la limite d'âge ou non

Il y a donc 4 possibilités :
- touriste plus vieux
- touriste plus jeune
- pas touriste plus vieux
- pas touriste plus jeune

On a besoin de 4 tests pour couvrir toutes les conditions, et toutes les branches.

On peut aussi ajouter un test pour vérifier qu'une personne ayant pile la limite d'age est traitée comme plus jeune

## Q4 :

Un test est soit réussi, soit échoué. Si plusieurs assertions sont évaluées dans un même test, on ne peut pas savoir laquelle est à l'origine du résultat du test. Il vaut donc mieux faire un test pour chaque cas : les résultats seront directement exploitables.