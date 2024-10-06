#include <iostream>

using namespace std;

void menu () {
    cout << "Menu" << endl << "1: Suma" << endl;
}

int suma (int a, int b){
    int resultado = a + b;
    return resultado;
}
int main () {
    int opcion;

    do {
        menu ();
        cout << "Ingrese una opcion: " << endl;
        cin >> opcion;
        if (opcion == 1) {
            int a;
            int b;
            int resultado;
            cout << "Ingrese un numero:" << endl;
            cin >> a;
            cout << "Ingrese un numero:" << endl;
            cin >> b;
            resultado = suma(a,b);
            cout << "El resultado de la suma es: " << resultado;
        }
    } while ( opcion != 2);

    return 0;
}