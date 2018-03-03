#include <iostream>
#include "Cronologia.h"
#include "Fecha_Historica.h"

using namespace std;


//Acceso al número de fechas históricas
int Cronologia::getnumdates() const{
  return cron.size();
}

//Operador de asignación
Cronologia & Cronologia::operator=(const Cronologia & orig){
  cron=orig.cron;
  return *this;
}

//Añade un objeto de Fecha_Historica
void Cronologia::addEvent(Fecha_Historica& eh){
  pair <int,Fecha_Historica> aux(eh.get_year(),eh);
  if(!cron.count(aux.first))
   cron.insert(aux);
 else{     
   Fecha_Historica auxf;
   Cronologia::iterator it=cron.find(aux.first);
   eh.Union((*it).second,auxf);
 
   cron.erase(it);
   cron.insert(pair <int,Fecha_Historica> (eh.get_year(),auxf));
 }   
}

 //Eventos históricos acontecidos en el intervalo [t1,t2)
 void Cronologia::filtrado_intervalo(Cronologia & c,int t1,int t2){
  pair<int,Fecha_Historica> aux;
  iterator it;
  if(t1<=t2){
  if(cron.count(t1)!=0 && cron.count(t2)!=0){ 
    for(it=cron.find(t1);it!=cron.find(t2);it++){ 
      aux.first=(*it).first;
      aux.second=(*it).second;
      c.cron.insert(aux);
    }
    aux.first=cron.find(t2)->first;
    aux.second=cron.find(t2)->second;
    c.cron.insert(aux);
  }
  }
}

//Cuenta el número total de eventos históricos que hay en la Cronología
int Cronologia::numevents(){
  iterator it;
  int n=0;

  for(it=begin();it!=end();it++){
    n=n+it->second.get_size();
  }

  return n;
}

//Máximo número de eventos por año  
int Cronologia::maxevents(){
  iterator it;
  int maximo=0;

  for(it=begin();it!=end();it++){
    if(it->second.get_size()>maximo){
      maximo=it->second.get_size();
    }
  }
  return maximo;
}

//Calcula la media del número de eventos por año
int Cronologia::mediaevents(){
  return numevents()/getnumdates();
}


//Unión de dos cronologías
void Cronologia::Union(const Cronologia &crono2, Cronologia &result){
    if(!result.cron.empty())
      result.cron.clear();

    result=crono2;
    Cronologia::iterator it; 
    for(it=begin();it!=end();it++){
      result.addEvent((*it).second);
    }
    
}
//Busca un evento en la Cronología dado un año y devuelve su posición en el vector
Cronologia::iterator Cronologia::search_year(int f){
    Cronologia::iterator it=cron.find(f);
    return it;
  
}

//Buscador de eventos dado una palabra clave
void Cronologia::search(Cronologia &result, string s){
if(!result.cron.empty())
  result.cron.clear();

Fecha_Historica aux;

Cronologia::iterator it;
for(it=begin();it!=end();it++){
  if((*it).second.search_event(s,aux)){
    result.addEvent(aux);
  }    
}
}

  //Operator []
  Fecha_Historica & Cronologia::operator[](int i){
    if(0<=i && i<getnumdates()){
		 Cronologia::iterator it=begin();
		 advance(it,i);
		 return (*it).second;
	  };
  }
  //Operator [] de sólo lectura
  const Fecha_Historica & Cronologia::operator[](int i) const{
    if(0<=i && i<getnumdates()){
		 Cronologia::const_iterator it=begin();
		 advance(it,i);
		 return (*it).second;
	  };
  }
  
//Operator <<
  ostream& operator<< (ostream& os, const Cronologia& c){
	  Cronologia::const_iterator it;
     for(it=c.begin(); it!=c.end(); it++)
        os << (*it).second <<endl;
     return os;     
  }

//Operator >>
  istream& operator>> (istream& is, Cronologia& c){
     Fecha_Historica aux;
     while(is >> aux){   
        c.addEvent(aux);
     }
     return is;
  } 

 


