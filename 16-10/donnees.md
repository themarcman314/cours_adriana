FS (File System): FAT32
FAT8, FAT16, FAT32
FAT : File Allocation Table
microSD de 8Go

Taille initiale d'unité d'allocation: 64Ko (Thomas)
-> "pas bon du tout"

proposition d'organisation:
- 1 répertoire/jour
- plusieurs fichiers de mesure, nommés avec le format suivant:
```
/2026_04_27/LOG00001.CSV
/2026_04_27/LOG00002.CSV
/2026_04_27/LOG00003.CSV
```
- trouver une solution permettant de minimiser le temps de recherche et l'espace utilisé (peu de métadonnées)

- jusqu'à 256 octets par ligne de mesure
