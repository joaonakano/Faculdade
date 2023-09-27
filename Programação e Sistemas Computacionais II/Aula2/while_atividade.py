clienteNumero = 1
descontos = 0

while clienteNumero <= 10:
    clienteNome = str(input(f"Olá, cliente número {clienteNumero}. Qual o seu nome? "))
    produtoValor = float(input("Insira o valor do produto: "))

    if produtoValor >= 1500:
        descontoProduto = 0.2 * produtoValor
    elif produtoValor < 1500:
        descontoProduto = 0.15 * produtoValor

    descontos = descontos + descontoProduto
    print(f"Olá, {clienteNome}. O valor da compra é de R$ {produtoValor}. O desconto aplicado será de R$ {descontoProduto} e o valor a ser pago será de R$ {produtoValor - descontoProduto}")
    clienteNumero = clienteNumero + 1

print("---------------------------- FIM DOS CÁLCULOS ----------------------------")
print(f"O total de desconto dado será de R$ {descontos}")

