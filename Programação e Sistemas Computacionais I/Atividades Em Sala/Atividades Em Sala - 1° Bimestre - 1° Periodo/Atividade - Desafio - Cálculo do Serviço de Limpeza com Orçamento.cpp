#include<iostream>
using namespace std;
int main(){
    const double preco_quarto_grande{150.00};
    const double preco_quarto_pequeno{100.00};
    const double preco_taxa{0.06};
    const double validade_orcamento{30};
    int numero_quartos_grandes;
    int numero_quartos_pequenos;
    string enfeite{"============================================"};

    // Menu
    cout<<enfeite;
    cout<<"\nServico de limpeza de quartos do Frank!"<<endl;
    cout<<"\nOpcoes:\nR$100,00 o quarto pequeno\nR$150,00 o quarto grande"<<endl;
    cout<<enfeite<<endl;

    // Input
    cout<<"Digite aqui o numero de quartos GRANDES: ";
    cin >> numero_quartos_grandes;
    cout<<"Digite aqui o numero de quartos PEQUENOS: ";
    cin>>numero_quartos_pequenos;
    cout<<enfeite<<endl;

    // Calculos
    double preco_por_quarto = ((numero_quartos_grandes*preco_quarto_grande) + (numero_quartos_pequenos*preco_quarto_pequeno));
    double imposto =  preco_por_quarto * preco_taxa;
    double total = imposto + preco_por_quarto;

    // Output
    cout<<"ORCAMENTO"<<"\n"<<enfeite<<endl;
    cout<<"Numero de quartos GRANDES: "<<numero_quartos_grandes<<endl;
    cout<<"Numero de quartos PEQUENOS: "<<numero_quartos_pequenos<<endl;
    cout<<"Preco do quarto GRANDE: R$150,00"<<endl;
    cout<<"Preco do quarto PEQUENO: R$100,00"<<endl;
    cout<<"CUSTO: R$"<<total<<",00"<<endl;
    cout<<"TAXA: R$"<<imposto<<",00"<<endl;
    
    // Detalhes do Orcamento
    cout<<enfeite<<endl;
    cout<<"ORCAMENTO TOTAL: R$"<<total<<",00"<<endl;
    cout<<"VALIDADE DO ORCAMENTO: "<<validade_orcamento<<" dias"<<endl;
    cout<<enfeite<<endl;
}