# 1- Escreva uma função recursiva em Python que calcule a soma dos primeiros N números inteiros positivos.
soma_1 = 0
user_input_1 = int(input("1- Digite um número inteiro positivo: "))

def calculaSomaRecursiva(numero):
    global soma_1
    if numero == 0:
        return print(f"A soma dos primeiros {user_input_1} números será: {soma_1}")
    else:
        soma_1 += numero
        return calculaSomaRecursiva(numero - 1)
    
calculaSomaRecursiva(user_input_1)

# 2- Escreva uma função recursiva para calcular o número fatorial de um número inteiro positivo.
user_input_2 = int(input("\n2- Digite um número para saber seu fatorial: "))

def calculaFatorialRecursivo(numero):
    if numero == 1:
        return 1
    return numero * calculaFatorialRecursivo(numero - 1)

print(f"O fatorial do número \"{user_input_2}\" é: {calculaFatorialRecursivo(user_input_2)}")


# 3- Escreva uma função que use uma pilha para inverter uma string.
input_user_3 = str(input("\n3- Digite uma palavra para inverter: ")).replace(" ", "").lower()
def inverterString(palavra):
    palavraPilha, palavraPilhaReverse, palavraReverse = [], [], ""
    
    for i in range(len(palavra)):
       palavraPilha.append(palavra[i])
    
    for j in range(len(palavraPilha)):
        palavraPilhaReverse.append(palavraPilha.pop())
    
    for i in range(len(palavraPilhaReverse)):
        palavraReverse += palavraPilhaReverse[i]

    return palavraReverse
    
print(inverterString(input_user_3))

# 4- Escreva uma função que converte um número decimal em sua representação binária usando uma pilha.,
def converteBinario(numero):
    binario = ""
    if numero == 0:
        return "0"
    
    while numero > 0:
        resto_da_divisao = numero % 2
        numero = numero // 2
        binario = str(resto_da_divisao) + binario
        
    return binario
    
input_user_4 = int(input("\n4- Digite um número e saiba seu correspondente binário: "))
print(converteBinario(input_user_4))

# 5- Implemente um histórico de comandos de um editor de texto simples usando uma pilha. A cada vez que um comando é executado, ele é adicionado à pilha. Implemente a capacidade de desfazer um comando usando a pilha.
boas_vindas = str(input("\nOlá, bem vindo à Central de Comandos! Insira um comando para prosseguirmos: "))
comandos, resposta, verificador = [boas_vindas], '', 1

def verificadorDeInput():
    global verificador, resposta
    resposta = str(input("\nDeseja INSERIR outro comando? (S)/(N): "))
    
    if resposta == "n" or resposta == "N":
        verificador = 0
    else:
        verificador = 1
        
    return verificador

def prompt():
    bash = str(input("\ncomandos@bashunofficial:~$ "))
    comandos.append(bash)

while True:
    verificadorDeInput()
    if verificador == 0:
        resposta = str(input("\nDeseja APAGAR o comando prévio? (S)/(N): "))
        
        if resposta == "s" or resposta == "S":
            print(f"\n-> O comando \"{comandos[-1]}\" foi apagado do registro com sucesso!")
            comandos.pop()
            if len(comandos) != 0:
                print(f"-> Comandos prévios: {comandos}")
            else:
                print(f"-> Oba! Não há comandos para serem apagados.")
        else:
            break
    else:
        prompt()