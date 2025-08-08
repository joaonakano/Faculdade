#include<iostream>
using namespace std;

int main() {
    int num1{}, num2{};

    cout<<boolalpha;
    cout<<"Insira dois numeros separados por um espaco: ";
    cin>>num1>>num2;

    cout<<"Seus numeros foram: "<<num1<<" e "<<num2<<". Mas "<<num1<<" > "<<num2<<"?"<<" "<<(num1>num2)<<endl;
    cout<<"Seus numeros foram: "<<num1<<" e "<<num2<<". Mas "<<num1<<" >= "<<num2<<"?"<<" "<<(num1>=num2)<<endl;
    cout<<"Seus numeros foram: "<<num1<<" e "<<num2<<". Mas "<<num1<<" < "<<num2<<"?"<<" "<<(num1<num2)<<endl;
    cout<<"Seus numeros foram: "<<num1<<" e "<<num2<<". Mas "<<num1<<" <= "<<num2<<"?"<<" "<<(num1<=num2)<<endl;
}