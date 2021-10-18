//
// Estructuras Formativas
//
// Ian García González
// A01706892
//
// File created on 17/10/21.
//
// Copyright © 2021. All rights reserved.
//
//

#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
 * Heap: Incluye la estructura necesaria para ejecutar el main.cpp.
 * @file: heap.h
 * @author: Ian
 */

template<class T>
class heap {
private:
    T *data;
    int max;
    int count;

    int parent(int) const;

    int left(int) const;

    int right(int) const;

    void swap(int, int);

    void heapify(int);

public:
    explicit heap(int);

    void push(T);

    void pop();

    T top() const;

    bool empty() const;

    int size() const;

    string toString() const;
};

/**
 * @brief Construct a new heap<T>::heap object
 * 
 * @param size Cantidad máxima de datos.
 */
template<class T>
heap<T>::heap(int size) {
    max = size;
    data = new T[max];
    count = 0;
}

/**
 * @brief Node (Padre).
 * 
 * @param position Posición del nodo.
 * @return int 
 */
template<class T>
int heap<T>::parent(int position) const {
    return (position - 1) / 2;
}

/**
 * @brief Child Node (Left).
 * 
 * @param position Posición del nodo.
 * @return int 
 */
template<class T>
int heap<T>::left(int position) const {
    return ((2 * position) + 1);
}

/**
 * @brief Child node (Right).
 * 
 * @param position Posición del nodo.
 * @return int 
 */
template<class T>
int heap<T>::right(int position) const {
    return ((2 * position) + 2);
}

/**
 * @brief Intercambia posición.
 * 
 * @param x Posición 1.
 * @param y Posición 2.
 */
template<class T>
void heap<T>::swap(int x, int y) {
    T aux = data[x];
    data[x] = data[y];
    data[y] = aux;
}

/**
 * @brief Acomoda a los nodos.
 * 
 * @param position Posición a acomodar.
 */
template<class T>
void heap<T>::heapify(int position) {
    int le = left(position), ri = right(position), min = position;
    if (le <= count && data[le] < data[min]) min = le;
    if (ri <= count && data[ri] < data[min]) min = ri;
    if (min != position) {
        swap(position, min);
        heapify(min);
    }
}

/**
 * @brief Agrega un nuevo nodo al Heap.
 * 
 * @param value Valor del nuevo nodo.
 */
template<class T>
void heap<T>::push(T value) {
    int position = count;
    count++;
    while (position > 0 && value < data[parent(position)]) {
        data[position] = data[parent(position)];
        position = parent(position);
    }
    data[position] = value;
}

/**
 * @brief Saca del Heap el dato con mayor prioridad.
 * 
 */
template<class T>
void heap<T>::pop() {
    T aux = data[0];
    data[0] = data[--count];
    heapify(0);
}

/**
 * @brief Obtiene el nodo con mayor prioridad en la fila.
 * 
 * @return T Valor del nodo.
 */
template<class T>
T heap<T>::top() const {
    return data[0];
}

/**
 * @brief Revisa si el Heap está vacío o no.
 * 
 * @return true Heap vacío.
 * @return false Heap no está vacío.
 */
template<class T>
bool heap<T>::empty() const {
    return count == 0;
}

/**
 * @brief Obtiene el número de nodos del Heap.
 * 
 * @return int Cantidad de nodos en la fila.
 */
template<class T>
int heap<T>::size() const {
    return count;
}

/**
 * @brief Obtiene los valores de todos los nodos del Heap.
 * 
 * @return std::string 
 */
template<class T>
std::string heap<T>::toString() const {
    std::stringstream aux;
    aux << "[";
    for (unsigned int i = 0; i < count; i++) {
        if (i != 0) {
            aux << " ";
        }
        aux << data[i];
    }
    aux << "]";
    return aux.str();
}

#endif  //HEAP_H_
