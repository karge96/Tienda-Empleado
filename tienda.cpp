#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Estructura del producto
struct Producto {
    string nombre;
    int stock;
    double precio;
    int cantidadVendida;
};

vector<Producto> inventario;

// funcion que agrega el producto
void agregarProducto() {
    Producto nuevoProducto;
    cout << "Ingrese el nombre del producto: ";
    cin >> nuevoProducto.nombre;
    cout << "Ingrese el stock del producto: ";
    cin >> nuevoProducto.stock;
    cout << "Ingrese el precio del producto: ";
    cin >> nuevoProducto.precio;
    nuevoProducto.cantidadVendida = 0; // Inicializamos la cantidad vendida a cero
    inventario.push_back(nuevoProducto);
    cout << "\n Producto agregado correctamente.\n";
}
//funcion que elimina el producto
void eliminarProducto() {
    string nombre;
    cout << "\n Ingrese el nombre del producto a eliminar: ";
    cin >> nombre;
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if (it->nombre == nombre) { //si coincide el nombre se elimina
            inventario.erase(it);
            cout << "\n Producto eliminado correctamente.\n";
            return;
        }
    }
    cout << "\n Producto no encontrado.\n";
}
//actualiza los datos del producto
void actualizarProducto() {
    string nombre;
    cout << "\n Ingrese el nombre del producto a actualizar: ";
    cin >> nombre;
    for (auto& producto : inventario) { //iteramos por producto
        if (producto.nombre == nombre) { //si coincide actualizamos
            int nuevoStock;
            double nuevoPrecio;
            cout << "Ingrese el nuevo stock del producto: ";
            cin >> nuevoStock;
            cout << "Ingrese el nuevo precio del producto: ";
            cin >> nuevoPrecio;
            producto.stock = nuevoStock;
            producto.precio = nuevoPrecio;
            cout << "\n Producto actualizado correctamente.\n";
            return;
        }
    }
    cout << "\n Producto no encontrado.\n";
}
//genera una venta y actualiza los datos
void generarVentaProducto() {
    string nombre;
    int stockVendido;
    cout << "Ingrese el nombre del producto: ";
    cin >> nombre;
    cout << "Ingrese la cantidad a vender del producto: ";
    cin >> stockVendido;
    for (auto& producto : inventario){
        if (producto.nombre == nombre) {
            producto.stock = producto.stock - stockVendido;
            // Calculamos la cantidad vendida sumando el stock anterior y restando el nuevo stock
            producto.cantidadVendida +=  stockVendido;
        }
    }
    cout << "Se han vendido: " << stockVendido << " " << nombre  << endl;
}
//consulta el stock disponible
void consultarStock() {
    cout << "Inventario actual:\n";
    for (const auto& producto : inventario) {
        cout << "Nombre: " << producto.nombre << ", Stock: " << producto.stock << ", Precio: $" << producto.precio << ", Vendido: " << producto.cantidadVendida << endl;
    }
}
//genera el informe de ventas
void generarInformeVentas() {
    double totalVentas = 0.0;
    cout << "Informe de ventas:\n";
    for (const auto& producto : inventario) {
        double ventasProducto = producto.precio * producto.cantidadVendida; // Ventas = precio * cantidad vendida
        totalVentas += ventasProducto;
        cout << "Nombre: " << producto.nombre << ", Ventas: $" << ventasProducto << endl;
    }
    cout << "Total de ventas: $" << totalVentas << endl;
}
//generamos el informe de stock
void generarInformeStock() {
    cout << "Informe de stock:\n";
    for (const auto& producto : inventario) {
        cout << "Nombre: " << producto.nombre << ", Stock: " << producto.stock << ", Vendido: " << producto.cantidadVendida << endl;
    }
}
//muestra el menu disponible
int main() {
    char opcion;
    do {
        cout << "\nMENU:\n";
        cout << "1. Agregar producto\n";
        cout << "2. Eliminar producto\n";
        cout << "3. Actualizar producto\n";
        cout << "4. Consultar inventario\n";
        cout << "5. Generar informe de ventas\n";
        cout << "6. Generar informe de stock\n";
        cout << "7. Generar venta\n";
        cout << "8. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                agregarProducto();
                break;
            case '2':
                eliminarProducto();
                break;
            case '3':
                actualizarProducto();
                break;
            case '4':
                consultarStock();
                break;
            case '5':
                generarInformeVentas();
                break;
            case '6':
                generarInformeStock();
                break;
            case '7':
                generarVentaProducto();
                break;
            case '8':
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida. Por favor, ingrese una opcion valida.\n";
        }
    } while (opcion != '8');

    return 0;
}
