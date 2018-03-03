/**
  * @file Fecha_Historica.h
  * @brief Fichero cabecera del TDA Fecha_Historica
  *
  */

#ifndef _FECHA_HISTORICA_
#define _FECHA_HISTORICA_

#include <iostream>
#include <string>
#include <cassert>
#include<set>


using namespace std;

/**
  *  @brief T.D.A. Fecha_Historica
  *
  * Una instancia @e c del tipo de datos abstracto @c Fecha_Historica es un 
  * par de valores: el primer valor es un entero(un año) y el segundo valor es un TDA set que contiene
    una colección de string correspondientes a los distintos acontecimientos históricos 
    que no se repiten y que permanecen ordenados. 
  * 
  * Año: 
  * *)Evento1
  *   ...
  *   ...
  * *)EventoN
  *
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author Silvia Barroso Moreno
  * @author Pilar Navarro Ramírez
  * @date 27/12/2017
  */

class Fecha_Historica {

 private:
/**
  * @page repConjunto Rep del TDA Fecha_Historica
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.anio > 0 && rep.anio < 9999
  *
  * Fijamos como limite que los años no sean ni negativos ni superiores a 9999.
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Fecha_Historica representa al valor
  *
  * Año: 
  * *)Evento1
  *   ...
  *   ...
  * *)EventoN 
  *
  *
  */
  pair<int,set<string> > events;

 public:

  typedef typename set<string>::iterator iterator;
  typedef typename set<string>::const_iterator const_iterator;

/**
 * @brief Develve un iterador señalando al primer elemento del conjunto
 * @return Un iterador apuntando al primer elemento
*/
  iterator begin ();

/**
 * @brief Develve un iterador constante señalando al primer elemento del conjunto
 * @return Un iterador constante apuntando al primer elemento
*/
  const_iterator begin () const;

/**
*@brief Devuelve un iterador sealando al último elemento del conjunto.
*@return Un iterador apuntando al último elemento.
*/
  iterator end ();

/**
*@brief Devuelve un iterador constante al último elemento del conjunto.
*@return Un iterador constante al úlltimo elemento.
*/
  const_iterator end () const;

/**
  * @brief Constructor por defecto de la clase. Lo creamos sencillamente para evitar 
  * errores o asignaciones de basura a objetos de nuestra clase. Crea una Fecha Historica 
  * por defecto con año 0 y 0 eventos.
  */

  Fecha_Historica(){}


/**
  * @brief Constructor de la clase
  * @param a año del evento a construir
  * @param s vector de string con el evento o eventos de ese año
  * @param n número de eventos que contienen el vector s que se pasa como parámetro
  * @return Crea el evento con año a y n eventos asociados
  * @pre a debe ser mayor o igual que 0 y menos o igual que 9999, n debe ser un número positivo
  * igual al número de eventos contenidos en el vector de string s
  */

  Fecha_Historica(int a, string *s, int n);

/**
  * @brief Constructor de copias de la clase
  * @param e objeto de la clase que se quiere copiar
  * @return Crea el evento con los datos de e
  */

  Fecha_Historica(const Fecha_Historica& e);

/**
  * @brief Destructor de la clase.Destruye el contenido de fecha historica y libera el espacio
  */

  ~Fecha_Historica(){}


/**
  * @brief Método de acceso al año de la Fecha_Historica
  * @return int con el valor del campo anio
  */

  int get_year () const{
    return events.first;
  }

 /**
  * @brief Método de acceso al número de eventos de la Fecha_Historica
  * @return int con el valor del anio
  */

  void set_year(int a);

/*
 * @brief Método que devuelve el numero de eventos
 * @return int con el numero de eventos
*/
  int get_size() const{
    return events.second.size();
  }

/**
  * @brief Añade un evento
  * @param event string con evento a añadir
  */

  void add_event(string event);


/**
  * @brief Búsqueda de eventos en una Fecha_Historica dada una palabra clave s
  * @param s string con la palabra a buscar
  * @param matches nueva Fecha_Historica donde se introducen únicamente los eventos de this que contienen el string s
  * @return Devuelve true o false indicando si hay o no algún match de la cadena clave s en los eventos de this
  */
	bool search_event(string s, Fecha_Historica &matches);

/**
 * @brief Unión de dos TDA Fecha_Historica
 * @param f objeto de Fecha_histórica que queremos unir con nuestro objeto
 * @param result objeto de Fecha_histórica donde vamos a almacenar la unión
 * @pre:El año de f debe ser el mismo que el del receptor
 */ 
	void Union(const Fecha_Historica & f, Fecha_Historica & result);
 
  /**
  * @brief Operador de asignación
  * @param orig objeto de Fecha_histórica que queremos asignarle a nuestro objeto
  * @pre orig debe ser un objeto de fecha histórica existente y válido
  * @return Devuelve una referencia al objeto para poder realizar asignaciones múltiples
  */
  Fecha_Historica & operator=(const Fecha_Historica & orig);

  /** @brief Acceso a los elementos del TDA Fecha_Histórica
    * @param i es la posición del iterador que apunta al string 0<=i<neventos  
    * @return Devuelve la referencia al elemento. Por tanto puede usarse para almacenar un valor en esa posición.
  */
  string operator[](int i);

/** @brief Acceso a los elementos de un TDA constante Fecha_Histórica
  * @param i es la posición del iterador que apunta al string 0<=i<neventos
  * @return Devuelve una referencia constante al string. Se supone que el TDA no se puede modificar y por tanto es acceso solo de lectura.
*/
  const string& operator[](int i) const;

/**
  * @brief Salida de un Fecha_Historica a ostream
  * @param os stream de salida
  * @param e Fecha_Historica a escribir
  * @post Se muestra la Fecha_Historica en formato "año#evento1#evento2#...#eventoN" 
  */

  friend ostream& operator<< (ostream& os, const Fecha_Historica& e);

/**
  * @brief Entrada de un Fecha_Historica desde istream
  * @param is stream de entrada
  * @param e Fecha_Historica que recibe el valor
  * @retval El Fecha_Historica leído en e
  * @pre La entrada tiene el formato "año#evento1#evento2#...#eventoN
  */

  friend istream& operator>> (istream& is, Fecha_Historica& e);  

};

#endif
