from abc import ABC, abstractmethod
import os
import time
import random

class Personagem():
    def __init__(self, nome, classe, vida, dano=0):
        self._poderes = []
        self._nome = nome
        self._vida = vida
        self._nome_da_classe = classe
        self._dano = dano

    @property
    def nome(self):
        return self._nome

    @nome.setter
    def nome(self, nome):
        if nome != None:
            self._nome = nome
    
    @property
    def dano(self):
        return self._dano

    @dano.setter
    def dano(self, personagem_quantidade):
        personagem, quantidade = personagem_quantidade[0], personagem_quantidade[1]
        print(f"{personagem} deu {quantidade} de DANO!")
        self.vida -= quantidade
        self._dano += quantidade

    @property
    def healing(self):
        return self._vida

    @healing.setter
    def healing(self, valor):
        self._vida += valor

    @property
    def vida(self):
        return self._vida

    @vida.setter
    def vida(self, valor):
        if self.vida - valor < 0:
            self._vida = 0
        else:
            self._vida = valor

    @property
    def nome_da_classe(self):
        return self._nome_da_classe

    @nome_da_classe.setter
    def nome_da_classe(self, classe):
        if classe in ("Guerreiro", "Arqueiro", "Mago"):
            self._nome_da_classe = classe
        else:
            raise ValueError("Classe incorreta!")

    def verifica_poderes(self, classe):
        for func in dir(classe):
            if callable(getattr(classe, func)) and not func.startswith("__") and not func in ("verifica_poderes"):
                self._poderes.append(func)

    @abstractmethod
    def usar_habilidade_especial(self):
        pass


class Mago(Personagem):
    def __init__(self, nome):
        super().__init__(nome, "Mago", 180)

    def bola_de_fogo(self, inimigo):
        print(f"{self._nome} soltou uma bola de fogo!")
        time.sleep(2)
        inimigo.dano = (self.nome, 10)


    def usar_habilidade_especial(self, inimigo):
        print(f"Você usou a CHUVA de METEOROS!")
        time.sleep(2)
        inimigo.dano = (self.nome, 60)


class Guerreiro(Personagem):
    def __init__(self, nome):
        super().__init__(nome, "Guerreiro", 250)

    def martelar(self, inimigo):
        print(f"{self._nome} martelou!")
        time.sleep(2)
        inimigo.dano = (self.nome, 25)

    def usar_habilidade_especial(self, inimigo):
        print(f"Você usou a BENÇÃO DIVINA!")
        time.sleep(2)
        print("Deu 50 de HP!")
        self.healing = 50


class Arqueiro(Personagem):
    def __init__(self, nome):
        super().__init__(nome, "Arqueiro", 100)

    def disparar_flecha(self):
        print(f"{self._nome} disparou uma flecha!")
        time.sleep(2)
        inimigo.dano = (self.nome, 40)
    
    def usar_habilidade_especial(self, inimigo):
        print(f"Você usou a MULTI-FLECHADA!")
        time.sleep(2)
        inimigo.dano = (self.nome, random.randint(50, 80))


class Interacoes(ABC):
    def __init__(self):
        self._user_classe = None

    @abstractmethod
    def criar_personagem(self):
        pass

    @abstractmethod
    def usar_habilidades(self):
        pass


class CriarPersonagem(Interacoes):
    def usar_habilidades(self):
        pass

    def criar_personagem(self):
        os.system('clear' if os.name == 'posix' else 'cls')
        self._nome = input("Digite o nome do seu personagem: ")

        while True:
            user_classe_selecao = int(input("[1] Mago\n[2] Arqueiro\n[3] Guerreiro\n\nSelecione a sua classe: "))

            if user_classe_selecao == 1:
                self._user_classe = Mago(self._nome)
            elif user_classe_selecao == 2:
                self._user_classe = Arqueiro(self._nome)
            elif user_classe_selecao == 3:
                self._user_classe = Guerreiro(self._nome)
            else:
                print("Classe inválida!")
                time.sleep(1)

            self._user_classe.verifica_poderes(self._user_classe)
            break


class Combate(Interacoes):
    def __init__(self, personagem):
        self._user_classe = personagem

    def criar_personagem(self):
        pass

    def usar_habilidades(self):
        while True:
            os.system('clear' if os.name == 'posix' else 'cls')
            
            for i, item in enumerate(self._user_classe._poderes):
                print(i+1, item)

            user_poder_selecao = input("\nCaste uma habilidade: ")
            print()

            if isinstance(self._user_classe, Mago):
                if user_poder_selecao == "bola_de_fogo" or int(user_poder_selecao) == 1:
                    self._user_classe.bola_de_fogo(self._orc)
                    break

            if isinstance(self._user_classe, Arqueiro):
                if user_poder_selecao == "disparar_flecha" or int(user_poder_selecao) == 1:
                    self._user_classe.disparar_flecha()
                    break

            if isinstance(self._user_classe, Guerreiro):
                if user_poder_selecao == "martelar" or int(user_poder_selecao) == 1:
                    self._user_classe.martelar(self._orc)
                    break

            if user_poder_selecao == "usar_habilidade_especial" or int(user_poder_selecao) == 2:
                self._user_classe.usar_habilidade_especial(self._orc)
                break

            else:
                print("Escolha errada!")
                time.sleep(1)

    def iniciar_combate(self):
        self._orc = Guerreiro("ORC")
        os.system('clear' if os.name == 'posix' else 'cls')
        print("Um ORC te desafiou!")
        time.sleep(2)
        self._user_classe.dano = ("ORC", 8)
        input(f"\nSua vida restante: {self._user_classe.vida} \n\nPressione ENTER para contra-atacar!")

    def combate_mid(self):
        ponteiro_da_vez = "usuario"
        while self._orc.vida > 0 and self._user_classe.vida > 0:
            if ponteiro_da_vez == "usuario":
                self.usar_habilidades()
                time.sleep(2)
                print(f"\n x Vida restante do ORC: {self._orc.vida}")
                time.sleep(2)
                print(f" - Vida restante de {self._user_classe.nome}: {self._user_classe.vida}")
                time.sleep(2)
                input("\nPressione ENTER para avançar...")
                ponteiro_da_vez = "orc"
            else:
                os.system('clear' if os.name == 'posix' else 'cls')
                self._user_classe.dano = ("ORC", random.randint(0, 50))
                time.sleep(2)
                print(f"\n x Vida restante do ORC: {self._orc.vida}")
                time.sleep(2)
                print(f" - Vida restante de {self._user_classe.nome}: {self._user_classe.vida}")
                time.sleep(2)
                ponteiro_da_vez = "usuario"

        if self._orc.vida < self._user_classe.vida:
            print("O ORC perdeu!")
        else:
            print("VOCÊ perdeu!")


def iniciar_jogo():
    personagem = CriarPersonagem()
    personagem.criar_personagem()
    combate = Combate(personagem._user_classe)
    combate.iniciar_combate()
    combate.combate_mid()
