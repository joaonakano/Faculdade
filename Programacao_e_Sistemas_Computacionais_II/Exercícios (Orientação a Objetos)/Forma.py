from abc import ABC, abstractmethod

class Forma(ABC):
    @abstractmethod
    def calcular_area(self):
        pass

class Retangulo(Forma):
    def __init__(self):
        super().__init__()

    def calcular_area(self, largura, comprimento):
        return largura * comprimento

class Circulo(Forma):
    def __init__(self):
        super().__init__()

    def calcular_area(self, raio):
        return 3.14 * (raio * raio)
