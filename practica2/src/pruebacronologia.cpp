#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Cronologia mi_cronologia;
   
   f >> mi_cronologia; //Cargamos en memoria
   
   cout << "Cronología leida del archivo: " << endl << mi_cronologia;
   
   //Pruebo la función que busca los eventos que suceden entre dos años
   Cronologia buscadora;
   buscadora=mi_cronologia.buscarevento_entredosanios(1954,1960);
   cout << "\nLos eventos que sucedieron entre 1954 y 1960 son: " <<endl << buscadora;
   
   //Utilización del constructor de copias
  Cronologia copia(buscadora); 
  cout << "\nCronologia copia: " << endl<< copia;

  /* To-do: Ej: buscar un evento y restringir copia a los acontecimientos con ese evento, después imprimir para comprobar */

   cout << "\nEventos encontrados con \"mathematic\":" << endl;
   Cronologia copia_evento(mi_cronologia.buscarEventos("mathematic"));
   cout << copia_evento;

   //Pruebo el operador[]
   cout << "\nLa fecha historica de la posicion 8 es: " << endl;
   cout << mi_cronologia[8];

   //Pruebo buscar año
   int posicion;
   posicion=mi_cronologia.buscarAnio(1911);
   cout << "\nLa posición de 1911 es: " << posicion<< endl;



}
