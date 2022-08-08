#include <iostream>
using namespace std;

class Reserva {

  string nombre_reserva;
  int id;
  int documento_pasajero;
  int numero_pasajes;
  // Lista[Itinerario] itinerarios;
  // Lista[Pasajero] pasajeros;

  Reserva(int id, int pasajero_doc, int num_pasajes) {
    this->id = id;
    this->documento_pasajero = pasajero_doc;
    this->numero_pasajes = num_pasajes;
  }
};
