#include "../modelos/Aerolinea.cpp"
#include "Cola.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class LectorAerolineas {
public:
  Aerolinea *obtenerDatos() {
    Aerolinea *data = NULL;
    Cola<string> *cola = new Cola<string>;
    ifstream file;
    string texto;

    file.open("persistencia/archivos/aerolineas.txt", ios::in); // abriendo el archivo

    if (file.fail())
      return NULL;

    while (!file.eof()) { // mientras bo sea el final del archivo
      getline(file, texto);
      cola->encolar(texto);
    }
    file.close();
    data = pasarDatos(cola);
    cout << "PasooooA" << endl;
    return data;
  }

private:
  Aerolinea *pasarDatos(Cola<string> *rawCola) {
    Aerolinea *datos;
    datos = new Aerolinea[rawCola->getTam()];
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
        cout << a.codigo << endl;
      
        a.nombre = datos_separados->desencolar();
        cout << a.nombre << endl;
      
        a.cuenta_bancaria = datos_separados->desencolar();
        cout << a.cuenta_bancaria << endl;

        datos[pos++] = a;
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

