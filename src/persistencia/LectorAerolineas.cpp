#include "../logica/ListaAerolinea.h"
#include "Cola.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class LectorAerolineas {
public:
  listaAerolinea obtenerDatos() {
    listaAerolinea l;
    Cola<string> *cola = new Cola<string>;
    ifstream file;
    string texto;

    file.open("persistencia/archivos/aerolineas.txt", ios::in); // abriendo el archivo

    if (file.fail())
      return l;

    while (!file.eof()) { // mientras bo sea el final del archivo
      getline(file, texto);
      cola->encolar(texto);
    }
    file.close();
    l = pasarDatos(cola);
    return l;
  }

private:
  listaAerolinea pasarDatos(Cola<string> *rawCola) {
    listaAerolinea lista;
    string linea = "";
    Cola<string> *datos_separados;

    int pos = 0;
    // parsear el registro del archivo a un objeto Aerolinea
    while (!rawCola->isEmpty()) {
      Aerolinea a;
      linea = rawCola->desencolar();
      if (linea != "") {
        datos_separados = split(linea);

        if (datos_separados->colaVacia())
          cout << "La cola esta vacia \n";

        a.codigo = atoi((datos_separados->desencolar()).c_str());
        a.nombre = datos_separados->desencolar();
        a.cuenta_bancaria = datos_separados->desencolar();
        
        lista.insertarFinal(a); 
	  }
    }
    return lista;
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
