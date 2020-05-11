/**********************************************************************
* Project           : Árboles Binarios de Búsqueda
*
* Class             : arbol_bb
*
* Author            : Miguel Alejandro Martín Reyes (miguel-martinr)
* e-mail            : alu0101209777@ull.edu.es
* github            : https://github.com/miguel-martinr
*
* Date created      : 20200511
*
* References  :
*
*
*
* Revision History  :
*
* Date        Author              Ref    Revision
* 20200511    miguel-martinr      1      ...
*
**********************************************************************/
#pragma once

#include "nodo_bb.hpp"

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

template <class Clave>
using node_lvl = pair<nodo_bb<Clave>*,int>;

template <class Clave>
class arbol_bb {

 public:
   arbol_bb(void): root_(NULL) {}
   arbol_bb(nodo_bb<Clave>* root): root_(root) {}

   nodo_bb<Clave>* buscar(Clave dato);
   nodo_bb<Clave>* buscar_rama(nodo_bb<Clave>* nodo, Clave dato);

   void insertar(Clave dato);
   void insertar_rama(nodo_bb<Clave>*& nodo, Clave dato);

   void eliminar(Clave dato);
   void eliminar_rama(nodo_bb<Clave>*& nodo, Clave dato);

   void sustituye(nodo_bb<Clave>*& eliminado, nodo_bb<Clave>*& sust);

   bool is_empty(void) { return (root_ == NULL); }

   ostream& print(ostream& os = cout);

 private:
   nodo_bb<Clave>* root_;
};

template <class Clave>
nodo_bb<Clave>* arbol_bb<Clave>::buscar(Clave dato) {
  return buscar_rama(root_, dato);
}

template <class Clave>
nodo_bb<Clave>* arbol_bb<Clave>::buscar_rama(nodo_bb<Clave>* nodo, Clave dato) {
  if (nodo == NULL)
    return NULL;
  if (dato == nodo->get_dato())
    return nodo;
  if (dato < nodo->get_dato())
    return buscar_rama(nodo->get_izq(), dato);
  return buscar_rama(nodo->get_dch(), dato);
}


template <class Clave>
void arbol_bb<Clave>::insertar(Clave dato) {
  insertar_rama(root_, dato);
}

template <class Clave>
void arbol_bb<Clave>::insertar_rama(nodo_bb<Clave>*& nodo, Clave dato) {
  if (nodo == NULL)
    nodo = new nodo_bb<Clave>(dato);
    else if (dato < nodo->get_dato())
    insertar_rama(nodo->get_izq(),dato);
    else
    insertar_rama(nodo->get_dch(),dato);
}


template <class Clave>
void arbol_bb<Clave>::eliminar (Clave dato) {
  eliminar_rama(root_,dato);
}

template <class Clave>
void arbol_bb<Clave>::eliminar_rama(nodo_bb<Clave>*& nodo, Clave dato) {
  if (nodo != NULL) {
    if (dato < nodo->get_dato())
      eliminar_rama(nodo->get_izq(), dato);
      else if (dato > nodo->get_dato())
      eliminar_rama(nodo->get_dch(), dato);
      else {
        nodo_bb<Clave>* eliminado = nodo;
        if (nodo->get_dch() == NULL)
          nodo = nodo->get_izq();
          else if (nodo->get_izq() == NULL)
          nodo = nodo->get_dch();
          else
          sustituye(eliminado, nodo->get_izq());

        delete eliminado;
      }
  }
}


template <class Clave>
void arbol_bb<Clave>::sustituye(nodo_bb<Clave>*& eliminado, nodo_bb<Clave>*& sust) {
  if (sust->get_dch() != NULL)
    sustituye(eliminado, sust->get_dch());
  else {
    eliminado->set_dato(sust->get_dato());
    eliminado = sust;
    sust = sust->get_izq();
  }
}

template <class Clave>
ostream& arbol_bb<Clave>::print(ostream& os) {
  queue<node_lvl<Clave>> myQueue; //En la cola se guarda el nodo junto a su nivel
  int lvl = 0, current_lvl = 0;
  node_lvl<Clave> duo_aux;
  duo_aux.first = root_;
  myQueue.push(duo_aux);

  os << "Nivel 0:";

  while (!myQueue.empty()) {
    duo_aux = myQueue.front();
    myQueue.pop();

    if (duo_aux.second > current_lvl) {
      current_lvl = duo_aux.second;
      os << "\nNivel " << current_lvl << ": ";
    }
    duo_aux.first->print(os);
    if (duo_aux.first != NULL) {
      nodo_bb<Clave>* nodo_aux = duo_aux.first;
      duo_aux.first = duo_aux.first->get_izq();
      duo_aux.second++;
      myQueue.push(duo_aux);
      duo_aux.first = nodo_aux->get_dch();
      myQueue.push(duo_aux);
    }
  }
  return os;
}
