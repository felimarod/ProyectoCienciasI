#include "logica/Multilista.h"
#include "persistencia/LectorAerolineas.cpp"
#include "persistencia/LectorAviones.cpp"
#include "persistencia/LectorLugares.cpp"
#include "persistencia/LectorModelosAviones.cpp"
#include "persistencia/LectorPasajeros.cpp"
#include "persistencia/LectorSillas.cpp"
#include "persistencia/LectorUsuarios.cpp"
#include "persistencia/LectorVuelosEspecificos.cpp"
#include "persistencia/LectorVuelosPlaneados.cpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>

LectorAerolineas lectorA;
listaAerolinea listaA;
Aerolinea *aerolinea;

LectorVuelosPlaneados lectorVp;
listaPlaneados listaVp;

LectorLugares lectorLu;
listaLugar listaLu;

LectorVuelosEspecificos lectorVE;
listaEspecificos listaVE;
VueloEspecifico *ve;

Multilista m;

void cargarDatos();
void menuIngreso();
void menuAerolinea();
void menuUsuario();
/* run this program using the console pauser or add your own getch,
 * system("pause") or input loop */
int main() {
  /*
   * Identificar que tipo de usuario es
   * a. Aereolinea
   *     Buscar
   *    + Destinos
   *    + Vuelos Planeados
   * b. Usuario
   *     Comprar tickets
   *     - Seleccione origen
   *     - Seleccione destino
   *     - Defina por que desea filtrar los vuelos
   *       + Adulto 0
   *       + Niño 1
   *       + Duracion 2
   * */
  int op;
  
  /*Consumir datos de los archivos planos*/
  cargarDatos();
  menuIngreso();

  return 0;
}
void limpiar() { system("cls");}
void cargarDatos() {
  VueloPlaneadoC *vp;
  int d;
  string dia;
  listaA = lectorA.obtenerDatos();
  listaVp = lectorVp.obtenerDatos();
  listaLu = lectorLu.obtenerDatos();
  listaVE = lectorVE.obtenerDatos();
  for (int i = 1; i < listaVp.tamLista(); i++) {
    vp = listaVp.buscarVueloPlaneado(i);
    d = vp->dia;

    switch (d) {
    case 1:
      dia = "Lunes";
      break;
    case 2:
      dia = "Martes";
      break;
    case 3:
      dia = "Miercoles";
      break;
    case 4:
      dia = "Jueves";
      break;
    case 5:
      dia = "Viernes";
      break;
    case 6:
      dia = "Sabado";
      break;
    case 7:
      dia = "Domingo";
      break;
    }
    m.insertar(i, vp->idAerolinea, vp->origen, vp->destino, dia,
               vp->hora_inicio, vp->duracion, vp->precio_adulto,
               vp->precio_ninio);
  }
}

void menuIngreso() {
  limpiar();
  int op = 0;
  cout << "------- BIENVENIDO -------\n"
       << "Primero necesitamos que te identifiques" << endl;

  while (op != 1 && op != 2) {
    cout << "Ingresa el número respectivo a tu tipo de usuario:\n"
         << "1.\tAerolinea\n"
         << "2.\tUsuario\n"
         << "Presione 3 para salir\n";
    cin >> op;
    if (op == 3)
      return;
  }
  if (op == 1)
    menuAerolinea();
  else
    menuUsuario();
  cout << "\n¿Deseas volver a ingresar?\n1. Si\n2. No\nIngresa tu elección: ";
  cin >> op;
  if (op == 1)
    menuIngreso();
}
void menuAerolinea() {
  limpiar();
  
  for (int i=1; i<=listaA.tamLista(); i++){
  	cout<<listaA.buscarAerolinea(i)->codigo<<".\t"<<listaA.buscarAerolinea(i)->nombre<<endl;
  }
  
  int id, op = 0;
  cout << "Ingresa el identificador de tu aereolinea: ";
  cin >> id;
  
  limpiar();
  while ((aerolinea = listaA.buscarAerolinea(id)) == NULL) {
    cout << "El identificador no se encuentra registrado, por favor verifica "
            "que es correcto y vuelve a ingresarlo\nIdentificador de tu "
            "aereolinea: ";
    cin >> id;
  }
  while (op != 1 && op != 2) {
    cout << "Ingresa el número respecivo a lo que deseas realizar:\n"
         << "1.\tVisualizar plan semanal de la aerolinea.\n"
         << "2.\tVisualizar los vuelos planeados que ofrece la aerolinea."
         << "Presione 3 para salir\n";
    cin >> op;
    cout<<"\n Aerolinea seleccionada: "<<listaA.buscarAerolinea(id)->nombre<<endl;
    if (op == 3)
      return;
  }
  int k;
  int *cabeceras = m.obtenerCabeceras();
  VueloPlaneado *v = m.obtenerMultilista();
  if (op == 1) {
    k = cabeceras[aerolinea->codigo]; // Id aerolinea
    if (!m.multilistaVacia()) { // lista de plan semanal de vuelo aerolinea
      while (k != -1) {
        cout << v[k].codigo << "\t" << listaLu.buscarLugar(v[k].origen)->nombre
             << "\t\t" << listaLu.buscarLugar(v[k].destino)->nombre;
        cout << "\t" << v[k].hora_salida << "\t" << v[k].duracion << "\t"
             << v[k].precio_adulto << "\t" << v[k].precio_ninio << endl;
        if (v[k].sigPlanAerolinea == -1)
          break;
        k = v[k].sigPlanAerolinea;
      }
    }
  } else if (op == 2) {
    k = cabeceras[aerolinea->codigo + 10]; // Id aerolinea + 10
    if (!m.multilistaVacia()) {            // lista de destinos de la aerolinea
      while (k != -1) {
        cout << listaLu.buscarLugar(v[k].destino)->nombre << endl;
        if (v[k].sigDestino == -1)
          break;
        k = v[k].sigDestino;
      }
    }
  }
}
int seleccionarOrigen() {
  int op = 0;
  while (op <= 0 || op > listaLu.tamLista()) {
    limpiar();
    for (int i = 1; i <= listaLu.tamLista(); i++)
      cout << i << "\t" << listaLu.buscarLugar(i)->nombre << endl;
    cout << "Elija su lugar de origen" << endl;
    cin >> op;
  }
  return op;
}
int seleccionarDestino(int id_origen) {
  int op = -1;
  bool estaEnElFiltro = false;
  VueloPlaneado *v;
  int i;

  do {
    limpiar();
    cout << "Los codigos y destinos de los vuelos que tienen el origen "
         << listaLu.buscarLugar(id_origen)->nombre << " son:\n\n";
    v = m.obtenerVuelosOrigen(id_origen);
    if(v[0].origen == -1){
    	cout<<"No se encontraron vuelos para este origen\n"<<endl;
    	system("pause");
    	return 0;
	}
    for (i = 0; v[i].codigo != -1; i++) {
      cout << "Id: " << listaLu.buscarLugar(v[i].destino)->idLugar
           << "\nDestino: " << listaLu.buscarLugar(v[i].destino)->nombre << "\n\n";
    }
    cout << "Ingrese el codigo del destino que desea: " << endl;
    cin >> op;
    for (i = 1; i<listaLu.tamLista(); i++) {
      if (listaLu.buscarLugar(i)->idLugar == op) {
        estaEnElFiltro = true;
        break;
      }
    }
  } while (!estaEnElFiltro);
  return op;
}

Cola<int> *splitFecha(string str) {
  char SEP = '/';

  int posInit = 0;
  int posFound = 0;
  string splitted;
  Cola<int> *results = new Cola<int>;

  while (posFound >= 0) {
    posFound = str.find(SEP, posInit);
    splitted = str.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results->encolar(atoi(splitted.c_str()));
  }

  return results;
}

void menuUsuario() {
  limpiar();
  /* Comprar tickets
   * - Seleccione origen
   * - Seleccione destino
   * - Defina por que desea filtrar los vuelos
   *   + Adulto 0
   *   + Niño 1
   *   + Duracion 2
   **/
  int op_origen, op_destino, op_ord;
  bool exitoso = false;
  int acepta = 0;
  op_origen = op_destino = op_ord = -1;
  int i = 0;
  int op_vp = -1;
  bool existe_vp = false;
  nodoE *e = listaVE.obtenerCab();
  int mes = -1;
  int anio = -1;
  Cola<int> *f;

  do {
    op_origen = seleccionarOrigen();
    op_destino = seleccionarDestino(op_origen);
	limpiar();
	if(op_destino != 0){
	    cout << "Comprarás un vuelo de " << listaLu.buscarLugar(op_origen)->nombre
	         << " a " << listaLu.buscarLugar(op_destino)->nombre
	         << "\n\n¿Confirmas?(1.Si\t2.No)\n";
	    cin >> acepta;
	    acepta--;
	    if (acepta == 0)
	      exitoso = true;
	}
    
  } while (!exitoso);

  while (op_ord != 0 && op_ord != 1 && op_ord != 2) {
    limpiar();
    cout << "Filtrar por:\n"
            "1.\tPrecio adulto\n"
            "2.\tPrecio Niño\n"
            "3.\tDuración del vuelo\n"
            "Ingrese el valor por el cual desea filtrar los vuelos: ";
    cin >> op_ord;
    op_ord--;
  }

  VueloPlaneado *vuelos = m.obtenerVuelos(op_origen, op_destino, op_ord);

  do {
    limpiar();
    cout << endl;
    while (vuelos[i].codigo != -1) {
      cout << "Codigo: " << vuelos[i].codigo << "\nDía: " << vuelos[i].dia
           << "\nHora de salida: " << vuelos[i].hora_salida
           << "\nPrecio Adulto: " << vuelos[i].precio_adulto
           << "\nPrecio Ninio: " << vuelos[i].precio_ninio
           << "\nDuración: " << vuelos[i].duracion << "\n\n";
      i++;
    }
    cout << "Ingresa el codigo del vuelo seleccionado: ";
    cin >> op_vp;
    for (i = 0; vuelos[i].codigo != -1; i++) {
      if (vuelos[i].codigo == op_vp) {
        existe_vp = true;
        break;
      }
    }
  } while (!existe_vp);

  /* Filtrar por vuelos espcificos dado:
   * Id vuelo planeado, mes y un año */

  limpiar();
  cout << "Codigo: " << vuelos[i].codigo << "\nDía: " << vuelos[i].dia
       << "\nHora de salida: " << vuelos[i].hora_salida
       << "\nPrecio Adulto: " << vuelos[i].precio_adulto
       << "\nPrecio Ninio: " << vuelos[i].precio_ninio
       << "\nDuración: " << vuelos[i].duracion << "\n\n";
  cout << "Ingrese el número del mes en que desea viajar(1-12): ";
  cin >> mes;
  cout << "Ingrese el año en que desea viajar(2022-2023): ";
  cin >> anio;
  limpiar();
  if (!listaVE.listaVacia()) {
    while (e != NULL) {
      if (e->info.idVueloPlaneado == op_vp) {
        cout << "Aerolinea: "
             << listaA.buscarAerolinea(vuelos[i].aerolinea)->nombre
             << "\nDía: " << vuelos[i].dia
             << "\nHora de salida: " << vuelos[i].hora_salida
             << "\nPrecio Adulto: " << vuelos[i].precio_adulto
             << "\nPrecio Ninio: " << vuelos[i].precio_ninio
             << "\nDuración: " << vuelos[i].duracion << "\n";
        break;
      }
      e = e->sigPlan;
    }
    while (e != NULL) {
      f = splitFecha(e->info.fecha_vuelo);
      if (f->desencolar() == mes) {
        f->desencolar();
        if (f->desencolar() == anio) {
          cout << "\nCodigo del vuelo: " << e->info.idVueloEspecifico
               << "\nFecha: " << e->info.fecha_vuelo << endl;
        }
      }
      if (e->info.idVueloPlaneado != (e->sig->info).idVueloPlaneado) {
        break;
      }
      e = e->sig;
    }
    int codVuelo=0;
    cout<<"Seleccione el codigo de vuelo que quiere: "; cin>>codVuelo;
    cout<<"\nCOMPRA EXITOSA! (aca se deberia salvar su informacion, pero no se alcanzo ;p)"<<endl;
     cout<<"Gracias por elegirnos como su gestor de vuelos de confianza"<<endl;
  }
}

