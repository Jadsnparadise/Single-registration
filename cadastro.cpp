#include <iostream>
#include <cstring>
#include "include/cadastro.hpp"
#include <fstream>
using namespace std;

Cadastro::Cadastro(string nomeCadastro){
	nome = nomeCadastro;
}

void Cadastro::adicionaPessoa(Pessoa p){
	bool jaCadastrada = false;
	if(cadastrados.size() == 0){
		cadastrados.push_back(p);
	}else{
		for(int i = 0; i < cadastrados.size(); i++){
			if(p.getCpf().compare(cadastrados.at(i).getCpf()) == 0){
				jaCadastrada = true;
				break;
			}
		}
		if(jaCadastrada == false){
			cadastrados.push_back(p);
		}
	}
}

void Cadastro::removePessoa(Pessoa p){
	for(int i = 0; i < cadastrados.size(); i++){
		if(p.getCpf().compare(cadastrados.at(i).getCpf()) == 0){
			cadastrados.erase(cadastrados.begin()+i);
			cout << "Pessoa Removida do cadastro com sucesso!"<<endl;
		}
	}	
}

Pessoa Cadastro::encontraPessoa(string cpf){
	Pessoa *teste = new Pessoa("","");
	for(int i = 0; i < cadastrados.size(); i++){
		if(cpf == cadastrados.at(i).getCpf()){
			*teste = cadastrados.at(i);
		}
	}
	return *teste;
}
	
void Cadastro::limpaCadastro(){
	cadastrados.clear();	
}

void Cadastro::imprimeUsuarios(){
	cout << nome<<endl;
	if(cadastrados.empty()){
		cout << "Ninguém cadastrado"<<endl;
	}else{
		for(int i = 0; i < cadastrados.size(); i++){
			cout <<cadastrados.at(i).getNome()<<endl;
		}
		cout <<endl;
	}
	
};