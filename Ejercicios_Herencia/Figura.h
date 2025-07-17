#pragma once
#include <string>   // Necesito esto para usar std::string
#include <iostream> 

using namespace std; 

class Figura
{
protected: // Los hijos pueden acceder a esto, pero fuera de la jerarqu�a no.
    string nombre; // El nombre de la figura (e.g., "C�rculo", "Cuadrado").

public:
    // Constructor de la figura. Recibe el nombre.
    Figura(string name) : nombre(name) {
        cout << "DEBUG: Constructor de Figura: " << nombre << endl;
    }

    // Destructor virtual. �S�per importante en herencia!
    virtual ~Figura() {
        cout << "DEBUG: Destructor de Figura: " << nombre << endl;
    }

    // Funciones virtuales puras. Esto hace a 'Figura' una clase abstracta.
    virtual float CalcularArea() = 0;
    virtual float CalcularPerimetro() = 0;

    // Funci�n normal para obtener el nombre.
    const string& ObtenerNombreDeFigura() {
        return nombre;
    }
};