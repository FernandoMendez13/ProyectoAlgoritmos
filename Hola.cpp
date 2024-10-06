#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

void menu () {
    cout << "Menu" << endl << "1: Suma" << endl << "2: Inventario" << endl << "3: Salir" << endl;
}

int suma (int a, int b) {
    int resultado = a + b;
    return resultado;
}
void inventario (int vectorA[5], int codigos[5]) {

    srand(time(0));
    set<int> codigosUsados;

    for (int i = 0; i < 5; i ++) {
        cout << "Ingresa el valor del articulo " << i + 1 << ": ";
        cin >> vectorA[i];

        int codigo;

        do {
            codigo = rand () % 20 + 10;
        } while (codigosUsados.find(codigo) != codigosUsados.end());

        codigos[i] = codigo;
        codigosUsados.insert(codigo);
    } 

    cout << "Inventario: ";
    for (int i = 0; i < 5; i ++) {
        cout << "Articulo " << i + 1 << ", " << "codigo: "<< "#" << codigos[i] << ": " << vectorA[i] << endl;
    }
}


int main () {
    int opcion;
    int vectorA[5];
    int codigos[5];

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
        if (opcion == 2) {
            inventario(vectorA, codigos);
        }
    } while ( opcion != 3);

    return 0;
}