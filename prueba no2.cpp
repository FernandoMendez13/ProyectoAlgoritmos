//prueba no2
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <iomanip>
#include <string>
using namespace std;

struct Producto {
    char codigo[20];
    char nombre[50];
    int cantidad;
    double precio;
    char fechaIngreso[11];
};

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
const int MAX_PRODUCTOS = 100;
Producto inventario[MAX_PRODUCTOS];
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
	if(numProductos >= MAX_PRODUCTOS) {
        cout << "El inventario está lleno.\n";
        return;
    }
	Producto p;
	cout << "Ingresa el codigo del producto: " <<endl;
	cin >> p.codigo;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Ingresa el nombre del producto: " <<endl;
	cin >> p.nombre;
	cin.getline(p.nombre, 50);
	cout << "Ingresa la cantidad del producto: " <<endl;
	cin >> p.cantidad;
	cout << "Ingresa el precio del producto: " <<endl;
	cin >> p.precio;
	cout << "Ingresa la fecha del producto: " <<endl;
	cin >> p.fechaIngreso;
	inventario[numProductos] = p;
	numProductos++;
	

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

