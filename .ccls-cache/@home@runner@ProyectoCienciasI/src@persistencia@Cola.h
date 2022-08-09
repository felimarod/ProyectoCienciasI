#include <iostream>

#ifndef COLA_H
#define COLA_H

template <class T> class Cola {
public:
  Cola() {
    cab = fin = NULL;
    tam = 0;
  }
  void encolar(T inf);
  T desencolar();
  inline bool isEmpty() { return tam == 0; }
  inline int getTam() { return tam; }
  ~Cola();

  inline bool colaVacia() { return cab == NULL; }

private:
  struct nodo {
    T info;
    struct nodo *sig;
  };
  nodo *cab, *fin;
  int tam;
};

template <class T> void Cola<T>::encolar(T inf) {
  nodo *nuevo = new nodo;
  nuevo->info = inf;
  nuevo->sig = NULL;
  if (cab == NULL)
    cab = nuevo;
  else
    fin->sig = nuevo;
  fin = nuevo;
  tam++;
}

template <class T> T Cola<T>::desencolar() {
  T x;
  nodo *aux = cab;
  cab = aux->sig;
  x = aux->info;
  tam--;
  delete aux;
  return x;
}

template <class T> Cola<T>::~Cola() {
  nodo *aux;
  while (cab != NULL) {
    aux = cab;
    cab = aux->sig;
    delete aux;
  }
  delete cab;
}

#endif
