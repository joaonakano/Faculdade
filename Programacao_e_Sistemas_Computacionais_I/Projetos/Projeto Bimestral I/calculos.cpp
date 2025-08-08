// Configura��o das Bibliotecas
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int calculo(){
    // Defini��o das Vari�veis
    int dias_trabalhados{}, dia{}, mes{}, ano{}, verificador_tipo_pessoa{0};
    double salario_dia{};
    float horas_trabalhadas{}, salario_liquido{}, desconto_previdenciario{}, desconto_imposto_renda{}, salario{};
    char tipo_funcionario{};
    string nome{}, endereco{}, cpf{}, data_admissao{};
    string enfeite_cadastro{"\n=============BEM-VINDO AO MENU DE CADASTRO!============="}, enfeite_fim_cadastro{"===================FIM DO CADASTRO!====================="}, enfeite_linha{"========================================="}, enfeite_login{"\n[==========100%==========]\nLOGIN FEITO COM SUCESSO!"}, enfeite_data_admissao{"================== Data de Admiss�o ===================="}, enfeite_informacoes{"output.exe                              [-][X]"}, enfeite_barra{"----------------------------------------------"}, enfeite_tipo_funcionario{"================ Tipo de Funcion�rio ==================="};

    // Setando a L�ngua do Terminal para PT-BR
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    // C�digo que pede o Nome do usu�rio e o insere na Vari�vel nome
    cout<<"Insira seu Nome: ";
    cin.ignore();    // Ignora os caracteres invisiveis de quebra de linha
    getline(cin,nome);    // Pega toda a linha de caracteres do usu�rio
    cout<<nome<<endl;    // Exibe o nome inserido na tela

    // C�digo que pede o Endere�o do usu�rio e o insere na Vari�vel endereco
    cout<<"Insira seu Endere�o: ";
    getline(cin, endereco);    // Pega toda a linha de caracteres do usu�rio e a insere na Vari�vel endereco
    cout<<endereco<<endl;    // Exibe o endere�o inserido na tela

    // C�digo que pede o CPF do usu�rio e o insere na Vari�vel cpf
    cout<<"Insira seu CPF: ";
    cin>>cpf;    // Pega a linha de caracteres do usu�rio e a insere na Vari�vel cpf
    cout<<cpf<<endl;    // Exibe o CPF inserido na tela

    // C�digo que pede a Data de Admissao do usu�rio e o insere na Vari�vel data_admissao
    cout<<enfeite_data_admissao<<endl;
    while (dia < 1 || dia > 31){    // La�o While para conferir o Dia inserido pelo usu�rio at� dar certo
        cout<<"Dia: ";
        cin>>dia;  
        if(dia<1||dia>31) {    // Se o Dia for maior que um m�s ou menor que um dia, exibe uma mensagem de invalida��o
            cout<<"Digite um Dia v�lido."<<endl;
        }
    }
    while (mes < 1 || mes > 12){    // La�o While para conferir o M�s inserido pelo usu�rio at� dar certo
        cout<<"M�s: ";
        cin>>mes;
        if(mes < 1 || mes > 12){    // Se o M�s for maior que um ano ou menor que um m�s, exibe uma mensagem de invalida��o
            cout<<"Digite um M�s v�lido."<<endl;
        }
    }
    while (ano < 1900 || ano > 2023){    // La�o While para conferir o Ano inserido pelo usu�rio at� dar certo
        cout<<"Ano: ";
        cin>>ano;
        if (ano < 1900 || ano > 2023){    // Se o Ano for posterior que o atual ou anterior que 1900, exibe uma mensagem de invalida��o
            cout<<"Digite um Ano v�lido."<<endl;
        }
    }

    data_admissao = to_string(dia)+"/"+to_string(mes)+"/"+to_string(ano);    // Converte todos os Inputs de Admiss�o em String e os organiza para serem Inseridos na Vari�vel data_admissao
    cout<<"Data de Admiss�o: "<<data_admissao<<'\n'<<enfeite_tipo_funcionario<<endl;    // Mostra a Data de Admiss�o j� Convertida e Organizada
    
    // La�o While para Verificar o Tipo de Funcion�rio at� o usu�rio dar um correto
    while (verificador_tipo_pessoa == 0){
        cout<<"Tipo de funcion�rio -> C (Contratado), E (Estagiario), T (Temporario): ";    // C�digo que pede o Tipo de Funcion�rio e armazena o Caractere Inserido na Vari�vel tipo_funcionario
        cin>>tipo_funcionario;

        switch (tipo_funcionario){    // Estrutura de Decis�o Switch Case para verificar o TIPO DE FUNCION�RIO inserido e realizar os C�lculos correspondentes
            case 'C':   // Caso o INPUT seja C, executa o c�digo do Funcion�rio Contratado
            case 'c':   // Caso o INPUT seja c, executa o c�digo do Funcion�rio Contratado
                cout<<"Insira seu sal�rio base: R$";    // Input para o usu�rio inserir seu Sal�rio Base a fim de ser armazenado na Vari�vel salario
                cin>>salario;
                
                cout<<"Insira suas horas extras: ";    // Pergunta ao usu�rio as Horas Extras feitas caso optado por Contratado e as armazena na Vari�vel horas_trabalhadas
                cin>>horas_trabalhadas;

                salario += (horas_trabalhadas*salario/160);    // Atribui��o das Horas Extras no Sal�rio

                if (salario <= 1302.00){    // Estrutura de Decis�o IF que confere o Sal�rio inserido Anteriormente e faz os c�lculos devidos para cada classe salarial
                    float previdencia = 0.08;    // A Taxa de Previd�ncia para sal�rios abaixo ou igual a R$1.302,00 � de 8%
                    desconto_previdenciario = salario * previdencia;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                } else if (salario > 1302.00 && salario <= 2512.00){
                    float previdencia = 0.09;    // A Taxa de Previd�ncia para sal�rios acima de R$1.302,00 e abaixo ou igual a R$2.512,00 � de 9%
                    desconto_previdenciario = salario * previdencia;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                } else if (salario > 2512.00 && salario <= 5024.00){
                    float previdencia = 0.11;    // A Taxa de Previd�ncia para sal�rios acima de R$2.512,00 e abaixo ou igual a R$5.024,00 � de 11%
                    desconto_previdenciario = salario * previdencia;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                } else{
                    float previdencia = 0.14;    // A Taxa de Previd�ncia para sal�rios al�m de R$5.024,00 � de 8%
                    desconto_previdenciario = salario * previdencia;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                }

                if (salario <= 1903.98) {    // Estrutura de Decis�o IF que confere o Sal�rio inserido Anteriormente e faz os c�lculos devidos para cada classe salarial
                    desconto_imposto_renda = salario * 0;    // N�o h� desconto de IR para salarios abaixo de R$1903,98
                } else if (salario >= 1903.99 && salario <= 2826.65) {
                    float taxa_ir = 0.075;    // A Taxa de Imposto de Renda para sal�rios acima ou iguais a R$1903,99 e abaixo ou iguais a R$2826,65 � de 7,5%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                } else if (salario >= 2826.66 && salario <= 3751.05) {
                    float taxa_ir = 0.15;    // A Taxa de Imposto de Renda para sal�rios acima ou iguais a R$2826,66 e abaixo ou iguais a R$3751,05 � de 15%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                } else if (salario >= 3751.06 && salario <= 4664.68) {
                    float taxa_ir = 0.225;    // A Taxa de Imposto de Renda para sal�rios acima ou iguais a R$3751,06 e abaixo ou iguais a R$4664,68 � de 22,5%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                } else {
                    float taxa_ir = 0.275;    // A Taxa de Imposto de Renda para sal�rios acima ou iguais a R$4664,69 � de 27,5%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                }

                salario_liquido = salario - (desconto_previdenciario + desconto_imposto_renda);    // C�lculo do Sal�rio L�quido (desconto previdenci�rio (calculado pela estrutura IF) e horas extras)
                cout<<enfeite_fim_cadastro<<endl;

                // OUTPUT - Informa��es do Funcion�rio - Contratado
                cout<<'\n'<<enfeite_barra<<'\n'<<enfeite_informacoes<<'\n'<<enfeite_barra<<endl;
                cout<<"Nome do funcion�rio: "<<nome<<endl;
                cout<<"Endere�o do funcion�rio: "<<endereco<<endl;
                cout<<"CPF do funcion�rio: "<<cpf<<endl;
                cout<<"Data de admiss�o do funcion�rio: "<<data_admissao<<endl;
                cout<<"Tipo de funcion�rio: Contratado"<<endl;
                cout<<"Sal�rio bruto do funcion�rio � de: R$"<<salario<<endl;
                cout<<"Horas extras trabalhadas pelo funcion�rio: "<<horas_trabalhadas<<endl;
                cout<<"O sal�rio liquido do funcion�rio � de: R$"<<salario_liquido<<endl;
                cout<<enfeite_barra<<endl;
                verificador_tipo_pessoa = 1;    // O verificador retorna o valor 1, Desativando o La�o While
                break;
            case 'E':   // Caso o INPUT seja E, executa o c�digo do Funcion�rio Estagi�rio
            case 'e':   // Caso o INPUT seja e, executa o c�digo do Funcion�rio Estagi�rio
                cout<<"Insira seu sal�rio base: R$";    // Input para o usu�rio inserir seu Sal�rio Base a fim de ser armazenado na Vari�vel salario
                cin>>salario;

                salario_liquido = salario;    // N�o � feito descontos salariais
                cout<<enfeite_fim_cadastro<<endl;

                // OUTPUT - Informa��es do Funcion�rio - Estagi�rio
                cout<<'\n'<<enfeite_barra<<'\n'<<enfeite_informacoes<<'\n'<<enfeite_barra<<endl;
                cout<<"Nome do funcion�rio: "<<nome<<endl;
                cout<<"Endere�o do funcion�rio: "<<endereco<<endl;
                cout<<"CPF do funcion�rio: "<<cpf<<endl;
                cout<<"Data de admiss�o do funcion�rio: "<<data_admissao<<endl;
                cout<<"Tipo de funcion�rio: Estagiario"<<endl;
                cout<<"Sal�rio bruto do funcion�rio � de: R$"<<salario<<endl;
                cout<<"O sal�rio liquido do funcion�rio � de: R$"<<salario_liquido<<endl;
                cout<<enfeite_barra<<endl;
                verificador_tipo_pessoa = 1;    // O verificador retorna o valor 1, Desativando o La�o While
                break;
            case 'T':   // Caso o INPUT seja T, executa o c�digo do Funcion�rio Tempor�rio
            case 't':   // Caso o INPUT seja t, executa o c�digo do Funcion�rio Tempor�rio
                cout<<"Insira seu sal�rio base: R$";    // Input para o usu�rio inserir seu Sal�rio Base a fim de ser armazenado na Vari�vel salario
                cin>>salario;

                salario_dia = salario/30;    // O sal�rio � Dividido por 1 m�s e atribu�do � Vari�vel salario_dia

                cout<<"Insira os dias trabalhados: ";    // Pede ao usu�rio o Per�odo ao qual foi Contratado e atribui o valor � Vari�vel dias_trabalhados
                cin>>dias_trabalhados;

                salario = dias_trabalhados*salario_dia;
                
                if (salario <= 1302.00){    // Estrutura de Decis�o IF que confere o Sal�rio inserido Anteriormente e faz os c�lculos devidos para cada classe salarial
                    float previdencia = 0.08;    // A Taxa de Previd�ncia para sal�rios abaixo ou igual a R$1.302,00 � de 8%
                    desconto_previdenciario = salario * previdencia;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                } else if (salario > 1302.00 && salario <= 2512.00){
                    float previdencia = 0.09;    // A Taxa de Previd�ncia para sal�rios acima de R$1.302,00 e abaixo ou igual a R$2.512,00 � de 9%
                    desconto_previdenciario = salario * previdencia;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                } else if (salario > 2512.00 && salario <= 5024.00){
                    float previdencia = 0.11;    // A Taxa de Previd�ncia para sal�rios acima de R$2.512,00 e abaixo ou igual a R$5.024,00 � de 11%
                    desconto_previdenciario = salario * previdencia;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                } else{
                    float previdencia = 0.14;    // A Taxa de Previd�ncia para sal�rios al�m de R$5.024,00 � de 8%
                    desconto_previdenciario = salario * previdencia;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                }

                if (salario <= 1903.98) {    // Estrutura de Decis�o IF que confere o Sal�rio inserido Anteriormente e faz os c�lculos devidos para cada classe salarial
                    desconto_imposto_renda = salario * 0;    // N�o h� desconto de IR para salarios abaixo de R$1903,98
                } else if (salario >= 1903.99 && salario <= 2826.65) {
                    float taxa_ir = 0.075;    // A Taxa de Imposto de Renda para sal�rios acima ou iguais a R$1903,99 e abaixo ou iguais a R$2826,65 � de 7,5%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                } else if (salario >= 2826.66 && salario <= 3751.05) {
                    float taxa_ir = 0.15;    // A Taxa de Imposto de Renda para sal�rios acima ou iguais a R$2826,66 e abaixo ou iguais a R$3751,05 � de 15%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                } else if (salario >= 3751.06 && salario <= 4664.68) {
                    float taxa_ir = 0.225;    // A Taxa de Imposto de Renda para sal�rios acima ou iguais a R$3751,06 e abaixo ou iguais a R$4664,68 � de 22,5%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                } else {
                    float taxa_ir = 0.275;    // A Taxa de Imposto de Renda para sal�rios acima ou iguais a R$4664,69 � de 27,5%
                    desconto_imposto_renda = salario * taxa_ir;    // Multiplica��o da Taxa pelo Sal�rio Base para o Desconto ser Aplicado
                }
                
                salario_liquido = salario - desconto_previdenciario - desconto_imposto_renda;    // O sal�rio � feito com base na Multiplica��o simples entre Dias trabalhados x Sal�rio/dia subtra�dos os descontos
                cout<<enfeite_fim_cadastro<<endl;

                // OUTPUT - Informa��es do Funcion�rio - Tempor�rio
                cout<<'\n'<<enfeite_barra<<'\n'<<enfeite_informacoes<<'\n'<<enfeite_barra<<endl;
                cout<<"Nome do funcion�rio: "<<nome<<endl;
                cout<<"Endere�o do funcion�rio: "<<endereco<<endl;
                cout<<"CPF do funcion�rio: "<<cpf<<endl;
                cout<<"Data de admiss�o do funcion�rio: "<<data_admissao<<endl;
                cout<<"Tipo de funcion�rio: Tempor�rio"<<endl;
                cout<<"Sal�rio bruto do funcion�rio � de: R$"<<salario<<endl;
                cout<<"Dias trabalhados pelo funcion�rio: "<<dias_trabalhados<<endl;
                cout<<"O sal�rio l�quido do funcion�rio � de: R$"<<salario_liquido<<endl;
                cout<<enfeite_barra<<endl;
                verificador_tipo_pessoa = 1;    // O verificador retorna o valor 1, Desativando o La�o While
                break;
            default:    // Caso o caractere inserido n�o seja v�lido, exibe-se uma mensagem de invalida��o e Volta novamente na mesma pergunta do Tipo de Pessoa
                cout<<"Insira um Tipo de Funcion�rio v�lido!"<<endl;
                break; 
        }
    }
    return 0;
}