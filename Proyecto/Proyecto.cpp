#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

void menu () {
    cout << "Tienda" << endl; 
    cout << "1: Inventario" << endl;
    cout << "2: Agregar articulo" << endl;
    cout << "3: Editar articulo" << endl; 
    cout << "4: Buscar articulo" << endl; 
    cout << "5: Eliminar articulo" << endl; 
    cout << "6: Salir" << endl;
}
void inventario (string vectorA[5], int codigosUnicos[5]) {
    cout << "Inventario:" << endl;
    for (int i = 0; i < 5; i++) {
        if (codigosUnicos[i] != 0) {
            cout << "Articulo" << i + 1 << ", " << "codigo: " << "#" << codigosUnicos[i] << ": " << vectorA[i] << endl;
        }
    }
}
void generarCodigos (int codigosUnicos[5]) {

    srand(time(0));
    set<int> codigosUsados;

    for (int i = 0; i < 5; i ++) {
        int codigo;

        do {
            codigo = rand () % 100 + 10;
        } while (codigosUsados.find(codigo) != codigosUsados.end());

        codigosUnicos[i] = codigo;
        codigosUsados.insert(codigo);
    } 
}

int eliminarArticulo (int codigoProducto, string vectorA[5], int codigosUnicos[5]) {
    for (int i = 0; i < 5; i++) {
        if (codigoProducto == codigosUnicos[i]){
            for (int j = i; j < 4; j++) {
                vectorA[j] = vectorA[j + 1];
                codigosUnicos[j] = codigosUnicos[j+1];
            }
            vectorA[4] = " ";
            codigosUnicos[4] = 0;
            return 1;
        }
        
    }
    return 0;  
}

int main () {
    int opcion;
    string vectorA[5] = {"Gorra", "Chumpa", "Camisa", "Pantalon", "Playera"};
    int codigosUnicos[5];

    generarCodigos(codigosUnicos);

    do {
        menu ();
        cout << "Ingrese una opcion: " << endl;
        cin >> opcion;
        if (opcion == 1) {
            inventario(vectorA, codigosUnicos);
        }
        if (opcion == 5) {
            int codigoProducto;
            cout << "Ingrese el codigo del articulo a eliminar: ";
            cin >> codigoProducto;
            
            if (eliminarArticulo(codigoProducto, vectorA, codigosUnicos)) {
                cout << "Articulo eliminado" << endl;
            } else {
                cout << "Codigo no encontrado" << endl;
            } 
        }
    } while ( opcion != 6);

    return 0;
}