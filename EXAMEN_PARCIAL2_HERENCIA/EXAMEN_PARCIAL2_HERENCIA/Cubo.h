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

    // CORRECION: CalcularArea() para el Cubo (�rea de su superficie total).
    // Un cubo tiene 6 caras, cada una con un �rea de lado * lado.
    float CalcularArea() override {
        return 6 * (lado * lado);
    }

    // CORRECION: CalcularPerimetro() para el Cubo (suma de sus 12 aristas).
    // Un cubo tiene 12 aristas, todas de la misma longitud (lado).
    float CalcularPerimetro() override {
        return 12 * lado;
    }

    // Funci�n para calcular el volumen del cubo (ya exist�a).
    float CalcularVolumen() {
        return lado * lado * lado;
    }

    // Funci�n para calcular el �rea de la superficie del cubo (es lo mismo que CalcularArea() sobrescrito).
    // Se mantiene por si el profesor desea una funci�n expl�cita con ese nombre.
    float CalcularSuperficie() {
        return CalcularArea(); // Reutiliza la l�gica de CalcularArea()
    }
};
