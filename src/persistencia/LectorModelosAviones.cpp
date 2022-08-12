#include "../modelos/ModeloAvion.cpp"
#include "Cola.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class LectorModelosAviones {
public:
  ModeloAvion *obtenerDatos() {
    ModeloAvion *data = NULL;
    Cola<string> *cola = new Cola<string>;
    ifstream file;
    string texto;

    file.open("persistencia/archivos/modelos_aviones.txt", ios::in); // abriendo el archivo

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
  ModeloAvion *pasarDatos(Cola<string> *rawCola) {
    ModeloAvion *datos;
    datos = new ModeloAvion[rawCola->getTam()];
    string linea = "";
    Cola<string> *datos_separados;

    int pos = 0;
    // parsear el registro del archivo a un objeto ModeloAvion
    while (!rawCola->isEmpty()) {
      ModeloAvion mda;
      linea = rawCola->desencolar();
	  if (linea != "") {
	    datos_separados = split(linea);

        if (datos_separados->colaVacia())
          cout << "La cola esta vacia \n";

        mda.idModeloAvion = atoi((datos_separados->desencolar()).c_str());
        mda.nombre = datos_separados->desencolar();
        mda.capacidad = atoi((datos_separados->desencolar()).c_str());

        datos[pos++] = mda;
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

