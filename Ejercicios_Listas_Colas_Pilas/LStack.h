#pragma once
#pragma once
#include <iostream>
#include <forward_list> // Necesitamos incluir esta librer�a para usar std::forward_list

using namespace std;



template <typename T>
class LStack
{
public:
    // Constructor de la pila.
    LStack()
    {
        // std::forward_list se inicializa por defecto. No necesitamos hacer nada aqu�.
        // count_elements la usaremos para llevar un conteo de los elementos,
        // ya que forward_list no tiene un .size() en O(1) o .GetCount() como nuestra SentinelLinkedList.
        count_elements = 0;
    }

    // A�ade el valor 'value' al tope de la pila.
    void Push(T value);

    // Quita el elemento del tope de la pila y regresa su valor T.
    T Pop();

    // Regresa el elemento del tope de la pila, pero sin sacarlo. Tambi�n conocido como Top.
    T Peak();

    // Regresa cu�ntos elementos tiene la pila.
    // Aunque forward_list no tiene un size() O(1), mantendremos nuestro propio contador.
    int Count() { return count_elements; };

private:
    // Usamos std::forward_list para almacenar los elementos de la pila.
    std::forward_list<T> internalList;

    // Llevaremos un contador manual, ya que std::forward_list no tiene un m�todo .size()
    // que sea O(1). Su .size() es O(N). Para mantener Count() en O(1), lo gestionamos nosotros.
    int count_elements;
};

// IMPLEMENTACIONES DE LAS FUNCIONES RESTANTES

template <typename T>
void LStack<T>::Push(T value)
{
    // Las pilas a�aden elementos por el "frente" de la lista enlazada (tope de la pila).
    // std::forward_list::push_front() es una operaci�n O(1).
    internalList.push_front(value);
    count_elements++; // Incrementamos nuestro contador.
}

template <typename T>
T LStack<T>::Pop()
{
    // Primero, verificamos si la pila est� vac�a para evitar errores.
    if (count_elements == 0) // Usamos nuestro contador para verificar si est� vac�a.
    {
        cout << "Advertencia, intent� sacar m�s elementos esta Stack ya est� vac�a." << endl;
        return {}; // Devuelve un valor por defecto si la pila est� vac�a.
    }

    // Obtenemos el valor del elemento en el tope antes de eliminarlo.
    // std::forward_list::front() es una operaci�n O(1).
    T value = internalList.front();

    // Quitamos el elemento del tope de la pila.
    // std::forward_list::pop_front() es una operaci�n O(1).
    internalList.pop_front();
    count_elements--; // Decrementamos nuestro contador.

    return value;
}

template <typename T>
T LStack<T>::Peak()
{
    // Primero, verificamos si la pila est� vac�a.
    if (count_elements == 0) // Usamos nuestro contador para verificar si est� vac�a.
    {
        cout << "Advertencia, esta Stack ya est� vac�a. No hay elemento para hacer Peak" << endl;
        return {}; // Devuelve un valor por defecto si la pila est� vac�a.
    }

    // Obtenemos el valor del elemento en el tope sin eliminarlo.
    // std::forward_list::front() es una operaci�n O(1).
    return internalList.front();
}