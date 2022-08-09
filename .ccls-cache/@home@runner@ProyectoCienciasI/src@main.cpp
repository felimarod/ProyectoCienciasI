#include <iostream>
#include "logica/Multilista.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Multilista m;
	m.insertar(1,1,2,"lunes","12:00",70,20,3,1);
	m.insertar(2,1,2,"lunes","12:00",70,20,3,2);
	m.insertar(3,2,3,"lunes","12:00",70,20,3,1);
	m.insertar(4,3,1,"lunes","12:00",70,20,3,1);
	m.insertar(7,2,1,"lunes","12:00",70,20,3,1);
	m.insertar(8,2,4,"lunes","12:00",30,20,30,3);
	m.insertar(9,2,4,"lunes","12:00",70,20,30,2);
	m.insertar(10,2,4,"lunes","12:00",40,10,3,4);
	m.insertar(11,2,4,"lunes","12:00",70,80,23,4);
	m.eliminar(6); 
	VueloPlaneado *vuelos=m.obtenerVuelos(2,4,2);
	for(int i=0;vuelos[i].codigo!=NULL;i++){
		cout<<vuelos[i].codigo<<endl;
	}
	return 0;
}