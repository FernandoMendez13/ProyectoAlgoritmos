//prueba no2
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <iomanip>
#include <string>
#include <limits>
#include <cstring>
using namespace std;
const int MAX_PRODUCTOS = 100;
int numProductos = 0;

void inventario(string vectorA[5], int codigosUnicos[5]) {
    cout << "Inventario:" << endl;
    for (int i = 0; i < 5; i++) {
        if (codigosUnicos[i] != 0) {
            cout << "Articulo " << i + 1 << ", Codigo: #" << codigosUnicos[i] << ": " << vectorA[i] << endl;
        }
    }
}
void agregarProducto(){
	int cantidad;
	double precio;
	char codigo[20], nombre[50], fechaIngreso[11];
	if(numProductos >= MAX_PRODUCTOS) {
        cout << "El inventario estÃ¡ lleno.\n";
        return;
    }
	cout << "Ingresa el codigo del producto: " <<endl;
	cin >> codigo;
	cout << "Ingresa el nombre del producto: " <<endl;
	cin >> nombre;
	cout << "Ingresa la cantidad del producto: " <<endl;
	cin >> cantidad;
	cout << "Ingresa el precio del producto: " <<endl;
	cin >> precio;
	cout << "Ingresa la fecha del producto: " <<endl;
	cin >> fechaIngreso;
    numProductos++;
    cout <<"Producto agregado exitosamente."<< endl;
}
void buscarProducto() {
    char codigo[20];
    cout << "Ingrese el codigo del producto a buscar: ";
    cin >> codigo;

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(inventario[i].codigo, codigo) == 0) {
            cout << "Producto encontrado:" << endl;
            cout << "Codigo: " << inventario[i].codigo << endl;
            cout << "Nombre: " << inventario[i].nombre << endl;
            cout << "Cantidad: " << inventario[i].cantidad << endl;
            cout << "Precio: " << inventario[i].precio << endl;
            cout << "Fecha de ingreso: " << inventario[i].fechaIngreso << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void generarCodigos(int codigosUnicos[5]) {
    srand(time(0));
    set<int> codigosUsados;

    for (int i = 0; i < 5; i++) {
        int codigo;

        do {
            codigo = rand() % 100 + 10;
        } while (codigosUsados.find(codigo) != codigosUsados.end());

        codigosUnicos[i] = codigo;
        codigosUsados.insert(codigo);
    }
}

int eliminarArticulo(int codigoProducto, string vectorA[5], int codigosUnicos[5]) {
    for (int i = 0; i < 5; i++) {
        if (codigoProducto == codigosUnicos[i]) {
            for (int j = i; j < 4; j++) {
                vectorA[j] = vectorA[j + 1];
                codigosUnicos[j] = codigosUnicos[j + 1];
            }
            vectorA[4] = " ";
            codigosUnicos[4] = 0;
            return 1;
        }
    }
    return 0;
}
void menu() {
    cout << "---------------------------------" << endl;
    cout << "Sistema de gestion de inventarios" << endl;
    cout << "---------------------------------" << endl;
    cout << "1: Inventario" << endl;
    cout << "2: Agregar producto al inventario" << endl;
    cout << "3: Editar informacion del producto" << endl;
    cout << "4: Buscar producto por codigo" << endl;
    cout << "5: Eliminar producto" << endl;
    cout << "6: Calcular el valor total del inventario" << endl;
    cout << "7: Buscar productos con mas de un ano en el inventario" << endl;
    cout << "8: Salir" << endl;
}
int main() {
    int opcion;
    string vectorA[5] = {"Gorra", "Chumpa", "Camisa", "Pantalon", "Playera"};
    int codigosUnicos[5];

    generarCodigos(codigosUnicos);

    do {
        menu();
        cout << "Ingrese una opcion: " << endl;
        cin >> opcion;

        switch(opcion) {
            case 1:
                inventario(vectorA, codigosUnicos);
                break;
            case 2:
				agregarProducto(vectorA, codigosUnicos);
				cout << "Que producto desea agregar?" << endl;
				cout << "Porfavor ingrese los datos requeridos" << endl;
				agregarProducto();
				cout << "Producto agregado exitosamente" << endl;
				break;   
			case 4:
                buscarProducto(vectorA, codigosUnicos);
                break;	 
            case 5:
                int codigoProducto;
                cout << "Ingrese el codigo del articulo a eliminar: ";
                cin >> codigoProducto;
                if (eliminarArticulo(codigoProducto, vectorA, codigosUnicos)) {
                    cout << "Articulo eliminado" << endl;
                } else {
                    cout << "Codigo no encontrado" << endl;
                }
                break;
            case 8:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Error... Ingresa una opcion valida" << endl;
        }
    } while (opcion != 8);

    return 0;
}
