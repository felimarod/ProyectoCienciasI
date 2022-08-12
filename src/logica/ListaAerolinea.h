#ifndef LISTAAEROLINEA_H
#define LISTAAEROLINEA_H

#include "../modelos/Aerolinea.cpp"

struct nodoA{
	Aerolinea info;
	nodoA *sig;
};

class listaAerolinea{
	private:
		nodoA *cab;
		int tam;
	public:
		listaAerolinea(){
			cab = NULL;
			tam = 0;
		}
		
		bool listaVacia(){
			return tam==0; //Retorna false o true 
		}
		
		int tamLista(){
			return tam;
		}
		
		void insertarFinal(Aerolinea inf){
			nodoA *p = new nodoA,*aux;
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
		
		Aerolinea* buscarAerolinea(int id){
			if(!listaVacia()){
				nodoA *aux=cab;
				while(aux!=NULL){
					if(aux->info.codigo == id){
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

