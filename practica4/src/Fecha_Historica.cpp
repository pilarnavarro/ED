#include <iostream>
#include <sstream>
#include <set>
#include <utility>
#include "Fecha_Historica.h"
#include <stdlib.h>
#include <stdio.h>
#include<string>
using namespace std;

//Develve un iterador señalando al primer elemento del conjunto
Fecha_Historica::iterator Fecha_Historica::begin(){  
  return events.second.begin();
}

//Develve un iterador constante señalando al primer elemento del conjunto
Fecha_Historica::const_iterator Fecha_Historica::begin()const{  
  return events.second.begin();
}

//Devuelve un iterador señalando al último elemento del conjunto.
Fecha_Historica::iterator Fecha_Historica::end(){  
  return events.second.end();
}

//Devuelve un iterador constante al último elemento del conjunto.
Fecha_Historica::const_iterator Fecha_Historica::end()const{  
  return events.second.end();
}

//Constructor de copias
   Fecha_Historica::Fecha_Historica(const Fecha_Historica & e){
      events=e.events;
   }

//Constructor con parámetros
   Fecha_Historica::Fecha_Historica(int a, string *s, int n){
      set_year(a);
      for(int i=0;i<n;i++){
        add_event(s[i]);
      }

   }

//Método de acceso al número de eventos de la Fecha_Historica
  void Fecha_Historica::set_year(int a){
    events.first=a;
  }

//Añade un evento
  void Fecha_Historica::add_event(string event){
      events.second.insert(event);
  }


//Buscador de eventos
  bool Fecha_Historica::search_event(string s, Fecha_Historica &matches){
      if(!matches.events.second.empty()){
        matches.events.second.clear();
      }

      bool encontrado=false;
     
     Fecha_Historica::const_iterator it;
      for(it=begin();it!=end();it++){
        if((*it).find(s)!=-1){
          matches.add_event(*it);
          encontrado=true;
        }
      }

      if (encontrado){
        matches.set_year(get_year());
      }

      return encontrado; 
}

//Union de los acontecimientos de dos fechas históricas
  void Fecha_Historica::Union(const Fecha_Historica & f, Fecha_Historica & result){
    if(!result.events.second.empty())
      result.events.second.clear();
    
    result=f;
    Fecha_Historica::iterator it;
    for(it=begin();it!=end();it++){
      if(!f.events.second.count(*it))
        result.add_event(*it);
    }  

  }

   //Operator =
   Fecha_Historica & Fecha_Historica::operator=(const Fecha_Historica & orig){
    events=orig.events;
    return *this;
  }

  //Operador []
  string Fecha_Historica::operator[](int i){
    assert(0<=i && i<get_size());
    Fecha_Historica::iterator it=begin();
    advance(it,i);
    return (*it);
  }
  
//Operador [] constante
  const string& Fecha_Historica::operator[](int i) const{
    assert(0<=i && i<get_size());
    Fecha_Historica::const_iterator it=begin();
    advance(it,i);
    return (*it);
  }
 
//Operador <<
  ostream& operator<< (ostream& os, const Fecha_Historica& e){
    os << e.get_year();
    Fecha_Historica::iterator it;
    for(it=e.begin();it!=e.end();it++){
        os << '#' << (*it);
    }
      os << '\n';
    return os;
  }

//Operador >>
istream& operator>> (istream& is, Fecha_Historica& e){  
  string linea; 
  const char ALM='#';
  
  if(!e.events.second.empty()){
    e.events.second.clear();
  }
  
  getline(is,linea,ALM);
  e.events.first=atoi(linea.c_str());
  
  getline(is,linea);
  stringstream ss(linea);
  
  while(!ss.eof()){
    getline(ss,linea,ALM);
    e.add_event(linea);
  }
  return is; 
}  

 
