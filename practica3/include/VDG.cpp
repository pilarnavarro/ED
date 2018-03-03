/**
  * @file VDG.cpp
  * @brief Implementación del TDA Vector Dinámico
  *
  */
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;

/*

  ** Función de abstracción:
     ----------------------

     fA : tipo_rep  -------> Tipo Abstracto
        {datos, num_comp}--> { datos[0], datos[1], ..., datos[num_comp - 1]}


  ** Invariante de Representación:
     ----------------------------
     Cualquier objeto del tipo_rep, {datos, num_comp}, debe cumplir:
     - num_comp >= 0;
     - datos: apunta a una zona con capacidad para albergar a
       'num_comp' objetos de la clase T.
 */

template <class T>
VectorDinamico<T>::VectorDinamico()
{
 	datos=NULL;
	num_comp=0;

}


template <class T>
VectorDinamico<T>::VectorDinamico(int num_elem)
{
  assert(num_elem>=0);
  if (num_elem>0)
    datos= new T[num_elem];
  num_comp= num_elem;

}


template <class T>
VectorDinamico<T>::~VectorDinamico()
{

	if(num_comp>0){
  		delete [] datos;
  		datos = 0;
  		num_comp = 0;
	}
}

template <class T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico<T> & original)
{
  num_comp=original.num_comp;
  if(num_comp>0){
    datos=new T [num_comp];
    for(int i=0;i<num_comp;i++){
      datos[i]=original.datos[i];
    }
  }
}


template <class T>
void VectorDinamico<T>::redimensionar(int n)
{
  assert (n>=0);
  if (n!=num_comp) {
    if (n!=0) {
      T * nuevos_datos;
      nuevos_datos= new T[n];
      if (num_comp>0) {
	int minimo;
	minimo= num_comp<n?num_comp:n;
	for (int i= 0; i<minimo;++i)
	  nuevos_datos[i]= datos[i];
	delete[] datos;
      }
      num_comp= n;
      datos= nuevos_datos;
    }
    else {
      if (num_comp>0)
	delete[] datos;
      datos= 0;
      num_comp= 0;
    }
  }

}


template <class T>
int VectorDinamico<T>::dimension() const
{
  return num_comp;
}


template <class T>
T VectorDinamico<T>::componente(int i) const
{
  assert (0 <= i && i < num_comp);

  return datos[i];
}



template <class T>
void VectorDinamico<T>::asignar_componente(int i, const T & valor)
{
	assert (0 <= i);

	if(i>=num_comp)
		redimensionar(i+1);
	 	 
	datos[i] = valor;
	num_comp=i+1;
}


template <class T>
T & VectorDinamico<T>::operator[](int i)
{
  assert (0 <= i && i < num_comp);

  return datos[i];
}

template <class T>
const T &
VectorDinamico<T>::operator[](int i) const
{
  assert (0 <= i && i < num_comp);

  return datos[i];
}

template <class T>
VectorDinamico<T> &
VectorDinamico<T>::operator=(const VectorDinamico<T> & original){
  if(this!=&original){
    if(num_comp>0)
      delete [] datos;
    num_comp=original.num_comp;
    datos=new T[num_comp];
    for(int i=0;i<num_comp;i++)
      datos[i]=original.datos[i];
  }
	return *this;
}

template <class T>
void VectorDinamico<T>::borrar(){
	num_comp--;
}

