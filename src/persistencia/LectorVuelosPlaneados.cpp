#include "../modelos/VueloPlaneado.cpp"
#include "Cola.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class LectorVuelosPlaneados {
public:
  	VueloPlaneado *obtenerDatos() {
	    VueloPlaneado *data = NULL;
	    Cola<string> *cola = new Cola<string>;
	    ifstream file;
	    string texto;
	
	    file.open("src/persistencia/archivos/vuelos_planeados.txt", ios::in); // abriendo el archivo
	
	    if (file.fail())
	      return NULL;
	
	    while (!file.eof()) { // mientras bo sea el final del archivo
	      getline(file, texto);
	      cola->encolar(texto);
	    }
	    file.close();
	    data = pasarDatos(cola);
	    cout << "PasooooVP" << endl;
	    return data;
  }

private:
  VueloPlaneado *pasarDatos(Cola<string> *rawCola) {
    VueloPlaneado *datos;
    datos = new VueloPlaneado[rawCola->getTam()];
    string linea = "";
    Cola<string> *datos_separados;

    int pos = 0;
    // parsear el registro del archivo a un objeto usuario
    while (!rawCola->isEmpty()) {
      VueloPlaneado vp;
      linea = rawCola->desencolar();
      datos_separados = split(linea);

      if (datos_separados->colaVacia())
        cout << "La cola esta vacia \n";

      vp.id_vuelo = atoi((datos_separados->desencolar()).c_str());
      cout << vp.id_vuelo << endl;
      
      vp.idAerolinea = atoi((datos_separados->desencolar()).c_str());
      cout << vp.idAerolinea << endl;
      
      vp.origen = atoi((datos_separados->desencolar()).c_str());
      cout << vp.origen << endl;
      
      vp.destino = atoi((datos_separados->desencolar()).c_str());
      cout << vp.destino << endl;
      
      vp.dia = atoi((datos_separados->desencolar()).c_str());
      cout << vp.dia << endl;
      
      vp.hora_inicio = datos_separados->desencolar(); //la hora que se desencola debe ser de tipo (struct hora)
      cout << vp.hora_inicio << endl;
      
      vp.duracion = atoi((datos_separados->desencolar()).c_str());
      cout << vp.duracion << endl;
      
      vp.precio_adulto = atoi((datos_separados->desencolar()).c_str());
      cout << vp.precio_adulto << endl;
      
      vp.precio_ninio = atoi((datos_separados->desencolar()).c_str());
      cout << vp.precio_ninio << endl;

      datos[pos++] = vp;
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
