// Main.cpp

#include "Header.h"

 void main()
 {
        Evento evento;
        Seccion seccionGA;
        Seccion seccionGB;
        Seccion seccionVIP;
        int opt, cantBoletos;
        double precioBoleto;
        string nombre;
        string seccion;
    
        // Initialize the event with the number of tickets and prices for each section, with validations
        do {
            cout << "Ingrese la cantidad de boletos para la seccion General A: ";
            cin >> cantBoletos;
        } while (cantBoletos > 0);
        do {
            cout << "Ingrese el precio de los boletos para la seccion General A: ";
            cin >> precioBoleto;
        } while (precioBoleto > 0);
        seccionGA.InicializarSeccion("General A", cantBoletos, precioBoleto);

        do {
            cout << "Ingrese la cantidad de boletos para la seccion General B: ";
            cin >> cantBoletos;
        } while (cantBoletos > 0);
        do {
            cout << "Ingrese el precio de los boletos para la seccion General B: ";
            cin >> precioBoleto;
        } while (precioBoleto > 0);
        seccionGB.InicializarSeccion("General B", cantBoletos, precioBoleto);

        do {
            cout << "Ingrese la cantidad de boletos para la seccion VIP: ";
            cin >> cantBoletos;
        } while (cantBoletos > 0);
        do {
            cout << "Ingrese el precio de los boletos para la seccion VIP: ";
            cin >> precioBoleto;
        } while (precioBoleto > 0);
        seccionVIP.InicializarSeccion("VIP", cantBoletos, precioBoleto);

        do {
            cout << endl;
            cout << "Menu Principal" << endl;
            cout << "1. Comprar Boletos" << endl;
            cout << "2. Consultar Boletos" << endl;
            cout << "3. Finalizar Compras" << endl;
            cout << "4. Salir" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opt;
    
            switch (opt) {
            case 1:
                evento.MostrarVentaBoletos();
                break;
            case 2:
                cout << endl;
                cout << "1. Consultar por Comprador" << endl;
                cout << "2. Consultar por Seccion" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opt;
    
                switch (opt) {
                case 1:
                    cout << "Ingrese el nombre del comprador: ";
                    cin >> nombre;
                    evento.BuscarPorComprador(nombre);
                    break;
                case 2:
                    cout << "Ingrese el nombre de la seccion: ";
                    cin >> seccion;
                    evento.BuscarPorSeccion(seccion);
                    break;
                default:
                    cout << "Opcion invalida" << endl;
                    break;
                }
                break;
            case 3:
                cout << "Compras finalizadas, resumen de la venta de boletos: " << endl;
                evento.MostrarVentaBoletos();
                break;
            case 4:
                cout << "Gracias por usar el sistema de venta de boletos" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
            }
        } while (opt != 4);
 }