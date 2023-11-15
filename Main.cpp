// Main.cpp

#include "Header.h"

int main()
 {
        Evento evento;
        Nodo boletoComprado;
        int opt, cantBoletos; 
        double precioBoleto;
        string nombre;
        string seccion;
    
        // Initialize the event with the number of tickets and prices for each section, with validations
        // SECCION GENERAL A
        cout << "\nIngrese la informacion de la seccion \"General A\"" << endl;
        do {
            cout << "\tCantidad de boletos: ";
            cin >> cantBoletos;
        } while (cantBoletos < 0);
        do {
            cout << "\tPrecio de cada boleto: ";
            cin >> precioBoleto;
        } while (precioBoleto < 0);
        evento.seccionGA.InicializarSeccion("General A", cantBoletos, precioBoleto);

        // SECCION GENERAL B
        cout << "\nIngrese la informacion de la seccion \"General B\"" << endl;
        do {
            cout << "\tCantidad de boletos: ";
            cin >> cantBoletos;
        } while (cantBoletos < 0);
        do {
            cout << "\tPrecio de cada boleto: ";
            cin >> precioBoleto;
        } while (precioBoleto < 0);
        evento.seccionGB.InicializarSeccion("General B", cantBoletos, precioBoleto);

        // SECCION VIP
        cout << "\nIngrese la informacion de la seccion \"VIP\"" << endl;
        do {
            cout << "\tCantidad de boletos: ";
            cin >> cantBoletos;
        } while (cantBoletos < 0);
        do {
            cout << "\tPrecio de cada boleto: ";
            cin >> precioBoleto;
        } while (precioBoleto < 0);
        evento.seccionVIP.InicializarSeccion("VIP", cantBoletos, precioBoleto);

        // LOOP DE MENÚ PRINCIPAL
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
            // Comprar boletos
            cout << "\nSección de boletos: " << endl;
            cout << "1. General A" << endl;
            cout << "2. General B" << endl;
            cout << "3. VIP" << endl;
            cout << "Ingrese la sección de los boletos a comprar: "; 
            cin >> opt;

            switch (opt)
            {
            case 1:
                // Comprar en Sección A
                cout << "Ingrese la cantidad de boletos que desea comprar: ";
                cin >> boletoComprado.cantidadBoletos;
                cout << "Ingrese su nombre: ";
                cin >> boletoComprado.nombreComprador;
                cout << "Ingrese el número de tarjeta: ";
                cin >> boletoComprado.numTarjeta;
                evento.seccionGA.ComprarBoletos(boletoComprado.cantidadBoletos, boletoComprado.nombreComprador, boletoComprado.numTarjeta);
                break;
            case 2:
                // Comprar en Sección B
                cout << "Ingrese la cantidad de boletos que desea comprar: ";
                cin >> boletoComprado.cantidadBoletos;
                cout << "Ingrese su nombre: ";
                cin >> boletoComprado.nombreComprador;
                cout << "Ingrese el número de tarjeta: ";
                cin >> boletoComprado.numTarjeta;
                evento.seccionGB.ComprarBoletos(boletoComprado.cantidadBoletos, boletoComprado.nombreComprador, boletoComprado.numTarjeta);
                break;
            case 3:
                // Comprar en VIP
                cout << "Ingrese la cantidad de boletos que desea comprar: ";
                cin >> boletoComprado.cantidadBoletos;
                cout << "Ingrese su nombre: ";
                cin >> boletoComprado.nombreComprador;
                cout << "Ingrese el número de tarjeta: ";
                cin >> boletoComprado.numTarjeta;
                evento.seccionVIP.ComprarBoletos(boletoComprado.cantidadBoletos, boletoComprado.nombreComprador, boletoComprado.numTarjeta);
                break;
            default:
                break;
            }
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
