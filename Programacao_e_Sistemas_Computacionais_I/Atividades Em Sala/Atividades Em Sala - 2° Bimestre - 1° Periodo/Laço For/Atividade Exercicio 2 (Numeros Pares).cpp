#include<iostream>
#include<Windows.h>
using namespace std;

int main(){
    int numero_par{};

    for(int i=1;i<=100;i++){
        if (i % 2 == 0){
            system("CLS");
            cout<<"Numero par da vez (1 a 100, VEJA ATE O FINAL!) e: "<<i<<endl;
            Sleep(200);
            system("color c0");
            Sleep(200);
            system("color 60");
            Sleep(200);
            system("color a0");
            system("CLS");
            
            if (i == 100){
                system("color 0F");

                cout<<"LISTA COMPLETA"<<endl;
                for(int j = 0; j <= 100;j+=2){
                    cout<<j<<endl;
                }
            }
        }
    }
}