// =================================================================
//
// File: priority_queue.h
// Author: Uri Jared Gopar Morales A01709413
// Date: 22/10/2022
//==================================================================
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <string>
#include <sstream>
#include <iostream>
#include "heap.h"
template <class T>
class PriorityQueue {
private:
  Heap<T> heap;

public:
    PriorityQueue(uint);
    ~PriorityQueue();
    void push(T);
    void pop();
    T top();
    bool empty();
    uint tamaño();
};


// Constructor. Crea el maximo tamaño de la heap

template <class T>
PriorityQueue<T>::PriorityQueue(uint tam) : heap(tam) {}

//Destructor.Elimina el arreglo
template <class T>
PriorityQueue<T>::~PriorityQueue() {}

//Agrega un nuevo Elemento
template <class T>
void PriorityQueue<T>::push(T value) {
    heap.add(value);
}

//Remmueve el elemento con la mayor prioridad.
template <class T>
void PriorityQueue<T>::pop() {
    heap.remove();
}

//Regresa el elemento con la prioridad más alta
template <class T>
T PriorityQueue<T>::top() {
    T aux = heap.remove();
    heap.add(aux);
    return aux;
}

//Regresa verdadero si queue esta vacio
template <class T>
bool PriorityQueue<T>::empty() {
    return heap.empty();
}


// Regresa el tamaño de la prioridad de queue.
template <class T>
uint PriorityQueue<T>::tamaño() {
    return heap.length();
}

#endif   