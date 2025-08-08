def fibonacci(posicao):
    if posicao == 0:
        return 0
    elif posicao == 1:
        return 1
    else:
        return fibonacci(posicao - 1) + posicao(posicao - 2)
