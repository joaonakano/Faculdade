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
m1 = Moto("Off-Road", 200)
c2 = Carro("Esportiva", 200)
print("Exercício 3 (moto):", m1._tipo, m1._velocidade)
print("Exercício 3 (carro):", c2._tipo, c2._velocidade)

# 4 - Na classe Veiculo, crie um método chamado descricao() que imprima uma descrição básica do veículo. Sobrescreva esse método nas classes Carro e Moto para fornecer descrições específicas para cada tipo de veículo.
print("Exercício 4: ", end="")
m1.descricao()
print("Exercício 4: ", end="")
m1.descricao("É uma Moto")
print("Exercício 4: ", end="")
c2.descricao("É um Carro")

# 5 - Crie uma função chamada acelerar(veiculo) que aceita qualquer objeto Veiculo e aumenta sua velocidade. Teste essa função com instâncias de Carro e Moto.
print("Exercício 5: ", end="")
c2.acelerar()
print("Exercício 5: ", end="")
m1.acelerar()

# 6 - Crie uma lista de objetos Veiculo contendo instâncias de Carro e Moto. Itere sobre a lista e chame o método descricao() para cada objeto.
lista_Veiculo = [c2, m1]
for i in lista_Veiculo:
    print("Exercício 6: ", end="")
    i.descricao()

# 7 - Crie uma classe abstrata chamada Forma com um método abstrato calcular_area(). Em seguida, crie classes Retangulo e Circulo que herdem de Forma e implementem o método calcular_area() para calcular a área do retângulo e do círculo, respectivamente.
from Forma import Retangulo, Circulo
ret1 = Retangulo()
cir1 = Circulo()
print("Exercício 7:", ret1.calcular_area(4, 6), "u")
print("Exercício 7:", cir1.calcular_area(2), "u")

# 8 - Crie uma interface chamada Imprimivel com um método imprimir(). Faça com que as classes Carro e Moto implementem essa interface e forneçam uma implementação para o método imprimir() que imprima informações sobre o veículo.
print("Exercício 8: ", end="")
c2.imprimir("Chevrolet", "Camaro")
print("Exercício 8: ", end="")
m1.imprimir("Suzuki", "Intruder")

# 9 - Crie classes para representar um sistema bancário com os princípios da orientação a objetos. Use encapsulamento para proteger informações sensíveis, herança para diferentes tipos de contas, polimorfismo para operações bancárias e abstração para representar transações.
from SistemaBancario import ContaCorrente, ContaPoupança
import os

print("Exercício 9: ")
pessoa1 = ContaPoupança("João", 200, 0.10)
pessoa2 = ContaCorrente("Hendrix", 300)

pessoa2.transferir(100, "John Doe")
pessoa2.depositar(900)
pessoa2.sacar(100000)
input("\nPressione ENTER para avançar...\n")
pessoa1.adicionar_juros()
pessoa1.transferir(100, "Yuri")
pessoa1.depositar(900)
pessoa1.sacar(100000)
input("\nPressione uma ENTER para avançar ao jogo do Exercício 10...")
os.system("clear" if os.name == "posix" else "cls")

# 10 - Crie um jogo simples com personagens que envolva encapsulamento para proteger pontos de vida, herança para diferentes tipos de personagens (guerreiro, mago, arqueiro), polimorfismo para habilidades únicas de cada personagem e abstração para representar a interação do jogador com o jogo.
from Jogo import CriarPersonagem, Combate
import time

classe = Combate()
classe.criar_personagem()
classe.usar_habilidades()