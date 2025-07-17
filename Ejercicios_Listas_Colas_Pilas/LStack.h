#pragma once
#include <iostream>
#include <forward_list> // Necesito esta para usar la lista ligada de C++ (std::forward_list).

using namespace std;

template <typename T>
class LStack
{
public:
    // Este es mi constructor para la pila.
    LStack()
    {
        // Mi 'internalList' (que es una std::forward_list) se inicializa sola.
        // Y aquí pongo mi contador de elementos a cero.
        count_elements = 0;
    }

    // Para meter un valor al "tope" de mi pila.
    void Push(T value);

    // Para sacar el valor que está en el "tope" de mi pila y devolverlo.
    T Pop();

    // Para ver el valor que está en el "tope" de mi pila, pero sin sacarlo.
    T Peak();

    // Para saber cuántos elementos tengo en mi pila.
    // Uso mi propio contador porque la 'forward_list' no me da un tamaño rápido.
    int Count() { return count_elements; };

private:
    // Esta es mi lista ligada de la librería estándar de C++ que uso para guardar los datos.
    std::forward_list<T> internalList;

    // Llevo mi propio contador de elementos.
    // Es importante porque la 'forward_list' no sabe rápido cuántos elementos tiene.
    int count_elements;
};

// IMPLEMENTACIONES DE MIS FUNCIONES DE LSTACK

template <typename T>
void LStack<T>::Push(T value)
{
    // En una pila, siempre metemos los elementos por el "tope".
    // La función 'push_front' de la 'forward_list' hace esto muy rápido (O(1)).
    internalList.push_front(value);
    count_elements++; // ¡Un elemento más!
}

template <typename T>
T LStack<T>::Pop()
{
    // Primero, reviso si mi pila está vacía. Si lo está, no hay nada que sacar.
    if (count_elements == 0)
    {
        cout << "Advertencia, intentaste sacar elementos pero la pila ya esta vacia." << endl;
        return {}; // Devuelvo un valor vacío por si acaso.
    }

    // Guardo el valor que está en el tope de la pila antes de quitarlo.
    // La función 'front()' de la 'forward_list' me da el primer elemento rapidísimo (O(1)).
    T value = internalList.front();

    // Ahora sí, quito el elemento del tope de la pila.
    // La función 'pop_front()' de la 'forward_list' es también muy rápida (O(1)).
    internalList.pop_front();
    count_elements--; // ¡Un elemento menos!

    return value; // Devuelvo el valor que saqué.
}

template <typename T>
T LStack<T>::Peak()
{
    // Siempre reviso si la pila está vacía antes de intentar ver algo.
    if (count_elements == 0)
    {
        cout << "Advertencia, la pila esta vacia. No hay elemento para hacer Peak." << endl;
        return {}; // Devuelvo un valor vacío.
    }

    // Devuelvo el valor que está en el tope de la pila, sin sacarlo.
    // La función 'front()' me da el primer elemento rapidísimo (O(1)).
    return internalList.front();
}