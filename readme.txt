Sistema Gerenciador de Transportes Coletivos

O "Sistema Gerenciador de Transportes Coletivos" é um programa de gerenciamento de linhas de ônibus urbanos.


## Instalação

1. Clone o repositório: https://github.com/fseabra93/PROJETO_ONIBUS.git
2. Abra o terminal e navegue até o diretório do projeto;
3. Execute os comandos:
	g++ -c main.cpp onibus.cpp
	g++ -o prog main.o onibus.o
	./prog

## Utilização

1. Ao iniciar, o programa solicitará ao usuário do programa a escolha do perfil, que pode ser o de usuário (cliente) do serviço de transportes coletivos urbanos (opção 1) ou de GERENTE do sistema (opção 2).

2. O perfil "cliente" do sistema apresenta as seguintes funcionalidades:
	1 - Ver ônibus cadastrados (nome da linha e bairro);
		Mostra todos os ônibus cadastrados no sistema.
	2 - Buscar um ônibus por nome do bairro (terminal);
		Mostra o número e o itinerário de um ônibus buscado pelo nome do seu bairro (terminal) 
	3 - Ver o itinerário de um ônibus (busque pelo número da linha);
		Mostra o itinerário e o nome do bairro (terminal) de um ônibus buscado pelo número da linha
	4 - Fazer uma reclamação (a reclamação será anônima);
		Permite ao usuário cadastrar uma reclamação de forma anoônima.
		
3. O perfil "GERENTE" do sistema só pode ser acessado após autentucação com senha (admin), e apresenta as seguintes funcionalidades:

	1 - Cadastrar linhas e ônibus;
		Permite o cadastro de novas linhas de ônibus com número da linha, nome do bairro (terminal) e itinerário. 
	2 - Listar todos os ônibus cadastrados
		Mostra todos os ônibus cadastrados no sistema.		
	3 - Buscar um ônibus pelo número da linha
		Mostra o itinerário e o nome do bairro (terminal) de um ônibus buscado pelo número da linha
	4 - Buscar um ônibus pelo bairro (terminal)
		Mostra o número e o itinerário de um ônibus buscado pelo nome do seu bairro (terminal) 
	5 - Atualizar o bairro (terminal) de um determinado ônibus
		Permite que o GERENTE atualize (modifique) o bairro (terminal) de um determinado ônibus buscado pelo número da linha
	6 - Atualizar o itinerário de um determinado ônibus
		Permite que o GERENTE atualize (modifique) o itinerário de um determinado ônibus buscado pelo número da linha
	7 - Excluir um ônibus (buscando pelo número da linha)
		Exclui uma linha ônibus. Obs. Essa funcionalidade solicita confirmação.
	8 - Listar reclamações
		LIsta todas as reclamações cadastradas pelos clientes.
	

