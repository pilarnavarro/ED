/**
 * @file quienesquien.h
 * @brief Fichero cabecera del QuienEsQuien.
 * @author Pilar Navarro Ramírez 
 * @author Silvia Barroso Moreno	
 * Almacena el árbol de preguntas para jugar al Quién es quién?.
 */

#ifndef _QUIENESQUIEN_H_
#define _QUIENESQUIEN_H_

#define DEBUG_QUIENESQUIEN 0

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cassert>
#include <set>
#include <sstream>

#include "pregunta.h"
#include "bintree.h"

using namespace std;

/**
 * @brief T.D.A. QuienEsQuien
 *
 * Conjunto de personajes con sus atributos.
 */
class QuienEsQuien{
private:
	/**
	  * @brief Almacena el nombre de los personajes. Su índice en 
	  *        este vector corresponde con el índice de su 
	  *        descripción en el tablero.
	  */
	vector<string> personajes;

	/**
	  * @brief Almacena los atributos.  Su índice en este vector 
	  *        corresponde con el índice correspondiente de cada 
	  *        vector del tablero.
	  */
	vector<string> atributos;

	/**
	  * @brief Matriz que almacena para cada personaje su valor para 
	  *        cada atributo.
	  */
	vector<vector<bool>> tablero;

	/**
	  * @brief Arbol de preguntas para adivinar personajes.
	  */
	bintree<Pregunta> arbol;

	/**
	  * @brief Nodo del arbol de preguntas correspondiente a la jugada 
	  *        actual.
	  */
	bintree<Pregunta>::node jugada_actual;

		/**
		* @brief Cuenta el número de personajes que tienen los atributos pasados como argumento en forma de vector
		* @param atrib: vector booleano con los atributos
		* @return numero entero que indica el número de personajes con atrib  
		**/
	int contar_personajes(const vector<bool> &atrib);

	/** @brief Busca el personaje del tablero cuyos atributos coinciden con atrib
	 * @param atrib: vector booleano con los atributos
	 * @return nombre del personaje
	*/
	string buscar_personaje(const vector<bool> &atrib);

	/**
		* @brief Función auxiliar para implementar crear_arbol.
		*	 Crea un arbol binario de forma recursiva que​ ​representa​ ​la​ ​ sucesión​ ​ de​ ​ preguntas​
		* ​ necesaria​ ​ para  adivinar​ ​cada​ personaje​ ​ del​ ​ tablero.​​ 
		*  Cada elemento que se inserta en el vector de bool hace que: 
		*	se cree un subarbol derecho si se inserta el valor '0' y un subarbol izquierdo si se inserta '1'.
    * @param nodo node a partir del cual se crea el arbol 
		* @param i indice del vector atributos correspondiente a la posición  
		*	del atributo que se inserta en el árbol
		* @param atrib vector de booleanos con los atributos 
    */
		void crear_arbol_recursivo(bintree<Pregunta>::node nodo, int i, vector<bool> atrib);

		/**
		 @brief Método auxiliar para implementar eliminar_nodos_redundantes, que elimina todas las preguntas 
		 * 			redundantes del árbol que cuelga del nodo n
		 @param n nodo a partir del cual se eliminan los nodos redundantes 
		 @post el árbol que cuelga de n se modifica de forma que no tiene preguntas redundates 
		**/
	void eliminar_nodos_redundantes_recursivo(bintree<Pregunta>::node n);
	

	/**
    * @brief Obtiene los​ ​ nombres​ ​ de​ ​ los​ ​ personajes​ ​ que​ ​ aún​ ​ no​ ​ han​ ​ sido​ ​ tumbados​ ​ en​ ​ el​ ​ tablero y los almacena en un conjunto
    * @param pers_levantados: set de string que almacena los personajes que quedan levantados
    * @param nodo: nodo que indica el estado del tablero.  
    */
		void personajes_restantes(set<string> & pers_levantados,bintree<Pregunta>::node nodo);
	
	/**
	 @brief Suma la profundidad de todas las hojas del árbol. Función auxiliar para calcular la profundidad 
					media de las hojas.
	 @param n nodo cuya profundidad se va a calcular y sumar a suma_profundidad_total
	 @param suma_total variable float que almacenará la suma de la profundidad de todos los nodos 
					 cuando hayan terminado las llamadas recursivas a la función
	 @param profundidad_nodo profundidad del nodo n
	  
	 @pre En la primera llamada suma_profundidad_total y profundidad_nodo deben ser 0.
	 @post suma_profundidad_total almacenará la suma de las profundidades de todas las hojas.
	**/
void suma_profundidad(bintree<Pregunta>::node n, float &suma_profundidad_total, int profundidad_nodo);

public:
	/**
	  * @brief Constructor básico de la clase
	  */
	QuienEsQuien(){}
	/**
	  * @brief Constructor de copia.
	  * @param quienEsQuien QuienEsQuien a copiar.
	  */
	QuienEsQuien(const QuienEsQuien &quienEsQuien);
	/**
	* @brief Destructor del receptor.
	*/
	~QuienEsQuien();
	/**
	  * @brief Vacia todos los datos del QuienEsQuien receptor.
	  */
	void limpiar();
	/**
	* @brief Sobrecarga del operador de asignación.
	* @param quienEsQuien objeto a copiar.
	* @return Referencia al objeto copiado.
	*/
	QuienEsQuien& operator = (const QuienEsQuien &quienEsQuien);
	
	/**
	* @brief Operador de extracción de flujo.
	* @param is Stream de entrada
	* @param quienEsQuien Quien es quien a leer.
	* @return Referencia al stream de entrada.
	* 
	* Lee de @e is un quien es quien y lo almacena en @e 
	* quienEsQuien. El formato aceptado para la lectura es un TSV 
	* (tab-separated values) en el que las columnas tienen cabecera y 
	* son las preguntas. La última columna corresponde al nombre del 
	* personaje. Tras la cabecera se especifica en cada línea un 
	* personaje, teniendo el valor 1 o 0 si tiene/no tiene el 
	* atributo de la columna. En la última columna se da el 
	* nombre del personaje.
	*/
	friend istream& operator >> (istream& is, QuienEsQuien &quienEsQuien);
	
	/**
	* @brief Operador de inserción de flujo.
	* @param os Stream de salida
	* @param quienEsQuien Quien es quien a escribir.
	* @return Referencia al stream de salida.
	* 
	* Escribe en @e os un quien es quien.
	* El formato usado para la escritura es un TSV 
	* (tab-separated values) en el que las columnas tienen cabecera y 
	* son las preguntas. La última columna corresponde al nombre del 
	* personaje. Tras la cabecera se especifica en cada línea un 
	* personaje, teniendo el valor 1 o 0 si tiene/no tiene el 
	* atributo de la columna. En la última columna se da el 
	* nombre del personaje.
	*/
	friend ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien);

	/**
	  * @brief Escribe en la salida estandard las estructuras atributos, personajes y tablero.
	  */
	void mostrar_estructuras_leidas();

	/**
	  * @brief Este método construye el árbol de preguntas para todos los personajes del tablero.
	  */
	bintree<Pregunta> crear_arbol();
	
	/**
	  * @brief Sustituye el árbol actual por el árbol pasado por parámetro.
	  * 
	  * @param arbol_nuevo Arbol de preguntas que sustituye al actual.
	  * 
	  */
	void usar_arbol(bintree<Pregunta> arbol_nuevo);

	/**
	  * @brief Escribe el arbol generado en la salida estandard.
	  */
	void escribir_arbol_completo() const;

	/**
	   @brief Método que modifica el árbol de preguntas para que no haya
	          preguntas redundantes.
	   @post El árbol de preguntas se modifica.
	*/
	void eliminar_nodos_redundantes();

	/**
	 * @brief Inicializa el juego.
	 * @post  Si la partida anterior no había terminado se 
	 *        pierde el progreso.
	 */
	void iniciar_juego();

	/**
	  * @brief Dado un estado del tablero devuelve los nombres de 
	  *        los personajes que aún no han sido tumbados en el 
	  *        tablero.
	  *
	  * @param jugada_actual Nodo del estado del tablero.
	  * 
	  * @return Conjunto de personajes que no han sido tumbados en el tablero.
	  * 
	  * @pre El arbol del QuienEsQuien receptor debe haber sido construido previamente.
	  * @pre El nodo indicado debe ser un nodo del arbol del QuienEsQuien receptor.
	  */
	set<string> informacion_jugada(bintree<Pregunta>::node jugada_actual);

/**
	  * @brief Escribe por pantalla los nombres de los personajes que aún no han sido tumbados en el 
		*        tablero en la jugada actual. Esta función es llamada dentro de iniciar_juego 
		*				 de forma que muestra los personajes que quedan tras cada respuesta del usuario.
		*	@pre Lo mismo que en información_jugada
**/
	
	void mostrar_informacion_jugada();
	
	/**
		* @brief Este método permite calcular la media de la profundidad de las hojas del árbol. Este valor representa el número (promedio) 
		*				de preguntas necesarias para adivinar cada personaje. A menor profundidad promedio, mejor solución.
	  *
	  * @return Profundidad media del arbol de preguntas.
	  *
	  * @pre El arbol de preguntas debe haber sido construido previamente.
	  */
	float profundidad_promedio_hojas(); 

	/**
	  * @brief Rellena los datos del QuienEsQuien con un tablero calculado aleatoriamente.
	  * 
	  * @param numero_de_personajes Número de personajes que tiene el tablero a crear.
	  */
	void tablero_aleatorio(int numero_de_personajes);
};

#endif

