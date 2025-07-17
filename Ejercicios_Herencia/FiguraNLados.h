#pragma once
#include "Figura.h" // Incluyo la clase base Figura

// ¡IMPORTANTE! Agregamos esta línea ANTES de incluir <cmath>
// para que M_PI esté disponible en algunos compiladores como MSVC.
#define _USE_MATH_DEFINES 
#include <cmath>    // Para funciones matemáticas como tan (tangente)

using namespace std; 
// Si M_PI todavía no está definido por alguna razón, lo podemos definir manualmente como fallback.
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

    // Implementación de CalcularArea() para FiguraNLados (polígono regular).
    // Fórmula: Area = (numLados * lado^2) / (4 * tan(PI / numLados))
    float CalcularArea() override {
        if (numLados < 3) return 0.0f; // Un polígono debe tener al menos 3 lados
        return (numLados * longitudLado * longitudLado) / (4 * tan(M_PI / numLados));
    }

    // Implementación de CalcularPerimetro() para FiguraNLados.
    float CalcularPerimetro() override {
        return numLados * longitudLado;
    }
};
