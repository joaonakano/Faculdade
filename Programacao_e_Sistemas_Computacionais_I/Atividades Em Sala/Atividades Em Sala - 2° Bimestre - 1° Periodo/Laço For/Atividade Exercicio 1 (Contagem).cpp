#include<iostream>
#include<Windows.h>
using namespace std;

int main(){
    for(int i=1;i<=50;i++){
        cout<<"O numero e: "<<i<<endl;
        Sleep(250);
        system("color c0");
        Sleep(250);
        system("color 60");
        Sleep(250);
        system("color a0");
        system("CLS");
    }
}