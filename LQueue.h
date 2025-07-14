#pragma once
#include "SentinelLinkedList.h" // �Importante incluir SentinelLinkedList.h!
#include <iostream>
using namespace std;

template <typename T>
class LQueue
{
private:
    // Se especific� que el miembro se llame 'data'.
    SentinelLinkedList<T> data;

public:
    // Constructor de la cola.
    LQueue()
    {
        // La SentinelLinkedList 'data' se inicializa por defecto al ser un miembro.
        // No necesitamos hacer nada especial aqu�.
    }

    // Cu�ntos elementos tiene esta LQueue. Delega en el GetCount de SentinelLinkedList.
    int GetCount();

    // A�ade el valor 'value' al final de la fila.
    // Deber� ser O(1) usando PushBack de SentinelLinkedList.
    void Enqueue(T value);

    // Quita el primer elemento de la fila y regresa su valor T.
    // Deber� ser O(1) usando PopFront de SentinelLinkedList.
    T Dequeue();

    // Regresa una copia de la data del nodo del frente, pero sin sacarlo de la lista.
    T Front(); // Funci�n Front a�adida, delegar� en data.Front()

};

// IMPLEMENTACIONES DE LAS FUNCIONES RESTANTES

template <typename T>
int LQueue<T>::GetCount()
{
    // Simplemente delegamos la llamada a la funci�n GetCount de nuestra lista ligada interna.
    return data.GetCount();
}

template <typename T>
void LQueue<T>::Enqueue(T value)
{
    // En una cola, los elementos se a�aden por el final.
    // Usamos PushBack de SentinelLinkedList, que es O(1).
    data.PushBack(value);
}

template <typename T>
T LQueue<T>::Dequeue()
{
    // En una cola, los elementos se quitan por el principio.
    // Usamos PopFront de SentinelLinkedList, que es O(1).
    // PopFront ya maneja el caso de lista vac�a y devuelve un valor por defecto.
    return data.PopFront();
}

template <typename T>
T LQueue<T>::Front()
{
    // Regresa el elemento del frente sin quitarlo.
    // Usamos Front de SentinelLinkedList, que es O(1).
    // SentinelLinkedList::Front() ya maneja el caso de lista vac�a.
    return data.Front();
}
