#pragma once
#include "Figura.h" // Incluyo la clase base Figura
#include <numeric>  // Para std::accumulate (para sumar elementos de un array)

using namespace std; 

class Linea : public Figura // Linea hereda publicamente de Figura
{
private:
    float* segmentos; // Puntero al arreglo de segmentos (memoria din�mica).
    int numSegmentos; // Cantidad de segmentos.

public:
    // Constructor de L�nea. Recibe un arreglo de flotantes y su tama�o.
    Linea(const float* arrSegmentos, int size) : Figura("L�nea"), numSegmentos(size) {
        cout << "DEBUG: Constructor de L�nea con " << numSegmentos << " segmentos." << endl;
        segmentos = new float[numSegmentos];
        for (int i = 0; i < numSegmentos; ++i) {
            segmentos[i] = arrSegmentos[i];
        }
    }

    // Destructor de L�nea. �CR�TICO para liberar la memoria din�mica!
    ~Linea() override {
        cout << "DEBUG: Destructor de L�nea con " << numSegmentos << " segmentos." << endl;
        delete[] segmentos;
        segmentos = nullptr;
    }

    // Implementaci�n de CalcularArea() para L�nea.
    float CalcularArea() override {
        return 0.0f;
    }

    // Implementaci�n de CalcularPerimetro() para L�nea (suma de segmentos).
    float CalcularPerimetro() override {
        float perimetroTotal = 0.0f;
        for (int i = 0; i < numSegmentos; ++i) {
            perimetroTotal += segmentos[i];
        }
        return perimetroTotal;
        // Opcional con <numeric>: return accumulate(segmentos, segmentos + numSegmentos, 0.0f);
    }
};
