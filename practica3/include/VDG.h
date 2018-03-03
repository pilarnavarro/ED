/**
  * @file VDG.h
  * @brief Fichero cabecera del TDA Vector Dinámico
  *
  * Se crea un vector con capacidad de crecer y decrecer
  */
#ifndef __VDG_H__
#define __VDG_H__

/**
   VectorDinamico::VectorDinamico, ~VectorDinamico, redimensionar,
   dimension, componente, asignar_componente, operator[]

   Este TDA representa vectores de objetos de la clase T cuyo tama�o
   puede cambiar en tiempo de ejecución.
   Son mutables.
   Residen en memoria dinámica.
  */ 

template <class T>
class VectorDinamico {
	public:

	/*
	 *  Operaciones
	 */

   // ---------------  Constructores ----------------
	/**
		Constructor por defecto
		@doc Crear un vector dinámico con 0 componentes.
	*/
	VectorDinamico();
	/**
     Constructor: crea un vector dinámico.
     @param num_elem: Número de componentes del nuevo vector.
            num_elem >= 0.
     @doc Crear un vector dinámico con num_elem componentes.
    */
   VectorDinamico(int num_elem);
	/**
   * Constructor de copia
   */
  VectorDinamico(const VectorDinamico & original);

	// ------------------ Destructor ------------------
   /**
     Destructor. 
	  @doc Destruye v liberando los recursos que empleaba.
    */
  ~VectorDinamico();
  // --------------- Otras funciones ---------------
  /**
	  @brief Redimensión del vector
     @param n: nuevo tamaño del vector. n >= 0.
     @post Los valores almacenados antes de la redimensión no se pierden
      (excepto los que se salen del nuevo rango de índices)
  */
   void redimensionar(int n);

  /**
     Devuelve el número de componentes del receptor.
     @return número de componentes del receptor.
    */
  int dimension() const;
  /**
     Acceso a una componente del vector.
     @param i: indice de la componente a obtener. 0 <= i < dimension().
     @return componente i-�sima del vector receptor.
    */
  T componente(int i) const;

  /**
     Modifica el valor de una componente del vector.
     @param i: indice de la componente a modificar. 0 <= i < dimension().
     @param valor: nuevo valor a asignar a la componente
     @doc Modifica la componente i-ésima de v, que pasa a ser 'valor'.
    */
  void asignar_componente(int i, const T & elem);

  /**
     Acceso a una componente del vector, con posibilidad de modificación. 
     @param i: indice de la componente a obtener. 0 <= i < dimension().
     @return referencia a la componente i-ésima del vector receptor.
    */
  T& operator[](int i);

	/**
     Acceso a una componente del vector, sin posibilidad de modificación.
     @param i: indice de la componente a obtener. 0 <= i < dimension(). 
     @return referencia a la componente i-ésima del vector receptor.
    */
  const T & operator[](int i) const;
  
  /**
    @brief operador de asignación
	 @param original: es un objeto de la clase VectorDinamico
   */
  VectorDinamico & operator=(const VectorDinamico & original);

	/**
	* @brief Borra el elemento de la ultima posición
	*/
  void borrar();
  
 private:
  T * datos;
  int num_comp;
};

#include "VDG.cpp"

#endif

