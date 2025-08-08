// Faça um programa que leia um numero e verifique se ele esta fora do intervalo entre 23 e 47 enquanto o numero digitado estiver dentro deste intervalo o programa deve permanecer em loop.

#include<iostream>
using namespace std;

int main(){
    int num{0};

    cout<<"Insira um numero inteiro fora do intervalo de 23 a 47\n";
    cin>>num;

    while (num >= 23 && num <= 47) {
        if (num % 2 == 0){
            system("color 2f");
        } else {
            system("color 1f");
        }
        system("CLS");
        cout<<num<<" esta fora do intervalo!"<<endl;
        cout<<"Insira um numero inteiro fora do intervalo de 23 a 47\n";
        cin>>num;
    }
}