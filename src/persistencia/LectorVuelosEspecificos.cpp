#include "../modelos/VueloEspecifico.cpp"
#include "Cola.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class LectorVuelosEspecificos {
public:
  	VueloEspecifico *obtenerDatos() {
	    VueloEspecifico *data = NULL;
	    Cola<string> *cola = new Cola<string>;
	    ifstream file;
	    string texto;
	
	    file.open("src/persistencia/archivos/vuelos_especificos.txt", ios::in); // abriendo el archivo
	
	    if (file.fail())
	      return NULL;
	
	    while (!file.eof()) { // mientras bo sea el final del archivo
	      getline(file, texto);
	      cola->encolar(texto);
	    }
	    file.close();
	    data = pasarDatos(cola);
	    cout << "PasooooVE" << endl;
	    return data;
  }

private:
  VueloEspecifico *pasarDatos(Cola<string> *rawCola) {
    VueloEspecifico *datos;
    datos = new VueloEspecifico[rawCola->getTam()];
    string linea = "";
    Cola<string> *datos_separados;

    int pos = 0;
    // parsear el registro del archivo a un objeto usuario
    while (!rawCola->isEmpty()) {
      VueloEspecifico ve;
      linea = rawCola->desencolar();
      datos_separados = split(linea);

      if (datos_separados->colaVacia())
        cout << "La cola esta vacia \n";

      ve.idVueloEspecifico = atoi((datos_separados->desencolar()).c_str());
      cout << ve.idVueloEspecifico << endl;
      
      ve.idVueloPlaneado = atoi((datos_separados->desencolar()).c_str());
      cout << ve.idVueloPlaneado << endl;
      
      ve.idModeloAvion = atoi((datos_separados->desencolar()).c_str());
      cout << ve.idModeloAvion << endl;
      
      ve.fecha_vuelo = datos_separados->desencolar();
      cout << ve.fecha_vuelo << endl;
      
      datos[pos++] = ve;
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
