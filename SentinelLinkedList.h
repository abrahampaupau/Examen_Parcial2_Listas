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
            // Se podr�a lograr implementar sin tenerlo aqu�, y (en teor�a) podr�as ganar
            // una cantidad peque�a peque��sima de performance, pero como esto es did�ctico,
            // les va a ayudar a evitar unos cuantos problemillas.
            prev = nullptr;
            next = nullptr;
        }

        Node(T value)
        {
            data = value;
            // Se podr�a lograr implementar sin tenerlo aqu�, y (en teor�a) podr�as ganar
            // una cantidad peque�a peque��sima de performance, pero como esto es did�ctico,
            // les va a ayudar a evitar unos cuantos problemillas.
            prev = nullptr;
            next = nullptr;
        }

        T data;
        Node<T>* next;
        Node<T>* prev;
    };

private:
    Node<T>* NIL; // un puntero al primer y �ltimo nodo de nuestra lista ligada.
    int count; // n�mero de elementos en esta lista ligada.

public:
    SentinelLinkedList()
    {
        count = 0;
        NIL = new SentinelLinkedList::Node<T>(); // S� lo tenemos que inicializar al construir la lista.
        NIL->next = NIL;
        NIL->prev = NIL;
    }

    // Destructor (es buena pr�ctica incluirlo para liberar memoria)
    ~SentinelLinkedList()
    {
        // Limpiar todos los nodos para evitar fugas de memoria
        Node<T>* current = NIL->next;
        while (current != NIL)
        {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete NIL; // Finalmente, eliminar el nodo centinela
        NIL = nullptr;
    }

    int GetCount() { return count; };

    // *** NOTA SOBRE FIND Y FINDV2 ***
    // Estas funciones devuelven una referencia (`Node<T>&`). Si un elemento no se encuentra,
    // devolver `nullptr` no es posible con una referencia. Para que el c�digo compile
    // manteniendo la firma original, se devuelve `*NIL` en caso de no encontrar el valor.
    // Esto es una soluci�n para el contexto did�ctico y de compilaci�n, pero en un
    // escenario real, preferir�as que estas funciones devolvieran un puntero (`Node<T>*`)
    // para poder retornar `nullptr` cuando no se encuentra, o lanzar una excepci�n.
    SentinelLinkedList::Node<T>& Find(T value);
    SentinelLinkedList::Node<T>& FindV2(T value);

    // Se devuelve una referencia al nodo siguiente/previo.
    // Asegurarse de que el nodo pasado no sea NIL si quieres acceder a data o que no sea un nullptr.
    SentinelLinkedList::Node<T>& Successor(SentinelLinkedList::Node<T>* node)
    {
        return *node->next;
    }

    SentinelLinkedList::Node<T>& Predecessor(SentinelLinkedList::Node<T>* node)
    {
        return *node->prev;
    }

    // A�ade un nuevo nodo al final de la lista.
    void PushBack(T value);

    // Quita el nodo del final de la lista y devuelve su valor.
    T PopBack();

    // A�ade un nuevo nodo al principio de la lista.
    void PushFront(T value);

    // Quita el nodo del principio de la lista y devuelve su valor.
    T PopFront();

    // Un nodo con el valor valueToInsert se insertar� como el Next de previousNode.
    void Insert(T valueToInsert, Node<T>* previousNode);

    void Remove(T valueToRemove);

    // Regresa una copia de la data del nodo del frente, pero sin sacarlo de la lista.
    T Front();

    int operationCounter; // Aseg�rate de que esta variable sea usada si se espera un comportamiento con ella
};

template<typename T>
void SentinelLinkedList<T>::Remove(T valueToRemove)
{
    // empieza en el primer de la lista
    Node<T>* currentNode = NIL->next; // usamos una variable auxiliar para no tocar la referencia al first.

    // hacemos un ciclo para checar todos los nodos, hasta que ya no haya nodo siguiente.
    while (currentNode != NIL)
    {
        // checa si la data del nodo actual es igual al valor a encontrarse (valueToRemove)
        if (currentNode->data == valueToRemove)
        {
            // El nodo anterior de currentNode su next debe apuntar a donde apunta currentNode-next
            // es decir, el nodo anterior de currentNode es currentNode->prev
            // es decir, el next de currentNode->prev ser�a currentNode->prev->next
            currentNode->prev->next = currentNode->next;
            // ahora hacemos lo mismo pero en la otra direcci�n
            // el prev de currentNode->next ser�a currentNode->next->prev debe apuntar a donde apunta currentNode-prev
            currentNode->next->prev = currentNode->prev;

            delete currentNode;
            count--;
            return;
        }
        else
        {
            // si no lo tiene, continuamos al nodo que le sigue a currentNode.
            currentNode = currentNode->next;
        }
    }
}

template<typename T>
SentinelLinkedList<T>::Node<T>& SentinelLinkedList<T>::Find(T value)
{
    // empieza en el primer de la lista, que ser�a el next de NIL
    Node<T>* currentNode = NIL->next; // usamos una variable auxiliar para no tocar la referencia al first.

    // hacemos un ciclo para checar todos los nodos, desde el primer elemento (NIL->next) hasta NIL
    while (currentNode != NIL)
    {
        // checa si la data del nodo actual es igual al valor a encontrarse (value)
        if (currentNode->data == value)
        {
            // si s� lo tiene, regresamos dicho nodo y nos salimos de la funci�n.
            return *currentNode;
        }
        else
        {
            // si no lo tiene, continuamos al nodo que le sigue a currentNode.
            currentNode = currentNode->next;
        }
    }

    // Si llegamos aqu�, no se encontr� el valor. Devolvemos una referencia al nodo centinela.
    // Esto es para que compile ya que la funci�n devuelve una referencia y no puede devolver nullptr.
    return *NIL;
}

template<typename T>
SentinelLinkedList<T>::Node<T>& SentinelLinkedList<T>::FindV2(T value)
{
    // empieza en el primer de la lista
    Node<T>* currentNode = NIL->next; // usamos una variable auxiliar para no tocar la referencia al first.

    // hacemos un ciclo para checar todos los nodos, hasta que ya no haya nodo siguiente.
    while (currentNode != NIL)
    {
        // checa si la data del nodo actual es igual al valor a encontrarse (value)
        if (currentNode->data == value)
            return *currentNode;

        // si no lo tiene, continuamos al nodo que le sigue a currentNode.
        currentNode = currentNode->next;
    }

    // Si llegamos aqu�, no se encontr� el valor. Devolvemos una referencia al nodo centinela.
    // Esto es para que compile ya que la funci�n devuelve una referencia y no puede devolver nullptr.
    return *NIL;
}

template<typename T>
void SentinelLinkedList<T>::Insert(T valueToInsert, SentinelLinkedList<T>::Node<T>* previousNode)
{
    // Un nodo con el valor valueToInsert se insertar� como el Next de previousNode.

    // Nuevo nodo que ser� el nuevo Next de previousNode
    Node<T>* newNode = new Node<T>(valueToInsert); // usamos una variable auxiliar para no tocar la referencia al first.

    // NOTA, es importante primero hacer la que va de newNode a previousNode->next y despu�s la de previousNode->next a newNode,
    // porque si no newNode termina teni�ndose como su propio next, lo cual es un grave error.

    // Hacemos la conexi�n desde newNode hacia el next de previousNode
    newNode->next = previousNode->next;

    // Hacemos la conexi�n desde previousNode hacia newNode como su next
    previousNode->next = newNode;

    // Conexi�n hacia atr�s: el nodo que estaba despu�s de previousNode (que ahora es newNode->next)
    // su 'prev' debe apuntar a newNode.
    newNode->next->prev = newNode;

    // La conexi�n de previousNode a newNode ya la hicimos antes.
    newNode->prev = previousNode;

    // aumentar el tama�o de la lista.
    count++;
}

// A�ade un nuevo nodo al final de la lista.
template<typename T>
void SentinelLinkedList<T>::PushBack(T value)
{
    // Creamos un nuevo nodo con el valor value como su data.
    Node<T>* newNode = new Node<T>(value);
    // su siguiente ya no va a ser nullptr, va a ser el nodo NIL
    newNode->next = NIL;

    // el que era el prev de nil (nil->prev) ahora su next apunta a newNode
    NIL->prev->next = newNode;

    // el prev de newNode apunte al prev de NIL
    newNode->prev = NIL->prev;
    // y ahora que el prev de NIL apunte al nodo nuevo
    NIL->prev = newNode;

    count++; // como metimos un nuevo elemento, aumentamos el contador de elementos.
}

template<typename T>
T SentinelLinkedList<T>::PopBack()
{
    // si no hay ning�n elemento.
    if (count == 0)
    {
        cout << "Cuidado, est�s haciendo pop back cuando ya no hay elementos en esta lista ligada";
        return {}; // {} es un elemento de tipo T con su valor por defecto, sin importar de qu� tipo sea T.
    }

    // ya sabemos que el �ltimo nodo es NIL->prev
    Node<T>* lastNode = NIL->prev;

    // tenemos que poner que del nodo que est� antes del �ltimo, su 'next' apunte a NIL
    lastNode->prev->next = NIL;
    // y que el 'prev' de NIL apunte al nodo que estaba antes del �ltimo
    NIL->prev = lastNode->prev;

    // guardamos la data del �ltimo nodo
    T data = lastNode->data;

    // ya que tenemos la data borramos al �ltimo nodo
    delete lastNode;
    lastNode = nullptr; // Buena pr�ctica para evitar punteros colgantes
    count--;

    return data;
}

// A�ade un nuevo nodo al principio de la lista.
template<typename T>
void SentinelLinkedList<T>::PushFront(T value)
{
    // 1. Creamos el nuevo nodo con el valor.
    Node<T>* newNode = new Node<T>(value);

    // 2. El 'next' del nuevo nodo debe apuntar al que actualmente es el primer nodo (NIL->next).
    newNode->next = NIL->next;

    // 3. El 'prev' del nuevo nodo debe apuntar a NIL.
    newNode->prev = NIL;

    // 4. El nodo que estaba *antes* en la primera posici�n (newNode->next)
    //    ahora debe tener su 'prev' apuntando al nuevo nodo.
    //    Esto es clave: si la lista estaba vac�a, newNode->next era NIL.
    //    Entonces, NIL->prev (que es NIL) debe apuntar a newNode.
    newNode->next->prev = newNode;

    // 5. Finalmente, el 'next' de NIL debe apuntar al nuevo nodo,
    //    estableci�ndolo como el nuevo primer elemento.
    NIL->next = newNode;

    // 6. Incrementamos el contador de elementos.
    count++;
}

// Quita el nodo del principio de la lista y devuelve su valor.
template<typename T>
T SentinelLinkedList<T>::PopFront()
{
    // 1. Verificamos si la lista est� vac�a.
    if (count == 0)
    {
        cout << "Advertencia: Intentando hacer PopFront en una lista vac�a." << endl;
        return {}; // Valor por defecto.
    }

    // 2. El nodo que queremos eliminar es el primero, despu�s de NIL.
    Node<T>* nodeToRemove = NIL->next;

    // 3. Actualizamos la conexi�n del nodo centinela (NIL).
    //    El 'next' de NIL ahora debe ser el 'next' del nodo que vamos a eliminar.
    NIL->next = nodeToRemove->next;

    // 4. Actualizamos la conexi�n del "nuevo primer nodo" (el que estaba despu�s de nodeToRemove).
    //    Su 'prev' debe apuntar ahora a NIL.
    nodeToRemove->next->prev = NIL;

    // 5. Guardamos la data antes de eliminar el nodo.
    T data = nodeToRemove->data;

    // 6. Eliminamos el nodo de la memoria y limpiamos el puntero.
    delete nodeToRemove;
    nodeToRemove = nullptr;

    // 7. Decrementamos el contador.
    count--;

    // 8. Devolvemos la data.
    return data;
}

template <typename T>
T SentinelLinkedList<T>::Front()
{
    if (count == 0)
    {
        cout << "Advertencia, se est� tratando de acceder al primer elemento de una SentinelLinkedList, pero est� vac�a" << endl;
        return {};
    }
    return NIL->next->data;
}
