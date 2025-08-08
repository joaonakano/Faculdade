# Conjuntos - Atividade
print("======= Conjuntos =======")

# 1- Crie um conjunto com os números de 1 a 10 e imprima o conjunto.
conjunto_01 = set()

for i in range(10):
    conjunto_01.add((int(i)+1))

print(f"1 - Conjunto de numeros de 1 a 10: {conjunto_01}")

# 2- Crie dois conjuntos, um com os números de 1 a 5 e outro com os números de 3 a 7. Imprima a união, a interseção e a diferença simétrica dos conjuntos.
conjunto_01_1, conjunto_01_2 = set(), set()

for i in range(7):
    if i+1 <= 5:
        conjunto_01_1.add(i+1)
    if 3 <= i+1 <= 7:
        conjunto_01_2.add(i+1)

uniao_01 = conjunto_01_1.union(conjunto_01_2)
interseccao_01 = conjunto_01_1.intersection(conjunto_01_2)
diferenca_simetrica_01 = conjunto_01_1.difference(conjunto_01_2)

print(f"\n2 - Uniao dos conjuntos 1 e 2: {uniao_01}\n  * Interseccao dos conjuntos 1 e 2: {interseccao_01}\n  * Diferenca Simetrica dos conjuntos 1 e 2: {diferenca_simetrica_01}")

# 3- Crie um conjunto com as vogais (a, e, i, o, u) e peça ao usuário para digitar uma palavra. Imprima as vogais que aparecem na palavra digitada.
conjunto_03_vogais = {"a", "e", "i", "o", "u"}
input_user_03_letra = str(input("\n3 - Digite uma palavra: "))
verificador = 0

for vogal in conjunto_03_vogais:
    if vogal in input_user_03_letra:
        print(f"Vogal encontrada: {vogal}")
        verificador = 1

if verificador != 1:
    print("Nao ha vogais conhecidas nesta palavra!")

# 4- Crie dois conjuntos com nomes de frutas e verifique se há alguma fruta em comum entre os conjuntos.
conjunto04_1_frutas, conjunto04_2_frutas = {"Uva", "Maçã", "Abacate", "Melancia", "Laranja", "Banana"}, {"Maçã", "Abacate", "Banana"}
conjunto04_3_frutas_nao_encontradas = set()

print('\n4 -')

for fruta in conjunto04_1_frutas:
    if fruta in conjunto04_2_frutas:
        print(f"Foi encontrada uma fruta comum nos dois conjuntos! -> {fruta}")
    else:
        conjunto04_3_frutas_nao_encontradas.add(fruta)
        
print(f"Frutas em comum NÃO ENCONTRADAS: {conjunto04_3_frutas_nao_encontradas}")

# 5- Crie um conjunto com números inteiros aleatórios e imprima o maior e o menor número do conjunto.
conjunto_05 = {1,6,33,4,12,96,3,77}

print(f"\n5- O maior número do conjunto 5 é \"{max(conjunto_05)}\" e o menor é \"{min(conjunto_05)}\"!")

# 6- Crie um conjunto com as cores do arco-íris (vermelho, laranja, amarelo, verde, azul, anil, violeta) e peça ao usuário para digitar uma cor. Verifique se a cor digitada está no conjunto e imprima uma mensagem correspondente.
conjunto_06_cores = {"vermelho", "laranja", "amarelo", "verde", "azul", "anil", "violeta"}
input_user_06_cor = str(input("\n6- Digite uma cor: "))

if input_user_06_cor in conjunto_06_cores:
    print(f"A cor \"{input_user_06_cor}\" está presente no Arco-íris!")
else:
    print(f"A cor \"{input_user_06_cor}\" NÃO está presente no Arco-íris!")
    
# 7- Crie um conjunto com os dias da semana (segunda, terça, quarta, quinta, sexta, sábado, domingo) e remova os dias úteis (segunda a sexta). Imprima o conjunto resultante.
conjunto_07_dias_da_semana = {"segunda", "terça", "quarta", "quinta", "sexta", "sábado", "domingo"}
conjunto_07_fim_de_semana = {"sábado", "domingo"}

print(f"\n7- Os dias não-úteis são: {conjunto_07_dias_da_semana.intersection(conjunto_07_fim_de_semana)}")

# 8- Crie um conjunto com os números de 1 a 20 e outro conjunto com os números pares de 1 a 10. Imprima a diferença entre os dois conjuntos.
conjunto_08_01, conjunto_08_02_pares = set(), set()

for i in range(20):
    if (i+1) <= 20:
        conjunto_08_01.add(i+1)
    if ((i+1) % 2) == 0 and (i+1) <= 10:
        conjunto_08_02_pares.add(i+1)

diferenca_08 = conjunto_08_01.difference(conjunto_08_02_pares)

print(f"\n8- A diferença entre o conjunto de números até o 20 e os números pares de 1 ao 10 será: \"{diferenca_08}\".")

# 9- Crie um conjunto com as notas de um aluno em uma disciplina e verifique se ele foi aprovado (média 7) ou reprovado (média abaixo de 7).
conjunto_09_notas = {7, 6, 5}
media = sum(conjunto_09_notas) / len(conjunto_09_notas)

if media >= 7:
    print(f"\n9- A média do aluno é: {media}. Ele está APROVADO!\nAs notas dele são: {conjunto_09_notas}")
else:
    print(f"\n9- A média do aluno é: {media}. Ele está REPROVADO!\nAs notas dele são: {conjunto_09_notas}")
    
# 10- Crie um conjunto com os números primos de 1 a 20 e verifique se um número digitado pelo usuário está no conjunto.
conjunto_10_primos = {2, 3, 5, 7, 11, 13, 17, 19}
input_user_10_numero = int(input("\n10- Digite um número: "))

if input_user_10_numero in conjunto_10_primos:
    print(f"O número \"{input_user_10_numero}\" está no conjunto 10, e portanto é PRIMO!")
else:
    print(f"O número \"{input_user_10_numero}\" NÃO está no conjunto 10, e portanto NÃO é PRIMO!")
