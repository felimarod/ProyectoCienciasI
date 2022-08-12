#include "../modelos/Usuario.cpp"
#include "Cola.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class LectorUsuarios {
public:
  Usuario *obtenerDatos() {
    Usuario *data = NULL;
    Cola<string> *cola = new Cola<string>;
    ifstream file;
    string texto;

    file.open("persistencia/archivos/usuarios.txt",
              ios::in); // abriendo el archivo

    if (file.fail())
      return NULL;

    while (!file.eof()) { // mientras bo sea el final del archivo
      getline(file, texto);
      cola->encolar(texto);
    }
    file.close();
    data = pasarDatos(cola);
    return data;
  }

private:
  Usuario *pasarDatos(Cola<string> *rawCola) {
    Usuario *datos;
    datos = new Usuario[rawCola->getTam()];
    string linea = "";
    Cola<string> *datos_separados;

    int pos = 0;
    // parsear el registro del archivo a un objeto usuario
    while (!rawCola->isEmpty()) {
      Usuario u;
      linea = rawCola->desencolar();
      if(linea != ""){
      	datos_separados = split(linea);

        if (datos_separados->colaVacia())
          cout << "La cola esta vacia \n";

        // datos[pos].idUsuario = atoi((datos_separados->desencolar()).c_str());
        u.idUsuario = atoi((datos_separados->desencolar()).c_str());
        u.nombre = datos_separados->desencolar();
        u.numeroDocumento = atoi((datos_separados->desencolar()).c_str());
        u.sexo = datos_separados->desencolar();

        datos[pos++] = u;	
	  }
    }
    return datos;
  }

  Cola<string> *split(string str) {
    char SEP = ';';

    int posInit = 0;
    int posFound = 0;
    string splitted;
    Cola<string> *results = new Cola<string>;

    while (posFound >= 0) {
      posFound = str.find(SEP, posInit);
      splitted = str.substr(posInit, posFound - posInit);
      posInit = posFound + 1;
      results->encolar(splitted);
    }

    return results;
  }
};

