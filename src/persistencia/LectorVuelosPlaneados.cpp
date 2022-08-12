#include "../logica/ListaPlaneados.h"
#include "Cola.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class LectorVuelosPlaneados {
	public:
		listaPlaneados obtenerDatos(){
		listaPlaneados l;
	    Cola<string> *cola = new Cola<string>;
	    ifstream file;
	    string texto;
	
	    file.open("persistencia/archivos/vuelos_planeados.txt", ios::in); // abriendo el archivo
	
	    if (file.fail())
	      return l;
	
	    while (!file.eof()) { // mientras bo sea el final del archivo
	      getline(file, texto);
	      cola->encolar(texto);
	    }
	    file.close();
	    l = pasarDatos(cola);
	    return l;
  }

private:
  listaPlaneados pasarDatos(Cola<string> *rawCola) {
  	listaPlaneados lista;
    string linea = "";
    Cola<string> *datos_separados;

    int pos = 0;
    // parsear el registro del archivo a un objeto usuario
    while (!rawCola->isEmpty()) {
      VueloPlaneadoC vp;
      linea = rawCola->desencolar();
      if(linea != "") {
      	datos_separados = split(linea);

        if (datos_separados->colaVacia())
          cout << "La cola esta vacia \n";

        vp.id_vuelo = atoi((datos_separados->desencolar()).c_str());
      
        vp.idAerolinea = atoi((datos_separados->desencolar()).c_str());
      
        vp.origen = atoi((datos_separados->desencolar()).c_str());
      
        vp.destino = atoi((datos_separados->desencolar()).c_str());
      
        vp.dia = atoi((datos_separados->desencolar()).c_str());
      
        vp.hora_inicio = datos_separados->desencolar(); //la hora que se desencola debe ser de tipo (struct hora)
      
        vp.duracion = atoi((datos_separados->desencolar()).c_str());
      
        vp.precio_adulto = atoi((datos_separados->desencolar()).c_str());
      
        vp.precio_ninio = atoi((datos_separados->desencolar()).c_str());

        lista.insertarFinal(vp);
	  }
    }
    return lista;
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
