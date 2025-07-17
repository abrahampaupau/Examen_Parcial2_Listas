#pragma once
#include "Figura.h" // Necesito incluir la clase base Figura
#include <cmath>    // Para M_PI (o definirlo si no est� disponible)

using namespace std; 

// Si M_PI no est� definido en cmath (a veces pasa en Windows o con ciertos est�ndares)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circulo : public Figura // Circulo hereda publicamente de Figura
{
private: // El radio es propio del circulo y no necesita ser accedido por otras clases.
    float radio;

public:
    // Constructor de Circulo. Llama al constructor de Figura.
    Circulo(float r) : Figura("C�rculo"), radio(r) {
        cout << "DEBUG: Constructor de C�rculo con radio: " << radio << endl;
    }

    // Destructor de Circulo.
    ~Circulo() override {
        cout << "DEBUG: Destructor de C�rculo con radio: " << radio << endl;
    }

    // Implementaci�n de CalcularArea() para C�rculo.
    float CalcularArea() override {
        return M_PI * radio * radio;
    }

    // Implementaci�n de CalcularPerimetro() para C�rculo.
    float CalcularPerimetro() override {
        return 2 * M_PI * radio;
    }
};