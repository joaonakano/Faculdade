// Configuração das Bibliotecas
#include "calculos.cpp"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main(){
    // Definição das Variáveis
    int RA{};
    char verificacao{};
    string enfeite_cadastro{"\n=============BEM-VINDO AO MENU DE CADASTRO!============="}, enfeite_login{"\n[==========100%==========]\nLOGIN FEITO COM SUCESSO!"};

    // Setando a Língua do Terminal para PT-BR
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    
    cout<<"Insira seu RA para efetuar o seu Login: ";    // Pede o RA do usuário
    cin>>RA;    // Insere a informação para a Variável RA

    if(RA==2023117055){    // Verifica se o RA do INPUT é igual ao do Boris
        cout<<enfeite_login<<endl;
        cout<<"Bem-vindo, Boris! Mas antes..."<<endl;
        verificacao = 's';    // Atribui a verificação como (S)im para continuar com o cadastro
    }

    else if(RA==2022216090){    // Verifica se o RA do INPUT é igual ao do Emanuel
        cout<<enfeite_login<<endl;
        cout<<"Bem-vindo, Emanuel! Mas antes..."<<endl;
        verificacao = 's';    // Atribui a verificação como (S)im para continuar com o cadastro
    }

    else if(RA==2022215094){    // Verifica se o RA do INPUT é igual ao do João
        cout<<enfeite_login<<endl;
        cout<<"Bem-vindo, João Vinicius! Mas antes..."<<endl;
        verificacao = 's';    // Atribui a verificação como (S)im para continuar com o cadastro
    }

    else{    // Se o RA inserido não se encontra na nossa base de dados, pergunta se deseja cadastrar-se
        cout<<"RA Invalido!"<<endl;
        cout<<"Deseja Cadastrar-se? (S/N): ";
        cin>>verificacao;    // Insere a informação na Variável verificacao
    }

    switch(verificacao){     // Estrutura de Decisão com SWITCH CASE para avaliar a Variável verificacao
        case 's':
        case 'S':
            cout<<enfeite_cadastro<<endl;
            calculo();    // Se inserido (S)im, o arquivo calculos.cpp é executado
            break;
        case 'n':
        case 'N':
            cout<<"Reinicie caso queira fazer o Login."<<endl;
            break;    // Se inserido (N)ão, o programa encerra seu processo
    }
    return 0;
}