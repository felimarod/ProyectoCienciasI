#include "../modelos/Avion.cpp"
#include "Cola.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class LectorAviones {
public:
  Avion *obtenerDatos() {
    Avion *data = NULL;
    Cola<string> *cola = new Cola<string>;
    ifstream file;
    string texto;

    file.open("persistencia/archivos/aviones.txt", ios::in); // abriendo el archivo

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
  Avion *pasarDatos(Cola<string> *rawCola) {
    Avion *datos;
    datos = new Avion[rawCola->getTam()];
    string linea = "";
    Cola<string> *datos_separados;

    int pos = 0;
    // parsear el registro del archivo a un objeto Avion
    while (!rawCola->isEmpty()) {
      Avion av;
      linea = rawCola->desencolar();
      if (linea != "") {

        datos_separados = split(linea);

        if (datos_separados->colaVacia())
          cout << "La cola esta vacia \n";

        av.idAvion = atoi((datos_separados->desencolar()).c_str());
        av.capacidad = atoi((datos_separados->desencolar()).c_str());
        av.idAerolinea = atoi((datos_separados->desencolar()).c_str());

        datos[pos++] = av;
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

