/*
Faça um algoritmo que leia as 4 notas de um aluno e calcule a sua
média anual ponderada, com o peso:
1, 3, 4 e 5, respectivamente.

Se a nota obtida for entre 7 a 10 está aprovado;
Se a nota obtiva for entre 4 e 6.9 em recuperação;
Se é menor que 4 reprovado.
Ao final pergunte se o usuário quer calcular uma nova média.
*/

#include<iostream>
using namespace std;

int main(){
    double nota{0},peso1{1},peso2{3},peso3{4},peso4{5},somatorio_notas_pelo_peso{0},media_ponderada{0};
    char verificador{'s'};
    string enfeite_borda{" —————————————————✦—————————————————"};

    do {
        cout<<enfeite_borda<<'\n';
        for(int contador = 1; contador <= 4; contador++){
            cout<<"Digite a "<<contador<<" nota: ";
            cin>>nota;

            switch(contador){
                case 1:
                    somatorio_notas_pelo_peso += (nota * peso1);
                    break;
                case 2:
                    somatorio_notas_pelo_peso += (nota * peso2);
                    break;
                case 3:
                    somatorio_notas_pelo_peso += (nota * peso3);
                    break;
                case 4:
                    somatorio_notas_pelo_peso += (nota * peso4);
                    media_ponderada = somatorio_notas_pelo_peso / (peso1+peso2+peso3+peso4);
                    break;
            }
        }
        cout<<"A media de suas notas e igual a "<<media_ponderada<<'\n';

        if (media_ponderada >= 7 && media_ponderada <= 10){
            cout<<"Voce esta aprovado! Parabens pela conquista."<<'\n'<<enfeite_borda<<'\n';
        } else if (media_ponderada >= 4 && media_ponderada <= 6.9) {
            cout<<"Voce esta em recuperacao! Estude um pouco e passe!"<<'\n'<<enfeite_borda<<'\n';
        } else {
            cout<<"Voce esta reprovado! Sinto muito, estude mais."<<'\n'<<enfeite_borda<<'\n';
        }
        
        cout<<"Deseja calcular a media novamente? (S)im ou (N)ao: ";
        cin.ignore();
        cin>>verificador;
    } while (verificador == 's' || verificador == 'S');
}