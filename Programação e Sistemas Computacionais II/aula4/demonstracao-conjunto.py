# Conjuntos

# Criando conjuntos vazios
meu_conjunto = set()

meu_conjunto2 = {1,2,3,4}

meu_conjunto2.add(8)
meu_conjunto2.remove(2)

# Verificar se um elemento está no conjunto
if 3 in meu_conjunto2:
    print("O conjunto contém o elemento 3.")

# Operações Matemáticas
# União de Conjuntos
conjunto1 = {1,2,3}
conjunto2 = {9,10,11}
uniao = conjunto1.union(conjunto2)      # x.union(y)

# Intersecção de Conjuntos
interseccao = conjunto2.intersection(conjunto2)     # x.intersection(y)

# Diferença
diferenca = conjunto1.difference(conjunto2)     # x.difference(y)
