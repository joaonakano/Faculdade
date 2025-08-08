from abc import ABC, abstractmethod

class Pessoa(ABC):
    def __init__(self, nome):
        self._nome = nome

    @abstractmethod
    def saudar(self):
        pass
