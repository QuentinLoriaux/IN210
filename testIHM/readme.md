# Test système automatique

Pour les 6 premières tâches, je me suis référé à ce que nous avions réalisé en cours.

## Question 1

Test Setup permet d'initialiser un environnement de manière commune à tous les tests  afin de ne pas avoir à le réécrire dans chaque test. Test Teardown permet de bien fermer tout ce qui a été démarré par Test Setup afin de ne pas saturer la machine qui fait les tests.

## Question 2

Si dans un test l'une des commandes échoue, les suivantes ne sont pas executées et le "close browser" n'est donc pas exécuté. D'où l'intérêt d'utiliser un Test Teardown pour fermer l'onglet : c'est une action à réaliser dans tous les cas, indépendamment de la réussite du test.

## Question 3

Le locator absolu est peu flexible car le changement de la structure générale de la page HTML peut le rendre erroné tandis que le locator relatif peut s'adapter à des changements Par exemple, passer la souris sur une partie de la page pourrait faire afficher des sous-menus ou une rubrique autrement invisible, ce qui modifierait l'arborescence des éléments suivants.

Bilan : on utilise les locator relatifs.

## Question 4

Les mots clés permettent d'abstraire les commandes utilisées pour réaliser les actions décrites. Cela rend les tests bien plus lisibles sémantiquement pour un humain : on lit des phrases françaises plutôt que des instructions d'un language informatique.

## Question 5

Nous avons créé un mot-clé "Rechercher et verifier" qui permet de réaliser l'action de rechercher un type de produit et vérifier son nombre d'occurences. Cela a rendu très simple l'écriture de nos tests (programmation de très haut niveau) et ils sont facilement compréhensibles. Nous avons donc utilisé une approche de type "Keyword".