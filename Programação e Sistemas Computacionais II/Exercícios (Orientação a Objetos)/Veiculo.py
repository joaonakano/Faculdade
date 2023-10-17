class Veiculo:
    def __init__(self, tipo, velocidade):
        self._tipo = tipo
        self._velocidade = velocidade

    def descricao(self):
        print("É um veículo.")

class Carro(Veiculo):
    def __init__(self, tipo, velocidade):
        super().__init__(tipo, velocidade)

    def descricao(self, texto_descritivo):
        print(f"O veículo é um: {texto_descritivo}.")

class Moto(Veiculo):
    def __init__(self, tipo, velocidade):
        super().__init__(tipo, velocidade)

    def descricao(self, texto_descritivo):
        print(f"O veículo é uma: {texto_descritivo}.")
