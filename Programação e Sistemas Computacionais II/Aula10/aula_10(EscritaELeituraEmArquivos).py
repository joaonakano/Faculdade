import random


# Exercício 1 -  Função que Escreve uma Sequência de Números Aleatórios em um Arquivo
def escreverNumerosAleatorios(qtdNumeros, nomeArquivo):
    arquivoNumeros = open(nomeArquivo, 'w') #<-- 'w' - Write      Abertura do Arquivo
    
    for i in range(qtdNumeros):
        arquivoNumeros.write(str(random.randint(0, 100)))       # Escrita do Arquivo
        arquivoNumeros.write('\n')                              # Escrita do Arquivo
            
    arquivoNumeros.close()                                      # Fechamento do Arquivo
    
    
''' Maneira simples - Sem While
def escreverMedia(nomeArquivo):
    arquivoNumeros = open(nomeArquivo)                          # Abertura do Arquivo
    soma, qtdNumeros = 0, 0
    
    for i in arquivoNumeros:
        num = float(arquivoNumeros.readline())                  # Leitura do Arquivo
        soma += num
        qtdNumeros += 1
        
    arquivoNumeros.close()                                      # Fechamento do Arquivo
    
    return soma / qtdNumeros
'''


# Exercício 2 -  Função que Calcula a Média dos Números dentro de um Arquivo
def escreverMedia(nomeArquivo):
    arquivoNumeros = open(nomeArquivo)                          # Abertura do Arquivo
    soma, qtdNumeros = 0, 0
    num = arquivoNumeros.readline()                             # Leitura da Primeira Linha do Arquivo
    
    while num != "":
        soma += float(num)
        qtdNumeros += 1
        num = arquivoNumeros.readline()                         # Leitura da Próxima Linha do Arquivo
        
    arquivoNumeros.close()                                      # Fechamento do Arquivo
    return soma / qtdNumeros


'''Como é estruturada a leitura e gravação de arquivos?

-> varArquivo = open(nomeArquivoFisico, modo, buffering)
modo = [r] leitura, [w] escrita, [a] escrita a partir do final, [r+] leitura e escrita'''


def falaEscreve(nomeArquivo, listaString):
    arquivo = open(nomeArquivo, "w")
    linha = " ".join(listaString)
    arquivo.write(linha)
    arquivo.close()


def copiaArquivos(arquivoAntigo, arquivoNovo):
    f1 = open(arquivoAntigo, "r")
    f2 = open(arquivoNovo, "w+")
    
    for texto in f1:
        f2.write(texto)
        
    f1.close()
    f2.close()


def leArquivos(arquivo):
    f1 = open(arquivo, 'r')
    stringLista = f1.readlines()
    print(stringLista)
    f1.close()
    

falaEscreve("transcription.txt", ["Hello", "hello?", "How","are", "you?"])      # Exemplo meu para inserir espaços em uma lista
print(escreverMedia('numeros.txt'))                                             # Execução da Função do Exercício 2 (!)
escreverNumerosAleatorios(100, 'aleatorios.txt')                                # Execução da Função do Exercício 1 (!)
copiaArquivos("transcription.txt", "copia.txt")                                 # Exemplo em aula de uma função que copia um arquivo
leArquivos("copia.txt")                                                         # Exemplo meu para ler o conteúdo de um arquivo