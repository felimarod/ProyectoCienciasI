#ifndef LISTALUGARES_H
#define LISTALUGARES_H

#include "../modelos/Lugar.cpp"

struct nodoL{
	Lugar info;
	nodoL *sig;
};

class listaLugar{
	private:
		nodoL *cab;
		int tam;
	public:
		listaLugar(){
			cab = NULL;
			tam = 0;
		}
		
		bool listaVacia(){
			return tam==0; //Retorna false o true 
		}
		
		int tamLista(){
			return tam;
		}
		
		void insertarFinal(Lugar inf){
			nodoL *p = new nodoL,*aux;
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
		
		Lugar* buscarLugar(int id){
			if(!listaVacia()){
				nodoL *aux=cab;
				while(aux!=NULL){
					if(aux->info.idLugar == id){
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

