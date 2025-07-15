#pragma once
#include "Figura.h" // Incluyo la clase base Figura
#include <numeric>  // Para std::accumulate (para sumar elementos de un array)

using namespace std; 

class Linea : public Figura // Linea hereda publicamente de Figura
{
private:
    float* segmentos; // Puntero al arreglo de segmentos (memoria dinámica).
    int numSegmentos; // Cantidad de segmentos.

public:
    // Constructor de Línea. Recibe un arreglo de flotantes y su tamaño.
    Linea(const float* arrSegmentos, int size) : Figura("Línea"), numSegmentos(size) {
        cout << "DEBUG: Constructor de Línea con " << numSegmentos << " segmentos." << endl;
        segmentos = new float[numSegmentos];
        for (int i = 0; i < numSegmentos; ++i) {
            segmentos[i] = arrSegmentos[i];
        }
    }

    // Destructor de Línea. ¡CRÍTICO para liberar la memoria dinámica!
    ~Linea() override {
        cout << "DEBUG: Destructor de Línea con " << numSegmentos << " segmentos." << endl;
        delete[] segmentos;
        segmentos = nullptr;
    }

    // Implementación de CalcularArea() para Línea.
    float CalcularArea() override {
        return 0.0f;
    }

    // Implementación de CalcularPerimetro() para Línea (suma de segmentos).
    float CalcularPerimetro() override {
        float perimetroTotal = 0.0f;
        for (int i = 0; i < numSegmentos; ++i) {
            perimetroTotal += segmentos[i];
        }
        return perimetroTotal;
        // Opcional con <numeric>: return accumulate(segmentos, segmentos + numSegmentos, 0.0f);
    }
};
