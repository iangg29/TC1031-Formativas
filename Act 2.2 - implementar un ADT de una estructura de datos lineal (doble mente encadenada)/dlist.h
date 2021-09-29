//
// Estructuras Formativas
//
// Ian García González
// A01706892
//
// File created on 29/09/21.
//
// Copyright © 2021. All rights reserved.
//
//
#ifndef DLIST_H_
#define DLIST_H_

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
 * DList: Incluye la estructura necesaria para ejecutar el main.cpp
 * @file: dlist.h
 * @author: Ian
 */

template <class T>
class DList;

template <class T>
class DLink {
   private:
    DLink(T);
    DLink(T, DLink<T> *, DLink<T> *);

    T value;
    DLink<T> *previous;
    DLink<T> *next;

    friend class DList<T>;
};

/**
 * @brief Construct a new DLink<T>::DLink object
 * 
 * @param val Valor del nodo.
 */
template <class T>
DLink<T>::DLink(T val) : value(val), previous(nullptr), next(nullptr) {}

/**
 * @brief Construct a new DLink<T>::DLink object
 * 
 * @param val Valor del nodo.
 * @param prev Liga al nodo anterior.
 * @param nxt Liga al siguiente nodo.
 */
template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink *nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
class DList {
   public:
    DList();
    ~DList();

    void clear();
    void insertion(T);
    void update(int, T);

    bool isEmpty() const;
    string toStringForward() const;
    string toStringBackward() const;
    int search(T) const;

    T deleteFirst();
    T deleteAt(int);

   private:
    DLink<T> *head;
    DLink<T> *tail;
    int size;
};

/**
 * @brief Construct a new DList<T>::DList object
 *
 */
template <class T>
DList<T>::DList() : head(nullptr), tail(nullptr), size(0) {}

/**
 * @brief Destroy the DList<T>::DList object
 * 
 */
template <class T>
DList<T>::~DList() {
    clear();
}

/**
 * @brief Limpia la lista dejándola vacía.
 * 
 */
template <class T>
void DList<T>::clear() {
    DLink<T> *p, *q;
    p = head;
    while (p != nullptr) {
        q = p->next;
        delete p;
        p = q;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/**
 * @brief Inserta un nuevo elemento a la lista.
 * 
 * @param val Valor a agregar.
 */
template <class T>
void DList<T>::insertion(T val) {
    DLink<T> *newLink;
    newLink = new DLink<T>(val);
    if (isEmpty()) {
        head = newLink;
        tail = newLink;
    } else {
        tail->next = newLink;
        newLink->previous = tail;
        tail = newLink;
    }
    size++;
}

/**
 * @brief Actualiza el valor de un nodo en un índice en específico.
 * 
 * @param index Índice objetivo.
 * @param val Nuevo valor del nodo.
 */
template <class T>
void DList<T>::update(int index, T val) {
    int pos;
    DLink<T> *p;
    if (index < 0 || index >= size) {
        cout << "Index inválido" << endl;
    }
    pos = 0;
    p = head;
    while (pos != index) {
        p = p->next;
        pos++;
    }
    p->value = val;
}

/**
 * @brief Verifica si la lista está vacía.
 * 
 * @return true La lista está vacía.
 * @return false La lista no está vacía.
 */
template <class T>
bool DList<T>::isEmpty() const {
    return (head == nullptr && tail == nullptr);
}

/**
 * @brief Imprime la lista empezando por el inicio.
 * 
 * @return std::string 
 */
template <class T>
std::string DList<T>::toStringForward() const {
    std::stringstream aux;
    DLink<T> *p;

    p = head;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->next != 0) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

/**
 * @brief Imprime la lista empezando por el final.
 * 
 * @return std::string 
 */
template <class T>
std::string DList<T>::toStringBackward() const {
    std::stringstream aux;
    DLink<T> *p;

    p = tail;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->previous != 0) {
            aux << ", ";
        }
        p = p->previous;
    }
    aux << "]";
    return aux.str();
}

/**
 * @brief Búsca un valor dentro de la lista.
 * 
 * @param val Valor a buscar.
 * @return int Índice del valor encontrado.
 */
template <class T>
int DList<T>::search(T val) const {
    int pos;
    DLink<T> *p;
    p = head;
    pos = 0;
    while (p != nullptr) {
        if (p->value == val) return pos;
        p = p->next;
        pos++;
    }
    return -1;
}

/**
 * @brief Elimina el primer nodo de la lista.
 * 
 * @return T Valor del nodo eliminado.
 */
template <class T>
T DList<T>::deleteFirst() {
    T val;
    DLink<T> *p;
    if (isEmpty()) {
        cout << "La lista está vacía." << endl;
    }
    p = head;
    val = p->value;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = p->next;
        p->next->previous = nullptr;
    }
    delete p;
    size--;
    return val;
}

/**
 * @brief Elimina un nodo en específico de la lista.
 * 
 * @param index Índice del nodo a eliminar.
 * @return T Valor del nodo eliminado.
 */
template <class T>
T DList<T>::deleteAt(int index) {
    T val;
    DLink<T> *p;
    int pos;
    if (index < 0 || index >= size) {
        cout << "Index inválido." << endl;
    }
    if (index == 0) return deleteFirst();
    p = head;
    pos = 0;
    while (pos != index) {
        p = p->next;
        pos++;
    }
    val = p->value;
    p->previous->next = p->next;
    if (p->next != nullptr) {
        p->next->previous = p->previous;
    }
    delete p;
    size--;
    return val;
}
#endif