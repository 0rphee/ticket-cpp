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
    string seccion;
    Nodo* sig;
};

class Seccion {
public:
    Seccion();
    ~Seccion();

    void InicializarSeccion(string nombre, int cantidadBoletos, double precioBoleto);
    void ComprarBoletos(int cantidad, string nombreComprador, int numTarjeta);
    void InsertarListaCompradores(Nodo*, string); /* Insertar compradores a una lista */
    void ConsultarBoletos();
    Nodo* ObtenerListaBoletosVendidos();  // Nuevo método

private:
    string nombreSeccion;
    int cantidadBoletosDisponibles;
    double precioBoleto;
    Nodo* listaBoletosVendidos, *sig;
};

class Evento {
public:
    Evento();
    ~Evento();

    void MostrarVentaBoletos();
    void BuscarPorComprador(string nombre);
    void BuscarPorSeccion(string seccion);
    void ExtraerDatosSecciones(); /* Extraer compradores de todas las secciones */
    void MostrarCompradores(); /* Mostrar lista completa */

    Seccion seccionGA;
    Seccion seccionGB;
    Seccion seccionVIP;
    Seccion listaCompleta; /* Agregar lista con todos los compradores */
private:
    bool comprasFinalizadas;
};
