# Tuplas
minha_tupla = ()
minha_tupla2 = (1,2,3,4,5,"olá",6,7,8,9,"sou uma string")
print(minha_tupla2)

# Como Concatenar Tuplas
minha_tupla3 = ('a', 'b', 'tupla3')
nova_tupla = minha_tupla2 + minha_tupla3
print(f"\nA nova tupla será: {nova_tupla}")

# Verificar a Existência de um Valor em uma Tupla
if 'f' in nova_tupla:
    print("\nExiste \'f\' em nova_tupla")
else:
    print("\nNão existe \'f\' em nova_tupla")

# Como ITERAR uma Tupla
print("\nValores em uma Iteração em nova_tupla:")
for valor in nova_tupla:
    print(valor)
