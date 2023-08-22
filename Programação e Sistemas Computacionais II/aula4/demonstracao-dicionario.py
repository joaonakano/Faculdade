# Dicionários
meu_dicionario = {}
meu_dicionario2 = {'nome': 'Maria Joaquina', 'idade': 9, 'cidade': 'Guarapuava'}
print(meu_dicionario2['nome'])

# Adicionando Elementos
meu_dicionario2['profissão'] = 'atriz'
print(meu_dicionario2['profissão'])

# Removendo Elementos
del meu_dicionario2['nome']

# Verificar a Existência de uma Chave
if 'nome' in meu_dicionario2:
    print("A chave \'nome\' existe no dicionário.\n")

# Coletar todas as Chaves do Dicionário
chaves = meu_dicionario2.keys()
print(f"\nAs chaves são: {chaves}")

# Coletar todos os Valores do Dicionário
valores = meu_dicionario2.values()
print(f"Os valores são: {valores}\n")

# Como ITERAR um Dicionário
for chave, valor in meu_dicionario2.items():
    print(f"{chave}: {valor}")

# Mesclar DOIS Dicionários
meu_dicionario3 = {'sobrenome': 'Arlindo', 'telefone':'(99)99321000'}
meu_dicionario2.update(meu_dicionario3)
print('\nDicionário Atualizado (dict2+dict3):', meu_dicionario2)
