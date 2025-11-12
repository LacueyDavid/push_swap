# push_swap (42)

![Push swap](/pushswap.png "pushswap.png")

## Description

Ce projet est une implémentation de l'exercice "push_swap" de l'école 42.
Le but est d'écrire un programme capable de trier une série d'entiers en utilisant
deux piles (stack A et stack B) et un jeu d'opérations limitées. Le programme
doit afficher la suite d'opérations qui permet de trier la pile A en ordre
croissant en minimisant le nombre d'opérations.

Ce dépôt contient une solution écrite en C, basée sur des listes chaînées pour
représenter les piles, ainsi que plusieurs stratégies pour gérer des tailles
différentes d'entrées.

## Règles (rappel)

- Entrée : une série d'entiers donnés en arguments de la ligne de commande.
- Interdiction d'utiliser des fonctions de tri externes : il faut trier en
  n'utilisant que les opérations autorisées.
- Opérations autorisées :
  - sa, sb, ss : swap (échanger 2 éléments en haut d'une pile)
  - pa, pb : push (déplacer le haut d'une pile vers l'autre)
  - ra, rb, rr : rotate (déplacer le haut d'une pile en bas)
  - rra, rrb, rrr : reverse rotate (déplacer le bas d'une pile en haut)

Consultez les fichiers sources (notamment `operations.c` et `operations.h`) pour
la liste et l'implémentation exacte des opérations supportées.

## Compilation

Le projet inclut un `Makefile`. Pour compiler l'exécutable principal :

```sh
make
```

Cela devrait générer l'exécutable `push_swap` dans la racine du dépôt.

Pour nettoyer les fichiers objets et l'exécutable :

```sh
make clean
make fclean
```

## Utilisation

Exemples d'utilisation :

```sh
# trier trois nombres
./push_swap 2 1 3

# trier plusieurs nombres
./push_swap 4 67 3 87 23 0
```

Le programme affiche la liste des opérations (une par ligne) à appliquer pour
obtenir la pile A triée.

## Exemples

Entrée : `./push_swap 2 1 3`

Sortie possible :

```
sa
```

Un exemple plus complet peut produire une suite d'opérations mêlant `pb`,
`ra`, `pa`, etc., en fonction de la stratégie utilisée.

## Stratégie / Algorithme

L'implémentation repose sur :

- une représentation des piles avec des listes chaînées (`linked_list.c`),
- des opérations atomiques définies dans `operations.c` / `operations.h`,
- des strategies de tri adaptées à la taille :
  - tri optimal/explicite pour les très petites tailles (2-5 éléments),
  - partitionnement / méthode par "chunks" ou approche radicielle pour
    améliorer le nombre d'opérations sur de plus grandes entrées.

Les détails de la stratégie sont dans les fichiers `push_swap.c`,
`push_swap_bis.c` et `push_swap_2.c` : vous y trouverez la logique qui
partitionne la pile et choisit les mouvements.

Remarque : l'objectif du projet est d'optimiser le nombre d'opérations, on
peut donc expérimenter plusieurs variantes (taille des chunks, heuristiques
de rotation, etc.).

## Tests et utilitaires

Le dépôt contient un dossier `test/` et un générateur d'entrées aléatoires
(`random_input_generator/`) pour évaluer la qualité de la solution.

Pour générer des entrées et tester :

```sh
# exemple : exécuter le binaire de test si présent
make
./test/test_push_swap

# ou utiliser le générateur d'entrées
cd random_input_generator && make
./random_input 100  # génère 100 nombres aléatoires
```

Adaptez les commandes selon les cibles définies dans le `Makefile`.

## Organisation du dépôt

- `*.c`, `*.h` : sources et en-têtes du projet
- `linked_list.c/.h` : gestion des piles
- `operations.c/.h` : opérations autorisées (sa, pb, ra, ...)
- `push_swap*.c` : logique principale et stratégies
- `random_input_generator/` : utilitaire pour générer des entrées
- `test/` : benchs / tests unitaires simples

## Bonnes pratiques et vérifications

- Vérifier les doublons et les valeurs non entières en entrée.
- Tester avec des jeux de tailles variées (petits: 2-5, moyens: 100, grands: 500)
  pour comparer le nombre d'opérations.

## Auteurs

- David Lacuey (@LacueyDavid)

## Contributions et améliorations possibles

- Ajouter un `checker` conforme au sujet 42 si ce n'est pas déjà présent.
- Mesurer automatiquement (bench) le nombre d'opérations moyen et afficher
  des statistiques.
- Expérimenter d'autres heuristiques (radix sort bitwise, tri par pivot, etc.)
  pour réduire le nombre d'opérations sur des grands jeux.

## Licence

Voir le fichier `LICENSE` si présent. Sinon, contactez l'auteur pour
clarifier les conditions de réutilisation.
