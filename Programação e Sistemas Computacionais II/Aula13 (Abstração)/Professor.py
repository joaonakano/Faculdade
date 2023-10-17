from Pessoa import Pessoa

class Professor(Pessoa):
    def __init__(self, nome):
        super().__init__(nome)
        self._nome = nome

    def saudar(self):
        print(f"Saudação, sou o professor {self._nome}!")
