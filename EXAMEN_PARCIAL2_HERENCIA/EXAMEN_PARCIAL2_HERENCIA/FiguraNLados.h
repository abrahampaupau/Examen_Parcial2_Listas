#pragma once
#include "Figura.h" // Incluyo la clase base Figura

// �IMPORTANTE! Agregamos esta l�nea ANTES de incluir <cmath>
// para que M_PI est� disponible en algunos compiladores como MSVC.
#define _USE_MATH_DEFINES 
#include <cmath>    // Para funciones matem�ticas como tan (tangente)

using namespace std; 
// Si M_PI todav�a no est� definido por alguna raz�n, lo podemos definir manualmente como fallback.
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class FiguraNLados : public Figura // FiguraNLados hereda publicamente de Figura
{
private:
    int numLados;
    float longitudLado;

public:
    // Constructor de FiguraNLados.
    FiguraNLados(int nLados, float lLado)
        : Figura("FiguraN-Lados"), numLados(nLados), longitudLado(lLado) {
        cout << "DEBUG: Constructor de FiguraN-Lados: " << numLados << " lados, " << longitudLado << " de lado." << endl;
    }

    // Destructor de FiguraNLados.
    ~FiguraNLados() override {
        cout << "DEBUG: Destructor de FiguraN-Lados: " << numLados << " lados, " << longitudLado << " de lado." << endl;
    }

    // Implementaci�n de CalcularArea() para FiguraNLados (pol�gono regular).
    // F�rmula: Area = (numLados * lado^2) / (4 * tan(PI / numLados))
    float CalcularArea() override {
        if (numLados < 3) return 0.0f; // Un pol�gono debe tener al menos 3 lados
        return (numLados * longitudLado * longitudLado) / (4 * tan(M_PI / numLados));
    }

    // Implementaci�n de CalcularPerimetro() para FiguraNLados.
    float CalcularPerimetro() override {
        return numLados * longitudLado;
    }
};
