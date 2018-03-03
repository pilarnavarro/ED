/**
  * @file Cronologia.h
  * @brief Fichero cabecera del TDA Cronologia
  *
  */

#ifndef _CRONOLOGIA_
#define _CRONOLOGIA_

#include <iostream>
#include <string>
#include <map>
#include "Fecha_Historica.h"

using namespace std;

/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de dato abstracto @c Cronologia es un objeto 
    constituido por un TDA map en el que la clave es un entero que representa 
    un año y los valores son objetos de Fecha_Histórica. Lo representamos como:
  *
  * Año_1:
  * *)Fecha_Historica_1
  * Año_2:
  * *)Fecha_Historica_2 
  * .
  * .
  * .
  * Año_N :
  * *)Fecha_Historica_N
  *
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author Pilar Navarro Ramírez
  * @author Silvia Barroso Moreno
  * @date 07/12/2017
  */

class Cronologia {

 private:
/**
  * @page repConjunto Rep del TDA Cronologia
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante está ligado al de los Eventos_Historicos \e rep.anio < 0 && rep.anio > 9999
  * que ya hemos fijado anteriormente
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Cronologia representa al valor
  *
  * Año_1:
  * *)Fecha_Historica_1
  * Año_2:
  * *)Fecha_Historica_2 
  * .
  * .
  * .
  * Año_N :
  * *)Fecha_Historica_N
  *
  */

  
  map<int,Fecha_Historica> cron;

 public:

  
  typedef typename map<int,Fecha_Historica>::iterator iterator;
  typedef typename map<int,Fecha_Historica>::const_iterator const_iterator;

  /**
  @brief Devuelve un iterador al 1er elemento de Conologia.
  @return Un iterador apuntando al primer elemento.
  **/
  iterator begin (){  
    return cron.begin();
  }
  /**
  @brief Devuelve un iterador constante al 1er elemento de Conologia.
  @return Un iterador constante apuntando al primer elemento.
  **/
  
  const_iterator begin () const{
    return cron.begin();
  }
  /**
  @brief Devuelve un iterador al último elemento.
  @return Un iterador apuntando al último elemento.
 **/
  iterator end (){
    return cron.end();
  }

  /**
  @brief Devuelve un iterador constante al último elemento.
  @return Un iterador constante apuntando al último elemento.
 **/
  const_iterator end () const{
    return cron.end();
  }

/**
  * @brief Constructor por defecto de la clase. Lo creamos sencillamente para evitar 
  * errores o asignaciones de basura a objetos de nuestra clase. Crea una Cronologia vacía.
  */

  Cronologia(){}

/**
  * @brief Constructor de copias de la clase
  * @param c objeto de la clase que se quiere copiar
  * @return Crea una Cronologia con los datos de c
  */

  Cronologia(const Cronologia& c){
    cron=c.cron;
  }

/**
  * @brief Destructor de la clase. El receptor es destruido liberando todos los
    recursos que usaba.
    @post El receptor es MODIFICADO.
  */

  ~Cronologia(){
  }

   /**
  * @brief Operador de asignación
  * @param orig objeto de Cronologia que queremos asignarle a nuestro objeto
  * @pre orig debe ser un objeto de cronología existente y válido
  * @return Devuelve una referencia al objeto para poder realizar asignaciones múltiples
  */

  Cronologia & operator=(const Cronologia & orig);

  /**
  * @brief Método de acceso al número de Fechas_Historicas (y por tanto de años) de Cronologia
  * @return int con el número de elementos de Cronología
  */

  int getnumdates() const;
    

/**
  * @brief Añade una Fecha_Histórica en la Cronología
  * @param eh la nueva Fecha_Historica
  * @return no devuelve nada
  */

  void addEvent(Fecha_Historica& eh);

	/**
  * @brief Busca una Fecha_Histórica dado su fecha
  * @param f el año del evento a buscar
  * @pre la fecha debe ser válida
  * @return Devuelve un iterador al pair que contiene el evento y si no se encuentra devuelve end();
  */

  iterator search_year(int f);
/**
  * @brief buscador de eventos dado una palabra clave
  * @param s vector de string con la palabra a buscar
    @param result Cronología vacía donde se guardará el resultado
  * @return no devuelve nada
  */

  void search(Cronologia &result,string s);

  /**
  * @brief Eventos históricos acontecidos en un intervalo de tiempo especificado
  * @param t1 primer año del intervalo de tiempo
  * @param t2 segundo año del intervalo de tiempo
    @param c Cronología vacía donde se guardará la subcronología resultante
    @pre t1<t2
  * @post Se obtiene un subconjunto de la cronología que incluye los eventos históricos ocurridos en el intervalo 
     ([t1, t2])
  **/

  void filtrado_intervalo(Cronologia & c,int t1,int t2);
  
  /**
  @brief Cuenta el número total de eventos históricos que hay en la Cronología
  @return Número total de eventos históricos.
  **/
  int numevents();

  /**
  @brief Devuelve el máximo número de eventos por año
  @return Máximo número de eventos por año
  **/
  int maxevents();
 
  /**
  @brief Calcula la media del número de eventos por año
  @return Media del número de eventos por año
  **/

  int mediaevents();
  
  /**
  * @brief Unión de los elementos de dos cronologías
  * @param crono2 cronologia con la que vamos a unir los elementos de la cronologia receptora
  * @param result Cronología vacía donde se guardará la unión de las cronologías
  */

  void Union(const Cronologia &crono2, Cronologia &result);

  /**
  * @brief Acceso a un elemento (Fecha_Histórica) de Cronología
  * @param i es la posición de Cronología donde está el elemento
  * @pre 0<=i<getnumdates()
  * @return Devuelve la referencia a la Fecha_Histórica que ocupa la posición i. 
  */
  
  Fecha_Historica & operator[](int i);

 /**
  * @brief Acceso a un elemento (Fecha_Histórica) de Cronología. El map no se puede modificar, es acceso de solo lectura.
  * @param i es la posición del vector de Cronología donde está el elemento
  * @pre 0<=i<getnumdates()
  * @return Devuelve una referencia constante al elemento. 
  */

  const Fecha_Historica & operator[](int i) const;
  

/**
  * @brief Salida de una Cronologia a ostream
  * @param os stream de salida
  * @param c Cronologia a escribir
  * @post Se obtienen varios años seguidos de la cadena de Eventos_Historicos con el formato
  * de Fecha_Historica
  */


  friend ostream& operator<< (ostream& os, const Cronologia& c);

/**
  * @brief Entrada de una Cronologia desde istream
  * @param is stream de entrada
  * @param c Cronologia que recibe el valor
  * @retval La Cronologia leída en c
  * @pre La entrada tiene el formato de Fecha_Historica getnumdates() numero de veces
  */

  friend istream& operator>> (istream& is, Cronologia& c);


};  

#endif
