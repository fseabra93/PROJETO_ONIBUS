#include <iostream>
#include <string>
#ifndef _ONIBUS_HPP
#define _ONIBUS_HPP

using namespace std;

  void cadastrarOnibus();
  void carregarValores();
  void listaOnibus();
  void buscaOnibusLinha(int num_linha);
  void buscaOnibusBairro(string bairro);
  void apagarOnibus(int linha);
  void atualizarArquivo_onibus();
  void listaReclamacoes();
  void cadastrarReclamacao();
  void listaOnibus();
  void alterarTerminal(int linha, string novo);
  void alterarItinerario(int linha, string novo);
  int perf();

#endif