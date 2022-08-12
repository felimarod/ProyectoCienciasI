#include "../logica/ListaLugar.h"
#include "Cola.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class LectorLugares {
public:
  listaLugar obtenerDatos() {
  	listaLugar ll;
    Cola<string> *cola = new Cola<string>;
    ifstream file;
    string texto;

    file.open("persistencia/archivos/lugares.txt", ios::in); // abriendo el archivo

    if (file.fail())
      return ll;

    while (!file.eof()) { // mientras bo sea el final del archivo
      getline(file, texto);
      cola->encolar(texto);
    }
    file.close();
    ll = pasarDatos(cola);
    return ll;
  }

private:
  listaLugar pasarDatos(Cola<string> *rawCola) {
    listaLugar listaL;
    string linea = "";
    Cola<string> *datos_separados;

    int pos = 0;
    // parsear el registro del archivo a un objeto listaLugar
    while (!rawCola->isEmpty()) {
      Lugar lu;
      linea = rawCola->desencolar();
      if (linea != "") {
        datos_separados = split(linea);

        if (datos_separados->colaVacia())
          cout << "La cola esta vacia \n";

        lu.idLugar = atoi((datos_separados->desencolar()).c_str());
        lu.nombre = datos_separados->desencolar();

        listaL.insertarFinal(lu);
  	  }
    }
    return listaL;
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

