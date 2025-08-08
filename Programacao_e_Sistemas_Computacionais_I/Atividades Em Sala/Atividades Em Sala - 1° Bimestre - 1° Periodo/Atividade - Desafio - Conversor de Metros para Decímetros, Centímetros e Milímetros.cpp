#include<iostream>
using namespace std;
int main(){
    double metros_user;
    const double decimetro{10.00};
    const double centimetro{100.00};
    const double milimetro{1000.00};

    // Input
    cout<<"\nIndique o valor em metros a ser convertido: ";
    cin>>metros_user;
    
    // Cálculo
    cout<<metros_user<<" metro(s) em decimetros e   "<<metros_user*decimetro<<endl;
    cout<<metros_user<<" metro(s) em centimetros e "<<metros_user*centimetro<<endl;
    cout<<metros_user<<" metro(s) em milimetros e "<<metros_user*milimetro<<endl;
}