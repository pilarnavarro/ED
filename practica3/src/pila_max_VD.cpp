/**
  * @file pila_max_VD.cpp
  * @brief Implementación del TDA Pila Max con vector dinámico
  *
  */
#include <cstdlib>
#include <iostream>
#include <cassert> 
#include "pila_max_VD.h"
using namespace std;

	ostream & operator<<(ostream & os,const elemento & a){
 		os<<a.ele<< " Maximo: "<<a.maximo<<endl;
 		return os;
	} 

 
    Pila_max_VD& Pila_max_VD::operator= (const Pila_max_VD& otra){ 
		datos = otra.datos;
		return *this;
    }
  
    bool Pila_max_VD::vacia() const{
      return (datos.dimension()==0);
    }
 
    elemento & Pila_max_VD::tope (){
      assert(datos.dimension()>0);       //Si la pila está vacía, abortar
      return datos[datos.dimension()-1]; //Devuelve el elemento del tope de la pila
    }
 
    const elemento & Pila_max_VD::tope () const{
      assert(datos.dimension()>0);       //Si la pila está vacía, abortar
      return datos[datos.dimension()-1]; //Devuelve el elemento del tope de la pila
    }
  
    void Pila_max_VD::poner(const int & elem){
      
      if (vacia()){
	  elemento a={elem,elem};
	  datos.asignar_componente(datos.dimension(),a);
      }
      else{
	if (datos.componente(datos.dimension()-1).maximo>elem){
	  elemento a={elem,datos.componente(datos.dimension()-1).maximo};
	  datos.asignar_componente(datos.dimension(),a);
	}
	else {
	  elemento a={elem,elem};
	  datos.asignar_componente(datos.dimension(),a);
	}  
      }
    }   
   
    void Pila_max_VD::quitar(){
        assert(datos.dimension()>0);       //Si la pila esta vacia, abortar
			datos.borrar();
	
    }	
 
    int Pila_max_VD::num_elementos() const{
      return datos.dimension();
    }
	 
	 int Pila_max_VD::max(){
		assert(datos.dimension()>0);      
      return tope().maximo; 
	 }



