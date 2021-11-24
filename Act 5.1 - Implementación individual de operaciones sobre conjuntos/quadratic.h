//
// Estructuras Formativas
//
// Ian García González
// A01706892
//
// File created on 23/11/21.
//
// Copyright © 2021. All rights reserved.
//
//

#ifndef QUADRATIC_H_
#define QUADRATIC_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * Quadratic: Incluye la estructura necesaria para ejecutar el main.cpp.
 * @file: quadratic.h
 * @author: Ian
 */

template<class Key, class Value>
class Quadratic {
private:
    unsigned int (*func)(const Key);

    unsigned int size;
    unsigned int count;
    Key *keys;
    Key initialValue;
    Value *values;

    long indexOf(const Key) const;

public:
    Quadratic(unsigned int, const Key, unsigned int (*)(const Key));

    ~Quadratic();

    bool full() const;

    bool put(const Key, const Value);

    bool contains(const Key) const;

    Value get(const Key) const;

    string toString() const;
};

/**
 * @brief Construct a new Quadratic< Key,  Value>:: Quadratic object
 * 
 * @tparam Key Class
 * @tparam Value Class
 * @param size Size of the array
 * @param initialValue Initial value of the array
 * @param func Function to use to calculate the index
 */
template<class Key, class Value>
Quadratic<Key, Value>::Quadratic(unsigned int size, const Key initialValue, unsigned int (*func)(const Key)) {
    this->size = size;
    this->keys = new Key[size];
    if (keys == nullptr) cout << "No memory." << endl;
    this->initialValue = initialValue;
    for (unsigned int i = 0; i < size; i++) {
        this->keys[i] = initialValue;
    }
    values = new Value[size];
    if (values == nullptr) cout << "No memory." << endl;
    for (int i = 0; i < size; i++) {
        this->values[i] = 0;
    }
    this->func = func;
    this->count = 0;
}

/**
 * @brief Destroy the Quadratic< Key,  Value>:: Quadratic object
 * 
 * @tparam Key Class
 * @tparam Value Class
 */
template<class Key, class Value>
Quadratic<Key, Value>::~Quadratic() {
    delete[] keys;
    delete[] values;
    keys = nullptr;
    values = nullptr;
    func = nullptr;
    size = 0;
    count = 0;
}

/**
 * @brief Check if the array is full
 * 
 * @tparam Key Class
 * @tparam Value Class
 * @return true If the array is full
 * @return false If the array is not full
 */
template<class Key, class Value>
bool Quadratic<Key, Value>::full() const {
    return count > size;
}

/**
 * @brief Get the index of the key
 * 
 * @tparam Key Class
 * @tparam Value Class
 * @param key Key to check
 * @return long Index of the key
 */
template<class Key, class Value>
long Quadratic<Key, Value>::indexOf(const Key key) const {
    unsigned int i, start;
    start = i = func(key) % size;
    for (int j = 0; j < size; j++) {
        if (keys[i] == key) return i;
        i = (start + j * j) % size;
    }
    return -1;
}

/**
 * @brief Put a new value in the array
 * 
 * @tparam Key Class
 * @tparam Value Class
 * @param key Key to put
 * @param value Value to check
 * @return true If the key was put successfully
 * @return false If the key wasn't put successfully
 */
template<class Key, class Value>
bool Quadratic<Key, Value>::put(const Key key, const Value value) {
    unsigned i, start;
    long pos;
    pos = indexOf(key);
    if (pos != -1) {
        values[pos] = value;
        return true;
    }
    start = i = func(key) % size;
    for (int j = 0; j < size; j++) {
        if (keys[i] == initialValue) {
            keys[i] = key;
            values[i] = value;
            return true;
        }
        i = (start + j * j) % size;
    }
    return false;
}

/**
 * @brief Check if the array contains a key
 * 
 * @tparam Key Class
 * @tparam Value Class
 * @param key Key to check
 * @return true If the array contains the key
 * @return false If the array does not contain the key
 */
template<class Key, class Value>
bool Quadratic<Key, Value>::contains(const Key key) const {
    return indexOf(key) != -1;
}

/**
 * @brief Get the value of a key
 * 
 * @tparam Key Class
 * @tparam Value Class
 * @param key Key to get value
 * @return Value Value of the key
 */
template<class Key, class Value>
Value Quadratic<Key, Value>::get(const Key key) const {
    long pos = indexOf(key);
    if (pos != -1) return values[pos];
    return 0;
}

/**
 * @brief Convert the array to a string
 * 
 * @tparam Key Class
 * @tparam Value Class
 * @return string String of the array
 */
template<class Key, class Value>
string Quadratic<Key, Value>::toString() const {
    stringstream aux;
    for (int i = 0; i < size; i++) {
        if (keys[i] != initialValue) {
            aux << "(" << i << " ";
            aux << keys[i] << " : " << values[i] << ") ";
        }
    }
    return aux.str();
}

#endif // QUADRATIC_H_