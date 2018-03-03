#include "Cronologia.h"
#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main(int argc,char *argv[]){
	int t1,t2;
	
	if(argc!=5){
		cout << "\nError al introducir los argumentos";
		return 0;
	}
	
	t1=atoi(argv[2]);
	t2=atoi(argv[3]);

	ifstream f(argv[1]);
	if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

	Cronologia mi_cronologia;
	Cronologia cron;
   
   f >> mi_cronologia; //Cargamos en memoria
   

	ofstream f2(argv[4]);
	if (!f2){
    cout<<"No puedo abrir el fichero "<<argv[4]<<endl;
    return 0;
   }
	
	mi_cronologia.filtrado_intervalo(cron,t1,t2);
	f2	<< cron;

}
