# 1 - Crie uma classe chamada Carro com atributos encapsulados (_modelo e _ano) e métodos para obter e definir esses atributos.
from Carro import Carros
c1 = Carros("Chevette", 1984)
print("Exercício 1 (modelo e carro):", c1._Carros__modelo, c1._Carros__ano)

# 2 - Modifique a classe Carro do exercício anterior para usar atributos privados (__modelo e __ano) e métodos de acesso para obter e definir esses atributos.
c1.ano = 1500
c1.modelo = "Fusca"
print("Exercício 2 (modelo e carro):", c1.modelo, c1.ano)

# 3 - Crie uma classe Veiculo com atributos como tipo e velocidade e, em seguida, crie classes Carro e Moto que herdem de Veiculo.
from Veiculo import Carro, Moto, Veiculo
m1 = Moto("Off-Road", 500)
c2 = Carro("Esportiva", 500)
print("Exercício 3 (moto):", m1._tipo, m1._velocidade)
print("Exercício 3 (carro):", c2._tipo, c2._velocidade)

# 4 - Na classe Veiculo, crie um método chamado descricao() que imprima uma descrição básica do veículo. Sobrescreva esse método nas classes Carro e Moto para fornecer descrições específicas para cada tipo de veículo.
Veiculo.descricao("cheetos")
m1.descricao("moto")
c2.descricao("carro")
