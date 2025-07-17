#pragma once
#include "SentinelLinkedList.h" // ¡Necesito mi SentinelLinkedList para que funcione esto!
#include <iostream>
using namespace std;

template <typename T>
class LQueue
{
private:
    // Esta es mi lista ligada centinela, la usaré para guardar los elementos de mi cola.
    SentinelLinkedList<T> data;

public:
    // Este es mi constructor de la cola.
    LQueue()
    {
        // Mi "data" (que es una SentinelLinkedList) se inicializa sola, ¡qué bueno!
    }

    // Quiero saber cuántos elementos hay en mi cola.
    // Simplemente le pregunto a mi lista interna.
    int GetCount();

    // Para añadir un valor al final de mi cola.
    void Enqueue(T value);

    // Para quitar el primer elemento de mi cola y devolverlo.
    T Dequeue();

    // Para ver el primer elemento de mi cola, pero sin quitarlo.
    T Front();
};

// IMPLEMENTACIONES DE MIS FUNCIONES DE LQUEUE

template <typename T>
int LQueue<T>::GetCount()
{
    // Le pido a mi lista interna (data) que me diga cuántos elementos tiene.
    return data.GetCount();
}

template <typename T>
void LQueue<T>::Enqueue(T value)
{
    // En una cola, los elementos nuevos siempre van al final.
    // Mi SentinelLinkedList tiene un "PushBack" que es perfecto y rápido (O(1)).
    data.PushBack(value);
}

template <typename T>
T LQueue<T>::Dequeue()
{
    // En una cola, los elementos se quitan por el principio.
    // Mi SentinelLinkedList tiene un "PopFront" que hace esto rapidísimo (O(1)).
    // La buena noticia es que PopFront ya maneja si la lista está vacía y me avisa.
    return data.PopFront();
}

template <typename T>
T LQueue<T>::Front()
{
    // Quiero ver el elemento que está al principio de mi cola, sin quitarlo.
    // La función Front de mi SentinelLinkedList hace esto por mí y también maneja si está vacía.
    return data.Front();
}
