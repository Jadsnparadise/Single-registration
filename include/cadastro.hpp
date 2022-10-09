#include <iostream>
#include "pessoa.hpp"
#include <vector>
using namespace std;

class Cadastro{

private:

	vector<Pessoa> cadastrados;
	string nome;

public:

	Cadastro(string nomeCadastro);

	void adicionaPessoa(Pessoa p);

	void removePessoa(Pessoa p);

	Pessoa encontraPessoa(string cpf);
	
	void limpaCadastro();

	void lerArquivo(string arqNome);

	void imprimeUsuarios();
};
