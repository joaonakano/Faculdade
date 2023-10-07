#include <iostream>
using namespace std;

int main() {
    int numero{10};    
    int original_number{10};    
    //----ESCREVA SEU CÓDIGO ABAIXO DESTA LINHA----
   
    cout << "O seu numero inicial e: " << numero << endl;
    //-- Multiplica o número por 2 e atribui o resultado de volta ao número
    numero *= 2;
    cout << "O seu numero vezes 2 e: " << numero << endl;
    //-- Adiciona 9 ao número e atribui o resultado de volta ao número
    numero += 9;
    cout << "O seu numero atual mais 9 e: " << numero << endl;
    //-- Subtrair 3 do número e atribuir o resultado de volta ao número
    numero -= 3;
    cout << "O seu numero atual menos 3 e: " << numero << endl;
    //-- Divide o número por 2 e atribui o resultado de volta ao número
    numero /= 2;
    cout << "O seu numero atual dividido por 2 e: " << numero << endl;
    //-- Subtrair original_number de number e atribuir o resultado de volta a number
    numero -= original_number;
    cout << "O seu numero atual menos o original number e: " << numero << endl;
    //-- Pegue o módulo 3 (%) do número e atribua-o de volta ao número
    numero %= 3;
    cout << "O resto da divisao de seu numero por 3 e: " << numero << endl;
 
   
    //----ESCREVA SEU CÓDIGO ACIMA DESTA LINHA----
   
    return 0;
}