#include <iostream>
#include "Cronologia.h"
#include "Fecha_Historica.h"

using namespace std;

//Resize
  void Cronologia::resize(int r){
    assert(r>=0);
    if(r!=reservados){
      if(r!=0){    
        Fecha_Historica *aux = new Fecha_Historica[r]; 
        if(reservados>0){
          int minimo;
          minimo=reservados<r?reservados:r;
          for(int i=0; i<minimo; ++i)
          aux[i]=event[i];
          delete[] event;
        }  
        event = aux;
        reservados=r;
        if(reservados<neventos)
          neventos=reservados;
     }else{
      if(reservados>0)
        delete[] event;
      event=0;
      reservados=0;
      neventos=0;  
     }   
    }
  }
  
//Ordena
  void Cronologia::ordenar(){
     for (int i=neventos-1; i>0; --i) 
      for (int j=0; j<i; ++j)
         if (event[j].getAnio() > event[j+1].getAnio()) {
            Fecha_Historica aux;
            aux = event[j];
            event[j] = event[j+1];
            event[j+1]= aux;
         }
}

//Constructor vacío
  Cronologia::Cronologia():reservados(0),neventos(0),event(0){}
     

//Constructor con parámetro cadena de Fecha_Historica y número de objetos
  Cronologia::Cronologia(Fecha_Historica *eh, int n):reservados(n),neventos(n){
     Fecha_Historica *event = new Fecha_Historica[n];   
     for (int i=0; i<n; i++)
        event[i]=eh[i];
  }

//Constructor de copias
   Cronologia::Cronologia(const Cronologia& c){
      event = new Fecha_Historica[c.reservados];
      neventos = c.neventos;
      reservados = c.neventos;
      for(int i=0; i<neventos; ++i)
         event[i] = c.event[i];
   }

//Acceso al número de fechas históricas
int Cronologia::getnumfechas(){
  return neventos;
}

//Operador de asignación
Cronologia & Cronologia::operator=(const Cronologia & orig){
  if(&orig!=this){
    if(neventos>0) 
      delete [] event;
  
    neventos=orig.neventos;
    reservados=orig.reservados;
    event=new Fecha_Historica[reservados];
    for(int i=0;i<neventos;i++){
      event[i]=orig.event[i];
    }
  }
  return *this;
}


//Añade objeto de Fecha_Historica
  void Cronologia::aniadirEvento(Fecha_Historica& eh){
     if (neventos == reservados){
        if (neventos==0)
           resize(1);
        else
           resize(2*reservados);
     }
     event[neventos]=eh;
     neventos++;
     ordenar();
  }


//Busca un evento en la Cronología y devuelve su posición en el vector
  int Cronologia::buscarAnio(int f){
     int i=0;
     bool valido=false;
     while(i<neventos && !valido){
        if(event[i].getAnio()==f)
           valido = true;
        else
           ++i;
     }
     if(!valido)
        i=-1;
     return i;
  }


//Busca un evento en la Cronología y devuelve su posición en el vector
  Cronologia Cronologia::buscarEventos(string s){
     Cronologia nuevo;
     for (int i=0; i < neventos; ++i){
        Fecha_Historica aux;
        if(event[i].buscarEventos(s,aux)){
           nuevo.aniadirEvento(aux);
        }
     }
     nuevo.ordenar();
     return nuevo;
   }

   //Buscar eventos que sucedieron entre dos años
  Cronologia Cronologia::buscarevento_entredosanios(int anio1,int anio2){
    Cronologia nuevo;
    for(int i=buscarAnio(anio1);i<buscarAnio(anio2)+1;i++){
      nuevo.aniadirEvento(event[i]);
    }
   
    return nuevo;
  }

  //Operator []
  Fecha_Historica & Cronologia::operator[](int i){
    assert(0<=i && i<neventos);
     return event[i];
  }
  //Operator [] de sólo lectura
  const Fecha_Historica & Cronologia::operator[](int i) const{
    assert(0<=i && i<neventos);
    return event[i];

  }
  
//Operador <<
  ostream& operator<< (ostream& os, const Cronologia& c){
     for(int i=0; i<c.neventos; i++)
        os << c.event[i];
     return os;     
  }

//Operador >>
  istream& operator>> (istream& is, Cronologia& c){
     Fecha_Historica b;
     while(is >> b){   
        c.aniadirEvento(b);

     }
     return is;
  } 
