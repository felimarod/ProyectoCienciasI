#include "logica/Multilista.h"
#include "persistencia/LectorUsuarios.cpp"
#include "persistencia/LectorVuelosEspecificos.cpp"
#include "persistencia/LectorAerolineas.cpp"
#include "persistencia/LectorAviones.cpp"
#include "persistencia/LectorLugares.cpp"
#include "persistencia/LectorModelosAviones.cpp"
#include "persistencia/LectorPasajeros.cpp"
#include "persistencia/LectorSillas.cpp"
#include "persistencia/LectorVuelosPlaneados.cpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>



/* run this program using the console pauser or add your own getch,
 * system("pause") or input loop */

int main(int argc, char **argv) {

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
  LectorVuelosPlaneados lectorVp;
  listaPlaneados listaVp;
  listaVp = lectorVp.obtenerDatos();
  VueloPlaneadoC *vp = listaVp.buscarVueloPlaneado(1);
  cout<<vp->dia<<endl;
  
  //consumir datos del archivo de aerolineas
  LectorAerolineas lectorA;
  listaAerolinea listaA;
  listaA = lectorA.obtenerDatos();
  Aerolinea *a = listaA.buscarAerolinea(2);
  if(a!=NULL){
  	cout<<a->nombre<<endl;
  }
  
  //consumir datos del archivo de lugares
  LectorLugares lectorLu;
  listaLugar listaLu;
  listaLu = lectorLu.obtenerDatos();
  Lugar *l = listaLu.buscarLugar(2);
  if(a!=NULL){
  	cout<<l->nombre<<endl;
  }
  
  //insertar en multilista
  int d=0;
  string dia="";
  Multilista m;
  
  for(int i=1; i<listaVp.tamLista(); i++){
  	vp=listaVp.buscarVueloPlaneado(i);
  	d=vp->dia;
  	
	switch(d){
  		case 1:
  			dia = "lunes";
  			break;
  		case 2:
  			dia = "martes";
  			break;
  		case 3:
  			dia = "miercoles";
  			break;
  		case 4:
  			dia = "jueves";
  			break;
  		case 5:
  			dia = "viernes";
  			break;
  		case 6:
  			dia = "sabado";
  			break;
  		case 7:
  			dia = "domingo";
  			break;	
	}
	m.insertar(i, vp->idAerolinea, vp->origen, vp->destino, dia, vp->hora_inicio, vp->duracion, vp->precio_adulto, vp->precio_ninio);	
  }
 
 	
	for(int i=1; i<listaLu.tamLista(); i++){
		l=listaLu.buscarLugar(i);
		cout<<l->nombre<<endl;
	}
	
	 VueloPlaneado *vuelos = m.obtenerVuelos(2, 4, 0);
	  for (int i = 0; vuelos[i].codigo != -1; i++) {
	    cout << vuelos[i].codigo<<"\t";
	    cout << vuelos[i].precio_adulto<<"\t\n";
	  }
	
	
	
  /*cout << "\n-----------------------------" << endl;
  cout << "MENU BETA- eleccion de vuelo" << endl;
  cout << "-------------------------------" << endl;
  cout << "\nIngrese su origen y destino" << endl;

cout << "Origen: ";
  cin >> origen;
  cout << "Destino: ";
  cin >> destino; */
  //Verficar si existe el lugar origen

  //Verficar si existe el lugar origen

  //Obtener lista con mismo origen y destino
  
  //consumir datos del archivo de vuelos_especificos
  //VueloEspecifico *dataVe;
  //LectorVuelosEspecificos lectorVe;
  //dataVe = lectorVe.obtenerDatos();
  
  //consumir datos del archivo de usuarios
  //Usuario *dataU;
  //LectorUsuarios lectorU ;
  //dataU = lectorU.obtenerDatos(); 
  
  //consumir datos del archivo de aviones
  //Avion *dataAv;
  //LectorAviones lectorAv;
  //dataAv = lectorAv.obtenerDatos(); */
  
  
  
  //consumir datos del archivo de modelos_aviones
  ModeloAvion *dataMda;
  LectorModelosAviones lectorMda;
  //dataMda = lectorMda.obtenerDatos(); 
  
  //consumir datos del archivo de pasajeros
  Pasajero *dataP;
  LectorPasajeros lectorP;
  //dataP = lectorP.obtenerDatos(); 
  
  //consumir datos del archivo de Sillas
  Silla *dataS;
  LectorSillas lectorS;
  //dataS = lectorS.obtenerDatos(); 
  //cout<<dataS[1].id_silla<<endl;  
  
  int op = 0;
  string origen;
  string destino;

  

  return 0;
}
