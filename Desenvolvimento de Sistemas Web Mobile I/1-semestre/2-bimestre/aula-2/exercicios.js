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
    let tamanhoVetor = +prompt("3. Insira a quantidade de números dentro do vetor");

    for (let i = 1; i <= tamanhoVetor; i++){
        let numero = +prompt("3. Insira o " + i + " número");
        vetor.push(numero);
    }

    let soma = 0;

    for (let i = 0; i < tamanhoVetor; i++) {
        soma += vetor[i];
    }

    let media = soma / tamanhoVetor;

    alert("Acesse o console -> 1. Inspecionar Elemento, 2. Console");
    console.log("Atividade 3: a media do números do vetor [" + vetor + "] é " + media);
}

// 4. Escreva um programa em JavaScript que exiba na tela uma mensagem de acordo com o valor de uma variável. Se a variável for igual a "a", exiba "A". Se a variável for igual a "b", exiba "B". Se a variável não for nem "a" nem "b", exiba "Outra letra".
function exercicio4() {
    variavelUsuario = prompt("4. Insira uma letra (a, b ou outras)");
    alert("Acesse o console -> 1. Inspecionar Elemento, 2. Console");

    if (variavelUsuario == 'a') {
        console.log("Atividade 4: 'A'");
    } else if (variavelUsuario == 'b') {
        console.log("Atividade 4: 'B'");
    } else {
        console.log("Atividade 4: Outra letra");
    }
}

// 5. Escreva um programa em JavaScript que exiba na tela a soma dos elementos de uma matriz.
function exercicio5() {
    const tamanhoMatrizLinhas = +prompt("5. Insira a quantidade de LINHAS da Matriz");
    const tamanhoMatrizColunas = +prompt("5. Insira a quantidade de COLUNAS da Matriz");
    let matriz = [];
    let soma = 0;

    for (let i = 0; i < tamanhoMatrizLinhas; i++) {
        matriz[i] = [];
        for (let j = 0; j < tamanhoMatrizColunas; j++) {
            matriz[i][j] = +prompt(`5. Insira o número da linha ${i+1} coluna ${j+1}`);
            soma += matriz[i][j];
        }
    }

    alert("Acesse o console -> 1. Inspecionar Elemento, 2. Console");
    console.log(`Atividade 5: Matriz ${tamanhoMatrizLinhas}x${tamanhoMatrizColunas}. A soma dos elementos será ${soma}`);
}

// 6. Escreva um programa em JavaScript que exiba na tela o fatorial de um número fornecido pelo usuário.
function exercicio6() {
    let numero = +prompt("6. Insira um número e receba seu fatorial");
    let fatorial = numero;
    alert("Acesse o console -> 1. Inspecionar Elemento, 2. Console");
    
    for (let i = (fatorial - 1); i > 0; i--) {
        fatorial = fatorial * i;
    }

    console.log(`Atividade 6: Fatorial de ${numero} é ${fatorial}`);
}

// 7. Escreva um programa em JavaScript que exiba na tela uma mensagem de acordo com a escolha do usuário em um menu de opções. O menu deve ter as opções "1. Opção 1", "2. Opção 2" e "3. Opção 3". Se o usuário escolher a opção 1, exiba "Opção 1 escolhida". Se o usuário escolher a opção 2, exiba "Opção 2 escolhida". Se o usuário escolher a opção 3, exiba "Opção 3 escolhida". Se o usuário escolher uma opção inválida, exiba "Opção inválida".
function exercicio7(){
    let escolha = +prompt("7. Insira uma opção (1. Opção 1, 2. Opção 2 e 3. Opção 3)");
    alert("Acesse o console -> 1. Inspecionar Elemento, 2. Console");

    if (escolha == 1) {
        console.log("Atividade 7: Opção 1 escolhida");
    } else if (escolha == 2) {
        console.log("Atividade 7: Opção 2 escolhida");
    } else if (escolha == 3) {
        console.log("Atividade 7: Opção 3 escolhida");
    } else {
        console.log("Atividade 7: Opção inválida");
    }
}

// 8. Escreva um programa em JavaScript que exiba na tela o maior número de um vetor.
function exercicio8() {
    let vetor = [];
    let tamanhoVetor = +prompt("8. Insira a quantidade de números");
    let maiorNumero = 0;

    for (let i = 0; i < tamanhoVetor; i++) {
        vetor[i] = +prompt(`8. Insira o ${i+1} número`)

        if (vetor[i] > maiorNumero) {
            maiorNumero = vetor[i];
        }
    }

    alert("Acesse o console -> 1. Inspecionar Elemento, 2. Console");
    console.log(`Atividade 8: o maior número do vetor [${vetor}] é ${maiorNumero} na posição vetor[${vetor.indexOf(maiorNumero)}]`);
}

// 9. Escreva um programa em JavaScript que exiba na tela a média dos elementos de uma matriz.
function exercicio9() {
    let matriz = [];
    let tamanhoMatrizLinhas = +prompt("9. Insira a quantidade de LINHAS da Matriz");
    let tamanhoMatrizColunas = +prompt("9. Insira a quantidade de COLUNAS da Matriz");
    let soma = 0;

    for (let i = 0; i < tamanhoMatrizLinhas; i++) {
        matriz[i] = [];

        for (let j = 0; j < tamanhoMatrizColunas; j++) {
            matriz[i][j] = +prompt(`9. Insira o número da linha ${i+1} e coluna ${j+1}`);
            soma += matriz[i][j];
        }
    }

    // O JavaScript apenas contabilizou o número de linhas com o matriz.length, foi feita uma modificação para que contabilizasse também a quantidade de elementos nas colunas.
    let media = soma / (matriz.length * tamanhoMatrizColunas);

    alert("Acesse o console -> 1. Inspecionar Elemento, 2. Console");
    console.log(`Atividade 9: a média da matriz ${tamanhoMatrizLinhas}x${tamanhoMatrizColunas} é ${media}`)
}

function main(){
    let opcao = +prompt("Saudações o/, \n\nBem vindo(a) à resolução das minhas atividades de JavaScript!\nPara iniciarmos, selecione uma opção:\n\n 1. Atividade 1\n 2. Atividade 2\n 3. Atividade 3\n 4. Atividade 4\n 5. Atividade 5\n 6. Atividade 6\n 7. Atividade 7\n 8. Atividade 8\n 9. Atividade 9\n 0. Sair\n\n");

    switch (opcao) {
        case 0:
            break;
        case 1:
            exercicio1();
            verificador();
            break;
        case 2:
            exercicio2();
            verificador();
            break;
        case 3:
            exercicio3();
            verificador();
            break;
        case 4:
            exercicio4();
            verificador();
            break;
        case 5:
            exercicio5();
            verificador();
            break;
        case 6:
            exercicio6();
            verificador();
            break;
        case 7:
            exercicio7();
            verificador();
            break;
        case 8:
            exercicio8();
            verificador();
            break;
        case 9:
            exercicio9();
            verificador();
            break;
        default:
            alert("Opção inválida.");
            main();
    }

    function verificador(){
        let opcao = +prompt("Deseja entrar em outra atividade?\n\n 1. Sim\n 0. Não\n\n");

        if (opcao == 1) {
            main();
        } else if (opcao == 0) {
        } else {
            verificador();
        }
    }
}


// Inicializando o Programa
main();