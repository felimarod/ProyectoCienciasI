#include "Aerolinea.cpp"
#include <iostream>
using namespace std;

struct VueloPlaneado{
	int aerolinea;
	int codigo;
	int origen;
	int destino;
	string dia; /* Lunes, Martes, ...  */
	string hora_salida;
	int duracion;
	double precio_adulto;
	double precio_ninio;
	int sigDestino;
	int sigPlanAerolinea;
	int sigOrigenDestino;
};

