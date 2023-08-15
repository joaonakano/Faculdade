# Exemplo de Recursividade usando Fatoriais
def fatorial(numero):
    if numero == 1:
        return 1
    return numero * fatorial(numero - 1)

print(fatorial(5))

'''
Escreva uma função que recebe como entrada um número inteiro positivo n e retorne a soma de todos os inteiros positivos menores ou iguais a n.
->> Com Recursividade
'''

# Somar - Recursivo
def somar(numero):
    # Caso Base
    if numero == 1:
        return 1
    # Chamada Recursiva
    return numero + somar(numero-1)

x = int(input("Indique um número para somar: "))
print("A soma é", somar(x))
