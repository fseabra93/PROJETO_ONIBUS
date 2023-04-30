#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include "onibus.hpp" //importa o arquivo de cabeçalho do onibus

using namespace std;

int main(){

  //imprimir o título

  string titulo = "### Sistema Gerenciador de Transportes Coletivos ###";
  int tam_titulo = titulo.length();

  cout << endl;

  for (int i=0; i<tam_titulo; i++){
    cout << "#";
  } cout << endl;
  
  cout << titulo << endl;

  for (int i=0; i<tam_titulo; i++){
    cout << "#";
  } cout << endl << endl;
  
  /* Escolhendo o perfil (cliente, gerente) */
  int perfil = perf();
  
  /* Lê os arquivos onibus.txt e reclamacoes.txt e carrega os dados no sistema */
  carregarValores();
  
  /* Menu de opções para o perfil cliente */
  if(perfil == 1){
    while(true){
      cout << "\n#####   Usuário (cliente)   #####\n\n";
      cout << "1 - Ver ônibus cadastrados (nome da linha e bairro)\n";
      cout << "2 - Buscar um ônibus por nome do bairro (terminal)\n";
      cout << "3 - Ver o itinerário de um ônibus (busque pelo número da linha)\n";
      cout << "4 - Fazer uma reclamação (a reclamação será anônima)\n";
      cout << "5 - Para sair\n";
      cout << "-> :";
      int opt;
      cin >> opt;
      
      /* Lista ônibus cadastrados */
      if(opt == 1){
        listaOnibus();
      }

      /* Busca ônibus por bairro */
      else if(opt == 2){
        cout << "\n####  Buscar ônibus por bairro   ####\n";
        string bairro;
        cin.ignore();        
        cout << "Digite o bairro (terminal): ";
        getline(cin, bairro);
        buscaOnibusBairro(bairro);
 
      }
        /* Busca ônibus por linha e mostra o itinerário */
      else if(opt == 3){
        cout << "\n####  Ver o itinerário de um ônibus   ####\n";
        cout << "Escolha uma linha de ônibus: ";
        int linha;
        cin >> linha;
        buscaOnibusLinha(linha);
 
      }

      /*Cadastra uma reclamação anônima*/
      else if(opt == 4){
        cin.ignore(); 
        cout << "\n####  Fazer uma reclamação   ####\n";
        cout << "Escreva sua reclamação: (a sua reclamação será anônima):\n->: ";
        cadastrarReclamacao();       
 
      }


      else if(opt >= 5){
        cout << "\n##  Obrigado por utilizar o Sistema Gerenciador de Transportes Coletivos   ##\n";
        sleep(2);
        exit(0);
 
      }
      
      /* Sai do while(true) 
      else{
        break;

      }*/
    } 
  }


  /* Menu de opções para o perfil admin */
  else if(perfil == 2){
    int autenticado = 0;
    while(true){
      string admin = "admin";
      string senha;
      if (autenticado == 0){
        cout << "\nPara entrar no perfil GERENTE é necessário autenticar seu perfil. \nDigite sua senha:\n";
      cin >> senha;
        if (senha == admin){
          autenticado = 1;
        } else {
            cout << "Você não tem acesso ao perfil GERENTE\n";
            cout << "O programa será encerrado. Obrigado.\n";
            sleep(3);
            exit(0);
            }
        }
      
        if (autenticado == 1){

          cout << "\n#####   Gerente   #####\n\n";
          cout << "1 - Cadastrar linhas e ônibus\n";
          cout << "2 - Listar todos os ônibus cadastrados\n";
          cout << "3 - Buscar um ônibus pelo número da linha\n";
          cout << "4 - Buscar um ônibus pelo bairro (terminal)\n";
          cout << "5 - Atualizar o bairro (terminal) de um determinado ônibus\n";
          cout << "6 - Atualizar o itinerário de um determinado ônibus\n";
          cout << "7 - Excluir um ônibus (buscando pelo número da linha)\n";
          cout << "8 - Listar reclamações\n";
          cout << "9 - Sair\n";
          cout << "-> : ";

          int opt;
          cin >> opt;
      

            /* Cadastrar linhas de onibus */
            if(opt == 1){
              cadastrarOnibus(); //Chama a função em onibus.cpp
              while (true){
                char op;
                //cin.ignore();
                cout << "\nDeseja cadastrar outra linha? [s/n]: ";
                cin >> op;
                cout << endl;
                if (op == 's' || op == 'S'){
                  cadastrarOnibus(); //Chama a função em onibus.cpp
                } else {
                  break;
                }
              }
            }

            /* Lista as linhas, terminais e itinerários */
            else if(opt == 2){
              listaOnibus(); //Chama a função em onibus.cpp
            } 

            /* Busca ônibus pela linha*/
            else if(opt == 3){
              int linha;
              cout << "Digite o número da linha: ";
              cin >> linha;
              buscaOnibusLinha(linha);
            }

            /* Busca ônibus pelo terminal*/
            else if(opt == 4){
              string bairro;
              cin.ignore();
              cout << "Digite o bairro (terminal): ";
              getline(cin, bairro);
              buscaOnibusBairro(bairro);
            }

            /* Atualizar o bairro (terminal) de um determinado ônibus */
            else if(opt == 5){
              cout << "Digite o número da linha que deseja atualizar o terminal: ";
              int num_linha;
              cin >> num_linha;
              cin.ignore();
              cout << "Digite o novo Terminal para a linha " << num_linha <<": ";
              string novo_terminal;
              getline(cin, novo_terminal);
              alterarTerminal(num_linha, novo_terminal); 
              atualizarArquivo_onibus();
            }

            /* Atualizar o itinerário de um determinado ônibus */
            else if(opt == 6){
              cout << "Digite a número da linha que deseja atualizar o itinerário: ";
              int num_linha;
              cin >> num_linha;
              cin.ignore();
              cout << "Digite o novo Itinerário para a linha " << num_linha <<": ";
              string novo_itiner;
              getline(cin, novo_itiner);
              alterarItinerario(num_linha, novo_itiner); 
              atualizarArquivo_onibus();
            }
            /*Excluir um ônibus (buscando pelo número da linha)*/
            else if(opt == 7){
              cout << "Digite a número da linha que deseja excluir: ";
              int num_linha;
              cin >> num_linha;
              apagarOnibus(num_linha); 
              
            }

            /*Listar reclamações*/
            else if(opt == 8){
              listaReclamacoes();
            }

            /* Sai do while(true) */
            else{
              cout << "\n##  Obrigado por utilizar o Sistema Gerenciador de Transportes Coletivos   ##\n";
              sleep(2);
              exit(0);

              break;
            }

        }
    }
  }

  
return 0; 
}