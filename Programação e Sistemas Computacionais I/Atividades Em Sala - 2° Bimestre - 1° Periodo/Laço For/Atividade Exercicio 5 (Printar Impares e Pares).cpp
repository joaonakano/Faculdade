#include<iostream>
#include<string>
using namespace std;

int main(){
    string pares{}, impares{};
    int valor_user{};

    for (int i = 1; i <= 10; i++){
        cout<<"Insira o "<<i<<" valor: ";
        cin>>valor_user;

        if (valor_user % 2 == 0){
            pares += " " + to_string(valor_user);
        } else {
            impares += " " + to_string(valor_user);
        }
    }

    cout<<"\nNUMEROS PARES: "<<pares<<'\n';
    cout<<"NUMEROS IMPARES: "<<impares<<'\n';
}