#include "logica/Multilista.h"
#include "persistencia/LectorUsuarios.cpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch,
 * system("pause") or input loop */

void leerArchivo() {
  ifstream archivo;
  string texto;

  archivo.open("/home/runner/ProyectoCienciasI/archivos/usuarios.txt", ios::in);

  if (archivo.fail()) {
    cout << "NO se pudo";
    exit(1);
  }

  while (!archivo.eof()) {
    getline(archivo, texto);
    cout << texto << endl;
  }
  archivo.close();
}

int main(int argc, char **argv) {

  Multilista m;
  m.insertar(1, 1, 1, 2, "lunes", "12:00", 70, 20, 3);
  m.insertar(2, 2, 1, 2, "lunes", "12:00", 70, 20, 3);
  m.insertar(3, 1, 2, 3, "lunes", "12:00", 70, 20, 3);
  m.insertar(4, 1, 3, 1, "lunes", "12:00", 70, 20, 3);
  m.insertar(7, 1, 2, 1, "lunes", "12:00", 70, 20, 3);
  m.insertar(8, 3, 2, 4, "lunes", "12:00", 30, 20, 30);
  m.insertar(9, 2, 2, 4, "lunes", "12:00", 70, 20, 30);
  m.insertar(10, 4, 2, 4, "lunes", "12:00", 40, 10, 3);
  m.insertar(11, 4, 2, 4, "lunes", "12:00", 70, 80, 23);
  m.eliminar(6);

  // Consumir datos del vuelo planeado para llenar multilista
  //leerArchivo();
/*   LectorUsuarios lector ;
  lector.obtenerDatos("usuarios.txt"); */

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
  VueloPlaneado *vuelos = m.obtenerVuelos(2, 4, 2);
  for (int i = 0; vuelos[i].codigo != -1; i++) {
    cout << vuelos[i].codigo << endl;
  }

  return 0;
}