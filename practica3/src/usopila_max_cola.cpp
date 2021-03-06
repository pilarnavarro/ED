#include<iostream>
#include "pila_max.h"
using namespace std;

int main(){
    Pila_max_cola p1;
    Pila_max_cola p2;
    elemento elem;
    int num_elementos;

    cin >> num_elementos;

    for(int i=0;i<num_elementos;i++){
        cin >> elem.valor;
        p1.poner(elem.valor);
    }

    p2=p1;

    cout << "\nTope pila 2: " << p2.tope();

    //ELimino lo que hay en el tope
    p2.quitar();
    cout << "\nNuevo tope pila 2: " << p2.tope();

    Pila_max_cola p3(p2);

    cout << "\nMáximo de la pila: " << p3.max() << endl;

    cout << "\nElementos Pila 3: " << endl;

	while(!p3.vacia()){
		cout << p3.tope() << endl;
       p3.quitar();
	}

    if(p3.vacia()){
        cout << "\nPila 3 esta vacia" << endl;
    }

}
