from abc import ABC, abstractmethod

class Transacoes(ABC):    
    @abstractmethod
    def depositar(self):
        pass
    
    @abstractmethod
    def sacar(self):
        pass
    
    @abstractmethod
    def transferir(self):
        pass
    

class ContaBancaria(Transacoes):
    def __init__(self, nome, saldo=0):
        self.__nome = nome
        self._saldo = float(saldo)
        
    @property
    def saldo(self):
        return self._saldo
        
    @saldo.setter
    def saldo(self, valor_novo):
            self._saldo = valor_novo
            
    def depositar(self, valor):
        if valor > 0:
            print(f"R${valor} foram depositados na conta de {self.__nome}, saldo restante de R${self.saldo + valor}!")
            self.saldo += valor
        else:
            raise ValueError("Insira uma quantia válida para o depósito!")
        
    def sacar(self, valor):
        if valor > 0:
            print(f"R${valor} foram retirados da conta de {self.__nome}, saldo restante de R${self.saldo - valor}!")
            self.saldo -= valor
        else:
            raise ValueError("Insira uma quantia válida para o saque!")
        
    def transferir(self, valor, pessoa):
        if valor > 0:
            print(f"R${valor} foram transferidos para a conta de {pessoa}, saldo restante de R${self.saldo - valor}!")
            self.saldo -= valor
        else:
            raise ValueError("Insira uma quantida válida para a transferência!")
    

class ContaPoupança(ContaBancaria):
    def __init__(self, nome, saldo=0, taxa=0.03):
        super().__init__(nome, saldo)
        self.__taxa = taxa
    
    def adicionar_juros(self):
        juros = self.saldo * self.__taxa
        print(f"R${juros} de juros aplicados sobre o saldo antigo de R${self.saldo}, o novo saldo será R${self.saldo + juros}")
        self.saldo = self.saldo + juros
        
        
class ContaCorrente(ContaBancaria):
    def __init__(self, nome, saldo=0):
        super().__init__(nome, saldo)
