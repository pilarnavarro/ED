#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Fecha_Historica.h"
#include <stdlib.h>
using namespace std;

//Resize 
  void Fecha_Historica::resize(int r){
    assert(r>=0);
    if(r!=reservados){
      if(r!=0){
        string *aux = new string[r]; 
        if(reservados>0){
          int minimo;
          minimo=reservados<r?reservados:r;
          for(int i=0; i<minimo; ++i)
            aux[i]=str[i];
          delete[] str;
        }
        str = aux;
        reservados = r;
        if(reservados<numeventos)
              numeventos=reservados;
     }
     else{
       if(reservados>0)
         delete[] str;
       str=0;
       reservados=0;
       numeventos=0;  
      }   
      
   }
    
  }


//Constructor vacío
  Fecha_Historica::Fecha_Historica():anio(0),reservados(0),numeventos(0),str(0),aC(false){}


//Constructor con parametros año, cadena de eventos,número de eventos a añadir y booleano que indica si el año es antes de cristo
  Fecha_Historica::Fecha_Historica(int a, string *s, int n, bool C):reservados(n),numeventos(n),aC(C){
     assert(a >= 0 && a<= 9999);
     anio = a;
     string *str = new string[n];   
     for (int i=0; i<n; i++)
        str[i]=s[i];
  }

//Constructor de copias
   Fecha_Historica::Fecha_Historica(const Fecha_Historica& e){
      str = new string[e.reservados];
      anio=e.anio;
      numeventos = e.numeventos;
      reservados = e.numeventos;
      aC=e.aC;
      for(int i=0; i<numeventos; ++i)
         str[i] = e.str[i];
   }
   
   
  //Método de acceso a año
   int Fecha_Historica::getAnio(){
    return anio;
   }

   //Método de acceso a numeventos
   int Fecha_Historica::getnumeventos(){
    return numeventos;
   }


//Añade un evento
  void Fecha_Historica::aniadirevento(string& event){
     if (numeventos == reservados){
        if (numeventos==0)
           resize(1);
        else
        resize(2*reservados);
     }
     str[numeventos]=event;
     numeventos++;
  }


//Buscador de eventos
  bool Fecha_Historica::buscarEventos(string s, Fecha_Historica &matches){
     bool encontrado=false;
     for (int i=0; i < numeventos; ++i){
        if(str[i].find(s) != -1 ){
           matches.aniadirevento(str[i]);
           encontrado = true;
        }
     }
     if (encontrado){
        matches.anio=anio;
        matches.aC=aC;
      }
    return encontrado;       
   }

   //Operator =
   Fecha_Historica & Fecha_Historica::operator=(const Fecha_Historica & orig){
    if(&orig!=this){
      if(numeventos>0) 
        delete [] str;
      
      anio=orig.anio;
      numeventos=orig.numeventos;
      reservados=orig.numeventos;
      aC=orig.aC;
      str=new string[numeventos];
      for(int i=0;i<numeventos;i++){
        str[i]=orig.str[i];
      }

      
    }
    return *this;
  }

  //  Operador []
  string& Fecha_Historica::operator[](int i){
    assert(0<=i && i<numeventos);
    return str[i];
  }
// Operador [] constante
  const string& Fecha_Historica::operator[](int i) const{
    assert(0<=i && i<numeventos);
    return str[i];
	}
//Operador <<
  ostream& operator<< (ostream& os, const Fecha_Historica& e){
    os << e.anio;
    if(e.aC)
      os << "d.C.";
    else
      os << "a.C.";
    os << '#';
    for(int i=0;i<e.numeventos;i++){
        os << e.str[i];
        if(i!=e.numeventos-1)  //No pongo almohadilla en la utima posición
            os << '#';
    }
      os << '\n';
    return os;
  }

//Operador >>
istream& operator>> (istream& is, Fecha_Historica& e){  
      string ac;
      string linea; 
      const char ALM='#';
      int contador=1;
      
      is >> e.anio;
      getline(is,ac,ALM);
      getline(is,linea);
  
      for(int i=0; i<linea.length(); i++){
          if(linea[i]==ALM)
              contador++;
      }
  
      e.numeventos=contador;
      e.reservados=e.numeventos;
      e.str=new string[contador];
  
      stringstream ss(linea);
  
      for(int i=0; i<contador; i++)
          getline(ss, e.str[i], ALM);
  
    if(ac=="d.C.")
      e.aC=true;

    return is; 

  }  

 
