// Operadores Relacionais

#include<iostream>
using namespace std;

int main(){
    float num1{};
    float num2{};

    const int menor{20}, maior{10};
    cout<<boolalpha;

    cout<<"\nInforme um valor maior que "<<maior<<": ";
    cin>>num1;
    cout<<num1<<" > "<<maior<<" e "<<(num1>=maior)<<": ";

    cout<<"\nInforme um valor menor que "<<menor<<": ";
    cin>>num2;
    cout<<num2<<" < "<<menor<<" e "<<(num2<=menor)<<": ";
}