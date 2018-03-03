#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
    if (argc<2 || argc>4){
        cout<<"Número de argumentos incorrecto.Fin del programa"<<endl;
        return 0;
    }

    ifstream f (argv[1]);
    if (!f){
        cout<<"No puedo abrir el fichero con la cronología "<<argv[1]<<endl;
        return 0;
    } 

    Cronologia my_cron,result;
    f >> my_cron;
     
    string key;
    if(argc>2)
        key=argv[2];
    else{
        cout<<"Introduce la palabra a buscar: "<<endl;
        cin>>key;
    }

    my_cron.search(result,key);

    if(argc==4){
        ofstream out(argv[3]);
        if (!out){
          cout<<"No puedo abrir el  fichero de salida "<<argv[3]<< ",el resultado se mostrará por pantalla. "<<endl;
          cout<<"Cronología que contiene la palabra introducida: "<<"\n"<<result<<"\n";
         }else  out<<"Cronología que contiene la palabra introducida: "<<"\n"<<result<<"\n";
      }else  cout<<"Cronología que contiene la palabra introducida: "<<"\n"<<result<<"\n";



}
