# -*- coding: utf-8 -*- 
# 9 - Crie classes para representar um sistema bancário com os princípios da orientação a objetos. Use encapsulamento para proteger informações sensíveis, herança para diferentes tipos de contas, polimorfismo para operações bancárias e abstração para representar transações.
from SistemaBancario import ContaCorrente, ContaPoupança
pessoa1 = ContaPoupança("João", 200, 0.10)
pessoa2 = ContaCorrente("Hendrix", 300)

pessoa2.transferir(100, "John Doe")
pessoa2.depositar(900)
pessoa2.sacar(100000)

pessoa1.adicionar_juros()
pessoa1.transferir(100, "Yuri")
pessoa1.depositar(900)
pessoa1.sacar(100000)

# 10 - Crie um jogo simples com personagens que envolva encapsulamento para proteger pontos de vida, herança para diferentes tipos de personagens (guerreiro, mago, arqueiro), polimorfismo para habilidades únicas de cada personagem e abstração para representar a interação do jogador com o jogo.
