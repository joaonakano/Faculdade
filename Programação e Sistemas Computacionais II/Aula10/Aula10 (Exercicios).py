'''
1. Faça um programa que leia um número N e gere um arquivo com N nomes e idades aleatórios
    ⦁ Faça uso de duas listas criadas na mão: uma que contenha 20 nomes e outra que contenha 20 sobrenomes
    ⦁ Cada linha do arquivo resultante deve conter um nome completo e a sua idade
'''

import random
nomes = ["João", "Maria", "Pedro", "Ana", "Carlos", "Isabel", "Luiz", "Marta", "Ricardo", "Laura", "Fernando", "Sofia", "Antônio", "Camila", "André", "Clara", "José", "Lúcia", "Miguel", "Raquel"]
sobrenomes = ["Silva", "Santos", "Oliveira", "Pereira", "Ferreira", "Rodrigues", "Almeida", "Cunha", "Machado", "Gomes", "Lima", "Costa", "Carvalho", "Martins", "Araújo", "Ribeiro", "Dias", "Castro", "Nunes", "Cardoso"]
idades = []
# userInput = int(input("Digite a quantidade de pessoas ALEATÓRIAS a serem criadas (0 a 20): "))
'''
def exercicio1(nomeArquivo):
    global idades
    arquivo = open(nomeArquivo, "w+", encoding="utf-8")
    arquivo.write(f'{"NOMES":<10} {"SOBRENOMES":<14} {"IDADES"}\n{"="*32}\n')
    idades = []
    
    for i in range(20):
        idades.append(random.randint(1,100))
        
    for i in range(userInput):
        ponteiro = random.randint(0, 19)
        nome = str(nomes[ponteiro])
        sobrenome = str(sobrenomes[ponteiro])
        idade = str(idades[ponteiro])
        
        pessoa = f"{nome:<10} {sobrenome:<12} {idade:>3} anos\n"
        arquivo.write(pessoa)
        
    arquivo.close()
'''
# exercicio1("arquivoNomesIdades.txt")


'''
2. Estenda o exemplo do cadastro para considerar também a altura da pessoa
'''
alturas = [1.65, 1.72, 1.58, 1.76, 1.62, 1.80, 1.68, 1.73, 1.55, 1.78, 1.60, 1.70, 1.63, 1.75, 1.59, 1.71, 1.66, 1.79, 1.61, 1.74]
# userInput = int(input("Digite a quantidade de pessoas ALEATÓRIAS a serem criadas (0 a 20): "))
'''
def exercicio2(nomeArquivo):
    arquivo = open(nomeArquivo, "w+", encoding="utf-8")
    arquivo.write(f'{"NOMES":<10} {"SOBRENOMES":<15} {"IDADE":<10} {"ALTURA"}\n{"="*44}\n')
    for i in range(userInput):
        ponteiro = random.randint(0, 19)
        nome = nomes[ponteiro]
        sobrenome = sobrenomes[ponteiro]
        idade = idades[ponteiro]
        altura = alturas[ponteiro]
        pessoa = f"{nome:<10} {sobrenome:<15} {idade:<10} {altura:.2f}m\n"
        arquivo.write(pessoa)
            
    arquivo.close()
    
# exercicio2("arquivoNomesIdadesAlturas.txt")
'''

'''
3. Escreva uma função que recebe dois nomes de arquivos e copia o conteúdo do primeiro arquivo para o segundo arquivo. Considere que o conteúdo do arquivo de origem é um texto. Sua função não deve copiar linhas comentadas (que começam com //)
'''

def exercicio3(arquivoAntigo, arquivoNovo):
    old = open(arquivoAntigo, 'r')
    new = open(arquivoNovo, 'w+')
    linha = old.readline()
    
    while linha != "":
        if linha.startswith("#"):
            linha = old.readline()
        else:
            new.write(linha)
            new.write("\n")
            linha = old.readline()

    old.close()
    new.close()

# exercicio3("antigo.txt", "novo.txt")


'''
4. Faça um programa contendo uma função que recebe como argumentos os nomes de dois arquivos. O primeiro arquivo contém nomes de alunos e o segundo arquivo contém as notas dos alunos. No primeiro arquivo, cada linha corresponde ao nome de um aluno e no segundo arquivo, cada linha corresponde às notas dos alunos (uma ou mais). Assuma que as notas foram armazenadas como strings, e estão separadas umas das outras por espaços em branco. Leia os dois arquivos e gere um terceiro arquivo que contém o nome do aluno seguido da média de suas notas.
'''

def exercicio4(arquivoNomes, arquivoNotas):
    nomes = open(arquivoNomes, 'r', encoding="utf-8")
    notas = open(arquivoNotas, 'r', encoding="utf-8")
    arquivoNomesNotas = open("arquivoNomesNotas.txt", 'w+', encoding="utf-8")

    linhaNotas = notas.readline()
    linhaNomes = nomes.readline()

    while linhaNotas != "":
        listaNotas = linhaNotas.split(" ")
        nome = linhaNomes.replace("\n", "")
        soma = 0.0
        
        for item in listaNotas:
            indice = listaNotas.index(item)
            if "\n" in item:
                listaNotas[indice] = listaNotas[indice].replace("\n", "")
            soma += float(listaNotas[indice])
                
        media = "{:.2f}".format(soma / 3)
        alunoMedia = f'{nome:<20} {media}\n'
        arquivoNomesNotas.write(alunoMedia)
        linhaNotas = notas.readline()
        linhaNomes = nomes.readline()
        
    arquivoNomesNotas.close()
    nomes.close()
    notas.close()
    
# exercicio4("nomesAlunos.txt", "notasAlunos.txt")


'''
5.Faça um programa para alterar uma das notas de um aluno (usando os arquivos do exercício anterior). O programa deve ter uma função que recebe o nome do aluno, a nota velha e a nova nota. A função deve fazer a alteração no arquivo.
'''
'''
def itNomes(aluno, lista_nomes):
    for i in lista_nomes:
        if aluno == i:
            indice = lista_nomes.index(i)
            return indice

def itNotas(indice, lista_notas):
    for i in range(len(lista_notas)):
        if i == indice:
            return lista_notas[i]

def exercicio5(arquivoNotas, arquivoNomes, nomeAluno, notaAtualizada):
    arquivo_nomes = open(arquivoNomes, 'r', encoding="utf-8")
    arquivo_notas = open(arquivoNotas, 'r+', encoding="utf-8")
    nota_atualizada = notaAtualizada
    aluno = nomeAluno+'\n'

    nomes = arquivo_nomes.readlines()
    notas = arquivo_notas.readlines()
    
    if aluno in nomes:
        print("Nome encontrado!\nDeseja alterar a nota? [S]/[N]: ", end='')
        confirmacao = input()
        if confirmacao == 's' or 'S':
            indice_aluno = itNomes(aluno, nomes)
            notas_na_lista = itNotas(indice_aluno, notas)
            
            print(f"Notas encontradas: {notas_na_lista}")
            
            arquivo_notas.close()
            
            print(f"Atualizando notas...")
            
            arquivo_notas = open(arquivoNotas, 'w', encoding="utf-8")
            notas.remove(notas_na_lista)
            notas[indice_aluno] = nota_atualizada
            arquivo_notas.writelines(notas)
            
            print(f"Notas atualizadas: {itNotas(indice_aluno, notas)}")
    else:
        print(f"Nome não encontrado! {nomes}")
    arquivo_nomes.flush()
    arquivo_notas.flush()
'''
# exercicio5("notasAlunos.txt","nomesAlunos.txt", "Ana Silva", "9.0 9.0 9.0\n")


'''
6.Faça uma função que leia um arquivo texto contendo uma lista de endereços IP e gere dois outros arquivos, um contendo os endereços IP válidos e outro contendo os endereços inválidos. O formato de um endereço IP é num1.num.num.num, onde num1 vai de 1 a 255 e num vai de 0 a 255.
'''

def exercicio6(arquivoIP):
    lista_ip = open(arquivoIP, 'r')
    ip = lista_ip.readline()
    lista_ip_valido = []
    lista_ip_invalido = []

    while ip != "":
        numero_ip = ip.split(".")
        if len(numero_ip) == 4:  # Verifique se há quatro octetos
            ip_valido = True

            for i in range(4):
                octeto = numero_ip[i].replace('\n', '')

                if not (0 <= int(octeto) <= 255):
                    ip_valido = False
                    break

            if ip_valido:
                lista_ip_valido.append(numero_ip)
            else:
                lista_ip_invalido.append(numero_ip)
        else:
            lista_ip_invalido.append(numero_ip)

        ip = lista_ip.readline()
        
    print("Endereços IP válidos:")
    for ip in lista_ip_valido:
        print(".".join(ip))

    print("Endereços IP inválidos:")
    for ip in lista_ip_invalido:
        print(".".join(ip))
exercicio6("listaIP.txt")
