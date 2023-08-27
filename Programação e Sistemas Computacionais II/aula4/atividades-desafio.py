# Desafio - Conjuntos
print("========= Desafio - Conjuntos =========")


# Crie um conjunto com os números de 1 a 10 e imprima o conjunto.
conjunto1 = {1,2,3,4,5,6,7,8,9,10}

print(f"\nConjunto1: {conjunto1}\n")
input("\nPressione enter para continuar...")
print('\n')


# Crie dois conjuntos, um com os números de 1 a 5 e outro com os números de 3 a 7. Imprima a união, a interseção e a diferença simétrica dos conjuntos.
conjunto2_1, conjunto2_2 = {1,2,3,4,5}, {3,4,5,6,7}

uniao = conjunto2_1.union(conjunto2_2)
interseccao = conjunto2_1.intersection(conjunto2_2)
diferenca = conjunto2_1.difference(conjunto2_2)

print(f"União: {uniao}\nIntersecção: {interseccao}\nDiferença: {diferenca}\n")
input("\nPressione enter para continuar...")
print('\n')


# Crie um conjunto com as vogais (a, e, i, o, u) e peça ao usuário para digitar uma palavra. Imprima as vogais que aparecem na palavra digitada.
conjunto3 = {'a', 'e', 'i', 'o', 'u'}

palavra = input("Digite uma palavra: ")
verificador = 0

for i in palavra:
    if i in conjunto3:
        verificador += 1
        print(f"Vogal encontrada! -> {i}")
if verificador == 0:
        print("Nao ha vogais!")

input("\n\nPressione enter para continuar...")
print('\n')


# Crie dois conjuntos com nomes de frutas e verifique se há alguma fruta em comum entre os conjuntos.
conjunto4_1 = {"abacate", "uva", "limao", "melancia", "kiwi", "laranja", "maca"}
conjunto4_2 = {"caju", "melancia", "laranja"}

for i in conjunto4_2:
    if i in conjunto4_1:
        print(f"{i} é comum no conjunto 4_2")
    elif i == len(conjunto4_1):
        print("\nNão existe frutas em comum entre os conjuntos\n")

input("\n\nPressione enter para continuar...")
print('\n')


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

print(f"O maior número na sequência é: {maior_numero}")
print(f"O menor número na sequência é: {menor_numero}\n")

input("\nPressione enter para continuar...")
print('\n')


# Crie um conjunto com as cores do arco-íris (vermelho, laranja, amarelo, verde, azul, anil, violeta) e peça ao usuário para digitar uma cor. Verifique se a cor digitada está no conjunto e imprima uma mensagem correspondente.
conjunto6 = ("vermelho", "laranja", "amarelo", "verde", "azul", "anil", "violeta")

cor = input("Digite uma cor: ")

if cor in conjunto6:
    print(f"Existe {cor} no Arco-íris.\n")
else:
    print(f"Não existe {cor} no Arco-íris.\n")

input("\nPressione enter para continuar...")
print('\n')


# Crie um conjunto com os dias da semana (segunda, terça, quarta, quinta, sexta, sábado, domingo) e remova os dias úteis (segunda a sexta). Imprima o conjunto resultante.
conjunto7_1 = {"segunda", "terça", "quarta", "quinta", "sexta", "sábado", "domingo"}
conjunto7_2 = {"sábado", "domingo"}

print("A intersecção entre os conjuntos *7_1 e *7_2 é:",conjunto7_1.intersection(conjunto7_2), "\n")
input("\nPressione enter para continuar...")
print('\n')


# Crie um conjunto com os números de 1 a 20 e outro conjunto com os números pares de 1 a 10. Imprima a diferença entre os dois conjuntos.
conjunto8_1, conjunto8_2 = set(), set()

for i in range(20):
    conjunto8_1.add(i+1)
    if i < 10:
        conjunto8_2.add(i+1)

print("A diferença entre os conjuntos *8_1 e *8_2 é:",conjunto8_1.difference(conjunto8_2))

input("\n\nPressione enter para continuar...")
print('\n')


# Crie um conjunto com as notas de um aluno em uma disciplina e verifique se ele foi aprovado (média 7) ou reprovado (média abaixo de 7).
conjunto9 = {10, 9, 2}

contagem, media = 0, 0

for i in conjunto9:
    media += i
    contagem += 1

media = media / contagem

if (media >= 7):
    print(f"A média do aluno é {media} e ele está APROVADO!")
else:
    print(f"A média do aluno é {media} e ele está REPROVADO!")

input("\n\nPressione enter para continuar...")
print('\n')


# Crie um conjunto com os números primos de 1 a 20 e verifique se um número digitado pelo usuário está no conjunto.
conjunto10 = {2,3,5,7,11,13,17,19}

numero_user = int(input("Digite um numero: "))

if numero_user in conjunto10:
    print(f"O numero {numero_user} é comum no conjunto_10.\n")
else:
    print(f"O numero {numero_user} é comum no conjunto_10.\n")

input("\nPressione enter para continuar...")
print('\n')


# Desafio - Dicionários
print("========= Desafio - Dicionários =========")


# Crie um dicionário vazio e adicione duas chaves e valores a ele.
dicionario1 = {}

dicionario1["salario", "nome"] = 1900, "Juasnir"

print("\n2 Valores foram adicionados ao dicionário vázio:", dicionario1.items())

input("\n\nPressione enter para continuar...")
print('\n')


# Crie um dicionário com as chaves "nome", "idade" e "cidade" e preencha com seus dados. Imprima o dicionário.
dicionario2 = {'nome':[], 'idade':[], 'cidade':[]}

nome2 = input("Digite seu nome: ")
idade2 = input("Digite sua idade: ")
cidade2 = input("Digite sua cidade: ")

dicionario2.update({'nome': nome2, 'idade': idade2, 'cidade': cidade2})

print("Dicionário com as informações atualizadas:", dicionario2.items(), '\n')

input("\nPressione enter para continuar...")
print('\n')


# Crie um dicionário com o nome e o preço de três produtos diferentes. Imprima o dicionário.
dicionario3 = {
    "produtos": ['Detergente', 'Carne moída', 'Sabão em pó'],
    "precos": [1.95, 10, 6.75]
}

produtos3 = dicionario3["produtos"]
precos3 = dicionario3["precos"]

for i in range(len(produtos3)):
    produto = produtos3[i]
    preco = precos3[i]
    print(f"Nome: {produto}................Preço: R${preco}")

input("\n\nPressione enter para continuar...")
print('\n')


# Crie um dicionário com o nome de três estados e suas respectivas capitais. Peça ao usuário para digitar um estado e imprima a capital correspondente.
dicionario4 = {"parana": "Curitiba", "santa catarina": "Florianópolis", "rio grande do sul": "Porto Alegre"}

estado4 = input("Digite um Estado da Região Sul (Parana, Santa Catarina ou Rio Grande do Sul): ").lower()

if estado4 in dicionario4.keys():
    print(dicionario4[estado4], '\n')
else:
    print("Estado inválido!", '\n')

input("\nPressione enter para continuar...")
print('\n')


# Crie um dicionário com o nome de cinco cidades e suas respectivas populações. Imprima a cidade com a maior população.
dicionario5 = {
    "Guarapuava": 150000,
    "São Paulo": 12000000,
    "Rio de Janeiro": 6500000,
    "Curitiba": 2000000,
    "Bahia": 3000000
}

cidade_mais_populosa = max(dicionario5)

print("A cidade mais populosa do dicionario5 é:", cidade_mais_populosa, f"com {dicionario5[cidade_mais_populosa]} habitantes!\n")

input("\nPressione enter para continuar...")
print('\n')


# Crie um dicionário com o nome de três alimentos e suas respectivas calorias. Peça ao usuário para digitar um alimento e imprima a quantidade de calorias correspondente.
dicionario_6 = {
    "alimentos": ["banana", "maracuja", "aveia"],
    "calorias": [105, 68, 389]
}

valor_procurado = input("Digite um alimento (banana, maracuja, aveia) e saiba suas calorias: ")
alimentos = dicionario_6["alimentos"]

if valor_procurado in alimentos:
    indice = alimentos.index(valor_procurado)
    print("->",valor_procurado,"tem",dicionario_6["calorias"][indice], "calorias.\n")
else:
    print(f"Não foi encontrado índice para a requisição de \'{valor_procurado}\'\n")

input("\nPressione enter para continuar...")
print('\n')


# 7 - Crie um dicionário com o nome de cinco animais e suas respectivas classificações (mamífero, ave, réptil, etc.). Imprima apenas os nomes dos animais.
dicionario_7 = {
    "Cachorro": "Mamífero",
    "Papagaio": "Ave",
    "Cobra": "Réptil",
    "Tubarão": "Peixe",
    "Gato": "Mamífero"
}

print("Os animais presentes no dicionario_7 são:")

for animal in dicionario_7:
    print(' *', animal)

input("\n\nPressione enter para continuar...")
print('\n')


# 8 - Crie um dicionário com o nome de cinco países e suas respectivas bandeiras. Imprima apenas os nomes dos países.
dicionario_8 = {
    "Brasil": "https://s1.static.brasilescola.uol.com.br/be/conteudo/images/2-bandeira-do-brasil.jpg",
    "Estados Unidos": "https://s4.static.brasilescola.uol.com.br/be/2022/05/bandeira-dos-estados-unidos.jpg",
    "França": "https://s3.static.brasilescola.uol.com.br/be/2021/07/bandeira-francesa.jpg",
    "Japão": "https://s4.static.brasilescola.uol.com.br/be/2022/11/bandeira-do-japao.jpg",
    "Austrália": "https://s2.static.brasilescola.uol.com.br/be/2022/10/bandeira-da-australia.jpg"
}

print("Os países presentes no dicionario_8 são:")

for pais in dicionario_8:
    print(' *', pais)

input("\n\nPressione enter para continuar...")
print('\n')


# 9 - Crie um dicionário com o nome de cinco frutas e suas respectivas cores. Imprima o nome de cada fruta seguido de sua cor.
dicionario_9 = {
    "Maçã": "Vermelha",
    "Banana": "Amarela",
    "Laranja": "Laranja",
    "Uva": "Roxa",
    "Morango": "Vermelho"
}

for nome, cor in dicionario_9.items():
    print(f"Fruta: {nome}................Cor: {cor}")

input("\n\nPressione enter para continuar...")
print('\n')


# 10 - Crie um dicionário com o nome de três jogos e a quantidade de jogadores necessária. Peça ao usuário para digitar um jogo e imprima a quantidade de jogadores correspondente.
dicionario_10 = {
    "jogos": ["league of legends", "team fortress 2", "super mario world"],
    "jogadores": [10, 2, 1]
}

jogo = input("Digite um jogo (League of Legends, Team Fortress 2, Super Mario World): ").lower()

if jogo in dicionario_10["jogos"]:
    indice = dicionario_10["jogos"].index(jogo)
    jogadores = dicionario_10["jogadores"]

    print(f"A quantidade de jogadores mínima necessária no {jogo} é {jogadores[indice]}!\n")
else:
    print("Jogo não encontrado na DataBase!\n")

input("\nPressione enter para continuar...")
print('\n')


# Desafio - Tuplas
print("========= Desafio - Tuplas =========")


# 1 - Crie uma tupla com os números de 1 a 5 e imprima a tupla.
tupla_1 = (1,2,3,4,5)

print("\nElementos da tupla 1:", tupla_1, '\n')

input("\nPressione enter para continuar...")
print('\n')


# 2 - Crie uma tupla com os nomes de três países e imprima o segundo elemento da tupla.
tupla_2 = ("Brasil", "China", "México")

print("O segundo elemento da tupla_2 é:",tupla_2[1], '\n')

input("\nPressione enter para continuar...")
print('\n')


# 3 - Crie uma tupla com os valores de uma conta de restaurante (valor da refeição, taxa de serviço e valor total). Imprima a tupla.
tupla_3 = (79.95, 10, 89.95)

print(f"TABELA DE VALORES - CONTA DE RESTAURANTE\nValor da Refeição:................{tupla_3[0]}\nValor da Taxa de Serviço:................{tupla_3[1]}\nValor Total:................{tupla_3[2]}\n")

input("\nPressione enter para continuar...")
print('\n')


# 4 - Crie uma tupla com os nomes de cinco pessoas e peça ao usuário para digitar um número entre 1 e 5. Imprima o nome correspondente ao número digitado.
tupla_4 = ("João", "Vitor", "Mariane", "Milena", "Alberto")

numero_usuario_4 = int(input("Digite um número entre 1 e 5: "))

print(f"O nome correspondente na tupla_4 ao número {numero_usuario_4} é {tupla_4[numero_usuario_4-1]}.\n")

input("\nPressione enter para continuar...")
print('\n')


# 5 - Crie uma tupla com as notas de um aluno em uma disciplina e imprima a média das notas.
tupla_5 = (9, 6, 3)

media = sum(tupla_5) / len(tupla_5)

print(f"A média do aluno com as notas {tupla_5} é:",media,'\n')

input("\nPressione enter para continuar...")
print('\n')


# 6 - Crie uma tupla com as cores do arco-íris (vermelho, laranja, amarelo, verde, azul, anil, violeta) e peça ao usuário para digitar uma cor. Verifique se a cor digitada está na tupla e imprima uma mensagem correspondente.
tupla_6 = ("vermelho", "laranja", "amarelo", "verde", "azul", "anil", "violeta")

cor_user_6 = str(input("Digite uma cor: "))

if cor_user_6 in tupla_6:
    print(f"A cor {cor_user_6} está presente no Arco-íris!\n")
else:
    print(f"A cor {cor_user_6} não está presente no Arco-íris!\n")

input("\nPressione enter para continuar...")
print('\n')


# 7 - Crie uma tupla com as temperaturas de uma semana (sete dias) e imprima a temperatura máxima e mínima da semana.
tupla_7 = (20, 21, 19, 18, 17, 18, 19)

print(f"A temperatura MÁXIMA da semana foi {max(tupla_7)}°C e a temperatura MÍNIMA foi {min(tupla_7)}°C.\n")

input("\nPressione enter para continuar...")
print('\n')


# 8 - Crie uma tupla com os nomes de cinco frutas e suas respectivas cores. Imprima o nome de cada fruta seguido de sua cor.
tupla_frutas_8 = ("Maçã", "Pera", "Melancia", "Banana", "Laranja")
tupla_cores_8 = ("Vermelha", "Verde", "Verde/Vermelha", "Amarela", "Laranja")

for i in range(len(tupla_frutas_8)):
    print(f"Fruta: {tupla_frutas_8[i-1]}................Cor: {tupla_cores_8[i-1]}")

input("\n\nPressione enter para continuar...")
print('\n')


# 9 - Crie uma tupla com os números de 1 a 10 e outra tupla com os números de 5 a 15. Imprima a interseção entre as duas tuplas.
tupla_9_1 = (1,2,3,4,5,6,7,8,9,10)
tupla_9_2 = (5,6,7,8,9,10,11,12,13,14,15)

interseccao_9 = list(set(tupla_9_1).intersection(set(tupla_9_2)))

print(f"A intersecção entre as tuplas *9_1 e *9_2 será: {interseccao_9}")

input("\n\nPressione enter para continuar...")
print('\n')


# 10 - Crie uma tupla com as letras do alfabeto e uma segunda tupla com as vogais. Imprima a diferença entre as duas tuplas.
tupla_10_1 = ('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z')
tupla_10_2 = ('a', 'e', 'i', 'o', 'u')

diferenca = list(set(tupla_10_1).difference(set(tupla_10_2)))

print(f"A diferença entre as tuplas *10_1 e *10_2 será: {diferenca}")

input("\n\nPressione enter para continuar...")
print('\n')
print("FIM! =]")