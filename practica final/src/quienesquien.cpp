//Pilar Navarro Ramírez, Silvia Barroso Moreno
#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien){
	limpiar();	
	personajes=quienEsQuien.personajes;
	atributos=quienEsQuien.atributos;
	tablero=quienEsQuien.tablero;
	arbol=quienEsQuien.arbol;
	jugada_actual=quienEsQuien.jugada_actual;
}

QuienEsQuien& QuienEsQuien::operator= (const QuienEsQuien &quienEsQuien){
		if(&quienEsQuien!=this){
		limpiar();
		personajes=quienEsQuien.personajes;
		atributos=quienEsQuien.atributos;
		tablero=quienEsQuien.tablero;
		arbol=quienEsQuien.arbol;
		jugada_actual=quienEsQuien.jugada_actual;
	}
	return *this;
}

QuienEsQuien::~QuienEsQuien(){
	this->limpiar();
}

void QuienEsQuien::limpiar(){
	if(!personajes.empty())
		personajes.clear();
	if(!atributos.empty())
		atributos.clear();
	if(!tablero.empty())
		tablero.clear();
	if(!arbol.empty())
		arbol.clear();
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

void QuienEsQuien::mostrar_estructuras_leidas(){
	cout << "personajes: "<< (this->personajes) << endl;
	cout << "atributos:  "<< (this->atributos)  << endl;
	cout << "tablero:    "<< endl;


	// Escribe la cabecera del tablero
	for(vector<string>::iterator it_atributos = this->atributos.begin();
		it_atributos != this->atributos.end();
		it_atributos++){
		cout << *it_atributos << "\t";
	}
	cout <<endl;

	int indice_personaje = 0;
	for(vector<vector<bool>>::iterator it_tablero_atributos = tablero.begin();
		it_tablero_atributos!= tablero.end();
		it_tablero_atributos++){

		string personaje = this->personajes[indice_personaje];
		int indice_atributo = 0;
		for(vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
			it_atributos_personaje != (*it_tablero_atributos).end();
			it_atributos_personaje++){

			cout << *it_atributos_personaje<<"\t";

			indice_atributo++;
		}

																								cout << personaje << endl;

		indice_personaje++;
	}

}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  * 
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);

	while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}

istream& operator >> (istream& is, QuienEsQuien &quienEsQuien) {
	quienEsQuien.limpiar();
	
  	if(is.good()){
  		string linea;
    	getline(is, linea, '\n');

    	linea = limpiar_string(linea,"\r");
    	
    	while(linea.find('\t') != string::npos ){
    		string atributo = linea.substr(0,linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
    		linea = linea.erase(0,linea.find('\t')+1);
    	}

		assert(linea ==  "Nombre personaje");
	}
	
    while( is.good() ) {
    	string linea;
    	getline(is, linea, '\n');
    	linea = limpiar_string(linea,"\r");

    	//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
    	if(linea != ""){;
	    	vector<bool> atributos_personaje;
	    	
	    	int indice_atributo=0;
	    	while(linea.find('\t') != string::npos){
	    		string valor = linea.substr(0,linea.find('\t'));
	    		
	    		assert(valor == "0" || valor == "1");
	    		
	    		bool valor_atributo = valor == "1";
	    		
	    		atributos_personaje.push_back(valor_atributo);
				
	    		linea = linea.erase(0,linea.find('\t')+1);
	    		indice_atributo++;
			}
			
			string nombre_personaje = linea;
	    	
	    	quienEsQuien.personajes.push_back(nombre_personaje);
	    	quienEsQuien.tablero.push_back(atributos_personaje);
	    }
  	}
  	
	return is;
}

ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien){

	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for(vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		it_atributos != quienEsQuien.atributos.end();
		it_atributos++){

		os  << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada l�nea y al final ponemos el nombre del personaje.
	for(int indice_personaje=0;indice_personaje<quienEsQuien.personajes.size();indice_personaje++){
		for(int indice_atributo=0;indice_atributo<quienEsQuien.atributos.size();indice_atributo++){

			os  << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os  << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}

/**
  * @brief Convierte un n�mero a un vector de bool que corresponde 
  *        con su representaci�n en binario con un numero de digitos
  *        fijo.
  *
  * @param n N�mero a convertir en binario.
  * @param digitos N�mero de d�gitos de la representaci�n binaria.
  *
  * @return Vector de booleanos con la representaci�n en binario de @e n 
  *      con el n�mero de elementos especificado por @e digitos. 

  */
vector<bool> convertir_a_vector_bool(int n, int digitos) {
  vector<bool> ret;
  while(n) {
    if (n&1){
      ret.push_back(true);
    } else{
      ret.push_back(false);
    }
    n>>=1;  
  }

  while(ret.size()<digitos){
  	ret.push_back(false);
  }

  reverse(ret.begin(),ret.end());
  return ret;
}

int QuienEsQuien::contar_personajes(const vector<bool> &atrib){
	int n=0,x=0;
	for(vector<vector<bool> >::iterator it=tablero.begin();it!=tablero.end();++it){
		for(int j=0; j<atrib.size(); j++){
			if( (*it)[j] == atrib[j] )
				x++;
		}
		if ( x==atrib.size() )
			n++;
		x=0;
	}

	return n;
}

string QuienEsQuien::buscar_personaje(const vector<bool> &atrib){
	int indice=0;
	int x=0;
	bool encontrado=false;
	for(int i=0;i<tablero.size() && !encontrado;i++){
	  x=0;
	  for(int j=0;j<atrib.size();j++){
		if(tablero[i][j]==atrib[j]) 
		  x++;
	  }
	  if(x==atrib.size()){
		encontrado=true;
		indice=i;  
	  }
	}
	return personajes[indice];
}
  
void QuienEsQuien::crear_arbol_recursivo(bintree<Pregunta>::node nodo, int i, vector<bool> atrib){
	if(!nodo.null() && i <= atributos.size()){
  
	  atrib.push_back(1);
	  int num_personajes=contar_personajes(atrib);
	  
	  if(num_personajes){
		if(num_personajes == 1){
		  if( (*nodo).obtener_num_personajes() > 1 )
			arbol.insert_left(nodo, Pregunta(buscar_personaje(atrib), num_personajes));
		}
		else
		  arbol.insert_left(nodo, Pregunta(atributos[i], num_personajes));
	  }
  
	  atrib.pop_back();
	  atrib.push_back(0);
	  num_personajes=contar_personajes(atrib);
	  
	  if(num_personajes){
		if(num_personajes == 1 ){
		  if((*nodo).obtener_num_personajes() > 1 )
			arbol.insert_right(nodo, Pregunta(buscar_personaje(atrib), num_personajes));
		}
		else
		  arbol.insert_right(nodo, Pregunta(atributos[i], num_personajes));
	  }
	  
	  atrib.pop_back();
  
	  atrib.push_back(1);
	  crear_arbol_recursivo(nodo.left(), 1+i, atrib);
	  atrib.pop_back(); 
	  atrib.push_back(0);
	  crear_arbol_recursivo(nodo.right(), 1+i, atrib);
	}
}


bintree<Pregunta> QuienEsQuien::crear_arbol()
{
	vector<bool> aux;
	if(!arbol.empty() ){
		arbol.clear();
	}
	if(personajes.size()>1){
	arbol=bintree<Pregunta>(Pregunta(atributos[0], personajes.size()));
	crear_arbol_recursivo(arbol.root(), 1, aux);
	}else arbol=bintree<Pregunta>(Pregunta(personajes[0],personajes.size()));
	
	return arbol;
}

void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo){
	arbol = arbol_nuevo;
}

void QuienEsQuien::iniciar_juego(){
  if(!arbol.empty()){
    jugada_actual=arbol.root();
    string respuesta;
    while((*jugada_actual).obtener_num_personajes()!=1){
	  cout<<(*jugada_actual)<<endl; 
	  cout<<"Personajes que nos quedan:"<<endl; 
		mostrar_informacion_jugada();	
      do{
      cin>>respuesta;
      if(respuesta.compare("Si")==0 && !jugada_actual.left().null())
        jugada_actual=jugada_actual.left();
      else if(respuesta.compare("No")==0 && !jugada_actual.right().null())
        jugada_actual=jugada_actual.right();
      else 
        cout<<"Su respuesta es incorrecta (escriba Si o No) o no existe ningún personaje con esos atributos"<<endl;
      }while(respuesta.compare("Si")!=0 && respuesta.compare("No")!=0);
    }

    cout<<"¡Ya lo sé! Tu personaje es "<<(*jugada_actual).obtener_personaje()<<endl;

    cout<<"¿Desea jugar otra partida?\n";
    cin>>respuesta;
    if(respuesta.compare("Si")==0)
      iniciar_juego();
    else if(respuesta.compare("No")==0){
	  cout << "Hasta la próxima\n";
      jugada_actual=arbol.root();
    }else{
      cout << "Respuesta incorrecta. Se termina el juego." << endl;
      jugada_actual=arbol.root();
    }
  }
}


void QuienEsQuien::personajes_restantes(set<string> & pers_levantados,bintree<Pregunta>::node nodo){
	if((*nodo).obtener_num_personajes()==1)    
	  pers_levantados.insert((*nodo).obtener_personaje());
	else{
	  if(!nodo.left().null())
		personajes_restantes(pers_levantados, nodo.left());
	  if(!nodo.right().null())    
		personajes_restantes(pers_levantados, nodo.right());
	}
}

set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual){
	set<string> personajes_levantados;
	personajes_restantes(personajes_levantados,jugada_actual);
	return personajes_levantados;
}


void QuienEsQuien::mostrar_informacion_jugada(){
	set<string> personajes_levantados;
	personajes_levantados=informacion_jugada(jugada_actual);
	set<string>::iterator it;
	for(it=personajes_levantados.begin();it!=personajes_levantados.end();it++)
		cout<<(*it)<<" ";
	cout<<endl;
}


void escribir_esquema_arbol(ostream& ss, const bintree<Pregunta>& a, bintree<Pregunta>::node n, string& pre){
	if (n.null()){
	    ss << pre << "-- x" << endl;
	} else {
	    ss << pre << "-- " << (*n) << endl;
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			pre += "   |";
	    	escribir_esquema_arbol(ss,a, n.right(), pre);
	     	pre.replace(pre.size()-4, 4, "    ");
	      	escribir_esquema_arbol (ss,a, n.left(), pre);
	      	pre.erase(pre.size()-4, 4);    
	    }
  	}
}

void QuienEsQuien::escribir_arbol_completo() const{
	string pre = "";
	escribir_esquema_arbol(cout,this->arbol,this->arbol.root(),pre);
}

void QuienEsQuien::eliminar_nodos_redundantes_recursivo(bintree<Pregunta>::node nodo){
//Si funcionara el método replace_subtree de la clase bintree la implementación de este método sería mucho más corta
	if(!nodo.null() && (*nodo).obtener_num_personajes()!=1){		
		if(!nodo.left().null() && nodo.right().null()){
			if(nodo==arbol.root()){
				arbol.assign_subtree(arbol, nodo.left());
				eliminar_nodos_redundantes_recursivo(arbol.root());
			}else{
				bintree<Pregunta> subarbol;
				subarbol.assign_subtree(arbol, nodo.left());
				if(nodo.parent().left()==nodo){
					arbol.insert_left(nodo.parent(), subarbol);
					eliminar_nodos_redundantes_recursivo(nodo.parent().left());
				}else{
					arbol.insert_right(nodo.parent(), subarbol);
					eliminar_nodos_redundantes_recursivo(nodo.parent().right());
				}
			}
			
		}else if(nodo.left().null() && !nodo.right().null()){
			
			if(nodo==arbol.root()){
				arbol.assign_subtree(arbol, nodo.right());
				eliminar_nodos_redundantes_recursivo(arbol.root());
			}else{
				bintree<Pregunta> subarbol;
				subarbol.assign_subtree(arbol,nodo.right());

				if(nodo.parent().left()==nodo){
					arbol.insert_left(nodo.parent(), subarbol);
					eliminar_nodos_redundantes_recursivo(nodo.parent().left());
				}else{
					arbol.insert_right(nodo.parent(), subarbol);
					eliminar_nodos_redundantes_recursivo(nodo.parent().right());
				}
			}
		}else{
			eliminar_nodos_redundantes_recursivo(nodo.left());
			eliminar_nodos_redundantes_recursivo(nodo.right());
		}
	}
}

void QuienEsQuien::eliminar_nodos_redundantes(){
	bintree<Pregunta>::node n(arbol.root());
	eliminar_nodos_redundantes_recursivo(n);
	
}

void QuienEsQuien::suma_profundidad(bintree<Pregunta>::node n, float &suma_profundidad_total, int profundidad_nodo){
	if((*n).obtener_num_personajes()!=1){
		if(!n.left().null())	
			suma_profundidad(n.left(), suma_profundidad_total, profundidad_nodo+1);
		if(!n.right().null())	
			suma_profundidad(n.right(), suma_profundidad_total, profundidad_nodo+1);
	}else{
		suma_profundidad_total+=profundidad_nodo;
	}
}

float QuienEsQuien::profundidad_promedio_hojas(){
	if(!arbol.empty()){
		float suma=0;
		int profundidad=0;
		suma_profundidad(arbol.root(), suma, profundidad);
		
		float media;
		media=suma/personajes.size();
		
		return media;
	}else	
		return -1;
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/

int generaEntero(int min, int max){
    int tam= max -min;
    return ((rand()%tam)+min);
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes){
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes)/log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petición para generar "<< numero_de_personajes<<" personajes ";
	cout << "con "<<numero_de_atributos<< " atributos"<<endl;
	cout << "Paso 1: generar "<< pow(2,numero_de_atributos) << " personajes"<<endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez
	for(int indice_personaje=0;indice_personaje< pow(2,numero_de_atributos);indice_personaje++){
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje,numero_de_atributos);
		string nombre_personaje = "Personaje_"+to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for(int indice_atributo=0;indice_atributo<numero_de_atributos;indice_atributo++){
		string nombre_atributo = "Atributo_"+to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar "<< (pow(2,numero_de_atributos)-numero_de_personajes) << " personajes"<<endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while(personajes.size()>numero_de_personajes){
		int personaje_a_eliminar = generaEntero(0,personajes.size());

		personajes.erase(personajes.begin()+personaje_a_eliminar);
		tablero.erase(tablero.begin()+personaje_a_eliminar);
	}
}
