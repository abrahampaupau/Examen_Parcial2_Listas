#pragma once
#include <string>   // Necesito esto para usar std::string
#include <iostream> 

using namespace std; 

class Figura
{
protected: // Los hijos pueden acceder a esto, pero fuera de la jerarquía no.
    string nombre; // El nombre de la figura (e.g., "Círculo", "Cuadrado").

public:
    // Constructor de la figura. Recibe el nombre.
    Figura(string name) : nombre(name) {
        cout << "DEBUG: Constructor de Figura: " << nombre << endl;
    }

    // Destructor virtual. ¡Súper importante en herencia!
    virtual ~Figura() {
        cout << "DEBUG: Destructor de Figura: " << nombre << endl;
    }

    // Funciones virtuales puras. Esto hace a 'Figura' una clase abstracta.
    virtual float CalcularArea() = 0;
    virtual float CalcularPerimetro() = 0;

    // Función normal para obtener el nombre.
    const string& ObtenerNombreDeFigura() {
        return nombre;
    }
};