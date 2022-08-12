#ifndef MULTILISTA_H
#define MULTILISTA_H

#include "VueloPlaneado.cpp"
using namespace std;


//Creaci?n de la clase Multilista
class Multilista{
	private:
		//Atributos de la Multilista 
		int *cabeceras;
		VueloPlaneado *datos;
		int tam;
		
	public:
		//Metodo Constructor (inicializacion de los atributos de la Multilista)
		Multilista(){
			cabeceras=new int[21];
			datos=new VueloPlaneado[200];
			tam=0;
			
			for(int i=0; i<21; i++)//inicializacion cabecera
				cabeceras[i]=-1;
				
			for(int i=0; i<200; i++){//inicializacion arreglo de datos
				datos[i].codigo=-1;
				datos[i].origen=-1;
				datos[i].destino=-1;
				datos[i].dia="";
				datos[i].hora_salida="";
				datos[i].duracion=-1;
				datos[i].precio_adulto=-1;
				datos[i].precio_ninio=-1;
				datos[i].aerolinea=-1;
				datos[i].sigDestino=-1;
				datos[i].sigPlanAerolinea=-1;
				datos[i].sigOrigenDestino=-1;
			}
				
		}
		
		//Destructor
		~Multilista(){
			delete[] datos;
			delete[] cabeceras;
		}
		
		//Metodos (acciones) de la Multilista
		bool insertar(int codigo,  int aerolinea, int origen, int destino, string dia, string hora_salida, int duracion, int precio_adulto, int precio_ninio);
		bool eliminar(int pos);
		bool multilistaLLena();
		bool multilistaVacia();
		int* obtenerCabeceras();
	    VueloPlaneado* obtenerMultilista();
	    void obtenerDestinosAerolinea(int aerolinea);
	    void obtenerPlanDeVuelosAerolinea(int aerolinea);
		VueloPlaneado* obtenerVuelos(int origen,int destino,int op);
		VueloPlaneado* obtenerVuelosOrigen(int origen);
		
};

int* Multilista :: obtenerCabeceras(){
	if(multilistaVacia()) return NULL;
	return cabeceras;
}

bool Multilista :: multilistaVacia(){
	return tam==0;
}

bool Multilista :: multilistaLLena(){
	return tam==200;
}

bool Multilista :: insertar(int codigo,  int aerolinea, int origen, int destino, string dia, string hora_salida, int duracion, int precio_adulto, int precio_ninio){
	if(multilistaLLena()) return false;
	
	VueloPlaneado v;
	
	v.codigo=codigo;
	v.origen=origen;
	v.destino=destino;
	v.dia=dia;
	v.hora_salida=hora_salida;
	v.duracion=duracion;
	v.precio_adulto=precio_adulto;
	v.precio_ninio=precio_ninio;
	v.aerolinea=aerolinea;
	v.sigDestino=-1;
	v.sigPlanAerolinea=-1;
	v.sigOrigenDestino=-1;
	
	int pos,k;
	
	/*Proceso para identificar la posicion de guardado del vueloPlaneado*/
	int i=0;
	while(datos[i].codigo!=-1){
		i++;
	}
	
	/*Validacion Aerolinea*/
	pos=aerolinea;
	
	//orden para plan de vuelo semanal
	k=cabeceras[pos];
	if(k == -1){ 
		cabeceras[pos]=i;
	}
	else{
		while(true){
			if(datos[k].sigPlanAerolinea == -1) break;
			k=datos[k].sigPlanAerolinea;
		}
		v.sigPlanAerolinea=-1;
		datos[k].sigPlanAerolinea=i;
	}
	
	//orden para destinos de la aerolinea
	pos+=10;
	bool x=true; 
	k=cabeceras[pos];
	if(k==-1){ 
		cabeceras[pos]=i;
	}
	else{
		while(true){
			if(datos[k].destino == destino) {
				x = false;
				break;	
			}
			if(datos[k].sigDestino==-1) break;
			k=datos[k].sigDestino;
		}
		v.sigDestino=-1;
		if(x) datos[k].sigDestino=i;
	}
	
	
	//orden para Origenes-Destinos
	if(cabeceras[0]==-1){ //cabecera de Origen-Destino
		cabeceras[0]=i;
	}else{
		k=cabeceras[0]; //posicion de el menor id de origen-destino
		
		if(origen<datos[k].origen){ //caso en que el id origen sea menor
			v.sigOrigenDestino=cabeceras[0];
			cabeceras[0]=i;
		}
		else if(origen == datos[k].origen && destino<=datos[k].destino){//caso id origen igual pero destino menor o igual
			v.sigOrigenDestino=cabeceras[0];
			cabeceras[0]=i;
		}
		else{
			
			while(true){
				if(datos[k].sigOrigenDestino==-1) break;
				if(origen<=datos[datos[k].sigOrigenDestino].origen) break;
				k=datos[k].sigOrigenDestino;
			}
			while(true){
				if(datos[k].sigOrigenDestino==-1 || origen<datos[datos[k].sigOrigenDestino].origen) break;
				if(destino<=datos[datos[k].sigOrigenDestino].destino) break;
				k=datos[k].sigOrigenDestino;
			}
			v.sigOrigenDestino=datos[k].sigOrigenDestino;
			datos[k].sigOrigenDestino=i;
		}
	}
	
	datos[i]=v;
	tam++;
	return true;
}



bool Multilista :: eliminar(int pos){
	if(multilistaVacia()) return false;
  
	if(datos[pos].codigo!=-1){
	int k,p;
	p=datos[pos].aerolinea;
  	
  	//eliminar en plan de vuleos semanal de aerolinea
	k=cabeceras[p];
	if(k!=-1){
		if(cabeceras[p]==pos){ //posicion a eliminar en la cabecera
			cabeceras[p]=datos[pos].sigPlanAerolinea;
		}
		else{
			while(true){
				if(datos[k].sigPlanAerolinea==pos) break;
				k=datos[k].sigPlanAerolinea;
			}
			datos[k].sigPlanAerolinea=datos[pos].sigPlanAerolinea;
		}
	}
	bool x=false;
	p+=10;
	k=cabeceras[p];
	if(k!=-1){
		if(cabeceras[p]==pos){ //posicion a eliminar en la cabecera
			cabeceras[p]=datos[pos].sigDestino;
		}
		else{
			while(true){
				if(datos[k].sigDestino==pos) break;
				if(datos[k].sigDestino==-1){
					x = false;
					break;
				}
				k=datos[k].sigDestino;
			}
			if(x) datos[k].sigDestino=datos[pos].sigDestino;
		}
	}
	
	//eliminar de destinos por aerolinea
	int y = cabeceras[p-10]; 
	if(x){
		while(y == -1){
			if(datos[pos].destino == datos[y].destino){
				x = false;
				break;
			}
			y = datos[y].sigPlanAerolinea;
		}
		if(!x){
			while(true){
				if(datos[k].sigDestino == -1){
					datos[k].sigDestino = y;
					break;
				}
				k = datos[k].sigDestino;
			}
		}
	}
	
	k=cabeceras[0];
	if(k!=-1){
		if(cabeceras[0]==pos){ //posicion a eliminar en la cabecera
			cabeceras[0]=datos[pos].sigOrigenDestino;
		}
		else{
			while(true){
				if(datos[k].sigOrigenDestino==pos) break;
				k=datos[k].sigOrigenDestino;
			}
			datos[k].sigOrigenDestino=datos[pos].sigOrigenDestino;
		}
	}
	
	datos[pos].codigo=-1;
	datos[pos].origen=-1;
	datos[pos].destino=-1;
	datos[pos].dia="";
	datos[pos].hora_salida="";
	datos[pos].duracion=-1;
	datos[pos].precio_adulto=-1;
	datos[pos].precio_ninio=-1;
	datos[pos].aerolinea=-1;
	datos[pos].sigDestino=-1;
	datos[pos].sigOrigenDestino=-1;
	datos[pos].sigPlanAerolinea=-1;
  	
	tam--;
	return true;
  }
  return false;
	
}


VueloPlaneado* Multilista :: obtenerMultilista(){
	
	return datos;
	
}

void Multilista :: obtenerPlanDeVuelosAerolinea(int aerolinea){
	cout<<"\nCODIGO / ORIGEN / DESTINO / AEROLINEA / DIA / HORA SALIDA / DURACION / PRECIO ADULTO / PRECIO NINIO"<<endl;
	
	if(!multilistaVacia()){
    	//Debe mostrar la multilista recorriendola por sigPlanAerolinea
    	//posicion de la cabecera es el entero aerolinea que se recibe por parametro
    	//primero leer en los archivos los campos que hacen falta (origen,destino,aerolinea) y luego si mostrar
	}
}

void Multilista :: obtenerDestinosAerolinea(int aerolinea){
	cout<<"\nCODIGO / ORIGEN / DESTINO / AEROLINEA / DIA / HORA SALIDA / DURACION / PRECIO ADULTO / PRECIO NINIO"<<endl;
	aerolinea+=10;//se suman 10 para el manejo de las cabeceras
	if(!multilistaVacia()){
    	//Debe mostrar la multilista recorriendola por sigDestino
    	//posicion de la cabecera es el entero aerolinea como se define arriba
    	//primero leer en los archivos los campos que hacen falta (origen,destino,aerolinea) y luego si mostrar
	}
	
}

VueloPlaneado* Multilista :: obtenerVuelos(int origen, int destino, int op){
	VueloPlaneado *vuelos;
	vuelos=new VueloPlaneado[200];

	for(int i=0; i<200; i++){//inicializacion arreglo de vueelos ya filtrados
				vuelos[i].codigo=-1;
				vuelos[i].origen=-1;
				vuelos[i].destino=-1;
				vuelos[i].dia="";
				vuelos[i].hora_salida="";
				vuelos[i].duracion=-1;
				vuelos[i].precio_adulto=-1;
				vuelos[i].precio_ninio=-1;
				vuelos[i].aerolinea=-1;
				vuelos[i].sigDestino=-1;
				vuelos[i].sigPlanAerolinea=-1;
				vuelos[i].sigOrigenDestino=-1;
			}
	int i = cabeceras[0],j = 0;
	while(datos[i].origen!=origen && i != -1){
		i=datos[i].sigOrigenDestino;
	}
	while(datos[i].origen==origen && i != -1){
		if(datos[i].destino == destino){
			vuelos[j] = datos[i];
			j++;
		}
		i=datos[i].sigOrigenDestino;
	}
	
	int min,k;
	if(op==0){
		for(i=0;i<j-1;i++){
			min=i;
			for(k=i+1;k<j;k++)
				if(vuelos[k].precio_adulto<vuelos[min].precio_adulto)
					min=k;
			VueloPlaneado aux = vuelos[i];
			vuelos[i]=vuelos[min];
			vuelos[min]=aux;
		}
	}
	else if(op==1){
		for(i=0;i<j-1;i++){
			min=i;
			for(k=i+1;k<j;k++)
				if(vuelos[k].precio_ninio<vuelos[min].precio_ninio)
					min=k;
			VueloPlaneado aux = vuelos[i];
			vuelos[i]=vuelos[min];
			vuelos[min]=aux;
		}
	}
	else if(op==2){
		for(i=0;i<j-1;i++){
			min=i;
			for(k=i+1;k<j;k++)
				if(vuelos[k].duracion<vuelos[min].duracion)
					min=k;
			VueloPlaneado aux = vuelos[i];
			vuelos[i]=vuelos[min];
			vuelos[min]=aux;
		}
	}
	return vuelos;
}

VueloPlaneado* Multilista :: obtenerVuelosOrigen(int origen){
	VueloPlaneado *vuelos;
	vuelos=new VueloPlaneado[200];

	for(int i=0; i<200; i++){//inicializacion arreglo de vuelos ya filtrados
				vuelos[i].codigo=-1;
				vuelos[i].origen=-1;
				vuelos[i].destino=-1;
				vuelos[i].dia="";
				vuelos[i].hora_salida="";
				vuelos[i].duracion=-1;
				vuelos[i].precio_adulto=-1;
				vuelos[i].precio_ninio=-1;
				vuelos[i].aerolinea=-1;
				vuelos[i].sigDestino=-1;
				vuelos[i].sigPlanAerolinea=-1;
				vuelos[i].sigOrigenDestino=-1;
			}
	int i = cabeceras[0],j = 0;
	while(datos[i].origen!=origen && i != -1){
		i=datos[i].sigOrigenDestino;
	}
	while(datos[i].origen==origen && i != -1){
		vuelos[j] = datos[i];
		j++;
		i=datos[i].sigOrigenDestino;
	}
	
	return vuelos;
}

#endif
