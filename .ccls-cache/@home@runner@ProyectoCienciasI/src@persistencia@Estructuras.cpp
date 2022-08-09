#include <iostream>
using namespace std;

class fecha{
  int dia;
  int mes;
};

class hora{
  int hora;
  int minuto;
};

class Silla {
  int id_silla;
  int idModeloAvion;
  string posicion;
};

class ModeloAvion {
  int idModeloAvion;
  string nombre;
  int capacidad;
};

class Avion{
  int idAvion;
  int idAerolinea;
  int capacidad;
};

class Aerolinea {
  int codigo;
  string nombre;
  string cuenta_bancaria;
};

class Lugar {
  int idLugar;
  string nombre;
};

class VueloPlaneado{
  int id_vuelo;
  int idAerolinea;
  int origen;
  int destino;
  int dia;
  hora hora_inicio;
  int duracion;
  int precio_adulto;
  int precio_ninio;
};

class VueloEspecifico {
  int idVueloEspecifico;
  int idVueloPlaneado;
  int idModeloAvion;
  fecha fecha_vuelo;
};

class SillaVendida {
  int idSilla;
  int idReservaPasajero;
  int idVueloEspecifico;
  string posicion;
};

class ItinerarioPasajero {
  string nombre;
  int idItinerario;
  int docPasajero;
};

class Pasajero {
  int numeroDocumento;
  string nombre;
  fecha nacimiento;
  bool adulto;
};

class Itinerario {
  int idItinerario;
  int idUsuario;
  string nombre;
  int costoTotal;
  bool comprado;
};

class Usuario {
  int numeroDocumento;
  string nombre;
  char sexo;
  int edad;
};