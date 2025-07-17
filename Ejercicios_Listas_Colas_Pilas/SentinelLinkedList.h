#pragma once
#include <iostream>
using namespace std;

template <typename T>
class SentinelLinkedList
{
private:
    template <typename T>
    class Node
    {
    public:
        Node()
        {
            // Ojo, siempre me aseguro de que mis punteros empiecen en null.
            // As� evito problemas raros de memoria.
            prev = nullptr;
            next = nullptr;
        }

        Node(T value)
        {
            data = value;
            // Lo mismo aqu�, �seguridad ante todo con los punteros!
            prev = nullptr;
            next = nullptr;
        }

        T data;
        Node<T>* next;
        Node<T>* prev;
    };

private:
    // Este es mi nodo especial que marca el principio y el final de mi lista.
    Node<T>* NIL;
    // Aqu� llevo la cuenta de cu�ntos elementos tengo en la lista.
    int count;

public:
    SentinelLinkedList()
    {
        count = 0;
        // Al crear la lista, creo mi nodo NIL y lo conecto consigo mismo.
        // As� s� que mi lista est� vac�a al principio.
        NIL = new SentinelLinkedList::Node<T>();
        NIL->next = NIL;
        NIL->prev = NIL;
    }

    // Mi destructor para limpiar la memoria. �Muy importante para no dejar basura!
    ~SentinelLinkedList()
    {
        // Recorro toda la lista para borrar cada nodo.
        Node<T>* current = NIL->next;
        while (current != NIL)
        {
            Node<T>* nextNode = current->next;
            delete current; // Borro el nodo actual.
            current = nextNode; // Paso al siguiente.
        }
        delete NIL; // Al final, borro mi nodo centinela NIL.
        NIL = nullptr; // Y limpio el puntero.
    }

    // Para saber cu�ntos elementos tengo en mi lista.
    int GetCount() { return count; };

    // *** NOTA PARA M� MISMO SOBRE FIND Y FINDV2 ***
    // Estas funciones son un poco raras porque devuelven una "referencia".
    // Si no encuentro algo, no puedo devolver "null" como con un puntero.
    // As� que, por ahora, si no encuentro nada, devuelvo una referencia a mi propio NIL.
    // �Tengo que recordar que esto no es lo ideal para la vida real!
    SentinelLinkedList::Node<T>& Find(T value);
    SentinelLinkedList::Node<T>& FindV2(T value);

    // Esta me da el siguiente nodo en la lista.
    // Ojo: �Necesito desreferenciar el puntero para devolver la referencia!
    SentinelLinkedList::Node<T>& Successor(SentinelLinkedList::Node<T>* node)
    {
        return *node->next;
    }

    // Esta me da el nodo anterior en la lista.
    // Ojo: �Tambi�n necesito desreferenciar el puntero aqu�!
    SentinelLinkedList::Node<T>& Predecessor(SentinelLinkedList::Node<T>* node)
    {
        return *node->prev;
    }

    // Para a�adir un nuevo elemento al final de mi lista.
    void PushBack(T value);

    // Para quitar el �ltimo elemento de mi lista y devolver lo que hab�a ah�.
    T PopBack();

    // Para a�adir un nuevo elemento al principio de mi lista.
    void PushFront(T value);

    // Para quitar el primer elemento de mi lista y devolver lo que hab�a ah�.
    T PopFront();

    // Para meter un nuevo elemento justo despu�s de un nodo que ya conozco.
    void Insert(T valueToInsert, Node<T>* previousNode);

    // Para encontrar un valor y borrar el nodo que lo contiene.
    void Remove(T valueToRemove);

    // Para ver el elemento que est� al principio de mi lista, pero sin quitarlo.
    T Front();

    // No estoy seguro si esta variable 'operationCounter' la usar�, pero ah� est� por si acaso.
    int operationCounter;
};

template<typename T>
void SentinelLinkedList<T>::Remove(T valueToRemove)
{
    // Empiezo a buscar desde el primer elemento real de mi lista (despu�s de NIL).
    Node<T>* currentNode = NIL->next;

    // Recorro la lista nodo por nodo hasta que llego de nuevo a NIL (lo que significa que ya di la vuelta).
    while (currentNode != NIL)
    {
        // Si encuentro el valor que quiero borrar...
        if (currentNode->data == valueToRemove)
        {
            // Conecto el nodo anterior al actual con el nodo siguiente al actual.
            // Pi�nsalo como 'saltarme' el currentNode.
            currentNode->prev->next = currentNode->next;
            // Y hago lo mismo en la otra direcci�n: conecto el siguiente al actual con el anterior al actual.
            currentNode->next->prev = currentNode->prev;

            delete currentNode; // �Borro el nodo de la memoria!
            count--; // Disminuyo mi contador de elementos.
            return; // Ya lo borr�, as� que termino la funci�n.
        }
        else
        {
            // Si no es el valor, sigo buscando en el siguiente nodo.
            currentNode = currentNode->next;
        }
    }
}

template<typename T>
SentinelLinkedList<T>::Node<T>& SentinelLinkedList<T>::Find(T value)
{
    // Empiezo mi b�squeda desde el primer elemento real de la lista.
    Node<T>* currentNode = NIL->next;

    // Recorro la lista hasta que el nodo actual sea NIL (ya busqu� en toda la lista).
    while (currentNode != NIL)
    {
        // Si el dato del nodo actual es el que estoy buscando...
        if (currentNode->data == value)
        {
            // �Lo encontr�! Devuelvo una referencia a ese nodo.
            return *currentNode;
        }
        else
        {
            // Si no, sigo buscando en el siguiente.
            currentNode = currentNode->next;
        }
    }

    // Si llegu� hasta aqu�, significa que no encontr� el valor.
    // Como tengo que devolver una referencia, devuelvo una referencia a mi nodo NIL.
    return *NIL;
}

template<typename T>
SentinelLinkedList<T>::Node<T>& SentinelLinkedList<T>::FindV2(T value)
{
    // Igual que Find, empiezo desde el principio.
    Node<T>* currentNode = NIL->next;

    // Recorro la lista hasta que no haya m�s nodos (llegue a NIL).
    while (currentNode != NIL)
    {
        // Si encuentro el valor, lo devuelvo.
        if (currentNode->data == value)
            return *currentNode;

        // Si no, paso al siguiente nodo.
        currentNode = currentNode->next;
    }

    // Si no lo encuentro, devuelvo NIL (por el tema de las referencias).
    return *NIL;
}

template<typename T>
void SentinelLinkedList<T>::Insert(T valueToInsert, SentinelLinkedList<T>::Node<T>* previousNode)
{
    // Voy a crear un nuevo nodo con el valor que me pasaron.
    Node<T>* newNode = new Node<T>(valueToInsert);

    // �Ojo al orden! Primero conecto mi nuevo nodo con el que va DESPU�S de previousNode.
    newNode->next = previousNode->next;

    // Luego, conecto el nodo anterior (previousNode) con mi nuevo nodo.
    previousNode->next = newNode;

    // Ahora, hago la conexi�n hacia atr�s: el nodo que estaba despu�s de previousNode
    // (que ahora es mi newNode->next) tiene que apuntar hacia atr�s a mi nuevo nodo.
    newNode->next->prev = newNode;

    // Y finalmente, mi nuevo nodo tiene que apuntar hacia atr�s a previousNode.
    newNode->prev = previousNode;

    count++; // �Aumento mi contador de elementos!
}

// Mi funci�n para a�adir algo al final de la lista.
template<typename T>
void SentinelLinkedList<T>::PushBack(T value)
{
    // Creo un nuevo nodo para el valor.
    Node<T>* newNode = new Node<T>(value);
    // El "siguiente" de mi nuevo nodo siempre ser� NIL, porque es el �ltimo.
    newNode->next = NIL;

    // El nodo que antes era el 'prev' de NIL (o sea, el �ltimo real de la lista),
    // ahora su 'next' debe apuntar a mi nuevo nodo.
    NIL->prev->next = newNode;

    // El 'prev' de mi nuevo nodo debe ser el que antes era el �ltimo real de la lista.
    newNode->prev = NIL->prev;
    // Y ahora, el 'prev' de NIL (el centinela) apunta a mi nuevo nodo, porque es el nuevo �ltimo.
    NIL->prev = newNode;

    count++; // �Un elemento m�s para la cuenta!
}

template<typename T>
T SentinelLinkedList<T>::PopBack()
{
    // Primero, me aseguro de que haya elementos. Si la lista est� vac�a...
    if (count == 0)
    {
        cout << "Cuidado, intentaste sacar algo del final de la lista pero ya no hay elementos." << endl;
        return {}; // Devuelvo un valor por defecto.
    }

    // El �ltimo nodo real de mi lista siempre es el 'prev' de NIL.
    Node<T>* lastNode = NIL->prev;

    // Conecto el nodo que est� ANTES del �ltimo con NIL (salt�ndome el lastNode).
    lastNode->prev->next = NIL;
    // Y conecto el 'prev' de NIL al nodo que ahora es el nuevo �ltimo.
    NIL->prev = lastNode->prev;

    // Guardo el dato del nodo que voy a borrar.
    T data = lastNode->data;

    delete lastNode; // �Borrar el nodo de la memoria!
    lastNode = nullptr; // Pongo el puntero a null para no apuntar a nada raro.
    count--; // �Un elemento menos!

    return data; // Devuelvo el dato que saqu�.
}

// Esta es mi funci�n para a�adir al principio de la lista.
template<typename T>
void SentinelLinkedList<T>::PushFront(T value)
{
    // 1. Creo mi nuevo nodo con el valor.
    Node<T>* newNode = new Node<T>(value);

    // 2. El "siguiente" de mi nuevo nodo es el que ahora mismo es el primer nodo (el que NIL->next apunta).
    newNode->next = NIL->next;

    // 3. El "anterior" de mi nuevo nodo es NIL, porque va justo despu�s de NIL.
    newNode->prev = NIL;

    // 4. El nodo que estaba al principio (el que mi newNode->next ahora apunta)
    //    ahora tiene que tener su "anterior" apuntando a mi nuevo nodo.
    //    Esto es clave: si la lista estaba vac�a, newNode->next era NIL.
    //    As� que, NIL->prev se actualizar� para apuntar a mi newNode.
    newNode->next->prev = newNode;

    // 5. Finalmente, el "siguiente" de NIL (el centinela) apunta a mi nuevo nodo,
    //    as� lo convierto en el nuevo primer elemento.
    NIL->next = newNode;

    // 6. Sumo uno a mi contador de elementos.
    count++;
}

// Esta es mi funci�n para quitar del principio de la lista.
template<typename T>
T SentinelLinkedList<T>::PopFront()
{
    // 1. Primero, me aseguro de que haya elementos en la lista.
    if (count == 0)
    {
        cout << "Advertencia: Intentaste sacar algo del principio pero la lista esta vacia." << endl;
        return {}; // Devuelvo un valor por defecto para no romper nada.
    }

    // 2. El nodo que quiero borrar es el primero, el que est� despu�s de NIL.
    Node<T>* nodeToRemove = NIL->next;

    // 3. Actualizo el puntero "next" de NIL para que salte al nodo que estaba despu�s del que voy a borrar.
    NIL->next = nodeToRemove->next;

    // 4. Ahora, el "prev" del nodo que antes estaba despu�s del que borro (mi nuevo primer nodo)
    //    debe apuntar a NIL.
    nodeToRemove->next->prev = NIL;

    // 5. Guardo el dato del nodo que estoy a punto de eliminar.
    T data = nodeToRemove->data;

    // 6. �Lo borro de la memoria!
    delete nodeToRemove;
    nodeToRemove = nullptr; // Lo pongo a null para no apuntar a memoria basura.

    // 7. Resto uno a mi contador de elementos.
    count--;

    // 8. Devuelvo el dato que saqu�.
    return data;
}

template <typename T>
T SentinelLinkedList<T>::Front()
{
    // Me aseguro de que la lista no est� vac�a antes de intentar ver el primer elemento.
    if (count == 0)
    {
        cout << "Advertencia, intentaste ver el primer elemento de la lista, pero esta vacia" << endl;
        return {}; // Devuelvo un valor por defecto.
    }
    // Si hay elementos, devuelvo el dato del primer nodo (el que sigue a NIL).
    return NIL->next->data;
}