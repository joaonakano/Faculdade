nomes = ["Jason", "Michael Myers", "PinHead", "GhostFace", "Freddy Krueger"]
idades = [666, 50, 30, 17, 40]
somatorio = 0
mediaIdades = 0

for i in range(len(idades)):
    if idades[i] >= 18:
        print(f"Maior de idade: {nomes[i]} com {idades[i]} anos.")
        somatorio += idades[i]

del nomes[2], idades [2]
print(f"Lista com o índice 2 removido: {nomes} {idades}")

nomes.append("Chucky")
idades.append(10)
print(f"Lista com um nome adicionado e uma idade adicionada: {nomes} {idades}")
