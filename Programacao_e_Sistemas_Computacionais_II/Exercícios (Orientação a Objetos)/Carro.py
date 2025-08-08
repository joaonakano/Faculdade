class Carros:
    def __init__(self, modelo, ano):
        self.__modelo = modelo
        self.__ano = ano

    @property
    def modelo(self):
        return self.__modelo

    @modelo.setter
    def modelo(self, modelo_novo):
       self.__modelo = modelo_novo

    @property
    def ano(self):
        return self.__ano

    @ano.setter
    def ano(self, ano_novo):
        self.__ano = ano_novo
