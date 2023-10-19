# -*- coding: utf-8 -*- 
# 9 - Crie classes para representar um sistema bancário com os princípios da orientação a objetos. Use encapsulamento para proteger informações sensíveis, herança para diferentes tipos de contas, polimorfismo para operações bancárias e abstração para representar transações.
from SistemaBancario import ContaCorrente, ContaPoupança
classe = ContaPoupança("João", 200, 0.10)
classe.adicionar_juros()
classe.transferir(100, "Yuri")
classe.depositar(900)
classe.sacar(100000)

# 10 - Crie um jogo simples com personagens que envolva encapsulamento para proteger pontos de vida, herança para diferentes tipos de personagens (guerreiro, mago, arqueiro), polimorfismo para habilidades únicas de cada personagem e abstração para representar a interação do jogador com o jogo.
