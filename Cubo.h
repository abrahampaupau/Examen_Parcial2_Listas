#pragma once
#include "Cuadrado.h" // Incluyo la clase base Cuadrado

using namespace std; 

class Cubo : public Cuadrado // Cubo hereda publicamente de Cuadrado
{
public:
    // Constructor de Cubo. Llama al constructor de Cuadrado.
    Cubo(float l) : Cuadrado(l) {
        this->nombre = "Cubo"; // Actualizo el nombre heredado de Figura.
        cout << "DEBUG: Constructor de Cubo con lado: " << lado << endl;
    }

    // Destructor de Cubo.
    ~Cubo() override {
        cout << "DEBUG: Destructor de Cubo con lado: " << lado << endl;
    }

    // Nueva función para calcular el volumen del cubo.
    float CalcularVolumen() {
        return lado * lado * lado;
    }

    // Nueva función para calcular el área de la superficie del cubo.
    float CalcularSuperficie() {
        return 6 * (lado * lado);
    }
};
