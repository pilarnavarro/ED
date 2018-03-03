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
   
   f >> mi_cronologia; 
   
   cout << "Cronología leida del archivo: " << endl << mi_cronologia;
  
  Cronologia copia(mi_cronologia); 
  cout << "\nCronologia copia: " << endl<< copia<<endl;

   cout << "\nLa fecha historica de la posicion 8 es: " << endl;
   cout << mi_cronologia[8];

   int anio;
   cout<<"Introduce el anio a buscar: "<<endl;
   cin>>anio;

   Cronologia::iterator it=mi_cronologia.search_year(anio);
   
	cout<<(*it).second<<endl;
  

}
