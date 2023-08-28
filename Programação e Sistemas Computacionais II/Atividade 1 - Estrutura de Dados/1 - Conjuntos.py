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

uniao = conjunto_01_1.union(conjunto_01_2)
interseccao = conjunto_01_1.intersection(conjunto_01_2)
diferenca_simetrica = conjunto_01_1.difference(conjunto_01_2)

print(f"\n2 - Uniao dos conjuntos 1 e 2: {uniao}\n  * Interseccao dos conjuntos 1 e 2: {interseccao}\n  * Diferenca Simetrica dos conjuntos 1 e 2: {diferenca_simetrica}")

# 3- Crie um conjunto com as vogais (a, e, i, o, u) e peça ao usuário para digitar uma palavra. Imprima as vogais que aparecem na palavra digitada.
conjunto_03_vogais = {"a", "e", "i", "o", "u"}
input_user_03_letra = str(input("\nDigite uma palavra: "))
verificador = 0

for vogal in conjunto_03_vogais:
    if vogal in input_user_03_letra:
        print(f"Vogal encontrada: {vogal}")
        verificador = 1

if verificador != 1:
    print("Nao ha vogais conhecidas nesta palavra!")
    
# 4- Crie dois conjuntos com nomes de frutas e verifique se há alguma fruta em comum entre os conjuntos.
conjunto0_04_1_frutas, conjunto0_04_2_frutas = {"Uva", "Maçã", "Abacate", "Melancia", "Laranja", "Banana"}, {"Maçã", "Abacate", "Banana"}

for fruta in conjunto0_04_1_frutas:
    if fruta in conjunto0_04_2_frutas:
        print(f"Foi encontrada uma fruta comum nos dois conjuntos! -> {fruta}")
