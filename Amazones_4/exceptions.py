# INFO-F-106 : Projet d’Informatique: Jeu des amazones (Partie 4)
#
# Nom : Grégoire
# Prénom : Jean-Nicolas
# Matricule : 000446638


class InvalidFormatError(SyntaxError):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)


class InvalidPositionError(Exception):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)


class InvalidActionError(Exception):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
