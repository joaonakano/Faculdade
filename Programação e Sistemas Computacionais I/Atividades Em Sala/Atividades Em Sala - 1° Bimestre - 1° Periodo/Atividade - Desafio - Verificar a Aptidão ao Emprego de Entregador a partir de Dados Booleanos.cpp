#include<iostream>
using namespace std;
int main() {
    int idade;
    bool numero_valido{false}, permissao_pais{false}, acidentes{false};
    cout<<boolalpha;

    cout<<"Insira seus anos de vida: ";
    cin>>idade;
    cout<<"O numero de seu seguro social e valido (digite 1 para sim, digite 0 para nao): ";
    cin>>numero_valido;
    cout<<"Voce ja se envolveu em algum acidente de transito (digite 1 para sim, digite 0 para nao):";
    cin>>acidentes;
    if (idade == 17 || idade == 16) {
        cout<<"Voce tem permissao dos seus pais (digite 1 para sim, digite 0 para nao): ";
        cin>>permissao_pais;
        cout<<"Voce esta apto para o emprego de motorista de entrega: "<<(permissao_pais&&numero_valido&&!acidentes);
    } else {
        cout<<"Voce esta apto para o emprego de motorista de entrega: "<<(idade>=18&&numero_valido&&!acidentes);
    }    
}

