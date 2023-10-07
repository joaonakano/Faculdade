// Configuração das Bibliotecas
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int calculo(){
    // Definição das Variáveis
    int dias_trabalhados{}, dia{}, mes{}, ano{}, verificador_tipo_pessoa{0};
    double salario_dia{};
    float horas_trabalhadas{}, salario_liquido{}, desconto_previdenciario{}, desconto_imposto_renda{}, salario{};
    char tipo_funcionario{};
    string nome{}, endereco{}, cpf{}, data_admissao{};
    string enfeite_cadastro{"\n=============BEM-VINDO AO MENU DE CADASTRO!============="}, enfeite_fim_cadastro{"===================FIM DO CADASTRO!====================="}, enfeite_linha{"========================================="}, enfeite_login{"\n[==========100%==========]\nLOGIN FEITO COM SUCESSO!"}, enfeite_data_admissao{"================== Data de Admissão ===================="}, enfeite_informacoes{"output.exe                              [-][X]"}, enfeite_barra{"----------------------------------------------"}, enfeite_tipo_funcionario{"================ Tipo de Funcionário ==================="};

    // Setando a Língua do Terminal para PT-BR
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    // Código que pede o Nome do usuário e o insere na Variável nome
    cout<<"Insira seu Nome: ";
    cin.ignore();    // Ignora os caracteres invisiveis de quebra de linha
    getline(cin,nome);    // Pega toda a linha de caracteres do usuário
    cout<<nome<<endl;    // Exibe o nome inserido na tela

    // Código que pede o Endereço do usuário e o insere na Variável endereco
    cout<<"Insira seu Endereço: ";
    getline(cin, endereco);    // Pega toda a linha de caracteres do usuário e a insere na Variável endereco
    cout<<endereco<<endl;    // Exibe o endereço inserido na tela

    // Código que pede o CPF do usuário e o insere na Variável cpf
    cout<<"Insira seu CPF: ";
    cin>>cpf;    // Pega a linha de caracteres do usuário e a insere na Variável cpf
    cout<<cpf<<endl;    // Exibe o CPF inserido na tela

    // Código que pede a Data de Admissao do usuário e o insere na Variável data_admissao
    cout<<enfeite_data_admissao<<endl;
    while (dia < 1 || dia > 31){    // Laço While para conferir o Dia inserido pelo usuário até dar certo
        cout<<"Dia: ";
        cin>>dia;  
        if(dia<1||dia>31) {    // Se o Dia for maior que um mês ou menor que um dia, exibe uma mensagem de invalidação
            cout<<"Digite um Dia válido."<<endl;
        }
    }
    while (mes < 1 || mes > 12){    // Laço While para conferir o Mês inserido pelo usuário até dar certo
        cout<<"Mês: ";
        cin>>mes;
        if(mes < 1 || mes > 12){    // Se o Mês for maior que um ano ou menor que um mês, exibe uma mensagem de invalidação
            cout<<"Digite um Mês válido."<<endl;
        }
    }
    while (ano < 1900 || ano > 2023){    // Laço While para conferir o Ano inserido pelo usuário até dar certo
        cout<<"Ano: ";
        cin>>ano;
        if (ano < 1900 || ano > 2023){    // Se o Ano for posterior que o atual ou anterior que 1900, exibe uma mensagem de invalidação
            cout<<"Digite um Ano válido."<<endl;
        }
    }

    data_admissao = to_string(dia)+"/"+to_string(mes)+"/"+to_string(ano);    // Converte todos os Inputs de Admissão em String e os organiza para serem Inseridos na Variável data_admissao
    cout<<"Data de Admissão: "<<data_admissao<<'\n'<<enfeite_tipo_funcionario<<endl;    // Mostra a Data de Admissão já Convertida e Organizada
    
    // Laço While para Verificar o Tipo de Funcionário até o usuário dar um correto
    while (verificador_tipo_pessoa == 0){
        cout<<"Tipo de funcionário -> C (Contratado), E (Estagiario), T (Temporario): ";    // Código que pede o Tipo de Funcionário e armazena o Caractere Inserido na Variável tipo_funcionario
        cin>>tipo_funcionario;

        switch (tipo_funcionario){    // Estrutura de Decisão Switch Case para verificar o TIPO DE FUNCIONÁRIO inserido e realizar os Cálculos correspondentes
            case 'C':   // Caso o INPUT seja C, executa o código do Funcionário Contratado
            case 'c':   // Caso o INPUT seja c, executa o código do Funcionário Contratado
                cout<<"Insira seu salário base: R$";    // Input para o usuário inserir seu Salário Base a fim de ser armazenado na Variável salario
                cin>>salario;
                
                cout<<"Insira suas horas extras: ";    // Pergunta ao usuário as Horas Extras feitas caso optado por Contratado e as armazena na Variável horas_trabalhadas
                cin>>horas_trabalhadas;

                salario += (horas_trabalhadas*salario/160);    // Atribuição das Horas Extras no Salário

                if (salario <= 1302.00){    // Estrutura de Decisão IF que confere o Salário inserido Anteriormente e faz os cálculos devidos para cada classe salarial
                    float previdencia = 0.08;    // A Taxa de Previdência para salários abaixo ou igual a R$1.302,00 é de 8%
                    desconto_previdenciario = salario * previdencia;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                } else if (salario > 1302.00 && salario <= 2512.00){
                    float previdencia = 0.09;    // A Taxa de Previdência para salários acima de R$1.302,00 e abaixo ou igual a R$2.512,00 é de 9%
                    desconto_previdenciario = salario * previdencia;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                } else if (salario > 2512.00 && salario <= 5024.00){
                    float previdencia = 0.11;    // A Taxa de Previdência para salários acima de R$2.512,00 e abaixo ou igual a R$5.024,00 é de 11%
                    desconto_previdenciario = salario * previdencia;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                } else{
                    float previdencia = 0.14;    // A Taxa de Previdência para salários além de R$5.024,00 é de 8%
                    desconto_previdenciario = salario * previdencia;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                }

                if (salario <= 1903.98) {    // Estrutura de Decisão IF que confere o Salário inserido Anteriormente e faz os cálculos devidos para cada classe salarial
                    desconto_imposto_renda = salario * 0;    // Não há desconto de IR para salarios abaixo de R$1903,98
                } else if (salario >= 1903.99 && salario <= 2826.65) {
                    float taxa_ir = 0.075;    // A Taxa de Imposto de Renda para salários acima ou iguais a R$1903,99 e abaixo ou iguais a R$2826,65 é de 7,5%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                } else if (salario >= 2826.66 && salario <= 3751.05) {
                    float taxa_ir = 0.15;    // A Taxa de Imposto de Renda para salários acima ou iguais a R$2826,66 e abaixo ou iguais a R$3751,05 é de 15%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                } else if (salario >= 3751.06 && salario <= 4664.68) {
                    float taxa_ir = 0.225;    // A Taxa de Imposto de Renda para salários acima ou iguais a R$3751,06 e abaixo ou iguais a R$4664,68 é de 22,5%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                } else {
                    float taxa_ir = 0.275;    // A Taxa de Imposto de Renda para salários acima ou iguais a R$4664,69 é de 27,5%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                }

                salario_liquido = salario - (desconto_previdenciario + desconto_imposto_renda);    // Cálculo do Salário Líquido (desconto previdenciário (calculado pela estrutura IF) e horas extras)
                cout<<enfeite_fim_cadastro<<endl;

                // OUTPUT - Informações do Funcionário - Contratado
                cout<<'\n'<<enfeite_barra<<'\n'<<enfeite_informacoes<<'\n'<<enfeite_barra<<endl;
                cout<<"Nome do funcionário: "<<nome<<endl;
                cout<<"Endereço do funcionário: "<<endereco<<endl;
                cout<<"CPF do funcionário: "<<cpf<<endl;
                cout<<"Data de admissão do funcionário: "<<data_admissao<<endl;
                cout<<"Tipo de funcionário: Contratado"<<endl;
                cout<<"Salário bruto do funcionário é de: R$"<<salario<<endl;
                cout<<"Horas extras trabalhadas pelo funcionário: "<<horas_trabalhadas<<endl;
                cout<<"O salário liquido do funcionário é de: R$"<<salario_liquido<<endl;
                cout<<enfeite_barra<<endl;
                verificador_tipo_pessoa = 1;    // O verificador retorna o valor 1, Desativando o Laço While
                break;
            case 'E':   // Caso o INPUT seja E, executa o código do Funcionário Estagiário
            case 'e':   // Caso o INPUT seja e, executa o código do Funcionário Estagiário
                cout<<"Insira seu salário base: R$";    // Input para o usuário inserir seu Salário Base a fim de ser armazenado na Variável salario
                cin>>salario;

                salario_liquido = salario;    // Não é feito descontos salariais
                cout<<enfeite_fim_cadastro<<endl;

                // OUTPUT - Informações do Funcionário - Estagiário
                cout<<'\n'<<enfeite_barra<<'\n'<<enfeite_informacoes<<'\n'<<enfeite_barra<<endl;
                cout<<"Nome do funcionário: "<<nome<<endl;
                cout<<"Endereço do funcionário: "<<endereco<<endl;
                cout<<"CPF do funcionário: "<<cpf<<endl;
                cout<<"Data de admissão do funcionário: "<<data_admissao<<endl;
                cout<<"Tipo de funcionário: Estagiario"<<endl;
                cout<<"Salário bruto do funcionário é de: R$"<<salario<<endl;
                cout<<"O salário liquido do funcionário é de: R$"<<salario_liquido<<endl;
                cout<<enfeite_barra<<endl;
                verificador_tipo_pessoa = 1;    // O verificador retorna o valor 1, Desativando o Laço While
                break;
            case 'T':   // Caso o INPUT seja T, executa o código do Funcionário Temporário
            case 't':   // Caso o INPUT seja t, executa o código do Funcionário Temporário
                cout<<"Insira seu salário base: R$";    // Input para o usuário inserir seu Salário Base a fim de ser armazenado na Variável salario
                cin>>salario;

                salario_dia = salario/30;    // O salário é Dividido por 1 mês e atribuído à Variável salario_dia

                cout<<"Insira os dias trabalhados: ";    // Pede ao usuário o Período ao qual foi Contratado e atribui o valor à Variável dias_trabalhados
                cin>>dias_trabalhados;

                salario = dias_trabalhados*salario_dia;
                
                if (salario <= 1302.00){    // Estrutura de Decisão IF que confere o Salário inserido Anteriormente e faz os cálculos devidos para cada classe salarial
                    float previdencia = 0.08;    // A Taxa de Previdência para salários abaixo ou igual a R$1.302,00 é de 8%
                    desconto_previdenciario = salario * previdencia;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                } else if (salario > 1302.00 && salario <= 2512.00){
                    float previdencia = 0.09;    // A Taxa de Previdência para salários acima de R$1.302,00 e abaixo ou igual a R$2.512,00 é de 9%
                    desconto_previdenciario = salario * previdencia;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                } else if (salario > 2512.00 && salario <= 5024.00){
                    float previdencia = 0.11;    // A Taxa de Previdência para salários acima de R$2.512,00 e abaixo ou igual a R$5.024,00 é de 11%
                    desconto_previdenciario = salario * previdencia;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                } else{
                    float previdencia = 0.14;    // A Taxa de Previdência para salários além de R$5.024,00 é de 8%
                    desconto_previdenciario = salario * previdencia;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                }

                if (salario <= 1903.98) {    // Estrutura de Decisão IF que confere o Salário inserido Anteriormente e faz os cálculos devidos para cada classe salarial
                    desconto_imposto_renda = salario * 0;    // Não há desconto de IR para salarios abaixo de R$1903,98
                } else if (salario >= 1903.99 && salario <= 2826.65) {
                    float taxa_ir = 0.075;    // A Taxa de Imposto de Renda para salários acima ou iguais a R$1903,99 e abaixo ou iguais a R$2826,65 é de 7,5%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                } else if (salario >= 2826.66 && salario <= 3751.05) {
                    float taxa_ir = 0.15;    // A Taxa de Imposto de Renda para salários acima ou iguais a R$2826,66 e abaixo ou iguais a R$3751,05 é de 15%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                } else if (salario >= 3751.06 && salario <= 4664.68) {
                    float taxa_ir = 0.225;    // A Taxa de Imposto de Renda para salários acima ou iguais a R$3751,06 e abaixo ou iguais a R$4664,68 é de 22,5%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                } else {
                    float taxa_ir = 0.275;    // A Taxa de Imposto de Renda para salários acima ou iguais a R$4664,69 é de 27,5%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplicação da Taxa pelo Salário Base para o Desconto ser Aplicado
                }
                
                salario_liquido = salario - desconto_previdenciario - desconto_imposto_renda;    // O salário é feito com base na Multiplicação simples entre Dias trabalhados x Salário/dia subtraídos os descontos
                cout<<enfeite_fim_cadastro<<endl;

                // OUTPUT - Informações do Funcionário - Temporário
                cout<<'\n'<<enfeite_barra<<'\n'<<enfeite_informacoes<<'\n'<<enfeite_barra<<endl;
                cout<<"Nome do funcionário: "<<nome<<endl;
                cout<<"Endereço do funcionário: "<<endereco<<endl;
                cout<<"CPF do funcionário: "<<cpf<<endl;
                cout<<"Data de admissão do funcionário: "<<data_admissao<<endl;
                cout<<"Tipo de funcionário: Temporário"<<endl;
                cout<<"Salário bruto do funcionário é de: R$"<<salario<<endl;
                cout<<"Dias trabalhados pelo funcionário: "<<dias_trabalhados<<endl;
                cout<<"O salário líquido do funcionário é de: R$"<<salario_liquido<<endl;
                cout<<enfeite_barra<<endl;
                verificador_tipo_pessoa = 1;    // O verificador retorna o valor 1, Desativando o Laço While
                break;
            default:    // Caso o caractere inserido não seja válido, exibe-se uma mensagem de invalidação e Volta novamente na mesma pergunta do Tipo de Pessoa
                cout<<"Insira um Tipo de Funcionário válido!"<<endl;
                break; 
        }
    }
    return 0;
}