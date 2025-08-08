// Configura��o das Bibliotecas
#include "calculos.cpp"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main(){
    // Defini��o das Vari�veis
    int RA{};
    char verificacao{};
    string enfeite_cadastro{"\n=============BEM-VINDO AO MENU DE CADASTRO!============="}, enfeite_login{"\n[==========100%==========]\nLOGIN FEITO COM SUCESSO!"};

    // Setando a L�ngua do Terminal para PT-BR
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    
    cout<<"Insira seu RA para efetuar o seu Login: ";    // Pede o RA do usu�rio
    cin>>RA;    // Insere a informa��o para a Vari�vel RA

    if(RA==2023117055){    // Verifica se o RA do INPUT � igual ao do Boris
        cout<<enfeite_login<<endl;
        cout<<"Bem-vindo, Boris! Mas antes..."<<endl;
        verificacao = 's';    // Atribui a verifica��o como (S)im para continuar com o cadastro
    }

    else if(RA==2022216090){    // Verifica se o RA do INPUT � igual ao do Emanuel
        cout<<enfeite_login<<endl;
        cout<<"Bem-vindo, Emanuel! Mas antes..."<<endl;
        verificacao = 's';    // Atribui a verifica��o como (S)im para continuar com o cadastro
    }

    else if(RA==2022215094){    // Verifica se o RA do INPUT � igual ao do Jo�o
        cout<<enfeite_login<<endl;
        cout<<"Bem-vindo, Jo�o Vinicius! Mas antes..."<<endl;
        verificacao = 's';    // Atribui a verifica��o como (S)im para continuar com o cadastro
    }

    else{    // Se o RA inserido n�o se encontra na nossa base de dados, pergunta se deseja cadastrar-se
        cout<<"RA Invalido!"<<endl;
        cout<<"Deseja Cadastrar-se? (S/N): ";
        cin>>verificacao;    // Insere a informa��o na Vari�vel verificacao
    }

    switch(verificacao){     // Estrutura de Decis�o com SWITCH CASE para avaliar a Vari�vel verificacao
        case 's':
        case 'S':
            cout<<enfeite_cadastro<<endl;
            calculo();    // Se inserido (S)im, o arquivo calculos.cpp � executado
            break;
        case 'n':
        case 'N':
            cout<<"Reinicie caso queira fazer o Login."<<endl;
            break;    // Se inserido (N)�o, o programa encerra seu processo
    }
    return 0;
}