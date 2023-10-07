#include<iostream>

using namespace std;
int main() {
    int cont{10};
    int result{10};

    //exemplo 1 - incremento simples
    cout<<"Contando: "<<cont<<endl;

    cont = cont + 1;

    cout<<"Contando: "<<cont<<endl;

    cont++;
    cout<<"Contando: "<<cont<<endl;

    ++cont;
    cout<<"Contando: "<<cont<<endl;

    cout<<"================================================="<<endl;
    cont = 10;
    result = 0;
    
    cout<<"Contando: "<<cont<<endl;
    result = ++cont;
    cout<<"Contando: "<<cont<<endl;
    cout<<"Resultado: "<<result<<endl;

}