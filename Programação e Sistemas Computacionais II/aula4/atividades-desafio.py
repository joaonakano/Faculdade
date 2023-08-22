# Desafio - Conjuntos

# Crie um conjunto com os números de 1 a 10 e imprima o conjunto.
conjunto1 = {1,2,3,4,5,6,7,8,9,10}
print(f"{conjunto1}\n")

# Crie dois conjuntos, um com os números de 1 a 5 e outro com os números de 3 a 7. Imprima a união, a interseção e a diferença simétrica dos conjuntos.
conjunto2_1 = {1,2,3,4,5}
conjunto2_2 = {3,4,5,6,7}
uniao = conjunto2_1.union(conjunto2_2)
interseccao = conjunto2_1.intersection(conjunto2_2)
diferenca = conjunto2_1.difference(conjunto2_2)
print(f"União: {uniao}\nIntersecção: {interseccao}\nDiferença: {diferenca}\n")

# Crie um conjunto com as vogais (a, e, i, o, u) e peça ao usuário para digitar uma palavra. Imprima as vogais que aparecem na palavra digitada.
conjunto3 = {'a', 'e', 'i', 'o', 'u'}
palavra = input("Digite uma palavra: ")
verificador = 0
for i in palavra:
    if i in conjunto3:
        verificador += 1
        print(f"Vogal encontrada! -> {i}")
if verificador == 0:
        print("Nao ha vogais!\n")
print('\n')

# Crie dois conjuntos com nomes de frutas e verifique se há alguma fruta em comum entre os conjuntos.
conjunto4_1 = {"abacate", "uva", "limao", "melancia", "kiwi", "laranja", "maca"}
conjunto4_2 = {"caju", "melancia", "laranja"}
for i in conjunto4_2:
    if i in conjunto4_1:
        print(f"Existe {i} no conjunto 4_2")
    elif i == len(conjunto4_1):
        print("\nNão existe frutas em comum entre os conjuntos\n")

# Crie um conjunto com números inteiros aleatórios e imprima o maior e o menor número do conjunto.
conjunto5 = {1,6,4,8,3,9}
maior_numero = 0
menor_numero = 0
for i in conjunto5:
    if i > maior_numero:
        maior_numero = i
        menor_numero = i
for j in conjunto5:
    if j < menor_numero:
        menor_numero = j
print(f"\nO maior número na sequência é: {maior_numero}")
print(f"O menor número na sequência é: {menor_numero}\n")

# Crie um conjunto com as cores do arco-íris (vermelho, laranja, amarelo, verde, azul, anil, violeta) e peça ao usuário para digitar uma cor. Verifique se a cor digitada está no conjunto e imprima uma mensagem correspondente.
conjunto6 = ("vermelho", "laranja", "amarelo", "verde", "azul", "anil", "violeta")
cor = input("Digite uma cor: ")
if cor in conjunto6:
    print(f"Existe {cor} no Arco-íris.\n")
else:
    print(f"Não existe {cor} no Arco-íris.\n")

# Crie um conjunto com os dias da semana (segunda, terça, quarta, quinta, sexta, sábado, domingo) e remova os dias úteis (segunda a sexta). Imprima o conjunto resultante.
conjunto7_1 = {"segunda", "terça", "quarta", "quinta", "sexta", "sábado", "domingo"}
conjunto7_2 = {"sábado", "domingo"}

print(conjunto7_1.intersection(conjunto7_2), "\n")

# Crie um conjunto com os números de 1 a 20 e outro conjunto com os números pares de 1 a 10. Imprima a diferença entre os dois conjuntos.
conjunto8_1 = set()
conjunto8_2 = set()
for i in range(20):
    conjunto8_1.add(i+1)
    if i < 10:
        conjunto8_2.add(i+1)
print(conjunto8_1.difference(conjunto8_2))

# Crie um conjunto com as notas de um aluno em uma disciplina e verifique se ele foi aprovado (média 7) ou reprovado (média abaixo de 7).
conjunto9 = {10, 9, 2}
contagem = 0
media = 0
for i in conjunto9:
    media += i
    contagem += 1
media = media / contagem
if (media >= 7):
    print(f"\nA média do aluno é {media} e ele está APROVADO!")
else:
    print(f"\nA média do aluno é {media} e ele está REPROVADO!")

# Crie um conjunto com os números primos de 1 a 20 e verifique se um número digitado pelo usuário está no conjunto.
conjunto10 = set()
for i in range(20):
    conjunto10.add(i+1)
numero_user = int(input("\nDigite um numero: "))
if numero_user in conjunto10:
    print(f"O numero {numero_user} existe no conjunto10.")
else:
    print(f"O numero {numero_user} nao existe no conjunto10.")