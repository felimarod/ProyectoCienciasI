#include "Cola.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include "../logica/Estructuras.cpp"

using std::ifstream;
using namespace std;

template <class T> class LectorArchivo {
public:
  T *obtenerDatos(string ruta) const {
    T *data = NULL;
    ifstream file = abrirArchivo(ruta);
    if (file.good()) {
      Cola<string> *rawData = obtenerDatos(file);
      data = pasarDatos(rawData);
    }
    return data;
  }

protected:
  virtual T *pasarDatos(Cola<string> *rawData) const = 0;

private:
  ifstream abrirArchivo(string ruta) const {
    ifstream file(ruta);
    return file;
  }
  Cola<string> *obtenerDatos(ifstream file) const {
    string texto;
    Cola<string> *cola = new Cola<string>;
    while (getline(file, texto))
      cola->push(texto);
    return cola;
  }
};
