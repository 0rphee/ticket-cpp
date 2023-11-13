// Metodos.cpp

#include "Header.h"

Seccion::Seccion() {
    nombreSeccion = "";
    cantidadBoletosDisponibles = 0;
    precioBoleto = 0.0;
    listaBoletosVendidos = nullptr;
}

Seccion::~Seccion() {
    // Agregar lógica de liberación de memoria si es necesario
}

void Seccion::InicializarSeccion(string nombre, int cantidadBoletos, double precioBoleto) {
    nombreSeccion = nombre;
    cantidadBoletosDisponibles = cantidadBoletos;
    this->precioBoleto = precioBoleto;
}

void Seccion::ComprarBoletos(int cantidad, string nombreComprador, int numTarjeta) {
    if (cantidad > 0 && cantidad <= cantidadBoletosDisponibles) {
        Nodo* nuevo = new Nodo();
        nuevo->nombreComprador = nombreComprador;
        nuevo->numTarjeta = numTarjeta;
        nuevo->cantidadBoletos = cantidad;
        nuevo->totalCompra = cantidad * precioBoleto;

        nuevo->sig = listaBoletosVendidos;
        listaBoletosVendidos = nuevo;

        // Actualizar la cantidad de boletos disponibles
        cantidadBoletosDisponibles -= cantidad;

        cout << "\n\tCompra realizada con éxito.\n";
        cout << "\tTotal a pagar: $" << nuevo->totalCompra << "\n";
    } else {
        cout << "\n\tNo hay suficientes boletos disponibles.\n";
    }
}

void Seccion::ConsultarBoletos() {
    cout << "\n\tSección: " << nombreSeccion << "\n";
    cout << "\tBoletos disponibles: " << cantidadBoletosDisponibles << "\n";
    cout << "\tPrecio por boleto: $" << precioBoleto << "\n";
}

Nodo* Seccion::ObtenerListaBoletosVendidos() {
    return listaBoletosVendidos;
}

Evento::Evento() {
    comprasFinalizadas = false;
}

Evento::~Evento() {
    // Agregar lógica de liberación de memoria si es necesario
}

void Evento::MostrarVentaBoletos() {
    seccionGA.ConsultarBoletos();
    seccionGB.ConsultarBoletos();
    seccionVIP.ConsultarBoletos();
}

void Evento::BuscarPorComprador(string nombre) {
    cout << "\nBuscando boletos comprados por: " << nombre << "\n";

    // Obtener las listas de boletos vendidos de cada sección
    Nodo* actualGA = seccionGA.ObtenerListaBoletosVendidos();
    Nodo* actualGB = seccionGB.ObtenerListaBoletosVendidos();
    Nodo* actualVIP = seccionVIP.ObtenerListaBoletosVendidos();

    // Buscar por comprador en cada sección
    bool encontrado = false;

    // Sección General A
    while (actualGA != nullptr) {
        if (actualGA->nombreComprador == nombre) {
            cout << "Boleto encontrado en General A - Número de Tarjeta: " << actualGA->numTarjeta << "\n";
            encontrado = true;
        }
        actualGA = actualGA->sig;
    }

    // Sección General B
    while (actualGB != nullptr) {
        if (actualGB->nombreComprador == nombre) {
            cout << "Boleto encontrado en General B - Número de Tarjeta: " << actualGB->numTarjeta << "\n";
            encontrado = true;
        }
        actualGB = actualGB->sig;
    }

    // Sección VIP  
    while (actualVIP != nullptr) {
        if (actualVIP->nombreComprador == nombre) {
            cout << "Boleto encontrado en VIP - Número de Tarjeta: " << actualVIP->numTarjeta << "\n";
            encontrado = true;
        }
        actualVIP = actualVIP->sig;
    }

    if (!encontrado) {
        cout << "No se encontraron boletos comprados por: " << nombre << "\n";
    }
}

void Evento::BuscarPorSeccion(string seccion) {
    cout << "\nBuscando boletos en la sección: " << seccion << "\n";

    // Determinar la sección y obtener la lista de boletos vendidos
    Seccion* seccionActual = nullptr;
    Nodo* listaBoletosVendidos = nullptr;

    if (seccion == "General A") {
        seccionActual = &seccionGA;
        listaBoletosVendidos = seccionActual->ObtenerListaBoletosVendidos();
    } else if (seccion == "General B") {
        seccionActual = &seccionGB;
        listaBoletosVendidos = seccionActual->ObtenerListaBoletosVendidos();
    } else if (seccion == "VIP") {
        seccionActual = &seccionVIP;
        listaBoletosVendidos = seccionActual->ObtenerListaBoletosVendidos();
    } else {
        cout << "\nSección no válida.\n";
        return;
    }

    // Mostrar la lista de boletos vendidos en la sección especificada
    while (listaBoletosVendidos != nullptr) {
        cout << "Número de Tarjeta: " << listaBoletosVendidos->numTarjeta
             << "\tComprador: " << listaBoletosVendidos->nombreComprador
             << "\tCantidad de Boletos: " << listaBoletosVendidos->cantidadBoletos
             << "\tTotal de Compra: $" << listaBoletosVendidos->totalCompra << "\n";

        listaBoletosVendidos = listaBoletosVendidos->sig;
    }
}