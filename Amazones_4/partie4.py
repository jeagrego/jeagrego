# INFO-F-106 : Projet d’Informatique: Jeu des amazones (Partie 4)
#
# Nom : Grégoire
# Prénom : Jean-Nicolas
# Matricule : 000446638
#
# Ajout d'une interface graphique via PyQt5 et amélioration de l'IA.


from sys import argv
from os.path import isfile
from time import time

from PyQt5.QtWidgets import QApplication

from gui import App
from amazons import Amazons


def check_file():
    if len(argv) < 2:
        print('Usage: python3 partie4.py <path>')
        return False
    if not isfile(argv[1]):
        print(f'{argv[1]} n\'est pas un chemin valide vers un fichier')
        return False
    return True


def main():
    if not check_file():
        return
    game = Amazons(argv[1])
    game.play()


if __name__ == '__main__':
    import random
    random.seed(0xCAFE)
    exit(main())
