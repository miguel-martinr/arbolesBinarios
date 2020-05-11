/**********************************************************************
* Project           : Árboles Binarios de Búsqueda
*
* Class             : nodo_bb
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

#include <iostream>

using namespace std;

template <class Clave>
class nodo_bb {
 public:
   nodo_bb(void): izq_(NULL), dch_(NULL) {}
   nodo_bb(Clave dato, nodo_bb<Clave>* izq = NULL, nodo_bb<Clave>* dch = NULL):
           dato_(dato), izq_(izq), dch_(dch) {}

   Clave get_dato(void) { return dato_; }
   nodo_bb<Clave>*& get_izq(void) { return izq_; }
   nodo_bb<Clave>*& get_dch(void) { return dch_; }

   void set_dato(Clave dato) { dato_ = dato; }

   ostream& print(ostream& os = cout);

 private:
   nodo_bb<Clave>* izq_;
   nodo_bb<Clave>* dch_;
   Clave dato_;

};

template <class Clave>
ostream& nodo_bb<Clave>::print(ostream& os) {
  if (this == NULL)
   os << "[.]";
   else
   os << '[' << dato_ << ']';
  return os;
}
