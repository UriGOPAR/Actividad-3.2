// =================================================================
//
// File: heap.h
// Author:Uri Jared Gopar Morales-A01709413
// DATE: 22/10/2022
// =================================================================
#ifndef HEAP_H
#define HEAP_H
#include <string>
#include <sstream>
#include <iostream>
#include "Excepciones.h"
#include "header.h"
using namespace std;
// Clase Heap
template <class T>
class Heap {
private:
	T 	 *dato;
	uint tamaño;
	uint c;
	uint padre(uint) const;
	uint izquierda(uint) const;
	uint derecha(uint) const;
	void pushDown(uint);
	void swap(uint, uint);

public:
	Heap(uint);
	~Heap();
	bool empty() const;
	bool full() const;
	uint length() const;
	void add(T);
	T remove();
	void clear();
	string toString() const;
};
//Constructor
//Inicializa el mayor valor de heap
template <class T>
Heap<T>::Heap(uint tam) {
	tamaño = tam;
	dato = new T[tamaño];
	c = 0;
}
//Destructor
//Libera Memoria
template <class T>
Heap<T>::~Heap() {
	delete [] dato;
	dato = NULL;
	tamaño= 0;
	c= 0;
}
//Ve si la heap esta vacia o no
template <class T>
bool Heap<T>::empty() const {
	return (c == 0);
}
//Regresa si la heap esta llena o no
template <class T>
bool Heap<T>::full() const {
	return (c == tamaño);
}
//Regresa los elementos que se encuentran en la heap
template <class T>
uint Heap<T>::length() const {
	return c;
}
//Devuelve la posicion del padre de un elemento
template <class T>
uint Heap<T>::padre(uint ubi) const {
	return (ubi - 1) / 2;
}
//Regresa la posicion de la izquierda del hijo
template <class T>
uint Heap<T>::izquierda(uint ubi) const {
	return (ubi * 2) + 1;
}
//Regresa la posición del hijo derecho de un elemento
template <class T>
uint Heap<T>::derecha(uint ubi) const {
	return (ubi * 2) + 2;
}
//Intercambia el contenido de 2 localidades
template <class T>
void Heap<T>::swap(uint i, uint j) {
	T aux = dato[i];
	dato[i] = dato[j];
	dato[j] = aux;
}

//Coloca los elementos en la posicion correcta
//El elemento debe ser mayor que sus hijos
template <class T>
void Heap<T>::pushDown(uint ubi) {
    uint iz = izquierda(ubi);
    uint de = derecha(ubi);
    uint max = ubi;

    if (iz < c && dato[iz] > dato[max]){
        max = iz;
    }
    if (de < c && dato[de] > dato[max]){
        max = de;
    }

    if(max != ubi){
        swap(ubi, max);
        pushDown(max);
    }
}
//  Agrega elemento a la heap
template <class T>
void Heap<T>::add(T val) {
	uint ubi;
	if (full()){
		throw Overflow();
	}

	ubi = c;
	c++;
	while(ubi > 0 && val > dato[padre(ubi)]){
		dato[ubi]= dato[padre(ubi)];
		ubi = padre(ubi);
	}
	dato[ubi] = val;
}

//Remueve la raíz. La hoja de la derecha se coloca como sucesor.
//Reorganizar con el método pushDown
template <class T>
T Heap<T>::remove() {
	if (empty()){
		throw NoSuchElement();
	}

	T aux = dato[0];
	dato[0] = dato[--c]; 
	pushDown(0);
	return aux;
}

template <class T>
void Heap<T>::clear() {
	c = 0;
}
//Remueve todos los elementos de la heap
template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;

	aux << "[";
	for (uint i = 0; i < c; i++) {
		if (i != 0) {
			aux << " ";
		}
	aux << dato[i];
	}
	aux << "]";
	return aux.str();
}
#endif /* HASH_H */