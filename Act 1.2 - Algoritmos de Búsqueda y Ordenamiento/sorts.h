//
// Estructuras Formativas
//
// Ian García González
// A01706892
//
// File created on 07/09/21.
//
// Copyright © 2021. All rights reserved.
//
//
#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <vector>

/*
 * Sorts: Incluye las funciones necesarias para ejecutar el main.cpp
 * @file sorts.h
 * @author Ian
 * */

using namespace std;

template<class T>
class Sorts {
private:
    void swap(vector<T> &, int, int);

    void copyArray(vector<T> &, vector<T> &, int, int);

    void mergeArray(vector<T> &, vector<T> &, int, int, int);

    void mergeSplit(vector<T> &, vector<T> &, int, int);

    int auxiliar(vector<T>, int, int, int);

public:
    void ordenaSeleccion(vector<T> &v);

    void ordenaBurbuja(vector<T> &v);

    void ordenaMerge(vector<T> &v);

    int busqSecuencial(const vector<T> &v, int target);

    int busqBinaria(const vector<T> &v, int target);
};

/*
 * Invierte los objetos dentro de un vector.
 * @param vector Vector completo
 * @param i Primer índice a cambiar
 * @param j Segundo índice a cambiar
 * */
template<class T>
void Sorts<T>::swap(vector<T> &vector, int i, int j) {
    T aux = vector[i];
    vector[i] = vector[j];
    vector[j] = aux;
}

/*
 * Copia un vector a otro vector.
 * @param A Vector 1 a copiar
 * @param B Vector 2 a copiar
 * @param low Índice más bajo
 * @param high Índice más alto
 * */
template<class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high) {
    for (int i = low; i <= high; ++i) {
        A[i] = B[i];
    }
}

/*
 * Junta dos vectores en orden.
 * @param A Vector 1 a juntar
 * @param B Vector 2 a juntar
 * @param low Índice más bajo
 * @param mid Índice de en medio
 * @param high Índice más alto
 * */
template<class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        while (j <= high) {
            B[k++] = A[j];
            j++;
        }
    } else {
        while (i <= mid) {
            B[k++] = A[i];
            i++;
        }
    }
}

/*
 * Junta mitades de vectores en orden.
 * @param A Vector 1
 * @param B Vector 2
 * @param low Índice más bajo
 * @param high Índice más alto
 * */
template<class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high) {
    if ((high - low) < 1) return;
    int mid = (high + low) / 2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
    copyArray(A, B, low, high);
}

/*
 * Algoritmo que ordena un vector con el método de selección.
 * @param v Vector a ordenar
 * @BigO O(n^2)
 * */
template<class T>
void Sorts<T>::ordenaSeleccion(vector<T> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(v, i, min);
        }
    }
}

/*
 * Algoritmo que ordena un vector con el método de burbuja.
 * @param v Vector a ordenar
 * @BigO O(n^2)
 * */
template<class T>
void Sorts<T>::ordenaBurbuja(vector<T> &v) {
    for (int i = v.size() - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (v[j] > v[j + 1]) {
                swap(v, j, j + 1);
            }
        }
    }
}

/*
 * Algoritmo que ordena un vector con el método de Merge
 * @param v Vector a ordenar
 * @BigO O(n log n)
 * */
template<class T>
void Sorts<T>::ordenaMerge(vector<T> &v) {
    vector<T> temporal(v.size());
    mergeSplit(v, temporal, 0, v.size() - 1);
}

/*
 * Algoritmo que busca dentro de un vector un valor de forma secuencial.
 * @param v Vector donde buscará
 * @param target Número que buscará
 * @BigO O(n)
 * */
template<class T>
int Sorts<T>::busqSecuencial(const vector<T> &v, int target) {
    vector<T> vec(v);
    for (int i = 0; i < vec.size(); ++i) {
        if (target == vec[i]) {
            return i;
        }
    }
    return -1;
}

/*
 * Algoritmo que busca dentro de un vector un valor de forma binaria.
 * @param v Vector donde buscará
 * @param target Número que buscará
 * @BigO O(log n)
 * */
template<class T>
int Sorts<T>::busqBinaria(const vector<T> &v, int target) {
    vector<T> vec(v);
    return auxiliar(vec, 0, vec.size() - 1, target);
}

/*
 * Algoritmo de ayuda para la búsqueda binaria.
 * @param vec Vector donde buscará
 * @param low Índice más bajo
 * @param high Índice más alto
 * @param target Número que buscará
 * */
template<class T>
int Sorts<T>::auxiliar(vector<T> vec, int low, int high, int target) {
    if (low < high) {
        int mid = (high + low) / 2;
        if (target == vec[mid]) {
            return mid;
        } else if (target < vec[mid]) {
            return auxiliar(vec, low, mid - 1, target);
        } else if (target > vec[mid]) {
            return auxiliar(vec, mid + 1, high, target);
        }
    }
    return -1;
}

#endif