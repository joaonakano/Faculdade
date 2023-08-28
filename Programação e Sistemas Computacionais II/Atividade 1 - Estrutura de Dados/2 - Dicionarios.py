# Dicionários
print("========= Desafio - Dicionários =========")

# 1- Crie um dicionário vazio e adicione duas chaves e valores a ele.
dicionario_01 = {}

dicionario_01.update({"Chave_01":"Valor_01","Chave_02":"Valor_02"})

print(f"\n1- Valores adicionados ao dicionário 1: {dicionario_01}")

# 2- Crie um dicionário com as chaves "nome", "idade" e "cidade" e preencha com seus dados. Imprima o dicionário.
dicionario_02 = {"nome":[], "idade":[], "cidade":[]}
user_input_02_nome, user_input_02_idade, user_input_02_cidade = input("\n2- Digite seu nome: "), input(" * Digite sua idade: "), input(" * Digite sua cidade: ")

dicionario_02.update({"nome":user_input_02_nome, "idade":user_input_02_idade, "cidade":user_input_02_cidade})

print(f"As informações foram registradas no dicionário: {dicionario_02}")

# 3- Crie um dicionário com o nome e o preço de três produtos diferentes. Imprima o dicionário.
dicionario_03 = {
    "preco": [17, 2.50, 9.99],
    "produto": ["Bacia de Plástico", "Salgado", "Xhitos"]
}

hover_preco_03, hover_produto_03 = dicionario_03["preco"], dicionario_03["produto"]

print("\n3- ")
for iterador in hover_produto_03:
    indice = hover_produto_03.index(iterador)
    print(f"Produto: {hover_produto_03[indice]} --------------- Preço:{hover_preco_03[indice]}")

# 4- Crie um dicionário com o nome de três estados e suas respectivas capitais. Peça ao usuário para digitar um estado e imprima a capital correspondente.
dicionario_04 = {
    "estados": ["parana", "paraná", "santacatarina", "riograndedosul"],
    "capitais": ["Curitiba", "Curitiba", "Florianópolis", "Porto Alegre"],
    "respostas": ["Paraná", "Paraná", "Santa Catarina", "Rio Grande do Sul"]
} 

hover_estados_04, hover_capitais_04, hover_respostas_04 = dicionario_04["estados"], dicionario_04["capitais"], dicionario_04["respostas"]
user_input_04_estado = str(input("\n4- Digite um Estado da região SUL do Brasil (parana, santa catarina ou rio grande do sul): ")).replace(" ", "").lower()

for i in hover_estados_04:
    if user_input_04_estado == i:
        indice = hover_estados_04.index(i)
        print(f"A capital de {hover_respostas_04[indice]} é {hover_capitais_04[indice]}!")
        break
    elif i == hover_estados_04[-1] and user_input_04_estado != i:
        print(f"A capital de {user_input_04_estado} não existe no conjunto!")
        break

# 5- Crie um dicionário com o nome de cinco cidades e suas respectivas populações. Imprima a cidade com a maior população.
dicionario_05 = {
    "São Paulo": 12252023,
    "Rio de Janeiro": 6747815,
    "Belo Horizonte": 2523794,
    "Salvador": 2886698,
    "Brasília": 3055149
}

cidade_mais_populosa_05 = max(dicionario_05)

print(f"\n5- A cidade com maior população do dicionário 5 é {cidade_mais_populosa_05} com {dicionario_05[cidade_mais_populosa_05]} habitante!")

# 6- Crie um dicionário com o nome de três alimentos e suas respectivas calorias. Peça ao usuário para digitar um alimento e imprima a quantidade de calorias correspondente.
dicionario_06 = {
    "alimentos": ["banana", "cereal", "cacau", "nescau"],
    "calorias": [105, 110, 12, 80]
}

hover_alimentos_06, hover_calorias_06 = dicionario_06["alimentos"], dicionario_06["calorias"]
user_input_06_alimento = input("\n6- Digite um dos seguintes alimentos e cheque suas calorias -> banana, cereal, cacau ou nescau: ")

for i in hover_alimentos_06:
    if user_input_06_alimento == i:
        indice = hover_alimentos_06.index(i)
        print(f"O alimento \"{user_input_06_alimento}\" tem \"{hover_calorias_06[indice]}\" calorias segundo a database!")
        break
    elif i == hover_alimentos_06[-1] and user_input_06_alimento != i:
        print(f"Não foi encontrado o alimento \"{user_input_06_alimento}\" na lista!")
        break

# 7- Crie um dicionário com o nome de cinco animais e suas respectivas classificações (mamífero, ave, réptil, etc.). Imprima apenas os nomes dos animais.
dicionario_07 = {
    'Elefante': 'Mamífero',
    'Pinguim': 'Ave',
    'Cobra': 'Réptil',
    'Golfinho': 'Mamífero',
    'Jacaré': 'Réptil'
}

print("\n7- Os animais do dicionário 7 são: ")
for i in dicionario_07:
    print(f"* {i}")

# 8- Crie um dicionário com o nome de cinco países e suas respectivas bandeiras. Imprima apenas os nomes dos países.
dicionario_08 = {
    "Japão":"https://www.countryflags.com/wp-content/uploads/japan-flag-png-large.png",
    "Bolívia":"https://www.countryflags.com/wp-content/uploads/flag-jpg-xl-1536x1050.jpg",
    "El Salvador":"https://www.countryflags.com/wp-content/uploads/el-salvador-flag-png-large.png",
    "México":"https://www.countryflags.com/wp-content/uploads/mexico-flag-png-large.png",
    "China":"https://www.countryflags.com/wp-content/uploads/china-flag-png-large.png"
}

print("\n8- Países dentro do dicionário 8:")
for i in dicionario_08:
    print(f"* {i}")

# 9- Crie um dicionário com o nome de cinco frutas e suas respectivas cores. Imprima o nome de cada fruta seguido de sua cor.
dicionario_09 = {
    'Maçã': 'Vermelha',
    'Banana': 'Amarela',
    'Morango': 'Vermelha',
    'Uva': 'Roxa',
    'Laranja': 'Laranja'
}

print("\n9- Fruta seguida de sua cor:")
for i in dicionario_09:
    print(f"* Fruta: {i} -------- Cor: {dicionario_09[i]}")

# 10 - Crie um dicionário com o nome de três jogos e a quantidade de jogadores necessária. Peça ao usuário para digitar um jogo e imprima a quantidade de jogadores correspondente.
dicionario_10 = {
    "jogos": ["happywheels", "teamfortress2", "gmod"],
    "jogadores": [1, 2, 1],
    "respostas": ["Happy Wheels", "Team Fortress 2", "Garry's Mod"]
}

user_input_10_jogo = input("\n10- Digite o nome de um dos jogos para checar os jogadores necessários -> happywheels, teamfortress2 ou gmod: ")
hover_jogos, hover_jogadores, hover_respostas = dicionario_10["jogos"], dicionario_10["jogadores"], dicionario_10["respostas"]

for i in hover_jogos:
    indice = hover_jogos.index(i)
    if i == user_input_10_jogo:
        print(f"O jogo \"{hover_respostas[indice]}\" precisa de \"{hover_jogadores[indice]}\" jogadores!")
        break
    elif i == hover_jogos[-1] and user_input_10_jogo != i:
        print(f"O jogo \"{hover_respostas[indice]}\" não existe na database.")
        break
