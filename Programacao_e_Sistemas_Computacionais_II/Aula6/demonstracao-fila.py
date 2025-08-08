# Fila
# FIFO


filaTeste = []


# Como inserir itens em uma fila
def enqueue(fila, elemento):
    fila.append(elemento)


# Como remover itens em uma fila
def dequeue(fila):
    if len(fila) == 0:
        return "A fila está vazia."
    else:
        return fila.pop(0)


# Como saber o primeiro elemento - Peek
def peek(fila):
    if len(fila) == 0:
        return "Fila vazia."
    else:
        return fila[0]


# Como saber se está vazia - Is Empty?
def is_empty(fila):
    return len(fila) == 0


# Como saber o tamanho - Size
def size(fila):
    return len(fila)


# Reverter a fila
def queueReverser(fila):
    filaReversa = []
    while not is_empty(fila):
        item = fila.pop()
        enqueue(filaReversa, item)
    return filaReversa


# Demonstração
# Colocando elementos
enqueue(filaTeste, 1)
enqueue(filaTeste, 2)
enqueue(filaTeste, 3)       # Fila estará [1, 2, 3]


# Tirando elementos
print(dequeue(filaTeste))   # Removerá o [1]
print(peek(filaTeste))      # Retornará [2]


print(queueReverser(filaTeste))
