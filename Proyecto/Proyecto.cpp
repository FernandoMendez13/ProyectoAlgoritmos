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
    cout << "6: Valor inventario" << endl;
    cout << "7: Productos antiguos" << endl;
    cout << "8: Salir" << endl;
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

void valorInventario(int precioProducto[10], int unidadProducto[10]) {
    int total = 0;
    for (int i = 0; i < 10; i++) {
        total += precioProducto[i] * unidadProducto[i];
    }
    cout << "El valor del inventario es de: " << total << endl;
}

void productosAntiguos (string vectorA[10], string fechaProducto[10]) {
    time_t t = time(0);
    tm* ahora = localtime(&t);
    int anioActual = ahora -> tm_year + 1900;
    int mesActual = ahora -> tm_year + 1;
    int diaActual = ahora -> tm_year;

    cout << "Productos en el inventario con mas de un anio:" << endl;
    for(int i = 0; i < 10; i++) {
        if (!fechaProducto[i].empty() && fechaProducto[i].length()>= 10) {
            int dia = stoi(fechaProducto[i].substr(0, 2));
            int mes = stoi(fechaProducto[i].substr(3, 2));
            int anio = stoi(fechaProducto[i].substr(6, 4));

            if (anioActual - anio > 1 || (anioActual - anio == 1 && (mesActual > mes ||(mesActual == mes && diaActual >= dia)))) {
                cout << vectorA[i] << " fecha de ingreso: " << fechaProducto[i] << endl;
            }
        } 
    }
}
void inventario (string vectorA[10], int codigosUnicos[10], string fechaProducto[10], int precioProducto[10], int unidadProducto[10]){
    cout << "Inventario:" << endl;
    int totalProductos = contarProductos(vectorA);
    cout << "Productos en el inventario: " << totalProductos << endl;
    for (int i = 0; i < 10; i++) {
        if (codigosUnicos[i] != 0 && vectorA[i] != "") {
            cout << "Articulo " << i + 1 << ", " << "codigo: " << "#" << codigosUnicos[i] << ": " << vectorA[i] << " fecha: " << fechaProducto[i] << ", precio: " << precioProducto[i] << ", cantidad: " << unidadProducto[i] << endl;
        }
    }
}
void generarCodigos (int codigosUnicos[10], set <int> & codigosUsados) {

    srand(time(0));

    for (int i = 0; i < 10; i ++) {
        int codigo;

        do {
            codigo = rand () % 100 + 10;
        } while (codigosUsados.find(codigo) != codigosUsados.end());

        codigosUnicos[i] = codigo;
        codigosUsados.insert(codigo);
    } 
}

void agregarProducto (string vectorA[10], int codigosUnicos[10], string fechaProducto[10], int precioProducto[10], int unidadProducto[10], set<int> & codigosUsados) {
    if (contarProductos(vectorA) >= 10) {
        cout << "El inventario esta lleno.\n";
        return;
    }
    int posicion = contarProductos(vectorA);

    cout << "Ingresa el nombre del nuevo producto: ";
    cin.ignore();
    getline(cin, vectorA[posicion]);

    int codigo;
    do {
        codigo = rand() % 100 + 10;
    } while (codigosUsados.find(codigo) != codigosUsados.end());
    codigosUnicos[posicion] = codigo;
    codigosUsados.insert(codigo);

    cout << "Codigo generado automaticamente: " << codigo << endl;

    cout << "Ingresa la fecha del nuevo producto: ";
    cin >> fechaProducto[posicion];

    cout << "Ingresa el precio del producto: ";
    cin >> precioProducto[posicion];

    cout << "Ingresa la cantidad de unidades del producto: ";
    cin >> unidadProducto[posicion];

    cout << "Producto agregado exitosamente." << endl;
}

void editarProducto(string vectorA[10], int codigosUnicos[10], int codigoBusqueda, string fechaProducto[10], int precioProducto[10], int unidadProducto[10], set <int> &codigosUsados) {
    for (int i = 0; i < 10; i++) {
        if (codigoBusqueda == codigosUnicos[i]) {
            
            cout << "Ingrese el nuevo nombre para el producto: " << endl;
            cin.ignore();
            getline(cin, vectorA[i]);

            int nuevoCodigo;
            do {
                cout << "Ingrese el nuevo codigo del producto: " << endl;
                cin >> nuevoCodigo;
                if (codigosUsados.find(nuevoCodigo) != codigosUsados.end()){
                    cout << "El codigo ingresado ya existe" << endl;
                }
            } while (codigosUsados.find(nuevoCodigo) != codigosUsados.end());

            codigosUnicos[i] = nuevoCodigo;
            codigosUsados.insert(nuevoCodigo);
           


            cout << "Ingrese la nueva fecha del producto: " << endl;
            cin >> fechaProducto[i];

            cout << "Ingrese el nuevo precio del producto: " << endl;
            cin >> precioProducto[i];

            cout << "Ingrese la nueva cantidad de productos: " << endl;
            cin >> unidadProducto[i];

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
int eliminarArticulo (int codigoProducto, string vectorA[10],string fechaProducto[10], int codigosUnicos[10], int precioProducto[10], int unidadProducto[10]) {
    int totalProductos = contarProductos(vectorA);
    for (int i = 0; i < totalProductos; i++) {
        if (codigoProducto == codigosUnicos[i]){
            for (int j = i; j < totalProductos -1; j++) {
                vectorA[j] = vectorA[j + 1];
                codigosUnicos[j] = codigosUnicos[j + 1];
                fechaProducto[j] = fechaProducto[j + 1];
                precioProducto[j] = precioProducto[j + 1];
                unidadProducto[j] = unidadProducto[j + 1];
            }
            vectorA[totalProductos - 1] = "";
            codigosUnicos[totalProductos -1] = 0;
            fechaProducto[totalProductos -1] = "";
            precioProducto[totalProductos -1] = 0;
            unidadProducto[totalProductos -1] = 0;
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
    int unidadProducto[10] = {5, 5, 5, 5, 5};
    int codigosUnicos[10];
    set <int> codigosUsados;

    generarCodigos(codigosUnicos, codigosUsados);
    system("cls");
    do {

        menu ();
        cout << "Ingrese una opcion: " << endl;
        cin >> opcion;
        if (opcion == 1) {
            inventario(vectorA, codigosUnicos, fechaProducto, precioProducto, unidadProducto);
        }

        if (opcion == 2) {
            agregarProducto(vectorA, codigosUnicos, fechaProducto, precioProducto, unidadProducto, codigosUsados);
        }

        if (opcion == 3) {
            int codigoBusqueda;
            cout << "Ingresa el codigo del producto que desea editar: " << endl;
            cin >> codigoBusqueda;
            editarProducto(vectorA, codigosUnicos, codigoBusqueda, fechaProducto, precioProducto, unidadProducto, codigosUsados);
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
            
            if (eliminarArticulo(codigoProducto, vectorA,  fechaProducto, codigosUnicos, precioProducto, unidadProducto)) {
                cout << "Articulo eliminado" << endl;
            } else {
                cout << "Codigo no encontrado" << endl;
            } 
        }

        if (opcion == 6) {
            system("cls");
            valorInventario(precioProducto, unidadProducto);
        }
        
        if (opcion == 7) {
            system("cls");
            productosAntiguos(vectorA, fechaProducto);
        }
    } while ( opcion != 8);

    return 0;
}