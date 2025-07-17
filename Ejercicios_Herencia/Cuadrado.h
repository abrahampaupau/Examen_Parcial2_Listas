#pragma once
#include "Figura.h" // Incluyo la clase base Figura

using namespace std; 

class Cuadrado : public Figura // Cuadrado hereda publicamente de Figura
{
protected: // El lado lo hago protected para que Cubo (su hijo) pueda accederlo directamente.
    float lado;

public:
    // Constructor de Cuadrado.
    Cuadrado(float l) : Figura("Cuadrado"), lado(l) {
        cout << "DEBUG: Constructor de Cuadrado con lado: " << lado << endl;
    }

    // Destructor de Cuadrado.
    ~Cuadrado() override {
        cout << "DEBUG: Destructor de Cuadrado con lado: " << lado << endl;
    }

    // Implementación de CalcularArea() para Cuadrado.
    float CalcularArea() override {
        return lado * lado;
    }

    // Implementación de CalcularPerimetro() para Cuadrado.
    float CalcularPerimetro() override {
        return 4 * lado;
    }
};