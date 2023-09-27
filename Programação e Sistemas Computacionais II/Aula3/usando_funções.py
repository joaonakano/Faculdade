def primeirafunção():       # Declaração da Função -> usa-se def
    print("Minha primeira função! Que emoção!")

primeirafunção()

# Parâmetros

def imprimenome(nome):      # Utilização de Parâmetros
    print(f"Olá, {nome}! Seja bem-vindo!")

imprimenome("João")
imprimenome("Maria")
imprimenome("Carla")

fabricante_processador = input("Intel ou AMD? ")
modelo_processador = input("Diga o modelo: ")
cpu_user = fabricante_processador.upper() + " " + modelo_processador
armazenamento = input("Diga a quantidade em GB de Memória ROM: ")
memoria = input("Diga a quantidade de Memória RAM: ")

def monta_computador(cpu, armazenamento, memoria):
    print(f"A configuração é: \n\t - CPU: {cpu} \n\t - Armazenamento: {armazenamento}GB \n\t - Memoria: {memoria}GB\n")

monta_computador(cpu_user, armazenamento, memoria)

# PROCEDIMENTO -> Função sem retorno
# FUNÇÃO -> Função com retorno

def somaDoisValores(valor1, valor2):
    soma = valor1 + valor2
    return soma

resultado = somaDoisValores(5, 9)
print("FUNÇÃO COM RETORNO \nO valor da soma é: ", resultado)
print("O valor da soma é: ", somaDoisValores(15, 20))
