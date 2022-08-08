#include "./Structuras.cpp"
#include <iostream>
using namespace std;

class VueloPlaneado {
  int codigo;
  string origen;
  string destino;
  string dia; /* Lunes, Martes, ... */
  hora hora_salida;
  hora hora_llegada;
  double precio_adulto;
  double precio_ninio;
  //vuelos_asociados; /* Al final se dejo raro en el diagrama xd */
};
