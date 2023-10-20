from abc import ABC, abstractmethod
import os
import time

class Personagem():
    def __init__(self, nome, classe, vida):
        self._poderes = []
        self._nome = nome
        self._vida = vida
        self._nome_da_classe = classe

    @property
    def nome(self):
        return self._nome

    @nome.setter
    def nome(self, nome):
        if nome != None:
            self._nome = nome

    @property
    def vida(self):
        return self._vida

    @vida.setter
    def vida(self, valor):
        if valor > 0:
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

    def bola_de_fogo(self):
        print(f"{self._nome} soltou uma bola de fogo!")

    def usar_habilidade_especial(self):
        print(f"Você usou a CHUVA de METEOROS!")


class Guerreiro(Personagem):
    def __init__(self, nome):
        super().__init__(nome, "Guerreiro", 250)

    def martelar(self):
        print(f"{self._nome} martelou!")

    def usar_habilidade_especial(self):
        print(f"Você usou a BENÇÃO DIVINA!")


class Arqueiro(Personagem):
    def __init__(self, nome):
        super().__init__(nome, "Arqueiro", 100)

    def disparar_flecha(self):
        print(f"{self._nome} disparou uma flecha!")
    
    def usar_habilidade_especial(self):
        print(f"Você usou a MULTI-FLECHADA!")


class Interacoes(ABC):
    def __init__(self):
        super().__init__()

    @abstractmethod
    def criar_personagem(self):
        pass


class CriarPersonagem(Interacoes, Personagem):
    def __init__(self):
        pass
    
    def criar_personagem(self):
        os.system('clear' if os.name == 'posix' else 'cls')
        self.nome = input("Digite o nome do seu personagem: ")

        while True:
            user_classe_selecao = int(input("[1] Mago\n[2] Arqueiro\n[3] Guerreiro\n\nSelecione a sua classe: "))

            if user_classe_selecao == 1:
                self._user_classe = Mago(self.nome)
                super().__init__()
            elif user_classe_selecao == 2:
                self._user_classe = Arqueiro(self.nome)
                super().__init__()
            elif user_classe_selecao == 3:
                self._user_classe = Guerreiro(self.nome)
                super().__init__()
            else:
                print("Classe inválida!")
                time.sleep(1)

            self._user_classe.verifica_poderes(self._user_classe)
            break


class Combate(CriarPersonagem):
    def __init__(self):
        super().__init__()

    def usar_habilidades(self):
        while True:
            os.system('clear' if os.name == 'posix' else 'cls')
            
            for i, item in enumerate(self._user_classe._poderes):
                print(i+1, item)

            user_poder_selecao = input("Caste uma habilidade: ")
            if self.nome_da_classe == "Mago":
                if user_poder_selecao == "bola_de_fogo" or int(user_poder_selecao) == 1:
                    self._user_classe.bola_de_fogo()
                    break

            elif self.nome_da_classe == "Arqueiro":
                if user_poder_selecao == "disparar_flecha" or int(user_poder_selecao) == 1:
                    self._user_classe.disparar_flecha()
                    break

            elif self.nome_da_classe == "Guerreiro":
                if user_poder_selecao == "martelar" or int(user_poder_selecao) == 1:
                    self._user_classe.martelar()
                    break

            if user_poder_selecao == "usar_habilidade_especial" or int(user_poder_selecao) == 2:
                self._user_classe.usar_habilidade_especial()
                break
            else:
                print("Escolha errada!")
                time.sleep(1)
                