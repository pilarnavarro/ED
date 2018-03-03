/**
  * @file pila_max_cola.h
  * @brief Fichero cabecera del TDA Pila max
  *
  * Gestiona una secuencia de elementos con facilidades
  * para la inserción y borrado de elementos en un extremo
  *
  */

#ifndef __pila_max_colas_H__
#define __pila_max_colas_H__
#include "cola.h"
#include <cassert>
#include<iostream>
using namespace std;

typedef struct{
  int valor; 
  int maximo; 

	/**
	* @brief Constructor por defecto
	*/
		    
	//elemento(): valor(0), maximo(0){}
		     
	/**
	* @brief Constructor con parámetros
	* @param v Valor del elemento.
	* @param m Valor máximo de todos los elementos de la pila hasta este.
	*/
	//elemento(int v, int m): valor(v), maximo(m){}


}elemento;  

ostream & operator<<(ostream & os,const elemento & elem);

/**
 *  @brief T.D.A. Pila_max_cola
 *
 *
 * Una instancia @e v del tipo de datos abstracto Pila_max_cola sobre el tipo @c entero es 
 * una lista de pares de elementos <entero,entero > con un funcionamiento @e LIFO (Last In, 
 * First Out). En una pila, las operaciones de inserción y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope. Una pila_max de longitud @e n la denotamos

 * - [<a1,max{a1...an}>,<a2,max{a2...an}>,<a3,max{a3...an}>,..,<an,an>>

 * donde @e ai es el elemento de la posición i-ésima. Y @e max{ai,...aj} es el máximo del conjunto de 
 * elementos que van desde @e ai a @e aj
 * En esta pila, tendremos acceso únicamente al elemento del @e Tope, es decir, 
 * a @e an. El borrado o consulta de un elemento será sobre  @e an, y la
 * inserción de un nuevo elemento se hará sobre este. Quedando el elemento
 * insertado como @e Tope de la pila.

 * Si @e n=0 diremos que la pila está vacía.

 * El espacio requerido para el almacenamiento es O(n). Donde n es el número de
 * elementos de la Pila_max.
 *
 */

class Pila_max_cola{
  private:
    Cola<elemento> datos;
  public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    Pila_max_cola(){}
    /**
     * @brief Constructor de copias
     * @param orig La pila de la que se hará la copia.
     */
    Pila_max_cola(const Pila_max_cola & orig):datos(orig.datos){}
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Pila_max_cola(){}
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignación
     * @param orig La pila que se va a asignar.
     * @return Devulve una referencia a la pila en la que estamos
     */
    Pila_max_cola& operator= (const Pila_max_cola& orig);

    /**
     * @brief Comprueba si la pila está vacía
     * @return Devuelve true si está vacía o false en caso contrario
     */
    bool vacia() const{
      return (datos.num_elementos()==0);
    }
 
   /**
     * @brief Devuelve el elemento del tope de la pila
     */
    elemento & tope ();
   
 /**
     * @brief Devuelve el elemento del tope de una pila constante
     */
   
 const elemento & tope () const;

  /**
     * @brief Devuelve el valor máximo que hay en pila en ese momento
     */

  int max ();

    /**
     * @brief Añade un elemento "encima" del tope de la pila
     * @param elem Elemento que se va a añadir.
     */

  
  void poner(const int & elem);


    /**
     * @brief Quita el elemento del tope de la pila
     */
  

  void quitar();

    /**
     * @brief Devuelve el número de elementos de la pila
     */

    int num_elementos() const{
      return datos.num_elementos();
    }
};


#endif

