# NanoTekSpice

NanoTekSpice est un simulateur de circuits logiques écrit en C++. Il permet de charger des fichiers de configuration de composants logiques, de simuler leur comportement et d'intéragir avec eux via une interface en ligne de commande.

## Fonctionnalités

- Simulation de circuits logiques combinatoires et séquentiels
- Prise en charge de nombreux composants (portes logiques, flip-flops, entrées/sorties, etc.)
- Chargement de circuits à partir de fichiers `.nts`
- Interface en ligne de commande pour manipuler et observer les circuits
- Système de commandes pour simuler, afficher, modifier les entrées, etc.

## Structure du projet

- `src/` : Code source principal
    - `Components/` : Implémentation des composants logiques
    - `Pins/` : Gestion des broches d'entrée/sortie
    - `Core/` : Noyau de la simulation et parsing des fichiers
    - `Commands/` : Gestion des commandes utilisateur
    - `Factories/` : Factories pour la création des composants et pins
    - `Error/` : Gestion des erreurs
- `config/` : Fichiers de configuration des composants (`.nts`)
- `tests/` : Scripts et fichiers de tests

## Compilation

Pour compiler le projet :

```sh
make
```
L'exécutable sera généré sous le nom nanotekspice.

## Utilisation

### Exécuter le projet
Lancez le simulateur avec un fichier de circuit :
```sh
./nanotekspice circuit.nts
```
Une fois lancé, vous pouvez utiliser différentes commandes pour intéragir avec le circuit (simulation, affichage, modification des entrées, etc.).

> [!INFO]
> Vous trouverez la documentation sur comment créer un fichier de configuration [ici](/DOCUMENTATION.md).

## Auteurs

|                                                                                                                                          |                                                                                                                                    |
|:----------------------------------------------------------------------------------------------------------------------------------------:|:----------------------------------------------------------------------------------------------------------------------------------:|
| <a href="https://github.com/eliestroun14">**Elie STROUN** <br><img src="https://avatars.githubusercontent.com/u/146193362?s=128&v4"></a> | <a href="https://github.com/nl1x">**Nathan JEANNOT** <br><img src="https://avatars.githubusercontent.com/u/83085376?s=128&v4"></a> |

## Licence
Projet réalisé dans le cadre de l'Epitech.
