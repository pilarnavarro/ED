#include "Cronologia.h"
#include <fstream>
#include <iostream>
using namespace std;


int main(int argc,char *argv[]){
	if(argc!=2){
		cout << "\nError al introducir los argumentos";
		return 0;
	}
	
	ifstream f(argv[1]);
	if(!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

	Cronologia mi_cronologia;
   
   f >> mi_cronologia; //Cargamos en memoria
   
	cout << "\nNumero total de años: " << mi_cronologia.getnumdates();
	cout << "\nNumero total de acontecimientos de la cronologia: " << mi_cronologia.numevents();
	cout << "\nMaximo de eventos por año: " << mi_cronologia.maxevents();
	cout << "\nMedia de eventos/año: " << mi_cronologia.mediaevents() << endl; 
}
