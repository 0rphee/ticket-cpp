// Header.h

#pragma once
#include <iostream>
#include <string>

using namespace std;

struct InfoBoleto {
  string nombreComprador;
  int numTarjeta;
  int cantidadBoletos;
  double totalCompra;
  string seccion;

  bool operator==(const InfoBoleto &other) const {
    return nombreComprador == other.nombreComprador;
  }

  bool operator!=(const InfoBoleto &other) const {
    return nombreComprador != other.nombreComprador;
  }
};

struct Nodo {
  InfoBoleto dato;
  Nodo *sig;
};

class ListaLigada {

public:
  ListaLigada();
  ~ListaLigada();

  void InsertarInicio(InfoBoleto);
  int InsertarInter(string, InfoBoleto);
  int InsertarFinal(InfoBoleto);

  InfoBoleto ExtraerInicio();
  InfoBoleto ExtraerIntermedio(string);
  InfoBoleto ExtraerFinal();

  ListaLigada BuscarPorComprador(string);

  void CopiarDatosASegundaLista(ListaLigada &segundaLista);

  void Mostrar();

private:
  int cantCompras;
  Nodo *cabecera, *final;

protected:
};

void mostrarValor(InfoBoleto);

class Seccion {
public:
  Seccion();
  ~Seccion();

  void InicializarSeccion(string nombre, int cantidadBoletos,
                          double precioBoleto);
  void ComprarBoletos(int cantidad, string nombreComprador, int numTarjeta);
  void ConsultarInfoBoletos();
  ListaLigada listaBoletosVendidos;

private:
  string nombreSeccion;
  int cantidadBoletosDisponibles;
  double precioBoleto;
};

class Evento {
public:
  Evento();
  ~Evento();

  void MostrarVentaBoletos();
  void BuscarPorComprador(string nombre);
  void BuscarPorSeccion(string seccion);
  void CopiarDatosSeccionesAListaCompleta(); /* Extraer compradores de todas las
                                                secciones */
  void MostrarCompradores();                 /* Mostrar lista completa */

  Seccion seccionGA;
  Seccion seccionGB;
  Seccion seccionVIP;
  ListaLigada
      listaCompletaDeVentaBoletos; /* Agregar lista con todos los compradores */
private:
};
