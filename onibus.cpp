#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <random>


using namespace std;

//Cria a scruct para armazenar os dados dos ônibus
struct Onibus{
  string terminal;
  string itiner;
};

//Cria a scruct para armazenar as reclamações
struct Recl{
  string data_recl;
  string texto_recl;
};

//Cria o map para armazenar os ônibus: Chave (número da linha) e valor (struct Onibus)
map<int, Onibus> onibus;

//Cria o map para armazenar as reclamações Chave (ID da reclamação) e valor (struct Recl)
map<int, Recl> recl;


//Lê o arquivo assim que o programa é iniciado para salvar no map
void carregarValores(){
  fstream arquivoCriarOnibus;
  fstream arquivoCriarRecl;

  //cria o arquivo onibus.txt caso não exista
  arquivoCriarOnibus.open("onibus.txt", ios::out | ios::app);
  arquivoCriarOnibus.close();
  
  //cria o arquivo reclamacoes.txt caso não exista
  arquivoCriarRecl.open("reclamacoes.txt", ios::out | ios::app);
  arquivoCriarRecl.close();
  
  //Abre o arquivo onibus.txt para leitura
  fstream arquivolerOnibus;
  arquivolerOnibus.open("onibus.txt", ios::in);
  string linha;
  vector<string> vetor_onibus;
  
  //Lê todas as linhas do arquivo onibus.txt e salva cada linha em um vector
  while(getline(arquivolerOnibus, linha)){
    vetor_onibus.push_back(linha);
  }
  arquivolerOnibus.close(); //fecha o arquivo lido.

    //Transfere as linhas do vector para dentro do map onibus
  for(int i = 0; i< vetor_onibus.size(); i+=3){
    int num_linha = stoi(vetor_onibus[i]);
    onibus[num_linha].terminal = vetor_onibus[i+1];
    onibus[num_linha].itiner = vetor_onibus[i+2];
  }

   //Abre o arquivo reclamacoes.txt para leitura
  fstream arquivolerRecl;
  arquivolerRecl.open("reclamacoes.txt", ios::in);
  string linha_r;
  vector<string> vetor_recl;
  
  //Lê todas as linhas do arquivo reclamacoes.txt e salva cada linha em um vector
  while(getline(arquivolerRecl, linha_r)){
    vetor_recl.push_back(linha_r);
  }
  arquivolerRecl.close(); //fecha o arquivo lido.

    //Transfere as linhas do vector para dentro do map recl
  for(int i = 0; i< vetor_recl.size(); i+=3){
    int num_lin = stoi(vetor_recl[i]);
    recl[num_lin].data_recl = vetor_recl[i+1];
    recl[num_lin].texto_recl = vetor_recl[i+2];
  }

}

//Faz o cadastro de linhas de ônibus com valores recebidos dos parametros
void cadastrarOnibus(){
  string terminal, itiner;
  int num_linha;
  cout << "\n#####   Cadastrar linhas e ônibus   #####\n";
  cout << "Número da linha: ";
  cin >> num_linha;
  cout << "Terminal: ";
  cin.ignore();
  getline(cin, terminal);
  cout << "Itinerário: ";
  getline(cin, itiner);


  
  fstream arquivo;
  arquivo.open("onibus.txt", ios::out | ios::app);
  arquivo << num_linha << endl;
  onibus[num_linha].terminal = terminal;
  arquivo << terminal << endl;
  onibus[num_linha].itiner = itiner;
  arquivo << itiner << endl;

  arquivo.close(); // Fecha o arquivo

  cout << "Ônibus cadastrado com sucesso.\n";
}

//Insere reclamações dos clientes
void cadastrarReclamacao(){
  string texto_reclam;
  getline(cin, texto_reclam);

// gerar data de hoje
  time_t t = std::time(nullptr);
  tm tm = *std::localtime(&t);
  char date[100];
  strftime(date, sizeof(date), "%d/%m/%Y", &tm);

// gerar numero aleatorio para o ID da reclamacao
  random_device rd;   // obtém uma semente de dispositivo aleatório
  mt19937 gen(rd());  // inicializa o gerador com a semente
  uniform_int_distribution<> distrib(0, 99);  // define a distribuição de números inteiros uniformes entre 0 e 99
  int num_aleatorio = distrib(gen);  // gera um número aleatório usando o gerador e a distribuição

  fstream arquivo_recl;
  arquivo_recl.open("reclamacoes.txt", ios::out | ios::app);
  arquivo_recl << num_aleatorio << endl;
  recl[num_aleatorio].data_recl = date;
  arquivo_recl << date << endl;
  recl[num_aleatorio].texto_recl = texto_reclam;
  arquivo_recl << texto_reclam << endl;

  arquivo_recl.close(); // Fecha o arquivo

  cout << "Sua reclamação foi registrada. Obrigado.\n";
}

//Lista Ônibus Cadastrados
void listaOnibus(){
  if (onibus.empty()) {
    cout << "Não há nenhum ônibus cadastrado.\n" << endl;  
  } else {
      cout << "\n####  Lista de Ônibus Cadastrados   ####\n\n";
      cout << "*************************\n";
      for(auto i : onibus){

        if (i.first != 0){
            cout << "Número da linha: "<< i.first << endl;
            cout << "Terminal: "<< i.second.terminal << endl;
            cout << "Itinerário: "<< i.second.itiner << endl;
            cout << "*************************\n\n";
        }

      }
  }

}


//Busca um ônibus pelo número da linha
void buscaOnibusLinha(int num_linha){
  if (onibus.empty()) {
    cout << "Não há nenhum ônibus cadastrado.\n" << endl;  
  } else {
      cout << "\n####  Buscando Ônibus   ####\n";
      for(auto i : onibus){
        if(i.first == num_linha){
          cout << "--------------------------\n";
          cout << "\nÔnibus encontrado!\n";
          cout << "\nO terminal desta linha é: " << i.second.terminal << endl;
          cout << "\nO itinerário desta linha é:\n " << i.second.terminal << " -> " << i.second.itiner << endl;
          cout << "--------------------------\n\n";

        }   
      }
    
  }
      
}

//Busca um ônibus pelo bairro (terminal)
void buscaOnibusBairro(string bairro){
  if (onibus.empty()) {
    cout << "Não há nenhum ônibus cadastrado.\n" << endl;  
  } else {
    cout << "\n####  Buscando Ônibus   ####\n";
  for(auto i : onibus){
    if(i.second.terminal == bairro){
      cout << "--------------------------\n";
      cout << "\nÔnibus encontrado!\n";
      cout << "\nO número desta linha é: " << i.first << endl;
      cout << "\nO itinerário desta linha é:\n " << i.second.terminal << " -> " << i.second.itiner << endl;
      cout << "--------------------------\n\n";

    }   
    }
  }
  
}


//Alterando terminal buscado pela linha
void alterarTerminal(int linha, string novo){
  string terminal_antigo;
  for(auto i : onibus){
    if(i.first == linha){
      terminal_antigo = onibus[linha].terminal;
      onibus[linha].terminal = novo;
      cout << "Terminal da linha "<< linha << " alterado de "
        << terminal_antigo <<" para " << onibus[linha].terminal <<"."<< endl;
      cout << "----------------------------------\n\n";
    }   
  }
}

//Alterando itinerário buscado pela linha
void alterarItinerario(int linha, string novo){
  string itiner_antigo;
  for(auto i : onibus){
    if(i.first == linha){
      itiner_antigo = onibus[linha].itiner;
      onibus[linha].itiner = novo;
      cout << "Itinerário da linha "<< linha << " alterado de "
        << itiner_antigo <<" para: " << onibus[linha].itiner <<"."<< endl;
      cout << "----------------------------------\n\n";
    }   
  }
}

//Atualiza o arquivo para excluir a linha apagada
void atualizarArquivo_onibus(){
  fstream arquivo;
  arquivo.open("onibus.txt", ios::out); //Apaga o arquivo original
  
  //Reescreve todo o arquivo do zero com os dados do map
  for(auto i : onibus){
    arquivo << i.first << endl;
    arquivo << i.second.terminal << endl;
    arquivo << i.second.itiner << endl;
    
  }
}

//Apaga linha de ônibus
void apagarOnibus(int linha){
  cout << "Você está tentando excluir a linha " << linha << endl;
  cout << "Esta operação não poderá ser desfeita." << endl;
  cout << "Deseja continuar? [s/n] ";
  char confirmacao;
  cin >> confirmacao;
  if (confirmacao == 's' || confirmacao == 'S'  ){
    for(auto i : onibus){
      if(i.first == linha){
        onibus.erase(linha);
        atualizarArquivo_onibus(); // Chama a função para atualizar o arquivo
        cout << "A linha "<< linha << " foi excluída com sucesso" << endl;
        cout << "----------------------------------\n\n";
        return;
      }   
    }
  } else {
    cout << "A exclusão não foi feita." << endl;
  }

}

//lista reclamações
void listaReclamacoes(){
  cout << "\n####  Lista de Reclamações   ####\n\n";
  cout << "*************************\n";
  for(auto i : recl){
    cout << "ID da reclamação: "<< i.first << endl;
    cout << "Data: "<< i.second.data_recl << endl;
    cout << "Reclamação: "<< i.second.texto_recl << endl;
    cout << "*************************\n";
  }
}

int perf(){
  cout << "Escolha seu perfil no sistema:\n";
  cout << "1 - Usuário (cliente)\n";
  cout << "2 - Gerente\n";
  cout << "-> :";
  int pf; 
  cin >> pf;

  return pf;
}



