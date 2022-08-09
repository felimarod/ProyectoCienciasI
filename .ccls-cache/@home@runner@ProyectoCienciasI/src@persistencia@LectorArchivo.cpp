#include "../logica/Estructuras.cpp"
#include "Cola.h"
#include <filesystem>
#include <fstream>
#include <iostream>

string CARPETA = "/home/runner/ProyectoCienciasI/archivos/";

using std::ifstream;
using namespace std;

template <class T> class LectorArchivo {
public:
  T *obtenerDatos(string archivo) const {
    T *data = NULL;
    Cola<string> *cola = new Cola<string>;
    ifstream file;
    string texto;

    file.open(CARPETA + archivo, ios::in); // abriendo el archivo

    if (file.fail())
      return NULL;

    while (!file.eof()) { // mientras bo sea el final del archivo
      getline(file, texto);
      cola->encolar(texto);
      // cout << texto << endl;
    }
    file.close();
    data = pasarDatos(cola);
    cout << "Pasoooo" << endl;
    return data;
  }

protected:
  virtual T *pasarDatos(Cola<string> *rawData) const = 0;

  Cola<string> *split(string str) const {
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