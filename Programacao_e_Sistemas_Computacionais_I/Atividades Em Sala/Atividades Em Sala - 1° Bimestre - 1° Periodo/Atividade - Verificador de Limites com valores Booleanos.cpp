// determinar se as entradas estão entre os numero inteiros

#include<iostream>
using namespace std;
int main() {
    int num{};
    const int menor{10}, maior{20};
    cout<<boolalpha;

    cout<<"Informe um numero entre "<<menor<<" e "<<maior<<" : ";
    cin>>num;

    bool entre_limites{false};
    entre_limites = (num>menor) && (num<maior);

    cout<<num<<" esta entre "<<menor<<" e "<<maior<<": "<<entre_limites<<endl;

    cout<<"Informe um numero fora de "<<menor<<" e "<<maior<<": ";
    cin>>num;
    entre_limites = (num<menor) || (num>maior);

    cout<<num<<" esta fora de "<<menor<<" e "<<maior<<": "<<entre_limites<<endl;
}