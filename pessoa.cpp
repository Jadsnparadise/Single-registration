#include <iostream>
#include "include/pessoa.hpp"
using namespace std;

Pessoa::Pessoa(string nomePessoa, string cpfNum){
	nome = nomePessoa;
	cpf = cpfNum;
}

string Pessoa::getNome(){
	return nome;
}

void Pessoa::setNome(string nomePessoa){
	nome = nomePessoa;
}

string Pessoa::getCpf(){
	return cpf;
}

void Pessoa::setCpf(string cpfNum){
	cpf = cpfNum;
}

string Pessoa::getEndereco(){
	return endereco;
}

void Pessoa::setEndereco(string rua){
	endereco = rua;
}