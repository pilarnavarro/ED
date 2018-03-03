/**
  * @file pila_max_VD.h
  * @brief Fichero cabecera del TDA Pila max Vector Dinámico
  *
  * Gestiona una secuencia de elementos con facilidades
  * para la inserción y borrado de elementos en un extremo
  *
  */
#ifndef _pila_max_VD_H_
#define _pila_max_VD_H_
#include "VDG.h"
#include<cassert>

typedef struct{
    int ele;
    int maximo;

}elemento;

ostream & operator<<(ostream & os,const elemento & a);
/**
 *  @brief T.D.A. Pila_max_VD
 *
 *
 * Una instancia @e v del tipo de datos abstracto Pila_max_VD sobre el tipo @c entero es 
 * una lista de pares de elementos <entero,entero > con un funcionamiento @e LIFO (Last In, 
 * First Out). En una pila, las operaciones de inserción y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope. Una pila_max_VD de longitud
 * @e n la denotamos

 * - [<a1,max{a1...an}>,<a2,max{a2...an}>,<a3,max{a3...an}>,..,<an,an>>

 * donde @e ai es el elemento de la posición i-esima. Y @e max{ai,...aj} es el maximo del conjunto de * elementos que van desde @e ai a @e aj
 * En esta pila, tendremos acceso unicamente al elemento del @e Tope, es decir, 
 * a @e an. El borrado o consulta de un elemento será sobre  @e an, y la
 * inserción de un nuevo elemento se hara sobre este. Quedando el elemento
 * insertado como @e Tope de la pila.

 * Si @e n=0 diremos que la pila esta vacia.

 * El espacio requerido para el almacenamiento es O(n). Donde n es el número de
 * elementos de la Pila_max.
 *
 */

class Pila_max_VD{
  private:
    VectorDinamico<elemento> datos;
  public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    Pila_max_VD(){}
    /**
     * @brief Constructor de copias
     * @param otra La pila de la que se hara la copia.
     */
    Pila_max_VD(const Pila_max_VD & otra):datos(otra.datos){}
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Pila_max_VD(){}
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignación
     * @param otra La pila que se va a asignar.
     */
    Pila_max_VD& operator= (const Pila_max_VD& otra);
    /**
     * @brief Comprueba si la pila esta vacia
     */
    bool vacia() const;
    /**
     * @brief Devuelve el elemento del tope de la pila
     */
    elemento & tope ();
    /**
     * @brief Devuelve el elemento del tope de una pila constante
     */
    const elemento & tope () const;
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
    int num_elementos() const;
	/**
     * @brief Devuelve el valor máximo que hay en pila en ese momento
     */
int max ();	
};


#endif
