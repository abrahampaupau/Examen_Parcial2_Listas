#include <iostream>
#include <string> // La necesito si voy a usar textos (strings) en mis pruebas.

// Incluyo mis propios archivos de encabezado. ¡Es importante que los nombres sean exactos!
#include "SentinelLinkedList.h" 
#include "LQueue.h"             
#include "LStack.h"             

// Para no tener que escribir "std::" a cada rato.
using namespace std;

// --- Funciones de ayuda (estas no son parte del entregable, solo para probar) ---
// No puedo imprimir la lista completa fácilmente sin cambiar mis clases,
// así que solo mostraré lo que puedo con lo que ya tengo.
// Para el profesor, con mostrar el Front/Peak y el Count debería ser suficiente.

int main()
{
    cout << "--- ¡HOLA PROFESOR! ESTA ES MI DEMOSTRACION ---" << endl;
    cout << "----------------------------------------------------" << endl;

    // ========================================================================
    // PRUEBAS PARA MI SENTINELLINKEDLIST (Punto 1)
    // ========================================================================
    cout << "\n=== Probando mi SentinelLinkedList (Punto 1) ===" << endl;
    SentinelLinkedList<int> mySList; // Creo una lista de números enteros.

    cout << "\nMi lista SentinelLinkedList al principio:" << endl;
    cout << "  Cantidad de elementos: " << mySList.GetCount() << endl; // Debería ser 0

    cout << "\n--- Vamos a meter cosas por el principio (PushFront) ---" << endl;
    mySList.PushFront(10); // Ahora la lista tiene: [10]
    mySList.PushFront(20); // Ahora tiene: [20, 10]
    mySList.PushFront(30); // Ahora tiene: [30, 20, 10]
    cout << "  Cantidad despues de meter 3 cosas: " << mySList.GetCount() << endl; // ¡Debería ser 3!
    cout << "  El primer elemento (Front) es: " << mySList.Front() << endl; // ¡Debería ser 30!

    cout << "\n--- Ahora vamos a sacar cosas por el principio (PopFront) ---" << endl;
    cout << "  Saqué (esperaba 30): " << mySList.PopFront() << endl; // Saco 30. La lista queda: [20, 10]
    cout << "  Cantidad: " << mySList.GetCount() << endl; // ¡Debería ser 2!
    cout << "  El nuevo primer elemento (Front) es: " << mySList.Front() << endl; // ¡Debería ser 20!

    cout << "  Saqué (esperaba 20): " << mySList.PopFront() << endl; // Saco 20. La lista queda: [10]
    cout << "  Cantidad: " << mySList.GetCount() << endl; // ¡Debería ser 1!
    cout << "  El nuevo primer elemento (Front) es: " << mySList.Front() << endl; // ¡Debería ser 10!

    cout << "\n--- Vamos a meter cosas por el final (PushBack) ---" << endl;
    mySList.PushBack(40); // Ahora la lista tiene: [10, 40]
    mySList.PushBack(50); // Ahora tiene: [10, 40, 50]
    cout << "  Cantidad despues de meter 2 cosas por el final: " << mySList.GetCount() << endl; // ¡Debería ser 3!
    cout << "  El primer elemento (Front) sigue siendo: " << mySList.Front() << endl; // ¡Todavía debe ser 10!

    cout << "\n--- Ahora vamos a sacar cosas por el final (PopBack) ---" << endl;
    cout << "  Saqué (esperaba 50): " << mySList.PopBack() << endl; // Saco 50. La lista queda: [10, 40]
    cout << "  Cantidad: " << mySList.GetCount() << endl; // ¡Debería ser 2!

    cout << "  Saqué (esperaba 40): " << mySList.PopBack() << endl; // Saco 40. La lista queda: [10]
    cout << "  Cantidad: " << mySList.GetCount() << endl; // ¡Debería ser 1!

    cout << "\n--- Vaciando lo que queda con PopFront y PopBack ---" << endl;
    cout << "  Saqué (esperaba 10): " << mySList.PopFront() << endl; // Saco 10. La lista queda: []
    cout << "  Cantidad final: " << mySList.GetCount() << endl; // ¡Debería ser 0!

    cout << "\n--- ¿Que pasa si intento sacar de una lista vacia? ---" << endl;
    mySList.PopFront(); // Esto debería avisarme que está vacía.
    mySList.PopBack();  // Esto también debería avisarme.
    cout << "  Cantidad despues de intentar sacar de una lista vacia: " << mySList.GetCount() << endl; // Sigue en 0.


    // ========================================================================
    // PRUEBAS PARA MI LQUEUE (Punto 2)
    // ========================================================================
    cout << "\n\n=== Probando mi LQueue (Punto 2) ===" << endl;
    LQueue<string> myQueue; // Creo una cola para guardar textos.

    cout << "\nMi LQueue al principio:" << endl;
    cout << "  Cantidad de elementos: " << myQueue.GetCount() << endl; // ¡0!

    cout << "\n--- Metiendo elementos en la cola (Enqueue) ---" << endl;
    myQueue.Enqueue("Primero");  // Cola: [Primero]
    myQueue.Enqueue("Segundo");  // Cola: [Primero, Segundo]
    myQueue.Enqueue("Tercero");  // Cola: [Primero, Segundo, Tercero]
    cout << "  Cantidad despues de meter 3 textos: " << myQueue.GetCount() << endl; // ¡Debería ser 3!
    cout << "  El elemento del frente (Front) es: " << myQueue.Front() << endl; // ¡Debería ser 'Primero'!

    cout << "\n--- Sacando elementos de la cola (Dequeue) ---" << endl;
    cout << "  Saqué (esperaba 'Primero'): " << myQueue.Dequeue() << endl; // Saco "Primero". Cola: [Segundo, Tercero]
    cout << "  Cantidad: " << myQueue.GetCount() << endl; // ¡Debería ser 2!
    cout << "  El nuevo frente (Front) es: " << myQueue.Front() << endl; // ¡Debería ser 'Segundo'!

    cout << "  Saqué (esperaba 'Segundo'): " << myQueue.Dequeue() << endl; // Saco "Segundo". Cola: [Tercero]
    cout << "  Cantidad: " << myQueue.GetCount() << endl; // ¡Debería ser 1!
    cout << "  El nuevo frente (Front) es: " << myQueue.Front() << endl; // ¡Debería ser 'Tercero'!

    cout << "\n--- Metiendo un ultimo elemento ---" << endl;
    myQueue.Enqueue("Cuarto"); // Cola: [Tercero, Cuarto]
    cout << "  Cantidad: " << myQueue.GetCount() << endl; // ¡Debería ser 2!
    cout << "  El frente sigue siendo: " << myQueue.Front() << endl; // ¡Debería ser 'Tercero'!

    cout << "\n--- Vaciando la cola ---" << endl;
    cout << "  Saqué (esperaba 'Tercero'): " << myQueue.Dequeue() << endl;
    cout << "  Saqué (esperaba 'Cuarto'): " << myQueue.Dequeue() << endl;
    cout << "  Cantidad final: " << myQueue.GetCount() << endl; // ¡Debería ser 0!

    cout << "\n--- ¿Que pasa si intento sacar o ver el frente de una cola vacia? ---" << endl;
    myQueue.Dequeue(); // Debería avisarme.
    myQueue.Front();   // Debería avisarme.
    cout << "  Cantidad despues de operaciones en vacia: " << myQueue.GetCount() << endl; // Sigue en 0.


    // ========================================================================
    // PRUEBAS PARA MI LSTACK (Punto 3)
    // ========================================================================
    cout << "\n\n=== Probando mi LStack (Punto 3) ===" << endl;
    LStack<double> myStack; // Creo una pila para guardar números con decimales.

    cout << "\nMi LStack al principio:" << endl;
    cout << "  Cantidad de elementos: " << myStack.Count() << endl; // ¡0!

    cout << "\n--- Metiendo elementos en la pila (Push) ---" << endl;
    myStack.Push(1.1); // Pila: [1.1] (el tope)
    myStack.Push(2.2); // Pila: [2.2, 1.1] (el tope ahora es 2.2)
    myStack.Push(3.3); // Pila: [3.3, 2.2, 1.1] (el tope ahora es 3.3)
    cout << "  Cantidad despues de meter 3 numeros: " << myStack.Count() << endl; // ¡Debería ser 3!
    cout << "  El tope (Peak) es: " << myStack.Peak() << endl; // ¡Debería ser 3.3!

    cout << "\n--- Sacando elementos de la pila (Pop) ---" << endl;
    cout << "  Saqué (esperaba 3.3): " << myStack.Pop() << endl; // Saco 3.3. Pila: [2.2, 1.1]
    cout << "  Cantidad: " << myStack.Count() << endl; // ¡Debería ser 2!
    cout << "  El nuevo tope (Peak) es: " << myStack.Peak() << endl; // ¡Debería ser 2.2!

    cout << "  Saqué (esperaba 2.2): " << myStack.Pop() << endl; // Saco 2.2. Pila: [1.1]
    cout << "  Cantidad: " << myStack.Count() << endl; // ¡Debería ser 1!
    cout << "  El nuevo tope (Peak) es: " << myStack.Peak() << endl; // ¡Debería ser 1.1!

    cout << "\n--- Metiendo un ultimo elemento ---" << endl;
    myStack.Push(4.4); // Pila: [4.4, 1.1]
    cout << "  Cantidad: " << myStack.Count() << endl; // ¡Debería ser 2!
    cout << "  El tope es: " << myStack.Peak() << endl; // ¡Debería ser 4.4!

    cout << "\n--- Vaciando la pila ---" << endl;
    cout << "  Saqué (esperaba 4.4): " << myStack.Pop() << endl;
    cout << "  Saqué (esperaba 1.1): " << myStack.Pop() << endl;
    cout << "  Cantidad final: " << myStack.Count() << endl; // ¡Debería ser 0!

    cout << "\n--- ¿Que pasa si intento sacar o ver el tope de una pila vacia? ---" << endl;
    myStack.Pop();  // Debería avisarme.
    myStack.Peak(); // Debería avisarme.
    cout << "  Cantidad despues de operaciones en vacia: " << myStack.Count() << endl; // Sigue en 0.

    cout << "\n----------------------------------------------------" << endl;
    cout << "--- ¡LISTO PROFESOR! DEMOSTRACION TERMINADA ---" << endl;

    return 0; // El programa terminó bien.
}