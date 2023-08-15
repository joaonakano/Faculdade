'''
Escreva uma função que recebe como entrada um número inteiro positivo n e retorne a soma de todos os inteiros positivos menores ou iguais a n.
'''

def somaDiferenciada(numeroPositivo):
    soma = 0
    for i in range(numeroPositivo+1):
        soma += i
    return soma
numeroUser = somaDiferenciada(int(input("Diga um número inteiro positivo: ")))
print(numeroUser)
