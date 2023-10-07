#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
  // ------------- DEFINIÇÃO DE VARIÁVEIS --------------
  int dias_trabalhados_user{}, dia{}, mes{}, ano{}, verificador_tipo_pessoa{0};

  double salario_dia_user{};
  
  float horas_trabalhadas_user{}, salario_liquido_user{}, desconto_previdenciario_user{}, desconto_imposto_renda_user{}, salario_user{};

  bool relatorio_menu{false}, add_menu{false}, edicao_menu{false};
  
  char confirma_cadastro{}, usuario_cadastrado{}, tipo_funcionario_user{}, menu_escolha{}, retorno_menu{'s'}, permanecer_edit_mode{'n'};
  
  string enfeite_data_admissao{"=========================== Data de Admissao ============================"}, enfeite_tipo_funcionario{"========================== Tipo de Funcionario =========================="}, enfeite_fim_cadastro{"=========================== FIM DO CADASTRO! ============================"}, enfeite_linha{"============================================="}, enfeite_login{"\n[==========100%==========]\nLOGIN FEITO COM SUCESSO!"}, enfeite_informacoes{"output.exe                              [-][X]"}, enfeite_barra{"---------------------------------------------"};
  
  string ra_user{}, nome_user{}, endereco_user{}, cpf_user{}, data_admissao_user{};
  
  vector<string> ra_database{"11","22","33"}, nome_database{"Joao", "Boris", "Emanuel"}, endereco_database{"Avenue X, at Cicero", "Rua Florinda das Flores", "Carlinha el Bigodon"}, cpf_database{"110.345.678-99", "119.565.666-69", "120.222.987-52"}, data_admissao_database{"12/02/2023", "25/05/1985", "22/13/2018"}; // Editáveis no EDIT MODE

  vector<char> tipo_funcionario_t_database{'T'}, tipo_funcionario_e_database{'E'}, tipo_funcionario_c_database{'C'};      // Relatório
  
  vector<float> salario_liquido_t_database{1200.00}, salario_liquido_e_database{500.00}, salario_liquido_c_database{3600.00}, salarios_liquidos_database{3600, 1200, 500};     // Relatório
  
  float soma_c{}, soma_t{}, soma_e{};       // Define-se mais algumas variáveis e o Total de Funcionários, o qual SOMA o tamanho dos Vetores de Funcionários tipo C, tipo T e tipo E
  // ---------------------------------------------------
  
  do{                                       // Todo o código é executado ao menos 1 vez, quando, posteriormente, no menu, for selecionado o CADASTRAMENTO de NOVO FUNCIONÁRIO, o código ele reinicia por esta primeira linha
    relatorio_menu = false;     
    add_menu = false;                       // As variáveis relatorio_menu, add_menu e edicao_menu são setadas para o valor padrão: FALSE. Não havendo, portanto, conflito com valores antigos
    edicao_menu = false;    
    
    cout<<"Insira um RA: ";                 // A primeira tela do programa é um pedido de RA do usuário que, posteriormente, é definida na variável ra_user
    cin>>ra_user;
      
    for (int i = 0; i <= (int)ra_database.size()-1; i++){       // Inicia-se um loop que itera a DATABASE de RAs (ra_database), pegando seu tamanho com <vector>.size() como limite
      if (ra_user == ra_database[i] || ra_user == "admin"){     // Se o RA inserido for a SENHA SUPER SECRETA "admin", ou o RA consta na database, o usuário é tido como cadastrado e o loop se encerra
        cout<<enfeite_login<<endl;
        usuario_cadastrado = 's';                               // Usuário é cadastrado
        break;
      } else if (i == (int)ra_database.size()-1) {                   // Caso contrário, se o iterador for igual ao tamanho da database e o RA não foi encontrado, exibir mensagem "RA não encontrado"
        cout<<"RA nao encontrado!"<<endl;
        usuario_cadastrado = 'n';                               // Usuário não é cadastrado
        break;
      }
    }
    
    if (usuario_cadastrado == 'n'){                             // Caso o usuário não seja cadastrado, um if é executado como verificação de um possível cadastro
      do {                                                      // Esse loop é executado ao menos uma vez, perguntando se deseja prosseguir com o cadastro
        cout<<"\nGostaria de Cadastrar? (S/N) ";
        cin>>confirma_cadastro;
       
        switch (confirma_cadastro){                             // Estrutura de verificação SWITCH CASE que checa qual foi o input do usuário
          case 'n': 
          case 'N':
            exit(1);                                            // Se a resposta for N ou n, o código encerra seu processo com exit(1)
          case 's':
          case 'S':
            confirma_cadastro = 's';                            // Se a resposta for S ou s, a confirmação do cadastro é feita e o loop para sua execução
            break;
          default:
            cout<<"Insira uma opçao valida!"<<endl;             // Caso for inserido um caractere inválido, executa a pergunta novamente até ser inserido S/s ou N/n
        }
      } while (confirma_cadastro != 's');                       // Condição para que o código execute sempre até que S/s for inserido
    }
    
    if (usuario_cadastrado == 's') {      // Estrutura de Decisão IF que verifica se o RA inserido NO COMEÇO é válido, mostrando o salário do funcionário registrado
      int index{};      // Definição da Variável index escopada

      for (int i = 0; i <= (int)ra_database.size()-1; i ++){     // Laço For que verifica a posição do RA inserido no RA Database
        if (ra_database[i] == ra_user){     // Caso sejam iguais as posições
          index = i;      // Atribui-se o valor inteiro do iterador para o index e o for encerra seu processo
          break;
        } else {          
          continue;       // Caso contrário, apenas continua o loop até encontrar
        }
      }

      cout<<"\nOla, "<<nome_database.at(index)<<". Seu Salario Mensal e de R$"<<salarios_liquidos_database.at(index)<<endl;     // Exibe-se o salário líquido do usuário
      cout<<"\nSe deseja acessar o MENU SEGURO, insira a senha super secreta (admin): ";      // Pergunta-se se o usuário deseja acessar o MENU SEGURO com a senha "admin"
      cin>>ra_user;     // Valor posto na variável ra_user
    }

    if ((confirma_cadastro == 's' || confirma_cadastro == 'S') && usuario_cadastrado == 'n'){           // Se o usuário respondeu cadastro, um IF executa verificando se ele já foi inserido na base de dados de RA anterior
      dia = 0;                          // Configuração das variáveis para o valor padrão, 0, de modo a previnir erros com valores antigos
      mes = 0;                          // Configuração das variáveis para o valor padrão, 0, de modo a previnir erros com valores antigos
      ano = 0;                          // Configuração das variáveis para o valor padrão, 0, de modo a previnir erros com valores antigos
      verificador_tipo_pessoa = 0;      // Configuração das variáveis para o valor padrão, 0, de modo a previnir erros com valores antigos
      
      cout<<"\n===================== BEM VINDO AO MENU DE CADASTRO! ====================\n";
  
      cout<<"Insira seu Nome Completo: ";                       // Pede-se o Nome do usuário
      cin.ignore();  
      getline(cin, nome_user);                                  // Ele é posto na variável nome_user, o qual será adicionado ao vetor nome_database posteriormente
        
      cout<<"\nInsira o seu Endereco: ";                        // Pede-se o Endereço do usuário
      getline(cin, endereco_user);                              // Ele é posto na variável endereco_user, e terá o mesmo destino que todas as outras variáveis terminadas em _user
  
      cout<<"\nInsira seu CPF: ";                               // Pede-se o CPF do usuário 
      getline(cin, cpf_user);
  
      cout<<enfeite_data_admissao<<endl;
      while (dia < 1 || dia > 31){                              // Laço While executado enquanto um dia fora do período de um mês for verdadeiro, o valor padrão da variável dia é 0, por isso o laço é executado uma primeira vez
        cout<<"Dia: ";                                          // Pede-se a inserção de um dia ao usuário
        cin>>dia;    
        cin.ignore();
        if(dia<1||dia>31) {                                     // No momento que pede-se a data de admissão, o verificador IF executa calculando se o dia inserido está fora do período de um mês, ou seja, de 30 dias
          cout<<"Digite um Dia valido."<<endl;                  // Se sim, ele mostra a mensagem "Digite um DIA válido", retornando ao loop
        }
      }
      
      while (mes < 1 || mes > 12){                              // A mesma lógica feita no Laço While para dia é feita para o mês, ou seja, enquanto a variável mes, que tem padrão 0, estiver fora do período de um ano, será sempre executado
        cout<<"\nMes: ";                                        // Pede-se a inserção de um mês ao usuário
        cin>>mes;
        cin.ignore();
        if(mes < 1 || mes > 12){                                // Verificador IF que valida ou não a inserção de um mês válido, se não, mostra a mensagem "Digite um Mês válido", retornando ao loop
          cout<<"Digite um Mes valido."<<endl;
        }
      }
        
      while (ano < 1900 || ano > 2023){                         // Mesma lógica feita no Laço While para dia e mês é feita para o ano
        cout<<"\nAno: ";                                        // Pede-se a inserção de um ano ao usuário
        cin>>ano;
        if (ano < 1900 || ano > 2023){                          // Verificador IF que valida se o ano inserido está fora ou dentro de um ano possível e real de trabalho, se não a esse último, exibe-se a mensagem "Insira um ano válido", retornando ao loop 
          cout<<"Digite um Ano valido."<<endl;                  
        }
      }
      
      data_admissao_user = to_string(dia)+"/"+to_string(mes)+"/"+to_string(ano);        // Após todas as verificações de data forem realizadas, as variáveis dia, mês e ano são convertidas em string e concatenadas na variável data_admissao_user
        
      cout<<"\nData de Admissao: "<<data_admissao_user<<'\n';   // Exibe-se uma mensagem que mostra a data inserida já formatada, exemplo 02/12/2012
      cout<<enfeite_tipo_funcionario<<endl;
  
      while (verificador_tipo_pessoa == 0){                     // Um Laço While é executado com o valor padrão da variável verificador_tipo_pessoa, que é 0, até a condição ser falseada durante o próprio Laço
        cout<<"Tipo de funcionario -> C (Contratado), E (Estagiario), T (Temporario): ";      // Pergunta-se ao usuário o Tipo de Funcionário que ele está atuando como e a armazena na variável tipo_funcionario_user
        cin>>tipo_funcionario_user;
      
        switch (tipo_funcionario_user){                         // A estrutura de decisão SWITCH CASE é executada com a variável tipo_funcionario_user em foco, analisando os possíveis casos (C/c, T/t, E/e e inválidas)
          case 'C':   
          case 'c':   
            cout<<"\nInsira seu salario base: R$";              // Se o tipo for Contratado, pergunta-se o Salário Base e as Horas Extras, armazenando as respostas, respectivamente, nas variáveis salario_user e horas_trabalhadas_user
            cin>>salario_user;
                      
            cout<<"\nInsira suas horas extras: ";    
            cin>>horas_trabalhadas_user;
      
            salario_user += (horas_trabalhadas_user * salario_user / 160);      // Um cálculo é feito especificamente para atribuir as horas extras ao Salário (horas extras * salario / 160)
  
            verificador_tipo_pessoa = 1;                        // Encerra-se o loop atribuindo ao verificador_tipo_pessoa o valor 1
            break;
            
          case 'E':  
          case 'e':       
            cout<<"\nInsira seu salario base: R$";              // Se o tipo for Estagiário, pergunta-se o Salário Base e atribui o valor à variável salario_user, sem demais cálculos
            cin>>salario_user;
                 
            verificador_tipo_pessoa = 1;                        // Encerra-se o loop atribuindo ao verificador_tipo_pessoa o valor 1
            break;  
            
          case 'T':   
          case 't':   
            cout<<"\nInsira seu salario base: R$";              // Se o tipo for Temporário, pergunta-se o Salário Base e o divide pelo total de um mês, 30 dias, atribuindo à variável salario_dia_user
            cin>>salario_user;
      
            salario_dia_user = salario_user / 30;         
      
            cout<<"\nInsira os dias trabalhados: ";             // Pergunta-se os Dias Trabalhados, armazenando o valor na variável dias_trabalhados_user
            cin>>dias_trabalhados_user;
      
            salario_user = dias_trabalhados_user * salario_dia_user;      // Um cálculo é feito especificamente para atribuir o Salário à variável salario_user (dias trabalhados * salario por dia)
            
            verificador_tipo_pessoa = 1;                        // Encerra-se o loop atribuindo ao verificador_tipo_pessoa o valor 1
            break;
            
          default:    
            cout<<"\nInsira um Tipo de Funcionario valido!"<<endl;        // Caso não for nenhum dos tipos citados acima, exibe-se uma mensagem de invalidação, retornando à pergunta inicial e reiniciando o loop
            break;    
        }
  
        // Cálculo da PREVIDÊNCIA
        if (salario_user <= 1302.00){                           // É feita uma série de estruturas de decisão IF que verificam o Salário inserido e fazem os Descontos de Previdência pertinentes a cada classe.
          float previdencia = 0.08;  
          desconto_previdenciario_user = salario_user * previdencia;  
            
          } else if (salario_user > 1302.00 && salario_user <= 2512.00){
            float previdencia = 0.09;   
            desconto_previdenciario_user = salario_user * previdencia;  
            
          } else if (salario_user > 2512.00 && salario_user <= 5024.00){
            float previdencia = 0.11;   
            desconto_previdenciario_user = salario_user * previdencia;    
            
          } else{
            float previdencia = 0.14;   
            desconto_previdenciario_user = salario_user * previdencia;    
          }
  
        // Cálculo do IMPOSTO DE RENDA
        if (salario_user <= 1903.98) {                          // É feita uma série de estruturas de decisão IF que verificam o Salário inserido e fazem os Descontos de Imposto de Renda pertinentes a cada classe.
          desconto_imposto_renda_user = salario_user * 0;  
            
        } else if (salario_user >= 1903.99 && salario_user <= 2826.65) {
          float taxa_ir = 0.075;  
          desconto_imposto_renda_user = salario_user * taxa_ir;  
            
        } else if (salario_user >= 2826.66 && salario_user <= 3751.05) {
          float taxa_ir = 0.15;    
          desconto_imposto_renda_user = salario_user * taxa_ir;  
                      
        } else if (salario_user >= 3751.06 && salario_user <= 4664.68) {
          float taxa_ir = 0.225;   
          desconto_imposto_renda_user = salario_user * taxa_ir;    
            
        } else {
          float taxa_ir = 0.275;    
          desconto_imposto_renda_user = salario_user * taxa_ir;    
        }
      }
  
      // Hora de Calcular Salário + Colocar os Editaveis nos Vetores
      if (tipo_funcionario_user == 'c' || tipo_funcionario_user == 'C'){      // Estrutura de decisão IF que verifica o Tipo de Funcionário inserido anteriormente e estabelece os descontos e os "empurra" para o vetor salario_liquido_database
        
        salario_liquido_user = salario_user - desconto_previdenciario_user - desconto_imposto_renda_user;     // Cálculo para o Tipo Contratado que há descontos em série
        salario_liquido_c_database.push_back(salario_liquido_user);     // "Empurra" o Salário do Funcionário na Database de Salário Líquido
        tipo_funcionario_c_database.push_back('c');  // Vetor que agrupa a quantidade de funcionarios tipo Contratado, visualizando, ficaria: vetor = ['c', 'c', 'c', 'c']
        
      } else if (tipo_funcionario_user == 't' || tipo_funcionario_user == 'T'){
        
        salario_liquido_user = salario_user - desconto_previdenciario_user - desconto_imposto_renda_user;     // Cálculo para o Tipo Temporário que há descontos em série
        salario_liquido_t_database.push_back(salario_liquido_user);     // "Empurra" o Salário do Funcionário na Database de Salário Líquido
        tipo_funcionario_t_database.push_back('t');  // Vetor que agrupa a quantidade de funcionarios tipo Temporário, visualizando, ficaria: vetor = ['t', 't', 't', 't']
        
      } else {
        
        salario_liquido_user = salario_user;      // Cálculo para o Tipo Estagiário que não há descontos
        salario_liquido_e_database.push_back(salario_liquido_user);     // "Empurra" o Salário do Funcionário na Database de Salário Líquido
        tipo_funcionario_e_database.push_back('e');  // Vetor que agrupa a quantidade de funcionarios tipo Estagiário, visualizando, ficaria: vetor = ['e', 'e', 'e', 'e']
      }

      // Hora de Colocar as Informações de Cadastro no Sistema
      salarios_liquidos_database.push_back(salario_liquido_user); // salario_liquido_user é posto no Vetor salarios_liquidos_database com a função push_back()
      ra_database.push_back(ra_user);                             // ra_user é posto no Vetor ra_database com a função push_back()
      nome_database.push_back(nome_user);                         // nome_user é posto no Vetor nome_database com a função push_back()
      endereco_database.push_back(endereco_user);                 // endereco_user é posto no Vetor endereco_database com a função push_back()
      cpf_database.push_back(cpf_user);                           // cpf_user é posto no Vetor cpf_database com a função push_back()
      data_admissao_database.push_back(data_admissao_user);       // data_admissao_user_user é posto no Vetor data_admissao_database com a função push_back()
      
      cout<<enfeite_fim_cadastro<<endl;

      cout<<"Considerando o Tipo de Funcionario e as Informacoes Apresentadas, seu Salario Mensal e de R$"<<salario_liquido_user<<endl;     // Após todo o Cadastro e Cálculos terem sido feitos, exibir o Salário Líquido do Funcionário com a variávle salario_liquido_user
      cout<<"\nSe deseja acessar o MENU SEGURO, insira a senha super secreta (admin): ";      // Após o Resultado ser inserido, perguntar se o usuário deseja acessar o MENU SEGURO com a senha "admin"
      cin>>ra_user;     // Valor posto na variável ra_user
    }     // Fim do REGISTRO e seu IF
    
    soma_c = 0;
    soma_t = 0;       // Redefinição das variáveis soma para 0, de modo a precaver erros de salário duplicado
    soma_e = 0;

    for (int i = 0; i < (int)tipo_funcionario_c_database.size(); i++){     // Executa-se um Laço For que itera a Database do Tipo de Funcionário C
      if (i < (int)salario_liquido_c_database.size()){                     // Estrutura de Decisão IF que verifica se o iterador i ainda é menor que o tamanho da Database do Salário Líquido Tipo C
        soma_c += salario_liquido_c_database[i];                      // Se sim, adicionar o valor correspondente do vetor Tipo de Funcionário C no vetor Salário C à Soma de Salários C, soma_c
      }    
    }
  
    for (int i = 0; i < (int)tipo_funcionario_t_database.size(); i++){     // Executa-se um Laço For que itera a Database do Tipo de Funcionário T
      if (i < (int)salario_liquido_t_database.size()){                     // Estrutura de Decisão IF que verifica se o iterador i ainda é menor que o tamanho da Database do Salário Líquido Tipo T
        soma_t += salario_liquido_t_database[i];                      // Se sim, adicionar o valor correspondente do vetor Tipo de Funcionário T no vetor Salário T à Soma de Salários T, soma_t
      }
    }
  
    for (int i = 0; i < (int)tipo_funcionario_e_database.size(); i++){     // Executa-se um Laço For que itera a Database do Tipo de Funcionário E
      if (i < (int)salario_liquido_e_database.size()){                     // Estrutura de Decisão IF que verifica se o iterador i ainda é menor que o tamanho da Database do Salário Líquido Tipo E
        soma_e += salario_liquido_e_database[i];                      // Se sim, adicionar o valor correspondente do vetor Tipo de Funcionário E no vetor Salário E à Soma de salários E, soma_e
      }
    }
  
    // Option Menu do Usuario
    if (ra_user == "admin" || ra_user == "ADMIN"){      // Se e apenas se o RA do usuário, ra_user, for "admin", o menu será executado
      do{                         // Laço Do-While que executa o menu ao menos uma vez dependendo do valor do caractere de Retorno ao Menu, retorno_menu
        edicao_menu = false;      // Seta o valor das variáveis edicao_menu e relatorio_menu ao seu estado default, que é o valor booleano FALSE, para não haver conflitos com valores inseridos em inicializações anteriores
        relatorio_menu = false;
        int total_func{(int)(tipo_funcionario_c_database.size()+tipo_funcionario_e_database.size()+tipo_funcionario_t_database.size())};      // Variável que calcula o total de funcionários, foi utilizada nesse escopo para precaver erros de funcionarios nao aparecendo
        
        cout<<"\n|------------------------------------|"<<endl;     // Exibe-se um MENU contextualizado com opções (1) RELATÓRIO, (2)EDIÇÃO e (3)ADICIONAR FUNCIONÁRIO
        cout<<"|Bem vindo ao Menu! Digite uma Opcao:|"<<endl;
        cout<<"|------------------------------------|"<<endl;
        cout<<"|(1) para abrir o RELATORIO.         |"<<endl;
        cout<<"|(2) para abrir a EDICAO.            |"<<endl;
        cout<<"|(3) para voltar ao LOGIN. (add)     |"<<endl;
        cout<<"|------------------------------------|"<<endl;
        cout<<"> ";
        cin>>menu_escolha;        // Armazena-se o resultado na variável menu_escolha
          
        switch(menu_escolha){     // Estrutura de Decisão SWITCH CASE que verifica a opção inserida no menu_escolha
          case '1':  
            relatorio_menu = true;      // Se 1, então a variável relatorio_menu tem valor TRUE, encerrando o SWITCH CASE
            break;
          case '2':
            edicao_menu = true;         // Se 2, então a variável edicao_menu tem valor TRUE, encerrando o SWITCH CASE
            break;
          case '3':
            add_menu = true;            // Se 3, então a variável add_menu tem valor TRUE, encerrando o SWITCH CASE
            retorno_menu = 'n';
            break;
          default:                      // Se nenhuma das anteriores, então exibe-se uma mensagem de caractere inválido, encerrando o SWITCH CASE e pulando os IFS posteriores de Relatório, Edição e Adição de Funcionário, apenas o IF que pergunta se deseja retornar ao MENU ou sair
            cout<<"Insira um caracter valido!"<<endl;
            break;
        }
      
        if (relatorio_menu == true){      // Se a opção 1 for digitada, a Estrutura de Decisão IF com a condição relatorio_menu == true é executada, exibindo o relatório completo com o Total de Funcionários, Total de Funcionários por Categoria, Média Salarial por Categoria, Valor Total por Categoria e Folha de Pagamento Salarial
          cout<<"\n================ RELATORIOS ================="<<endl;
          cout<<"Quantidade de Funcionarios: "<<total_func<<endl;
          cout<<enfeite_linha<<endl;
          cout<<"Quantidade de Funcionarios por Categoria (Contratado): "<<tipo_funcionario_c_database.size()<<endl;
          cout<<"Quantidade de Funcionarios por Categoria (Temporario): "<<tipo_funcionario_t_database.size()<<endl;
          cout<<"Quantidade de Funcionarios por Categoria (Estagiario): "<<tipo_funcionario_e_database.size()<<endl;
          cout<<enfeite_linha<<endl;
          cout<<"Media Salarial por Categoria (Contratado): R$"<<soma_c/tipo_funcionario_c_database.size()<<endl;
          cout<<"Media Salarial por Categoria (Temporario): R$"<<soma_t/tipo_funcionario_t_database.size()<<endl;
          cout<<"Media Salarial por Categoria (Estagiario): R$"<<soma_e/tipo_funcionario_e_database.size()<<endl;
          cout<<enfeite_linha<<endl;
          cout<<"Valor Salarial Total (Contratado): R$"<<soma_c<<endl;
          cout<<"Valor Salarial Total (Temporario): R$"<<soma_t<<endl;
          cout<<"Valor Salarial Total (Estagiario): R$"<<soma_e<<endl;
          cout<<enfeite_barra<<endl;
          cout<<"Folha de Pagamento Salarial: R$"<<soma_c+soma_e+soma_t<<endl;
          permanecer_edit_mode = 'n';     // Após o Relatório ser exibido ao usuário, atribui-se à variável permanecer_edit_mode o valor char de 'n', de modo a confirmar a condição do IF posterior que pergunta se deseja retornar ao menu ou sair
          relatorio_menu = false;         // Relatorio Menu é configurado ao seu estado default, FALSE
        }
        
        if (edicao_menu == true){     // Se a opção 2 for digitada, a Estrutura de Decisão IF com a condição edicao_menu == true é executada, exibindo um Menu de Edição de Nome, Endereço, CPF e Data de Admissão
          cout<<"\n================ EDICAO ================="<<endl;
          
          cout<<"Qual seu nome? (Insira da mesma forma que digitou no cadastro) ";      // Primeiro, pede-se ao usuário o Nome que esse digitou no Cadastro/Pós-Edição, colocando-o na variável string nome_user
          cin.ignore();
          getline(cin, nome_user);
  
          int index{}, selecao_edit_menu{};     // Define-se algumas variáveis, indexe selecao_edit_menu escopadas ao Menu de Edição
          
          for (int i = 0; i <= (int)nome_database.size()-1; i++){                              // Um Laço For é inicializado que itera no tamanho da Database de Nomes, nome_database
            if (nome_database[i] == nome_user){                                           // Se o Nome do Usuário for igual ao nome dentro do Vetor nome_database, a variável index passa a ter o valor do iterador inteiro
              index = i;
              permanecer_edit_mode = 's';                                                 // Atribui-se à variável permanecer_edit_mode o char 's', para confirmar que o nome foi de fato encontrado
              break;
            } else if (nome_database[i] != nome_user && i == (int)nome_database.size()-1){     // Se o Nome do Usuário não for encontrado na Database e também o iterador tiver o mesmo valor do tamanho do Vetor (2 iterador = 2 nomes da database), exibir a mensagem "Nome não encontrado", encerrando o loop
              cout<<"Nome nao encontrado."<<endl;
            } else {                                                                      // Caso contrário, continuar o loop até a condição Else If de "Nome não encontrado" ser executada
              continue;
            }
          }
          
          while (permanecer_edit_mode == 's'){      // Laço While é executado caso o nome foi realmente encontrado com a condição (permanecer_edit_mode == 's')
            cout<<"\nSelecione o item que deseja Editar: "<<endl;                         // Exibe-se um Menu de Escolha de Edição constando (1) Nome, (2) Endereço, (3) CPF e (4) Data de Admissão
            cout<<"(1) - Nome: "<<nome_user<<endl;                                        // Usa-se o index obtido no FOR anterior para encontrar o nome, endereço, cpf e data de admissão correspondente em uma escala 1x1
            cout<<"(2) - Endereco: "<<endereco_database.at(index)<<endl;
            cout<<"(3) - CPF: "<<cpf_database.at(index)<<endl;
            cout<<"(4) - Data de Admissao: "<<data_admissao_database.at(index)<<endl;

            do{     // O Laço Do-While executa ao menos uma vez o pedido de opção do Menu de Edição
              cout<<"> ";
              cin>>selecao_edit_menu;     // Armazena-se o valor obtido na variável selecao_edit_menu
    
              switch(selecao_edit_menu){      // Estrutura de Decisão SWITCH CASE que verifica o digito do selecao_edit_menu
                case 1:
                  cout<<"Insira seu novo NOME (exemplo: Ana Maria): ";                // Se for 1, então exibe-se a mensagem que pede a inserção de um NOVO NOME
                  cin.ignore();
                  getline(cin, nome_user);  
                  nome_database.at(index) = nome_user;                                // Substitui o NOME digitado no sistema, Nome Database, através do index obtido em processos anteriores
                  break;
                case 2:                                                   
                  cout<<"Insira seu novo ENDERECO (exemplo: Avenida X, Cicero): ";    // Se for 2, então exibe-se a mensagem que pede a inserção de um NOVO ENDEREÇO
                  cin.ignore();
                  getline(cin, endereco_user);
                  endereco_database.at(index) = endereco_user;                        // Substitui o ENDEREÇO digitado no sistema, Endereço Database, através do index obtido em processos anteriores
                  break;
                case 3:
                  cout<<"Insira seu novo CPF (exemplo: 123.456.789-10): ";            // Se for 3, então exibe-se a mensagem que pede a inserção de um NOVO CPF
                  cin.ignore();
                  getline(cin, cpf_user);
                  cpf_database.at(index) = cpf_user;                                  // Substitui o CPF digitado no sistema, CPF Database, através do index obtido em processos anteriores
                  break;
                case 4:
                  cout<<"Insira sua nova DATA DE ADMISSAO (exemplo: 02/12/2023): ";   // Se for 4, então exibe-se a mensagem que pede a inserção de uma NOVA DATA DE ADMISSÃO
                  cin.ignore();
                  getline(cin, data_admissao_user);
                  data_admissao_database.at(index) = data_admissao_user;              // Substitui a DATA de admissão digitado no sistema, Data de Admissão Database, através do index obtido em processos anteriores
                  break;
                default:
                  cout<<"Erro! Opcao invalida! "<<endl;                               // Se nenhuma das opções, exibe-se uma mensagem de "Opção inválida!" e reinicia o loop de pedido
                  break;
              }
            } while ((selecao_edit_menu < 1) || (selecao_edit_menu > 4));     // Condição que permite a execução do código de pedido da opção até que o digito inserido esteja na lista e encerre o processo
            
            cout<<"Deseja Permanecer na tela de Edicao? (S/N) ";      // Após a Edição ser feita, pergunta-se ao usuário "Deseja Permanecer na tela de Edição?", armazenando a resposta na variável permanecer_edit_mode
            cin>>permanecer_edit_mode;
            
            switch(permanecer_edit_mode){     // Estrutura de Decisão SWITCH CASE que verifica o valor da variável permanecer_edit_mode
              case 's':
              case 'S':
                permanecer_edit_mode = 's';                               // Se for digitado 'S', alterar esse valor para 's' e parar a execução do SWITCH
                break;
              case 'n':
              case 'N':
                permanecer_edit_mode = 'n';                               // Se for digitado 'N', alterar esse valor para 'n' e parar a execução do SWITCH
                break;
              default:
                cout<<"Opcao invalida -> Redirecionando ao Menu"<<endl;   // Se o char não for encontrado, exibir uma mensagm de "Opção Inválida" e redirecionar ao Menu Principal
                break;
            }
          }   // Fim do PERMANECER NO EDIT MODE
        }     // Fim do EDIT MODE
        
        if (add_menu == false && permanecer_edit_mode == 'n'){      // Se a variável add_menu tiver o valor booleano FALSE, que é o valor padrão e obtido quando se seleciona a opção RELATÓRIOS ou EDIÇÃO, e se a variável permanecer_edit_mode tiver char 'n', que é também padrão, executa uma tela que PERGUNTA do retorno ao Menu
          do{     // Executa-se ao menos uma vez o Pedido de Retorno ao Menu Principal
            cout<<enfeite_barra<<endl;
            cout<<"Gostaria de retornar ao menu? (S/N) ";
            cin>>retorno_menu;        // Armazena-se o char obtido na variável retorno_menu
  
            switch(retorno_menu){     // Estrutura de Decisão SWITCH CASE que verifica a variável retorno_menu
              case 'n':
              case 'N':               // Se for digitado 'N' ou 'n', o código para sua execução
                exit(1);
              case 'S':               // Se for digitado 'S', o retorno muda seu valor para 's', encerrando o switch e passando para a verificação do while posterior
                retorno_menu = 's';
                break;
              default:                // Se for digitado um caractere inválido, apenas executa o loop novamente, perguntando se deseja retornar ao Menu. Se for digitado 's', ele apenas encerra o processo, concluindo a condição While
                break;
            }
            
          } while (retorno_menu != 's');      // While que tem a condição (retorno_menu for diferente de 's'), se for igual a 's' o loop se encerra
        } // Fim da Pergunta de Retorno
        
      } while (retorno_menu == 's');          // While que tem a condição (retorno_menu for igual a 's'), se for igual a 's' o loop reinicia desde a Tela de Menu / Administrador
    }     // Fim da Tela de Administrador    
  } while (add_menu == true);                 // While que tem a condição (add_menu for igual a TRUE) e reinicia o sistema caso a opção 3 for acionada, possibilitando adicionar mais um funcionário
}