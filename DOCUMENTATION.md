# NanoTekSpice - Documentation

Cette documentation porte sur les fichiers de configuration permettant de créer des circuits.

## Configurer un fichier NTS

### Circuit simple
Pour créer un fichier `.nts`, décrivez les composants et leurs connexions selon la syntaxe suivante :

```
chipsets:
input   a
input   b
output  out
and     gate1

links:
a       gate1:1
b       gate1:2
gate1:3 out
```
- La section `chipsets:` liste les composants utilisés (entrées, sorties, portes logiques, etc.).
- La section `links:` définit les connexions entre les pins des composants.
- Les noms et numéros de pins dépendent du composant (voir la documentation des composants pour plus de détails).

> [!INFO]
> Le fichier ci-dessus décrit une porte AND à deux entrées.

Les composants primitifs sont :
- `input`: entrée logique (modifiable par l'utilisateur)
- `output`: sortie logique (affiche le résultat)
- `clock`: signal d'horloge (bascule entre 0 et 1 à chaque étape de simulation)
- `true`: constante logique 1
- `false`: constante logique 0
- `and`, `or`, `xor`, `not`, `nand`, `nor`: portes logiques de base
- `flipflop`, `counter`: composants séquentiels

Vous pouvez utiliser ces composants primitifs pour créer des circuits.

> [!TIP]
> Si vous placez vos circuits dans le dossier `config/`, vous pourrez les utiliser dans d'autres circuits.
> Vous trouverez plusieurs exemples dans ce même dossier.

### Créer un circuit ré-utilisable

Pour créer un circuit ré-utilisable, créez un fichier `.nts` avec la syntaxe suivante :

```
.pins:
1=a:1
2=b:1
3=out:1

.chipsets:
input   a
input   b
output  out
and     gate1

.links:
a       gate1:1
b       gate1:2
gate1:3 out
```
- La section `pins:` liste les pins disponibles du circuit et indique à quel composant du circuit ils sont reliés.
- La section `chipsets:` liste les composants utilisés dans le circuit (entrées, sorties, portes logiques, etc.).
- La section `links:` définit les connexions entre les pins des composants.
