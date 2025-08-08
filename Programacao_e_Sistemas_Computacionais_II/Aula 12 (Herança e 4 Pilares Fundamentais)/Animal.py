class Animal:
    def __init__(self, nome, especie):
        self._nome = nome
        self._especie = especie

    def emitirSom(self):
        print(f"{self._nome} fez um som!")
