#include "Aerolinea.cpp"
#include "Structuras.cpp"
#include <iostream>
using namespace std;

struct VueloPlaneado{
	
	Aerolinea aerolinea;
	int codigo;
	string origen;
	string destino;
	string dia; /* Lunes, Martes, ...  */
	hora hora_salida;
	int duracion;
	double precio_adulto;
	double precio_ninio;
	int sigDestino;
	int sigPlanAerolinea;
};
