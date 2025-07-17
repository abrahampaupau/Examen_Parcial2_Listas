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
        // Y aqu� pongo mi contador de elementos a cero.
        count_elements = 0;
    }

    // Para meter un valor al "tope" de mi pila.
    void Push(T value);

    // Para sacar el valor que est� en el "tope" de mi pila y devolverlo.
    T Pop();

    // Para ver el valor que est� en el "tope" de mi pila, pero sin sacarlo.
    T Peak();

    // Para saber cu�ntos elementos tengo en mi pila.
    // Uso mi propio contador porque la 'forward_list' no me da un tama�o r�pido.
    int Count() { return count_elements; };

private:
    // Esta es mi lista ligada de la librer�a est�ndar de C++ que uso para guardar los datos.
    std::forward_list<T> internalList;

    // Llevo mi propio contador de elementos.
    // Es importante porque la 'forward_list' no sabe r�pido cu�ntos elementos tiene.
    int count_elements;
};

// IMPLEMENTACIONES DE MIS FUNCIONES DE LSTACK

template <typename T>
void LStack<T>::Push(T value)
{
    // En una pila, siempre metemos los elementos por el "tope".
    // La funci�n 'push_front' de la 'forward_list' hace esto muy r�pido (O(1)).
    internalList.push_front(value);
    count_elements++; // �Un elemento m�s!
}

template <typename T>
T LStack<T>::Pop()
{
    // Primero, reviso si mi pila est� vac�a. Si lo est�, no hay nada que sacar.
    if (count_elements == 0)
    {
        cout << "Advertencia, intentaste sacar elementos pero la pila ya esta vacia." << endl;
        return {}; // Devuelvo un valor vac�o por si acaso.
    }

    // Guardo el valor que est� en el tope de la pila antes de quitarlo.
    // La funci�n 'front()' de la 'forward_list' me da el primer elemento rapid�simo (O(1)).
    T value = internalList.front();

    // Ahora s�, quito el elemento del tope de la pila.
    // La funci�n 'pop_front()' de la 'forward_list' es tambi�n muy r�pida (O(1)).
    internalList.pop_front();
    count_elements--; // �Un elemento menos!

    return value; // Devuelvo el valor que saqu�.
}

template <typename T>
T LStack<T>::Peak()
{
    // Siempre reviso si la pila est� vac�a antes de intentar ver algo.
    if (count_elements == 0)
    {
        cout << "Advertencia, la pila esta vacia. No hay elemento para hacer Peak." << endl;
        return {}; // Devuelvo un valor vac�o.
    }

    // Devuelvo el valor que est� en el tope de la pila, sin sacarlo.
    // La funci�n 'front()' me da el primer elemento rapid�simo (O(1)).
    return internalList.front();
}