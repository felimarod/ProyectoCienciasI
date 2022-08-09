#include <iostream>
#include "logica/Multilista.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char **argv)
{
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

	VueloPlaneado *vuelos = m.obtenerVuelos(2, 4, 2);
	for (int i = 0; vuelos[i].codigo != -1; i++)
	{
		cout << vuelos[i].codigo << endl;
	}
	return 0;

	int op = 0;

	while (op != 9)
	{
		cout << "\n-----------------------------" << endl;
		cout << "MENU BETA- eleccion de vuelo" << endl;
		cout << "-------------------------------" << endl;
		cout << "\n1. Seleccion destiono y origen"<<endl;
		cin >> op;

		switch (op)
		{
		case 0:
			cout << "nombre: ";
			cin >> nom;
			m.buscarNombre(nom) ? cout << "" << endl : cout << "No encontrado" << endl; // operador condicional
			break;
		case 1:
			cout << "nombre: ";
			cin >> nom;
			cout << "carrera (sistemas, electrica, industrial, catastral): ";
			cin >> carr;
			cout << "actividad (danza, basquet, natacion, beisbol): ";
			cin >> act;
			cout << "edad: ";
			cin >> edad;
			m.insertar(nom, act, carr, edad) ? cout << "" << endl : cout << "false" << endl; // operador condicional ternario
			break;
		case 2:
			m.obtenerMultilista();
			cout << "pos a eliminar: ";
			cin >> pos;
			m.eliminar(pos) ? cout << "true" << endl : cout << "false" << endl; // operador condicional ternario
			break;
		case 3:
			m.multilistaLLena() ? cout << "true" << endl : cout << "false" << endl; // operador condicional ternario
			break;
		case 4:
			m.multilistaVacia() ? cout << "true" << endl : cout << "false" << endl; // operador condicional ternario
			break;
		case 5:
			m.obtenerNombres();
			break;
		case 6:
			cout << "carrera que desea obtener: ";
			cin >> carr;
			m.obtenerCarreras(carr);
			break;
		case 7:
			cout << "actividad que desea obtener: ";
			cin >> act;
			m.obtenerActividades(act);
			break;
		case 8:
			m.obtenerEdades();
			break;
		case 9:
			cout << "Gracias" << endl;
			break;
		}
	}
}