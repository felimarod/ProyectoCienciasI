#include "../modelos/Lugar.cpp"
#include "Cola.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class LectorLugares {
public:
  Lugar *obtenerDatos() {
    Lugar *data = NULL;
    Cola<string> *cola = new Cola<string>;
    ifstream file;
    string texto;

    file.open("src/persistencia/archivos/lugares.txt", ios::in); // abriendo el archivo

    if (file.fail())
      return NULL;

    while (!file.eof()) { // mientras bo sea el final del archivo
      getline(file, texto);
      cola->encolar(texto);
    }
    file.close();
    data = pasarDatos(cola);
    cout << "PasooooLu" << endl;
    return data;
  }

private:
  Lugar *pasarDatos(Cola<string> *rawCola) {
    Lugar *datos;
    datos = new Lugar[rawCola->getTam()];
    string linea = "";
    Cola<string> *datos_separados;

    int pos = 0;
    // parsear el registro del archivo a un objeto Lugar
    while (!rawCola->isEmpty()) {
      Lugar lu;
      linea = rawCola->desencolar();
      datos_separados = split(linea);

      if (datos_separados->colaVacia())
        cout << "La cola esta vacia \n";

      lu.idLugar = atoi((datos_separados->desencolar()).c_str());
      cout << lu.idLugar<<endl;
      
      lu.nombre = datos_separados->desencolar();
      cout << lu.nombre << endl;

      datos[pos++] = lu;
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

