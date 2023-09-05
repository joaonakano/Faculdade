'''
Desafio - 04/09/2023
Uma pessoa está em uma fila de um parque de diversões e deseja saber qual é o tempo de espera estimado para chegar
ao brinquedo. Cada pessoa leva um determinado tempo para utilizar o brinquedo e, em seguida, sai da fila.
A pessoa quer saber qual será a sua posição na fila e quanto tempo ela terá que esperar par a chegar ao brinquedo.
'''


def enqueue(fila, elemento):
    fila.append(elemento)


def dequeue(fila):
    if len(fila) == 0:
        return "A fila está vazia."
    else:
        return fila.pop(0)


def peek(fila):
    if len(fila) == 0:
        return "Fila vazia."
    else:
        return fila[0]


def is_empty(fila):
    return len(fila) == 0


def size(fila):
    return len(fila)


filaTeste = ['pessoa1', 'pessoa2', 'pessoa3', 'pessoa4']
tempoMedio = 20     # 20 minutos


def estimador(fila, tempo):
    somador = 0                     # Variável acumuladora
    ultimaPessoa = fila.index(fila[-1])
    while not is_empty(filaTeste):
        if (somador/20) == ultimaPessoa:
            break
        else:
            pessoa = dequeue(fila)
            somador += tempo
    return somador

print(estimador(filaTeste, tempoMedio), "minutos de espera.")
print(f"Existem {size(filaTeste) - 1} pessoas na sua frente.")
