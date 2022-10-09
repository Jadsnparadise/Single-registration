#include <iostream>
using namespace std;

class Pessoa{

private:
	string nome;
	string cpf;
	string endereco;

public:

	Pessoa(string nomePessoa, string cpf);

	string getNome();

	void setNome(string nomePessoa);

	string getCpf();

	void setCpf(string cpfNum);

	string getEndereco();

	void setEndereco(string rua);
};