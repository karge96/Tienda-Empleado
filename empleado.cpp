#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Empleado {
    string nombre;
    double salarioPorHora;
    int horasTrabajadas;
    double salarioBruto;
    double impuesto;
    double seguroSocial;
    double deducciones;
    double salarioNeto;
};

vector<Empleado> nomina;

// Función para calcular el salario bruto
double calcularSalarioBruto(double salarioPorHora, int horasTrabajadas) {
    return (salarioPorHora * (horasTrabajadas * 4)); // Suponiendo un mes de 4 semanas
}

// Función para calcular las deducciones
void calcularDeducciones(Empleado &empleado) {
    const double IMPUESTO = 0.10; // 10% de impuestos
    const double SEGURO_SOCIAL = 0.07; // 7% de seguro social
    empleado.impuesto = empleado.salarioBruto * IMPUESTO;
    empleado.seguroSocial = empleado.salarioBruto * SEGURO_SOCIAL;
    empleado.deducciones = empleado.impuesto + empleado.seguroSocial;
}

// Función para calcular el salario neto
double calcularSalarioNeto(double salarioBruto, double deducciones) {
    return salarioBruto - deducciones;
}

// Función para ingresar los datos de los empleados
void ingresarDatosEmpleado() {
    Empleado nuevoEmpleado;
    cout << "Ingrese el nombre del empleado: ";
    cin >> nuevoEmpleado.nombre;
    cout << "Ingrese el salario por hora del empleado: ";
    cin >> nuevoEmpleado.salarioPorHora;

    bool horasValidas = false;
    do {
        cout << "Ingrese las horas semanales trabajadas por el empleado: ";
        cin >> nuevoEmpleado.horasTrabajadas;
        if (1 <= nuevoEmpleado.horasTrabajadas && nuevoEmpleado.horasTrabajadas <= 45) {
            horasValidas = true;
        } else {
            cout << "Error: Las horas trabajadas deben estar entre 1 y 45.\n";
        }
    } while (!horasValidas);

    nuevoEmpleado.salarioBruto = calcularSalarioBruto(nuevoEmpleado.salarioPorHora, nuevoEmpleado.horasTrabajadas);
    calcularDeducciones(nuevoEmpleado);
    nuevoEmpleado.salarioNeto = calcularSalarioNeto(nuevoEmpleado.salarioBruto, nuevoEmpleado.deducciones);

    nomina.push_back(nuevoEmpleado);
    cout << "\nEmpleado agregado correctamente.\n";
}

// Función para mostrar el salario bruto, deducciones y salario neto
void mostrarSalarioYDeducciones() {
    cout << fixed << setprecision(2); // Formatear los valores a dos decimales
    for (const auto& empleado : nomina) {
        cout << "\nNombre: " << empleado.nombre << endl;
        cout << "Salario bruto: $" << empleado.salarioBruto << endl;
        cout << "Deducciones detalladas:\n";
        cout << "  - Impuesto (10%): $" << empleado.impuesto << endl;
        cout << "  - Seguro Social (7%): $" << empleado.seguroSocial << endl;
        cout << "Total deducciones: $" << empleado.deducciones << endl;
        cout << "Salario neto: $" << empleado.salarioNeto << endl;
        cout << "-----------------------------\n";
    }
}

// Función para generar recibos de pago
void generarRecibosDePago() {
    cout << fixed << setprecision(2); // Formatear los valores a dos decimales
    cout << "\nRecibos de pago:\n";
    for (const auto& empleado : nomina) {
        cout << "\nNombre: " << empleado.nombre << endl;
        cout << "Salario por hora: $" << empleado.salarioPorHora << endl;
        cout << "Horas trabajadas por semana: " << empleado.horasTrabajadas << endl;
        cout << "Salario bruto: $" << empleado.salarioBruto << endl;
        cout << "Total deducciones: $" << empleado.deducciones << endl;
        cout << "Salario neto: $" << empleado.salarioNeto << endl;
        cout << "-----------------------------\n";
    }
}

// Función para mostrar la nómina de empleados
void mostrarNomina() {
    cout << "\nNomina de empleados:\n";
    for (const auto& empleado : nomina) {
        cout << "Nombre: " << empleado.nombre << ", Horas trabajadas: " << empleado.horasTrabajadas << endl;
    }
}

int main() {
    char opcion;
    do {
        cout << "\nMENU:\n";
        cout << "1. Ingresar datos de empleado\n";
        cout << "2. Mostrar nomina de empleados\n";
        cout << "3. Mostrar detalles de sueldo\n";
        cout << "4. Generar recibos de pago\n";
        cout << "5. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                ingresarDatosEmpleado();
                break;
            case '2':
                mostrarNomina();
                break;
            case '3':
                mostrarSalarioYDeducciones();
                break;
            case '4':
                generarRecibosDePago();
                break;
            case '5':
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida. Por favor, ingrese una opcion valida.\n";
        }
    } while (opcion != '5');

    return 0;
}
