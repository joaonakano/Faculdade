class Personagem:
    def __init__(self, nome):
        self._poderes = []
        self._nome = nome
        pass

    def verifica_poderes(self, classe):
        for func in dir(classe):
            if callable(getattr(classe, func)) and not func.startswith("__") and not func in ("verifica_poderes"):
                self._poderes.append(func)


class Mago(Personagem):
    def __init__(self, nome):
        super().__init__(nome)
    
    def bola(self):
        print(f"{self._nome} soltou uma bola de fogo!")


class Guerreiro(Personagem):
    def __init__(self, nome):
        super().__init__(nome)

    def martelar(self):
        print(f"{self._nome} martelou!")


class Arqueiro(Personagem):
    def __init__(self, nome):
        super().__init__(nome)
    
    def disparar_flecha(self):
        print(f"{self._nome} disparou uma flecha!")