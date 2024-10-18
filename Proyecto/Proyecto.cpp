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
int contarProductos(string vectorA[10]) {
    int contador = 0;
    for (int i = 0; i < 10; i++) {
        if (vectorA[i] != "") {
            contador++;
        }
    }
    return contador;
}

void inventario (string vectorA[10], int codigosUnicos[10], string fechaProducto[10], int precioProducto[10]){
    cout << "Inventario:" << endl;
    int totalProductos = contarProductos(vectorA);
    cout << "Productos en el inventario: " << totalProductos << endl;
    for (int i = 0; i < 10; i++) {
        if (codigosUnicos[i] != 0 && vectorA[i] != "") {
            cout << "Articulo" << i + 1 << ", " << "codigo: " << "#" << codigosUnicos[i] << ": " << vectorA[i] << " fecha: " << fechaProducto[i] << ", precio: " << precioProducto[i] << endl;
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

void agregarProducto (string vectorA[10], int codigosUnicos[10], string fechaProducto[10], int precioProducto[10]) {
    if (contarProductos(vectorA) >= 10) {
        cout << "El inventario esta lleno.\n";
        return;
    }
    int posicion = contarProductos(vectorA);

    cout << "Ingresa el nombre del nuevo producto: ";
    cin.ignore();  // Para ignorar el salto de línea anterior
    getline(cin, vectorA[posicion]);


    cout << "Ingresa el codigo del nuevo producto: ";
    cin >> codigosUnicos[posicion];

    cout << "Ingresa la fecha del nuevo producto: ";
    cin >> fechaProducto[posicion];

    cout << "Ingresa el precio del producto: ";
    cin >> precioProducto[posicion];

    cout << "Producto agregado exitosamente." << endl;
}

void editarProducto(string vectorA[10], int codigosUnicos[10], int codigoBusqueda, string fechaProducto[10], int precioProducto[10]) {
    for (int i = 0; i < 10; i++) {
        if (codigoBusqueda == codigosUnicos[i]) {
            
            cout << "Ingrese el nuevo nombre para el producto: " << endl;
            cin.ignore();
            getline(cin, vectorA[i]);

            cout << "Ingrese el nuevo codigo del producto: " << endl;
            cin >> codigosUnicos[i];

            cout << "Ingrese la nueva fecha del producto: " << endl;
            cin >> fechaProducto[i];

            cout << "Ingrese el nuevo precio del producto: " << endl;
            cin >> precioProducto[i];

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
int eliminarArticulo (int codigoProducto, string vectorA[10],string fechaProducto[10], int codigosUnicos[10], int precioProducto[10]) {
    int totalProductos = contarProductos(vectorA);
    for (int i = 0; i < totalProductos; i++) {
        if (codigoProducto == codigosUnicos[i]){
            for (int j = i; j < totalProductos -1; j++) {
                vectorA[j] = vectorA[j + 1];
                codigosUnicos[j] = codigosUnicos[j + 1];
                fechaProducto[j] = fechaProducto[j + 1];
                precioProducto[j] = precioProducto[j+1];
            }
            vectorA[totalProductos - 1] = "";
            codigosUnicos[totalProductos -1] = 0;
            fechaProducto[totalProductos -1] = "";
            precioProducto[totalProductos -1] = 0;
            return 1;
        }
        
    }
    return 0;  
}

int main () {
    int opcion;
    string vectorA[10] = {"Gorra", "Chumpa", "Camisa", "Pantalon", "Playera"};
    string fechaProducto[10] = {"10/12/2020","20/01/2022","11/11/2019","08/05/2013","12/10/2021"};
    int precioProducto[10] = {10, 20, 15, 25, 12};
    int codigosUnicos[10];

    generarCodigos(codigosUnicos);

    do {
        menu ();
        cout << "Ingrese una opcion: " << endl;
        cin >> opcion;
        if (opcion == 1) {
            inventario(vectorA, codigosUnicos, fechaProducto, precioProducto);
        }

        if (opcion == 2) {
            agregarProducto(vectorA, codigosUnicos, fechaProducto, precioProducto);
        }

        if (opcion == 3) {
            int codigoBusqueda;
            cout << "Ingresa el codigo del producto que desea editar: " << endl;
            cin >> codigoBusqueda;
            editarProducto(vectorA, codigosUnicos, codigoBusqueda, fechaProducto, precioProducto);
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
            
            if (eliminarArticulo(codigoProducto, vectorA,  fechaProducto, codigosUnicos, precioProducto)) {
                cout << "Articulo eliminado" << endl;
            } else {
                cout << "Codigo no encontrado" << endl;
            } 
        }
    } while ( opcion != 6);

    return 0;
}