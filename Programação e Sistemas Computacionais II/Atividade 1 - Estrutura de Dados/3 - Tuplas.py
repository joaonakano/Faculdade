'''
# 1 - Crie uma tupla com os números de 1 a 5 e imprima a tupla.
Tupla = (1,2,3,4,5)
print(Tupla)

# 2 - Crie uma tupla com os nomes de três países e imprima o segundo elemento da tupla.
Tupla2 = ('Rússia', 'Austrália', 'Costa do Marfim')
print(Tupla2[1])

# 3 - Crie uma tupla com os valores de uma conta de restaurante (valor da refeição, taxa de serviço e valor total). Imprima a tupla.
tupla3 = (45 , 10 , 55)
print(f"Conta do Restaurante - VALOR DA REFEIÇÃO: R${tupla3[0]} - TAXA DE SERVIÇO: R${tupla3[1]} - VALOR TOTAL: R${tupla3[2]}")

# 4 - Crie uma tupla com os nomes de cinco pessoas e peça ao usuário para
# digitar um número entre 1 e 5. Imprima o nome correspondente ao número
# digitado.
tupla4 = ('João', 'Vitor', 'Lucas', 'Mateus', 'Enzo')
tuplaDigita = int(input("Digite um numero de 1 a 5: "))
print(tupla4[tuplaDigita])

# 5 - Crie uma tupla com as notas de um aluno em uma disciplina e imprima a
# média das notas.
tupla5 = (6,6,8)
media = sum(tupla5)/len(tupla5)
print("{:.2f}".format(media))

# 6 - Crie uma tupla com as cores do arco-íris (vermelho, laranja, amarelo, verde,
# azul, anil, violeta) e peça ao usuário para digitar uma cor. Verifique se a cor
# digitada está na tupla e imprima uma mensagem correspondente.
tupla6 = ('vermelho', 'laranja', 'amarelo', 'verde', 'azul', 'anil', 'violeta')
tuplaDigit = input("Digite uma cor: ")
if tuplaDigit in tupla6:
    print(f"A cor: {tuplaDigit} está na Tupla!.")
else:
    print(f"A cor: {tuplaDigit} NÃO está na Tupla!.")

# 7 - Crie uma tupla com as temperaturas de uma semana (sete dias) e imprima a
# temperatura máxima e mínima da semana.
tupla7 = (11,12,16,17,18,20,21)
print(f"A Temperatura mais baixa é {min(tupla7)} e a Temperatura mais alta é {max(tupla7)}")

# 8 - Crie uma tupla com os nomes de cinco frutas e suas respectivas cores.
# Imprima o nome de cada fruta seguido de sua cor.
tupla8 = ('Abacaxi', 'Morango', 'Laranja', 'Limão', 'Uva')
tupla8_Cor = ('Amarelo', 'Vermelho', 'Laranja', 'Verde', 'Roxo')
for i in range(len(tupla8)):
    print(f"Frutas: {tupla8[i]} Cor: {tupla8_Cor[i]}")

# 9 - Crie uma tupla com os números de 1 a 10 e outra tupla com os números de 5
# a 15. Imprima a interseção entre as duas tuplas.
tupla9 = (1,2,3,4,5,6,7,8,9,10)
tupla9B = (5,6,7,8,9,10,11,12,13,14,15)
intersecao = list(set(tupla9).intersection(list(set(tupla9B))))
print(intersecao)

# 10 - Crie uma tupla com as letras do alfabeto e uma segunda tupla com as vogais.
# Imprima a diferença entre as duas tuplas.
tupla10 = ('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z')
tupla10B = ('a','e','i','o','u')
diferenca10 = list(set(tupla10).difference(list(set(tupla10B))))

print(f"A Diferença é: {diferenca10}")
'''
