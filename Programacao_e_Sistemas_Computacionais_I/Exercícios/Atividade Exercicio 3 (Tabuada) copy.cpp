#include<iostream>
using namespace std;

int main(){
    int valor_user{}, tabuada{};

    for (int i = -1; i < 0 || i > 10; i = valor_user){
        cout<<"Insira um numero de 1 a 10: "<<endl;
        cin>>valor_user;
    }

    cout<<"Tabuada do "<<valor_user<<"!"<<endl;

    for (int b = 1; b <= 10; b++){
        tabuada = b * valor_user;
        cout<<b<<"x"<<valor_user<<" = "<<tabuada<<endl;
    }
}