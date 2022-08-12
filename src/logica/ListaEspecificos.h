#ifndef LISTAESPECIFICOS_H
#define LISTAESPECIFICOS_H

#include "../modelos/VueloEspecifico.cpp"

struct nodoE{
	VueloEspecifico info;
	nodoE *sig;
	nodoE *sigPlan;
};

class listaEspecificos{
	private:
		nodoE *cab;
		int tam;
	public:
		listaEspecificos(){
			cab = NULL;
			tam = 0;
		}
		
		bool listaVacia(){
			return tam==0; //Retorna false o true 
		}
		
		int tamLista(){
			return tam;
		}
		
		nodoE *obtenerCab(){
			return cab;
		} 
		
		void insertar(VueloEspecifico inf){
			nodoE *p = new nodoE,*aux,*aux2;
			p->info=inf;
			p->sig=NULL;
			p->sigPlan=NULL;
			
			if(cab==NULL) { //No hay cabecera de la lista
				cab=p;
			} else{ //Ya hay una lista conformada
				aux=cab;
				while (aux->sig!=NULL){
					if(p->info.idVueloPlaneado>(aux->sig->info).idVueloPlaneado) break;
					aux=aux->sig;
				}
				p->sig=aux->sig;
				aux->sig=p;
			}
			
			aux2=cab;
			while(aux2->sigPlan != NULL){
				aux2 = aux2->sigPlan;
			}
			
			if(aux2->info.idVueloPlaneado<aux->info.idVueloPlaneado){
				aux=aux2;
				while (aux->sig!=NULL){
					if(p->info.idVueloPlaneado>(aux->sig->info).idVueloPlaneado){
						aux2->sigPlan = p;
						break;
					}
					aux=aux->sig;
				}
			}
			
			tam++;
		}
		
};
#endif

