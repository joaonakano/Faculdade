# Inputs
print("Olá, usuário! Quantos pães foram vendidos?")
totalDePaes = input()
precoTotalDosPaes = float(totalDePaes) * 0.80

# Inputs
print("E quantas broas foram vendidas?")
totalDeBroas = input()
precoTotalDasBroas = float(totalDeBroas) * 2.50

# Cálculos
totalArrecadado = float(precoTotalDasBroas + precoTotalDosPaes)
custosDeFabricacao = float(0.43 * totalArrecadado)
totalDaPoupanca = float((totalArrecadado - custosDeFabricacao) * 0.15)
totalViagemReais = float((totalArrecadado - custosDeFabricacao) * 0.15)
totalViagemEuros = float(totalViagemReais / 4.60)
lucro = float(totalArrecadado - custosDeFabricacao - totalDaPoupanca - totalViagemReais)

# Output de todos os Cálculos
print("Foram vendidos", totalDePaes,"pães.")
print("Foram vendidas", totalDeBroas, "broas.")
print("O total arrecadado foi", totalArrecadado, "reais.")
print("Os custos de fabricação somaram {custo:.2f} reais.".format(custo = custosDeFabricacao))
print("O valor destinado à poupança foi de {valorpoupanca:.2f} reais.".format(valorpoupanca = totalDaPoupanca))
print("O valor destinado à viagem em R$ foi de {totalreais:.2f} reais.".format(totalreais = totalViagemReais))
print("O valor destinado à viagem em £ foi de {totaleuros:.2f} euros.".format(totaleuros = totalViagemEuros))
print("Seu LUCRO foi de {lucro:.2f} reais.".format(lucro = lucro))
