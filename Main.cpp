// Main.cpp

#include "Header.h"

int main()
 {
        Evento evento;
        int opt, cantBoletos;
        double precioBoleto;
        string nombre;
        string seccion;
    
        // Initialize the event with the number of tickets and prices for each section, with validations
        do {
            cout << "Ingrese la cantidad de boletos para la seccion General A: ";
            cin >> cantBoletos;
        } while (cantBoletos < 0);
        do {
            cout << "Ingrese el precio de los boletos para la seccion General A: ";
            cin >> precioBoleto;
        } while (precioBoleto < 0);
        evento.seccionGA.InicializarSeccion("General A", cantBoletos, precioBoleto);

        do {
            cout << "Ingrese la cantidad de boletos para la seccion General B: ";
            cin >> cantBoletos;
        } while (cantBoletos < 0);
        do {
            cout << "Ingrese el precio de los boletos para la seccion General B: ";
            cin >> precioBoleto;
        } while (precioBoleto < 0);
        evento.seccionGB.InicializarSeccion("General B", cantBoletos, precioBoleto);

        do {
            cout << "Ingrese la cantidad de boletos para la seccion VIP: ";
            cin >> cantBoletos;
        } while (cantBoletos < 0);
        do {
            cout << "Ingrese el precio de los boletos para la seccion VIP: ";
            cin >> precioBoleto;
        } while (precioBoleto < 0);
        evento.seccionVIP.InicializarSeccion("VIP", cantBoletos, precioBoleto);

        do {
            cout << endl;
            cout << "Menu Principal" << endl;
            cout << "1. Comprar Boletos" << endl;
            cout << "2. Consultar información de Boletos" << endl;
            cout << "3. Finalizar Compras" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opt;
    
            switch (opt) {
            case 1:
                cout << "** Sin implementar **" << endl;
                break;
            case 2:
                evento.MostrarVentaBoletos();
                break;
            case 3:
                cout << "\nCompras finalizadas, resumen de la venta de boletos" << endl;
                do {
                    cout << "\n\n\t1. Mostrar lista de Ventas" << endl;
                    cout << "\t2. Consultar por Comprador" << endl;
                    cout << "\t3. Consultar por Seccion" << endl;
                    cout << "\t4. Salir de la aplicacion" << endl;
                    cout << "\tIngrese una opcion: ";
                    cin >> opt;

                    switch (opt) {
                    case 1:
                        evento.MostrarVentaBoletos();
                        break;
                    case 2:
                        cout << "Ingrese el nombre del comprador: ";
                        cin >> nombre;
                        evento.BuscarPorComprador(nombre);
                        break;
                    case 3:
                        cout << "Ingrese el nombre de la seccion: ";
                        cin >> seccion;
                        evento.BuscarPorSeccion(seccion);
                        break;
                    case 4:
                        cout << "Gracias por usar el sistema de venta de boletos" << endl;
                        break;
                    default:
                        cout << "** OPCION INVALIDA" << endl;
                        break;
                    }
                } while (opt != 4);
                opt = 3; // TERMINA
                break;
            default:
                cout << "** OPCION INVALIDA **" << endl;
                break;
            }
        } while (opt != 3);
 }
