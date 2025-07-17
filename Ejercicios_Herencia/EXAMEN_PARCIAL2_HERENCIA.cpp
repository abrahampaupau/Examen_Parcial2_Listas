#include <iostream>  // Para usar cout, endl, etc.
#include <vector>    // Para usar std::vector, muy útil para manejar punteros a Figuras.
#include <string>    // Necesario para std::string

// Incluyo todas mis clases de figuras.
#include "Figura.h"
#include "Circulo.h"
#include "Cuadrado.h"
#include "FiguraNLados.h"
#include "Cubo.h"
#include "Linea.h"

using namespace std; 

// Función auxiliar para imprimir detalles de una figura.
// Recibe un puntero a Figura para demostrar el polimorfismo.
void ImprimirDetallesFigura(Figura* fig) {
    if (fig == nullptr) {
        cout << "Error: Figura es nula." << endl;
        return;
    }
    cout << "------------------------------------------" << endl;
    cout << "Nombre de la Figura: " << fig->ObtenerNombreDeFigura() << endl;
    cout << "  Área: " << fig->CalcularArea() << endl;
    cout << "  Perímetro: " << fig->CalcularPerimetro() << endl;

    // Usamos dynamic_cast para intentar convertir el puntero a tipos más específicos.
    // Esto es para demostrar funciones únicas de las clases derivadas.
    if (Cubo* cubo = dynamic_cast<Cubo*>(fig)) {
        cout << "  (Es un Cubo)" << endl;
        cout << "  Volumen: " << cubo->CalcularVolumen() << endl;
        cout << "  Área de Superficie: " << cubo->CalcularSuperficie() << endl;
    }
    cout << "------------------------------------------" << endl;
}


int main()
{
    cout << "=== DEMOSTRACION DE HERENCIA Y POLIMORFISMO ===" << endl;
    cout << "------------------------------------------------" << endl;

    // --- Prueba de Circulo ---
    cout << "\n--- Probando Círculo ---" << endl;
    Circulo miCirculo(5.0f); // Creo un objeto Círculo directamente.
    ImprimirDetallesFigura(&miCirculo); // Paso la dirección de mi objeto Circulo.

    // --- Prueba de Cuadrado ---
    cout << "\n--- Probando Cuadrado ---" << endl;
    Cuadrado miCuadrado(4.0f); // Creo un objeto Cuadrado directamente.
    ImprimirDetallesFigura(&miCuadrado);

    // --- Prueba de FiguraNLados (Pentágono regular) ---
    cout << "\n--- Probando FiguraNLados (Pentágono) ---" << endl;
    FiguraNLados miPentagono(5, 6.0f); // Un pentágono de 5 lados, cada lado mide 6.
    ImprimirDetallesFigura(&miPentagono);

    // --- Prueba de Cubo ---
    cout << "\n--- Probando Cubo ---" << endl;
    Cubo miCubo(3.0f); // Un cubo de lado 3.
    ImprimirDetallesFigura(&miCubo); // La función ImprimirDetallesFigura sabrá que es un Cubo.

    // --- Prueba de Línea (¡Puntos extra!) ---
    cout << "\n--- Probando Línea (con puntero a Figura) ---" << endl;
    float segmentosLinea[] = { 2.5f, 3.0f, 1.5f, 4.0f }; // Arreglo de segmentos.
    int numSegmentos = sizeof(segmentosLinea) / sizeof(segmentosLinea[0]); // Calcula el tamaño del arreglo.

    // Creamos la Línea usando un puntero a Figura, como se pide en el ejercicio.
    Figura* miLinea = new Linea(segmentosLinea, numSegmentos);
    ImprimirDetallesFigura(miLinea);
    delete miLinea; // ¡IMPORTANTE! Liberar la memoria de la Línea creada con 'new'.

    // --- Demostración de Polimorfismo con un vector de punteros a Figura ---
    // Esto es muy potente: puedo guardar diferentes tipos de figuras en un mismo contenedor
    // y llamarlos de forma genérica.
    cout << "\n=== Demostración de Polimorfismo con std::vector<Figura*> ===" << endl;
    vector<Figura*> figuras; // Un vector que guarda punteros a Figura.

    // Agrego las figuras al vector.
    figuras.push_back(new Circulo(7.0f));
    figuras.push_back(new Cuadrado(6.0f));
    figuras.push_back(new FiguraNLados(8, 2.0f)); // Octágono
    figuras.push_back(new Cubo(4.0f));
    float otrosSegmentos[] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
    figuras.push_back(new Linea(otrosSegmentos, 5)); // Otra línea

    // Itero sobre el vector y llamo a las funciones de forma polimórfica.
    // Los métodos CalcularArea/CalcularPerimetro correctos se llamarán automáticamente.
    for (Figura* figuraActual : figuras) {
        ImprimirDetallesFigura(figuraActual);
    }

    // ¡MUY IMPORTANTE! Liberar la memoria de todos los objetos creados con 'new'.
    cout << "\n=== Liberando memoria de objetos en el vector ===" << endl;
    for (Figura* figuraActual : figuras) {
        delete figuraActual; // Esto llamará al destructor virtual correcto de cada clase hija.
        figuraActual = nullptr; // Buena práctica para evitar "dangling pointers".
    }
    figuras.clear(); // Limpio el vector de punteros.

    cout << "\n------------------------------------------------" << endl;
    cout << "=== DEMOSTRACION COMPLETADA ===" << endl;

    return 0; // El programa terminó exitosamente.
}