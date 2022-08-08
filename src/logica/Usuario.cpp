#include <iostream>
using namespace std;

class Usuario {

  string nombre;
  char sexo;
  int edad;
  int documento;

	Usuario(string nombre, char sexo, int edad, int documento){
		this->nombre = nombre;
		this->sexo = sexo;
		this->edad = edad;
		this->documento = documento;
	}
};
