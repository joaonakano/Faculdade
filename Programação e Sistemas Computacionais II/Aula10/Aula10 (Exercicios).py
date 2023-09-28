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
    
exercicio4("nomesAlunos.txt", "notasAlunos.txt")


'''
5. Faça um programa para alterar uma das notas de um aluno (usando os arquivos do exercício anterior). O programa deve ter uma função que recebe o nome do aluno, a nota velha e a nova nota. A função deve fazer a alteração no arquivo.
'''

def exercicio5(arquivo):
    nomeNotas = open(arquivo, 'w+', encoding="utf-8")
    print(nomeNotas.readlines())
exercicio5("arquivoNomesNotas.txt")
