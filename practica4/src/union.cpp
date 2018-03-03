#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc<3 || argc>4){
      cout<<"Error en el número de argumentos"<<endl;
      return 0;
  }

   ifstream f1 (argv[1]);
   if (!f1){
    cout<<"No puedo abrir el  primer fichero "<<argv[1]<<endl;
    return 0;
  }


   ifstream f2 (argv[2]);
   if (!f2){
    cout<<"No puedo abrir el  segundo fichero "<<argv[2]<<endl;
    return 0;
  }

   Cronologia crono1,crono2,result;
   f1>>crono1;
   f2>>crono2;
   crono1.Union(crono2,result);

  if(argc==4){
    ofstream out(argv[3]);
    if (!out){
      cout<<"No puedo abrir el  fichero de salida,el resultado se mostrará por pantalla. "<<argv[3]<<endl;
      cout<<"Uníón de ambas cronologías: "<<"\n"<<result<<"\n";
     }else  out<<"Uníón de ambas cronologías: "<<"\n"<<result<<"\n";
  }else   cout<<"Uníón de ambas cronologías: "<<"\n"<<result<<"\n";
  
  return 0;
}

   
