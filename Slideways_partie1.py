import os

lettre = {'A' : 0, 'B' : 1, 'C' : 2, 'D' : 3}
chiffre = {'4' : 0, '3' : 1, '2' : 2, '1' : 3}
plateau = [[0, 0, 0, 0],
           [0, 0, 0, 0],
           [0, 0, 0, 0],
           [0, 0, 0, 0]]
ligne = [4, 3, 2, 1, " "]
win = False


def afficher(plateau):
    n = 0
    for i in range(4):
        print(ligne[n], end=" ")
        n += 1
        for j in range(4):
            if plateau[i][j] == 0:
                plateau[i][j] = "_"
            if plateau[i][j] == 1:
                plateau[i][j] = "X"
            if plateau[i][j] == 2:
                plateau[i][j] = "O"
            print(plateau[i][j], end=" ")
        print()
    print("  A B C D")


def verif_ligne(plateau):
    win = False
    for i in range(4):
        if plateau[i][0] and plateau[i][1] and plateau[i][2] and plateau[i][3] == 1:
            win = True
        if plateau[i][0] and plateau[i][1] and plateau[i][2] and plateau[i][3] == 2:
            win = True
        if win:
            print("C'est gagné !")
            return win


def verif_colonne(plateau):
    win = False
    for i in range(4):
        if plateau[0][i] and plateau[1][i] and plateau[2][i] and plateau[3][i] == 1:
            win = True
        if plateau[0][i] and plateau[1][i] and plateau[2][i] and plateau[3][i] == 2:
            win = True
        if win:
            print("C'est gagné !")
            return win


def verif_diagonale(plateau):
    win = False
    if plateau[0][3] and plateau[1][2] and plateau[2][1] and plateau[3][0] == 1:
        win = True
    if plateau[0][3] and plateau[1][2] and plateau[2][1] and plateau[3][0] == 2:
        win = True
    if plateau[0][0] and plateau[1][1] and plateau[2][2] and plateau[3][3] == 1:
        win = True
    if plateau[0][0] and plateau[1][1] and plateau[2][2] and plateau[3][3] == 2:
        win = True
    if win:
        print("C'est gagné !")
        return win


def ajoute_coup(coup, pion):
    if plateau[chiffre[coup[1]]][lettre[coup[0]]] == "_":
        plateau[chiffre[coup[1]]][lettre[coup[0]]] = pion


def boucle_jeu():
    for i in range(8):
        afficher(plateau)
        os.system('cls')
        print(" ")
        print("Au tour du joueur 1.")
        coup = input("Entrez votre coup: ")
        ajoute_coup(coup, 1)
        verif_ligne(plateau)
        verif_colonne(plateau)
        """verif_diagonale(plateau)"""

        afficher(plateau)
        os.system('cls')
        print(" ")
        print("Au tour du joueur 2.")
        coup = input("Entrez votre coup: ")
        ajoute_coup(coup, 2)
        verif_ligne(plateau)
        verif_colonne(plateau)
        """verif_diagonale(plateau)"""


boucle_jeu()
