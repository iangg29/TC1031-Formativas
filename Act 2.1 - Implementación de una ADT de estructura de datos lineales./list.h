//
// Estructuras Formativas
//
// Ian García González
// A01706892
//
// File created on 20/09/21.
//
// Copyright © 2021. All rights reserved.
//
//
#ifndef LIST_H
#define LIST_H

/*
 * List: Incluye la estructura necesaria para ejecutar el main.cpp
 * @file list.h
 * @author Ian
 * */

template <class T>
class List;

template <class T>
class Link {
   private:
    Link(T);
    Link(T, Link<T> *);

    T value;
    Link<T> *next;

    friend class List<T>;
};
/**
 * @brief Construct a new Link< T>:: Link object
 * 
 * @param val Valor del nodo
 */
template <class T>
Link<T>::Link(T val) : value(val), next(nullptr) {}

/**
 * @brief Construct a new Link< T>:: Link object
 * 
 * @param val Valor del nodo.
 * @param nxt Liga al siguiente nodo.
 */
template <class T>
Link<T>::Link(T val, Link *nxt) : value(val), next(nxt) {}

template <class T>
class List {
   public:
    List();
    ~List();

    void clear();
    void addFirst(T);
    void insertion(T);
    void update(int, T);

    int search(T) const;

    T deleteAt(int);
    T deleteFirst();

    bool isEmpty() const;
    std::string toString() const;

   private:
    Link<T> *head;
    int size;
};

/**
 * @brief Construct a new List< T>:: List object
 */
template <class T>
List<T>::List() : head(nullptr), size(0) {}

/**
 * @brief Destroy the List< T>:: List object
 */
template <class T>
List<T>::~List() {
    clear();
}

/**
 * @brief Clears the linked list.
 */
template <class T>
void List<T>::clear() {
    Link<T> *p, *q;
    p = head;
    while (p != nullptr) {
        q = p->next;
        delete p;
        p = q;
    }
    head = nullptr;
    size = 0;
}

/**
 * @brief Prints the contents of the linked list.
 * 
 * @return std::string 
 */
template <class T>
std::string List<T>::toString() const {
    std::stringstream aux;
    Link<T> *p;

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
 * @brief Checks if the linked list is empty.
 * 
 * @return true List is empty.
 * @return false List is not empty;
 */
template <class T>
bool List<T>::isEmpty() const {
    return head == nullptr;
}

/**
 * @brief Adds new node in the head of the linked list.
 * 
 * @param val Valor del nodo.
 */
template <class T>
void List<T>::addFirst(T val) {
    Link<T> *newLink;

    newLink = new Link<T>(val);
    newLink->next = head;
    head = newLink;
    size++;
}

/**
 * @brief Insert a new node to the linked list.
 * 
 * @param val Valor del nodo.
 */
template <class T>
void List<T>::insertion(T val) {
    Link<T> *newLink, *p;
    newLink = new Link<T>(val);
    if (isEmpty()) {
        addFirst(val);
        return;
    }
    p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    newLink->next = nullptr;
    p->next = newLink;
    size++;
}

/**
 * @brief Deletes the first node of the linked list.
 * 
 * @return T Valor del nodo eliminado.
 */
template <class T>
T List<T>::deleteFirst() {
    T val;
    Link<T> *p;
    if (isEmpty()) {
        std::cout << "La lista está vacía!" << std::endl;
    }
    p = head;
    head = p->next;
    val = p->value;
    delete p;
    size--;
    return val;
}

/**
 * @brief Deletes a node of certain index in the linked list.
 * 
 * @param index Índice del nodo a eliminar.
 * @return T Valor del nodo eliminado.
 */
template <class T>
T List<T>::deleteAt(int index) {
    T val;
    Link<T> *p, *q;
    int pos;
    if (index < 0 || index >= size) {
        std::cout << "Index inválido!" << std::endl;
    }
    if (index == 0) return deleteFirst();
    pos = 0;
    p = head;
    q = nullptr;
    while (pos != index) {
        q = p;
        p = p->next;
        pos++;
    }
    val = p->value;
    q->next = p->next;
    delete p;
    size--;
    return val;
}

/**
 * @brief Updates node value at certain index in the linked list.
 * 
 * @param index Índice del nodo a actualizar.
 * @param val Nuevo valor del nodo.
 */
template <class T>
void List<T>::update(int index, T val) {
    int pos;
    Link<T> *p;
    if (index < 0 || index >= size) {
        std::cout << "Index inválido!" << std::endl;
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
 * @brief Search a certain value in the linked list.
 * 
 * @param val Valor a buscar en la lista.
 * @return int Índice del valor encontrado.
 */
template <class T>
int List<T>::search(T val) const {
    int pos;
    Link<T> *p;
    if (isEmpty()) return -1;
    p = head;
    pos = 0;
    while (p != nullptr) {
        if (p->value == val) return pos;
        p = p->next;
        pos++;
    }
    return -1;
}
#endif