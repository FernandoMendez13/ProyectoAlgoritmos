#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

int numeroProductos = 5;

void menu () {
    cout << "Tienda" << endl; 
    cout << "1: Inventario" << endl;
    cout << "2: Agregar articulo" << endl;
    cout << "3: Editar articulo" << endl; 
    cout << "4: Buscar articulo" << endl; 
    cout << "5: Eliminar articulo" << endl; 
    cout << "6: Salir" << endl;
}
void inventario (string vectorA[10], int codigosUnicos[10]) {
    cout << "Inventario:" << endl;
    for (int i = 0; i < 10; i++) {
        if (codigosUnicos[i] != 0) {
            cout << "Articulo" << i + 1 << ", " << "codigo: " << "#" << codigosUnicos[i] << ": " << vectorA[i] << endl;
        }
    }
}
void generarCodigos (int codigosUnicos[10]) {

    srand(time(0));
    set<int> codigosUsados;

    for (int i = 0; i < 10; i ++) {
        int codigo;

        do {
            codigo = rand () % 100 + 10;
        } while (codigosUsados.find(codigo) != codigosUsados.end());

        codigosUnicos[i] = codigo;
        codigosUsados.insert(codigo);
    } 
}

void agregarProducto(string vectorA[10], int codigosUnicos[10]) {
    if (numeroProductos >= 10) {
        cout << "El inventario esta lleno.\n";
        return;
    }

    cout << "Ingresa el nombre del nuevo producto: ";
    cin.ignore();  // Para ignorar el salto de línea anterior
    getline(cin, vectorA[numeroProductos]);

    cout << "Ingresa el codigo del nuevo producto: ";
    cin >> codigosUnicos[numeroProductos];

    numeroProductos++;
    cout << "Producto agregado exitosamente." << endl;
}

void editarProducto(string vectorA[10], int codigosUnicos[10], int codigoBusqueda) {
    for (int i = 0; i < 10; i++) {
        if (codigoBusqueda == codigosUnicos[i]) {
            cout << "Ingrese el nuevo nombre para el producto: " << endl;
            getline(cin, vectorA[i]);
            cout << "Producto actualizado exitosamente" << endl;
            return;
        }
    }
    
}

void buscarArticulo (int codigosUnicos[10], string vectorA[10], int codigoBusqueda) {
    for (int i = 0; i < 10; i++) {
        if (codigoBusqueda == codigosUnicos[i]) {
            cout << "El producto con codigo: " << codigosUnicos[i] << " es: "  << vectorA[i] << endl;
            return;
        }
    }
    cout << "Producto no encontrado" << endl;

}
int eliminarArticulo (int codigoProducto, string vectorA[10], int codigosUnicos[10]) {
    for (int i = 0; i < 10; i++) {
        if (codigoProducto == codigosUnicos[i]){
            for (int j = i; j < 9; j++) {
                vectorA[j] = vectorA[j + 1];
                codigosUnicos[j] = codigosUnicos[j+1];
            }
            vectorA[9] = " ";
            codigosUnicos[9] = 0;
            numeroProductos--;
            return 1;
        }
        
    }
    return 0;  
}

int main () {
    int opcion;
    string vectorA[10] = {"Gorra", "Chumpa", "Camisa", "Pantalon", "Playera"};
    int codigosUnicos[10];

    generarCodigos(codigosUnicos);

    do {
        menu ();
        cout << "Ingrese una opcion: " << endl;
        cin >> opcion;
        if (opcion == 1) {
            inventario(vectorA, codigosUnicos);
        }

        if (opcion == 2) {
            agregarProducto(vectorA, codigosUnicos);
        }

        if (opcion == 3) {
            int codigoBusqueda;
            cout << "Ingresa el codigo del producto que desea editar: " << endl;
            cin >> codigoBusqueda;
            editarProducto(vectorA, codigosUnicos, codigoBusqueda);
        }

        if (opcion == 4) {
            int codigoBusqueda;
            cout << "Ingrese el codigo del producto que desea buscar: " << endl;
            cin >> codigoBusqueda;
            buscarArticulo(codigosUnicos, vectorA, codigoBusqueda);
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