from Imprimivel import Imprimivel

class Veiculo:
    def __init__(self, tipo, velocidade, descritivo=None):
        self._tipo = tipo
        self._velocidade = velocidade
        self._descritivo = descritivo

    def descricao(self, texto_descritivo=None):
        if self._descritivo != None:
            print(self._descritivo)
        else:
            if texto_descritivo == None:
                print("É um veículo.")
            else:
                print(texto_descritivo)
                self._descritivo = texto_descritivo

    def acelerar(self):
        print(f"Velocidade antes: {self._velocidade}km/h ", end="")
        self._velocidade += 50
        print(f"Velocidade acelerada: {self._velocidade}km/h")


class Carro(Veiculo, Imprimivel):
    def __init__(self, tipo, velocidade):
        super().__init__(tipo, velocidade)

    def imprimir(self, marca, modelo):
        print(f"Marca: {marca}, Modelo: {modelo}, Tipo: {self._tipo}, Velocidade: {self._velocidade}, Descrição: {self._descritivo}")

class Moto(Veiculo, Imprimivel):
    def __init__(self, tipo, velocidade):
        super().__init__(tipo, velocidade)

    def imprimir(self, marca, modelo):
        print(f"Marca: {marca}, Modelo: {modelo}, Tipo: {self._tipo}, Velocidade: {self._velocidade}, Descrição: {self._descritivo}")