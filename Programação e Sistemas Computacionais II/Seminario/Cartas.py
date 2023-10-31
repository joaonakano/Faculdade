import random

class Carta:
    def __init__(self):
        self._carta = None
        self._numero_da_carta = None
        self._numero_aleatorio = None
        self._cartas = [2, 3, 4, 5, 6, 7, 8, 9]
        self._naipes = ["HEARTS", "SPADES", "CLUBS", "DIAMONDS"]

    def numeroAleatorio(self):
        self._numero_aleatorio = random.randint(0, len(self._cartas) - 1)
        return self._numero_aleatorio

    def criarCarta(self):
        self._numero_da_carta = self._cartas[self.numeroAleatorio()]
        self._carta = f"""
 _____
|{self._numero_da_carta} .  |
| /.\ |
|(_._)|
|  |  |
|____{self._numero_da_carta}|"""
        print(self._carta)