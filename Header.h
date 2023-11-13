// Header.h

#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Nodo {
    string nombreComprador;
    int numTarjeta;
    int cantidadBoletos;
    double totalCompra;
    Nodo* sig;
};

class Seccion {
public:
    Seccion();
    ~Seccion();

    void InicializarSeccion(string nombre, int cantidadBoletos, double precioBoleto);
    void ComprarBoletos(int cantidad, string nombreComprador, int numTarjeta);
    void ConsultarBoletos();
    Nodo* ObtenerListaBoletosVendidos();  // Nuevo método

private:
    string nombreSeccion;
    int cantidadBoletosDisponibles;
    double precioBoleto;
    Nodo* listaBoletosVendidos;
};

class Evento {
public:
    Evento();
    ~Evento();

    void MostrarVentaBoletos();
    void BuscarPorComprador(string nombre);
    void BuscarPorSeccion(string seccion);

    Seccion seccionGA;
    Seccion seccionGB;
    Seccion seccionVIP;
private:
    bool comprasFinalizadas;
};
