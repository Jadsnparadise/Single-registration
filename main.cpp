#include <iostream>
#include <fstream>
#include "include/cadastro.hpp"
using namespace std;

void clear(){
  cout<< "\033[2J\033[1;1H";
	}

int main() {
	
	ifstream arqCadastro;
	Cadastro unico("Cadastro Unico");
	arqCadastro.open("src/data/cadastro_unico.txt",ios::in);
	if (!arqCadastro) {
		
 		cerr << "O Arquivo não pôde ser aberto" << endl;
 		exit(1);
		
	}else {
		
 		while (!arqCadastro.eof()) {
			string nome;
			string cpf;
			string endereco;

			getline(arqCadastro,nome);
			nome = nome.erase(nome.size()-1,nome.size());
			getline(arqCadastro,cpf);
			cpf = cpf.erase(cpf.size()-1,cpf.size());
			getline(arqCadastro,endereco);
			endereco = endereco.erase(endereco.size()-1,endereco.size());
			
			Pessoa *pessoa = new Pessoa(nome,cpf);
			pessoa->setEndereco(endereco);
			
			unico.adicionaPessoa(*pessoa);

		}
		arqCadastro.close();
 }
	
	Cadastro sus("SUS");
	Cadastro CadEstadual("CE");
	Cadastro cadMunicipal("CM");
	int numCadastros = 0;

	Pessoa ajuda("","");

	pair <string,string> cpfSistema;

	cout << "Quantos cadastros serão realizados?" <<endl;
	cin >> numCadastros;
	for(int i = 0; i < numCadastros; i++){
		cin >> cpfSistema.first;
		cin.ignore();
		cin >> cpfSistema.second;

		if(cpfSistema.second == "SUS"){
			sus.adicionaPessoa(unico.encontraPessoa(cpfSistema.first));
		}else if(cpfSistema.second == "CE"){
			CadEstadual.adicionaPessoa(unico.encontraPessoa(cpfSistema.first));
		}else{
			cadMunicipal.adicionaPessoa(unico.encontraPessoa(cpfSistema.first));
		}
	}
	clear();
	sus.imprimeUsuarios();
	CadEstadual.imprimeUsuarios();
	cadMunicipal.imprimeUsuarios();

	
	return 0;
}
		