from Animal import Animal

class Gato(Animal):
    def __init__(self, nome, cor):
        super().__init__(nome, especie="Gato")
        self._cor = cor

    def emitirSom(self):
        print(f"{self._nome} mia. (miau)")

    def arranhar(self):
        print(f"{self._nome} arranha o sofá!")
