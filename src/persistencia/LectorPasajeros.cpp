#include "../modelos/Pasajero.cpp"
#include "Cola.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class LectorPasajeros {
public:
  Pasajero *obtenerDatos() {
    Pasajero *data = NULL;
    Cola<string> *cola = new Cola<string>;
    ifstream file;
    string texto;

    file.open("persistencia/archivos/pasajeros.txt", ios::in); // abriendo el archivo

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
  Pasajero *pasarDatos(Cola<string> *rawCola) {
    Pasajero *datos;
    datos = new Pasajero[rawCola->getTam()];
    string linea = "";
    Cola<string> *datos_separados;

    int pos = 0;
    // parsear el registro del archivo a un objeto Pasajero
    while (!rawCola->isEmpty()) {
        linea = rawCola->desencolar();
		if (linea != "") {
	        datos_separados = split(linea);

			datos[pos].idPasajero = atoi((datos_separados->desencolar()).c_str());
		    
		    datos[pos].nombre = datos_separados->desencolar();
		    
		    datos[pos].numeroDocumento = atoi(datos_separados->desencolar().c_str());
		    
		    datos[pos].fechaNac = datos_separados->desencolar();
		    
		    datos[pos].adulto = atoi(datos_separados->desencolar().c_str());
		
		    pos++;		
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

