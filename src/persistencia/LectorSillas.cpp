#include "../modelos/Silla.cpp"
#include "Cola.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class LectorSillas {
public:
  Silla *obtenerDatos() {
    Silla *data = NULL;
    Cola<string> *cola = new Cola<string>;
    ifstream file;
    string texto;

    file.open("persistencia/archivos/sillas.txt", ios::in); // abriendo el archivo

    if (file.fail()){
    	cout << "No se pudo abrir el archivo sillas.txt" << endl;
    	return NULL;	
	}
      

    while (!file.eof()) { // mientras bo sea el final del archivo
      getline(file, texto);
      cola->encolar(texto);
    }
    file.close();
    data = pasarDatos(cola);
    cout << "PasooooS" << endl;
    return data;
  }

private:
  Silla *pasarDatos(Cola<string> *rawCola) {
    Silla *datos;
    datos = new Silla[rawCola->getTam()];
    string linea = "";
    Cola<string> *datos_separados;

    int pos = 0;
    // parsear el registro del archivo a un objeto Silla
    while (!rawCola->isEmpty()) {
      Silla s;
      linea = rawCola->desencolar();
      datos_separados = split(linea);

      if (datos_separados->colaVacia())
        cout << "La cola esta vacia \n";

      s.id_silla = atoi((datos_separados->desencolar()).c_str());
      //cout << s.id_silla<<endl;
      
      s.idModeloAvion = atoi((datos_separados->desencolar()).c_str());
      //cout << s.idModeloAvion<<endl;
      
      s.posicion = datos_separados->desencolar();
      //cout << s.posicion << endl;
      datos[pos++] = s;
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

