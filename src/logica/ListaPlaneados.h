#ifndef LISTAPlANEADOS_H
#define LISTAPLANEADOS_H

#include "../modelos/VueloPlaneado.cpp"

struct nodoP{
	VueloPlaneadoC info;
	nodoP *sig;
};

class listaPlaneados{
	private:
		nodoP *cab;
		int tam;
	public:
		listaPlaneados(){
			cab = NULL;
			tam = 0;
		}
		
		bool listaVacia(){
			return tam==0; //Retorna false o true 
		}
		
		int tamLista(){
			return tam;
		}
		
		nodoP *obtenerCabecera(){
			return cab;
		}
		
		void insertarFinal(VueloPlaneadoC inf){
			nodoP *p = new nodoP,*aux;
			p->info=inf;
			p->sig=NULL;
			
			if(cab==NULL) { //No hay cabecera de la lista
				cab=p;
			} else{ //Ya hay una lista conformada
				aux=cab; 
				while (aux->sig!=NULL) //Se recorren los nodos de la lista hasta el nodo final
					aux=aux->sig;
				aux->sig=p; //Se enlaza el ultimo nodo de la lista con el nuevo nodo (nuevo ultimo nodo)
			}
			tam++;
		}
		
		VueloPlaneadoC* buscarVueloPlaneado(int id){
			if(!listaVacia()){
				nodoP *aux=cab;
				while(aux!=NULL){
					if(aux->info.id_vuelo == id){
						return &aux->info;
					}
					else{
						aux=aux->sig;
					}
				}
			}
			return NULL;
		}
};

#endif
