// 1. Escreva um programa em JavaScript que exiba na tela o maior número entre dois números fornecidos pelo usuário.
function exercicio1() {
    let numero1 = +prompt("1. Digite o Primeiro Número");
    let numero2 = +prompt("1. Digite o Segundo Número");
    alert("Acesse o console -> 1. Inspecionar Elemento, 2. Console")

    if (numero1 > numero2) {
        console.log("Atividade 1: " + numero1 + " é maior que " + numero2);
    } else if (numero1 == numero2) {
        console.log("Atividade 1: os dois números são iguais.");
    } else {
        console.log("Atividade 1: " + numero2 + " é maior que " + numero1);
    }
}

// 2. Escreva um programa em JavaScript que exiba na tela uma mensagem de acordo com a nota do usuário. Se a nota for menor do que 6, exiba "Reprovado". Se a nota for maior ou igual a 6 e menor do que 8, exiba "Aprovado". Se a nota for maior ou igual a 8, exiba "Aprovado com louvor".
function exercicio2() {
    let numero1 = +prompt("2. Digite sua Nota");
    alert("Acesse o console -> 1. Inspecionar Elemento, 2. Console");

    if (numero1 >= 8) {
        console.log("Atividade 2: Aprovado com Louvor");
    } else if (numero1 >= 6) {
        console.log("Atividade 2: Aprovado");
    } else if (numero1 < 6) {
        console.log("Atividade 2: Reprovado");
    }
}

// 3. Escreva um programa em JavaScript que exiba na tela a média dos números de um vetor.
function exercicio3() {
    let vetor = [];
    let maiorNumero = 0;
    
    for (let i = 1; i <= 5; i++) {
        let numero = +prompt("3. Digite a nota " + i);
        vetor.push(numero);
        if (numero > maiorNumero) {
            maiorNumero = numero;
        }
    }

    alert("Acesse o console -> 1. Inspecionar Elemento, 2. Console");
    console.log("Atividade 3: o maior número do vetor [" + vetor + "] é " + maiorNumero);
}

// 4.