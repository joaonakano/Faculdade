// Faça um programa que receba uma senha formada de quatro números inteiros, verifique se a senha está correta e, caso não esteja, solicite novamente a senha. Se a senha entrada for a correta, deverá ser apresentada a mensagem “Senha Correta”, caso contrário, “Senha Incorreta”.

#include<iostream>
#include <cstdlib>
using namespace std;

int main(){
    int senha_padrao{4425}, senha_usuario{};

    do{
        cout<<"Insira uma senha composta por 4 numeros INTEIROS\n";
        cin>>senha_usuario;

        if (senha_usuario == senha_padrao){
            system("clear");
            cout<<"Senha correta, senhor(a)!"<<'\n';
        } else {
            system("clear");
            cout<<"Senha incorreta, senhor(a)! Tente novamente."<<'\n';
        }
    } while (senha_usuario != senha_padrao);
}