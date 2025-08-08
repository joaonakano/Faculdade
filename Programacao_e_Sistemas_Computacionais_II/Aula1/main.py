'''
Operadores Aritméticos
=====================[-][][x]
= Adição ------------ +     =
= Subtração --------- -     =
= Multiplicação ----- *     =
= Divisão ----------- /     =
= Exponenciação ----- **    =
= Parte inteira ----- //    =
= Módulo ------------ %     =
=============================
'''

#Entrada e Saída
print("Digite seu nome: ")
nome = input()
print("Bem vindo(a),", nome)

'''
=====================[-][][x]
= Operadores de Comparação  =
= Igualdade ---------- ==   =
= Diferente ---------- !=   =
= Menor ou igual ----- <=   =
= Menor -------------- <    =
= Maior ou igual ----- >=   =
= Maior -------------- >    =
=============================
'''

#Estruturas Condicionais Simples
a = 6
b = 4
soma = a + b

if soma >= 10 :
    print("O valor da soma é:", soma)
else :
    print("A soma não é maior ou igual a dez!")

'''
=====================[-][][x]
= Operadores Lógicos        =
= And ----- e               =
= Or ------ ou              =
= Not ----- não             =
=============================
'''

x = 3.5
y = 1.2

if y < x and x > 3 :
    print("As duas condições são verdadeiras.")
else :
    print("Pelo menos uma condição é verdadeira ou as duas são falsas.")

#Estrutura Condicional Composta
temperatura = float(input("Informe a temperatura: "))

if temperatura >= 30 :
    print("Muito quente!")
elif temperatura >= 24 :
    print("Quente")
elif temperatura >= 17 :
    print("Temperatura Amena")
elif temperatura >= 7 :
    print("Temperatura Fria")
else :
    print("Muito fria!")

numero = int(input("Informe um número: "))

if numero % 2 == 0 and numero > 0:
    print(f"{numero} é um número é par.")
elif numero % 2 != 0 :
    print(f"{numero} é um número é ímpar.")
else :
    print(f"{numero} é zero.")
