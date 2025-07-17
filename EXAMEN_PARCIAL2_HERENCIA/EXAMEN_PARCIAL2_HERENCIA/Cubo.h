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

    // CORRECION: CalcularArea() para el Cubo (área de su superficie total).
    // Un cubo tiene 6 caras, cada una con un área de lado * lado.
    float CalcularArea() override {
        return 6 * (lado * lado);
    }

    // CORRECION: CalcularPerimetro() para el Cubo (suma de sus 12 aristas).
    // Un cubo tiene 12 aristas, todas de la misma longitud (lado).
    float CalcularPerimetro() override {
        return 12 * lado;
    }

    // Función para calcular el volumen del cubo (ya existía).
    float CalcularVolumen() {
        return lado * lado * lado;
    }

    // Función para calcular el área de la superficie del cubo (es lo mismo que CalcularArea() sobrescrito).
    // Se mantiene por si el profesor desea una función explícita con ese nombre.
    float CalcularSuperficie() {
        return CalcularArea(); // Reutiliza la lógica de CalcularArea()
    }
};
