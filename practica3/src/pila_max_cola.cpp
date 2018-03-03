/**
  * @file pila_max_cola.cpp
  * @brief Implementación del TDA Pila Max con colas
  *
  */

#include <cassert>
#include "pila_max_cola.h"
#include <cstdlib>
#include <iostream>
using namespace std;

	ostream & operator<<(ostream & os,const elemento & elem){
	 os<<elem.valor<< " Máximo: "<<elem.maximo<<endl;
	 return os;
	} 

	Pila_max_cola& Pila_max_cola::operator= (const Pila_max_cola& orig){ 
		datos = orig.datos;
		return *this;   
	}


	elemento & Pila_max_cola::tope (){
	      assert(datos.num_elementos()>0);      
	      return datos.frente(); 
	}

	const elemento & Pila_max_cola::tope () const{
	      assert(datos.num_elementos()>0);       
	      return datos.frente(); 
	}

	int Pila_max_cola::max(){
	      assert(datos.num_elementos()>0);      
	      return tope().maximo; 
	}

	void Pila_max_cola::poner(const int & elem){
	      
	      if (datos.num_elementos()==0){
		  elemento a={elem,elem};
		  datos.ponerfrente(a);
	      }
	      else{
		if (datos.frente().maximo>elem){
		  elemento a={elem,datos.frente().maximo};
		  datos.ponerfrente(a);
		}
		else {
		  elemento a={elem,elem};
		  datos.ponerfrente(a);
		}  
	      }
	}   

	void Pila_max_cola::quitar(){
		assert(datos.num_elementos()>0);      
				datos.quitar();
	}	



