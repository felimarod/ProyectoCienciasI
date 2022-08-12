//#include "logica/Multilista.h"
#include "persistencia/LectorUsuarios.cpp"
#include "persistencia/LectorVuelosPlaneados.cpp"
#include "persistencia/LectorVuelosEspecificos.cpp"
#include "persistencia/LectorAerolineas.cpp"
#include "persistencia/LectorAviones.cpp"
#include "persistencia/LectorLugares.cpp"
#include "persistencia/LectorModelosAviones.cpp"
#include "persistencia/LectorPasajeros.cpp"
#include "persistencia/LectorSillas.cpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>

/* 
 * Ejecutable principal del proyecto
 * */

int main() {

  /*Multilista m;
  m.insertar(1, 1, 1, 2, "lunes", "12:00", 70, 20, 3);
  m.insertar(2, 2, 1, 2, "lunes", "12:00", 70, 20, 3);
  m.insertar(3, 1, 2, 3, "lunes", "12:00", 70, 20, 3);
  m.insertar(4, 1, 3, 1, "lunes", "12:00", 70, 20, 3);
  m.insertar(7, 1, 2, 1, "lunes", "12:00", 70, 20, 3);
  m.insertar(8, 3, 2, 4, "lunes", "12:00", 30, 20, 30);
  m.insertar(9, 2, 2, 4, "lunes", "12:00", 70, 20, 30);
  m.insertar(10, 4, 2, 4, "lunes", "12:00", 40, 10, 3);
  m.insertar(11, 4, 2, 4, "lunes", "12:00", 70, 80, 23);
  m.eliminar(6);*/

  // Consumir datos del vuelo planeado para llenar multilista
  
  
  //consumir datos del archivo de vuelos_planeados
  VueloPlaneado *dataVp;
  LectorVuelosPlaneados lectorVp;
  //dataVp = lectorVp.obtenerDatos();
  
  //consumir datos del archivo de vuelos_especificos
  VueloEspecifico *dataVe;
  LectorVuelosEspecificos lectorVe;
  //dataVe = lectorVe.obtenerDatos();
  
  //consumir datos del archivo de usuarios
  Usuario *dataU;
  LectorUsuarios lectorU ;
  //dataU = lectorU.obtenerDatos(); 
  
  //consumir datos del archivo de aerolineas
  Aerolinea *dataA;
  LectorAerolineas lectorA;
  //dataA = lectorA.obtenerDatos(); 
  
  //consumir datos del archivo de aviones
  Avion *dataAv;
  LectorAviones lectorAv;
  //dataAv = lectorAv.obtenerDatos(); 
  
  //consumir datos del archivo de lugares
  Lugar *dataLu;
  LectorLugares lectorLu;
  //dataLu = lectorLu.obtenerDatos(); 
  
  //consumir datos del archivo de modelos_aviones
  ModeloAvion *dataMda;
  LectorModelosAviones lectorMda;
  dataMda = lectorMda.obtenerDatos(); 
  
  //consumir datos del archivo de pasajeros
  Pasajero *dataP;
  LectorPasajeros lectorP;
  //dataP = lectorP.obtenerDatos(); 
  
  //consumir datos del archivo de Sillas
  Silla *dataS;
  LectorSillas lectorS;
  dataS = lectorS.obtenerDatos(); 
  
  
  int op = 0;
  string origen;
  string destino;

  cout << "\n-----------------------------" << endl;
  cout << "MENU BETA- eleccion de vuelo" << endl;
  cout << "-------------------------------" << endl;
  cout << "\nIngrese su origen y destino" << endl;
/*   cout << "Origen: ";
  cin >> origen;
  cout << "Destino: ";
  cin >> destino; */
  // Verficar si existe el lugar origen

  // Verficar si existe el lugar origen

  // Obtener lista con mismo origen y destino
  /*VueloPlaneado *vuelos = m.obtenerVuelos(2, 4, 2);
  for (int i = 0; vuelos[i].codigo != -1; i++) {
    cout << vuelos[i].codigo << endl;
  }*/

  return 0;
}
