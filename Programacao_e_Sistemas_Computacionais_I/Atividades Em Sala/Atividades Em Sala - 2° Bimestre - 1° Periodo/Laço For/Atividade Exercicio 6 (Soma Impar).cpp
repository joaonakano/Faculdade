#include<iostream>
using namespace std;

int main(){
    int soma{};
    for (int i = 1; i <= 15; i++) {
        if (i % 2 == 1) {
            soma += i;
        }
    }
    
    cout<<"A soma dos numeros IMPARES e: "<<soma<<'\n';
}