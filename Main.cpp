// Main.cpp

#include "Header.h"
#include <string>

int pedirInt(string prompt) {
  int retorno;
  do {
    cout << prompt;
    cin >> retorno;
  } while (retorno < 0);
  return retorno;
}

int main() {
  Evento evento;
  InfoBoleto boletoComprado;
  int opt, cantBoletos;
  double precioBoleto;
  string nombre;
  string seccion;

  // Initialize the event with the number of tickets and prices for each
  // section, with validations SECCION GENERAL A
  cout << "\nIngrese la informacion de la seccion \"General A\"" << endl;
  cantBoletos = pedirInt("\tCantidad de boletos: ");
  precioBoleto = pedirInt("\tPrecio de cada boleto: ");
  evento.seccionGA.InicializarSeccion("General A", cantBoletos, precioBoleto);

  // SECCION GENERAL B
  cout << "\nIngrese la informacion de la seccion \"General B\"" << endl;
  cantBoletos = pedirInt("\tCantidad de boletos: ");
  precioBoleto = pedirInt("\tPrecio de cada boleto: ");
  evento.seccionGB.InicializarSeccion("General B", cantBoletos, precioBoleto);

  // SECCION VIP
  cout << "\nIngrese la informacion de la seccion \"VIP\"" << endl;
  cantBoletos = pedirInt("\tCantidad de boletos: ");
  precioBoleto = pedirInt("\tPrecio de cada boleto: ");
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

      switch (opt) {
      case 1:
        // Comprar en Sección A
        cout << "Ingrese la cantidad de boletos que desea comprar: ";
        cin >> boletoComprado.cantidadBoletos;
        cout << "Ingrese su nombre: ";
        cin >> boletoComprado.nombreComprador;
        cout << "Ingrese el número de tarjeta: ";
        cin >> boletoComprado.numTarjeta;
        boletoComprado.seccion = "General A";
        evento.seccionGA.ComprarBoletos(boletoComprado.cantidadBoletos,
                                        boletoComprado.nombreComprador,
                                        boletoComprado.numTarjeta);
        break;
      case 2:
        // Comprar en Sección B
        cout << "Ingrese la cantidad de boletos que desea comprar: ";
        cin >> boletoComprado.cantidadBoletos;
        cout << "Ingrese su nombre: ";
        cin >> boletoComprado.nombreComprador;
        cout << "Ingrese el número de tarjeta: ";
        cin >> boletoComprado.numTarjeta;
        evento.seccionGB.ComprarBoletos(boletoComprado.cantidadBoletos,
                                        boletoComprado.nombreComprador,
                                        boletoComprado.numTarjeta);
        break;
      case 3:
        // Comprar en VIP
        cout << "Ingrese la cantidad de boletos que desea comprar: ";
        cin >> boletoComprado.cantidadBoletos;
        cout << "Ingrese su nombre: ";
        cin >> boletoComprado.nombreComprador;
        cout << "Ingrese el número de tarjeta: ";
        cin >> boletoComprado.numTarjeta;
        evento.seccionVIP.ComprarBoletos(boletoComprado.cantidadBoletos,
                                         boletoComprado.nombreComprador,
                                         boletoComprado.numTarjeta);
        break;
      default:
        cout << "** OPCION INVALIDA" << endl;
        break;
      }
      opt = 1;
      break;
    case 2:
      evento.MostrarVentaBoletos(true);
      break;
    case 3:
      /* Extraer compradores */
      evento.CopiarDatosSeccionesAListaCompleta();
      cout << "\nCompras finalizadas, resumen de la venta de boletos" << endl;
      do {
        cout << "\n\n"
             << "\t1. Mostrar lista de Ventas" << endl
             << "\t2. Consultar por Comprador" << endl
             << "\t3. Consultar por Seccion" << endl

             << "\t4. Mostrar estadísticas de venta por sección" << endl
             << "\t5. Mostrar estadísticas de venta totales" << endl
             << "\t6. Mostrar boletos sobrantes" << endl

             << "\t7. Salir de la aplicacion" << endl
             << "\tIngrese una opcion: ";
        cin >> opt;
        cout << "\n";

        switch (opt) {
        case 1:
          /* Mostrar lista de compradores */
          evento.MostrarCompradores();
          break;
        case 2:
          cout << "Ingrese el nombre del comprador: ";
          cin >> nombre;
          evento.BuscarPorComprador(nombre);
          break;
        case 3:
          cin.ignore();
          cout << "Ingrese el nombre de la seccion: ";
          getline(cin, seccion, '\n');
          // cin >> seccion;
          evento.BuscarPorSeccion(seccion);
          break;
        case 4: // Mostrar estadisticas por seccion
          evento.seccionGA.MostrarInformacionDeSeccion();
          evento.seccionGB.MostrarInformacionDeSeccion();
          evento.seccionVIP.MostrarInformacionDeSeccion();
          break;
        case 5: // Mostrar estadísticas totales
          cout << "\tEn total, para todo el evento:" << endl
               << "\t\tSe compraron en promedio: "
               << evento.listaCompletaDeVentaBoletos
                      .CalcularPromedioDeBoletosComprados()
               << " boletos por compra" << endl
               << "\t\tPor compra se gastó en promedio: $"
               << evento.listaCompletaDeVentaBoletos.CalcularPromedioDeCosto()
               << endl
               << "\t\tSe vendieron en esta seccion: "
               << evento.listaCompletaDeVentaBoletos
                      .CalcularSumaCantidadDeBoletosComprados()
               << " boletos" << endl;
          break;
        case 6: // Mostrar Boletos sobrantes
          cout << "Boletos sobrantes:" << endl;
          evento.MostrarVentaBoletos(false);
          break;
        case 7: // FIN DE LA APLICACION
          cout << "\n\n"
               << "** FIN DE LA APLICACION **" << endl
               << "Gracias por usar el sistema de venta de boletos" << endl;
          break;
        default:
          cout << "** OPCION INVALIDA" << endl;
          break;
        }
      } while (opt != 7);
      opt = 3; // TERMINA PROGRAMA
      break;
    default:
      cout << "** OPCION INVALIDA **" << endl;
      break;
    }
  } while (opt != 3);
}
