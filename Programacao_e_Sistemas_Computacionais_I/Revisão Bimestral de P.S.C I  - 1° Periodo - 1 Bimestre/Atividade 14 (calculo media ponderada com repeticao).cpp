// Faça um algoritmo que leia as 3 notas de um aluno e calcule a sua média anual ponderada, com o peso: 2, 3 e 5, respectivamente. Se a nota obtida for entre 6 a 10 está aprovado; se é entre 4 e 5.9 em recuperação, se é menor que 4 reprovado. Se o aluno está em recuperação ler a nota de recuperação e calcular a média final (que é a média entre a média anual e a nota de recuperação). Se a média final é menor que 5 o aluno está reprovado após recuperação, se é igual ou maior que 5 está aprovado após recuperação.

#include<iostream>
using namespace std;

int main(){
    float nota1{}, nota2{}, nota3{}, media_ponderada{}, nota_recuperacao{}, media_final{};
    const float peso1{2}, peso2{3}, peso3{5};
    string enfeite{"-----------------------------------"};

    // Input
    cout<<"Insira suas tres notas separadas por um espaco (\" \"): ";
    cin>>nota1>>nota2>>nota3;
    cout<<enfeite<<'\n';

    // Calculo da Media Anual Ponderada
    media_ponderada = ((nota1*peso1)+(nota2*peso2)+(nota3*peso3))/(peso1+peso2+peso3);

    // Estrutura de Decisao
    for (int i=1; i<=2; i++) {    // Uso do FOR para rodar as condições novamente e automatizar o processo de verificação.
        if (media_ponderada >= 6 && media_ponderada <= 10) {
            cout<<"Voce esta aprovado, com media "<<media_ponderada<<"!"<<'\n'<<enfeite<<'\n';
            break;
        } else if (media_ponderada >= 4 && media_ponderada <= 5.9) {
            if (media_final < 5 && media_final != 0) {    // IF atua como verificador, se a a NOTA DA RECUPERAÇÃO foi INSERIDA, então diz se foi aprovado ou reprovado. Caso contrário, ele executa o código do ELSE para PEDIR a NOTA DA RECUPERAÇÃO e REPETIR NOVAMENTE os IFs.
                cout<<"Voce esta reprovado."<<'\n'<<enfeite<<'\n';
            } else if (media_final >= 5 && media_final != 0) {
                cout<<"Voce esta aprovado."<<'\n'<<enfeite<<'\n';
            } else {
                cout<<"Voce esta em recuperacao, com media "<<media_ponderada<<"!"<<'\n';
                
                cout<<"Insira sua nota de recuperacao: ";    // Pega o valor da recuperação e o sobrepoe na variavel nota_recuperacao.
                cin>>nota_recuperacao;
                
                media_final = (media_ponderada + nota_recuperacao) / 2;    // Faz o calculo da media anual e sobrepoe o resultado na variavel media_ponderada.
            }
        } else if (media_ponderada < 4) {
            cout<<"Voce esta reprovado, com media "<<media_ponderada<<"!"<<'\n'<<enfeite<<'\n';
            break;
        } else {
            cout<<"A media nao esta correta!"<<'\n';
            break;
        }
    }
}