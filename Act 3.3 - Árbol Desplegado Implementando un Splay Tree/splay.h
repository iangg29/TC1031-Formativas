//
// Estructuras Formativas
//
// Ian García González
// A01706892
//
// File created on 19/10/21.
//
// Copyright © 2021. All rights reserved.
//
//

#ifndef SPLAY_H_
#define SPLAY_H_

#include <iostream>
#include <sstream>

using namespace std;

/**
 * Splay: Incluye la estructura necesaria para ejecutar el main.cpp.
 * @file: splay.h
 * @author: Ian
 */

template<class T>
class SplayTree;

template<class T>
class Node {
private:
    T value;
    Node *left, *right, *parent;

    Node<T> *succesor();

    Node<T> *rot_right(Node<T> *);

    Node<T> *rot_left(Node<T> *);

public:
    explicit Node(T);

    Node<T> *add(T);

    Node<T> *remove(T);

    Node<T> *find(T);

    void inorder(stringstream &) const;

    void preorder(stringstream &) const;

    Node<T> *splay(Node<T> *, Node<T> *);

    friend class SplayTree<T>;
};

/**
 * @brief Construct a new Node< T>:: Node object
 * 
 * @param val Valor del nodo.
 */
template<class T>
Node<T>::Node(T val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}

/**
 * @brief Agrega un nuevo nodo.
 * 
 * @param val Valor del nuevo nodo.
 * @return Node<T>* Nodo creado.
 */
template<class T>
Node<T> *Node<T>::add(T val) {
    if (val < value) {
        if (left != nullptr) return left->add(val);
        left = new Node<T>(val);
        left->parent = this;
        return left;
    } else {
        if (right != nullptr) return right->add(val);
        right = new Node<T>(val);
        right->parent = this;
        return right;
    }
}

/**
 * @brief Remueve un nodo.
 * 
 * @param val Valor del nodo a remover.
 * @return Node<T>* Nodo eliminado.
 */
template<class T>
Node<T> *Node<T>::remove(T val) {
    Node<T> *succ, *previous;
    if (val < value) {
        if (left != nullptr) {
            if (left->value == val) {
                previous = left;
                if (previous->left != nullptr && previous->right != nullptr) {
                    succ = left->succesor();
                    if (succ != nullptr) {
                        succ->left = previous->left;
                        succ->right = previous->right;
                        succ->parent = previous->parent;
                        if (succ->left) succ->left->parent = succ;
                        if (succ->right) succ->right->parent = succ;
                    }
                    left = succ;
                } else if (previous->right != nullptr) {
                    previous->right->parent = left->parent;
                    left = previous->right;
                } else if (previous->left != nullptr) {
                    previous->left->parent = left->parent;
                    left = previous->left;
                } else {
                    left = nullptr;
                }
                delete previous;
                return this;
            } else {
                return left->remove(val);
            }
        }
    } else if (val > value) {
        if (right != nullptr) {
            if (right->value == val) {
                previous = right;
                if (previous->left != nullptr && previous->right != nullptr) {
                    succ = right->succesor();
                    if (succ != nullptr) {
                        succ->left = previous->left;
                        succ->right = previous->right;
                        succ->parent = previous->parent;
                        if (succ->left) succ->left->parent = succ;
                        if (succ->right) succ->right->parent = succ;
                    }
                    right = succ;
                } else if (previous->right != nullptr) {
                    previous->right->parent = right->parent;
                    right = previous->right;
                } else if (previous->left != nullptr) {
                    previous->left->parent = right->parent;
                    right = previous->left;
                } else {
                    right = nullptr;
                }
                delete previous;
                return this;
            } else {
                return right->remove(val);
            }
        }
    }
    return this;
}

/**
 * @brief Busca un nodo por su valor.
 * 
 * @param val Valor del nodo a buscar.
 * @return Node<T>* Nodo encontrado.
 */
template<class T>
Node<T> *Node<T>::find(T val) {
    if (val == value) return this;
    if (val < value) {
        if (left != nullptr) return left->find(val);
    } else {
        if (right != nullptr) return right->find(val);
    }
    return nullptr;
}

/**
 * @brief Imprime el Splay Tree en orden.
 * 
 * @param aux StringStream
 */
template<class T>
void Node<T>::inorder(stringstream &aux) const {
    if (left != nullptr) left->inorder(aux);
    if (aux.tellp() != 1) aux << " ";
    aux << value;
    if (right != nullptr) right->inorder(aux);
}

/**
 * @brief Imprime el Splay Tree en preorder.
 * 
 * @param aux StringStream
 */
template<class T>
void Node<T>::preorder(stringstream &aux) const {
    aux << value;
    if (left != nullptr) {
        aux << " ";
        left->preorder(aux);
    }
    if (right != nullptr) {
        aux << " ";
        right->preorder(aux);
    }
}

/**
 * @brief Rota el los nodos para moverlo a la raiz,
 * 
 * @param root Raiz del Splay Tree.
 * @param targetNode Target node.
 * @return Node<T>* Target node.
 */
template<class T>
Node<T> *Node<T>::splay(Node<T> *root, Node<T> *targetNode) {
    while (targetNode->parent != nullptr) {
        if (targetNode->parent->value == root->value) {
            if (targetNode->parent->left && targetNode->parent->left->value == targetNode->value) {
                rot_right(targetNode->parent);
            } else {
                rot_left(targetNode->parent);
            }
        } else {
            Node<T> *targetNodeParent = targetNode->parent;
            Node<T> *targetNodeGrandP = targetNodeParent->parent;
            if (targetNodeParent->left && targetNodeGrandP->left &&
                targetNode->value == targetNodeParent->left->value &&
                targetNodeParent->value == targetNodeGrandP->left->value) {
                rot_right(targetNodeGrandP);
                rot_right(targetNodeParent);
            } else if (targetNodeParent->right && targetNodeGrandP->right &&
                       targetNode->value == targetNodeParent->right->value &&
                       targetNodeParent->value == targetNodeGrandP->right->value) {
                rot_left(targetNodeGrandP);
                rot_left(targetNodeParent);
            } else if (targetNodeParent->left && targetNodeGrandP->right &&
                       targetNode->value == targetNodeParent->left->value &&
                       targetNodeParent->value == targetNodeGrandP->right->value) {
                rot_right(targetNodeParent);
                rot_left(targetNodeGrandP);
            } else {
                rot_left(targetNodeParent);
                rot_right(targetNodeGrandP);
            }
        }
    }
    return targetNode;
}

/**
 * @brief Obtiene el sucesor de un nodo.
 * 
 * @return Node<T>* Sucesor del nodo.
 */
template<class T>
Node<T> *Node<T>::succesor() {
    Node<T> *le = left, *ri = right;
    if (right == nullptr) {
        if (left != nullptr) left = nullptr;
        if (le) le->parent = nullptr;
        return le;
    }

    if (right->left == nullptr) {
        right = right->right;
        if (right) right->parent = parent;
        if (ri) {
            ri->right = nullptr;
            ri->parent = nullptr;
        }
        return ri;
    }

    Node<T> *p = right, *c = right->left;
    while (c->left != nullptr) {
        p = c;
        c = c->left;
    }
    p->left = c->right;
    if (p->left != nullptr) p->left->parent = p;
    c->right = nullptr;
    return c;
}

/**
 * @brief Rota al lado derecho.
 * 
 * @param targetNode Nodo a rotar.
 * @return Node<T>* Nodo.
 */
template<class T>
Node<T> *Node<T>::rot_right(Node<T> *targetNode) {
    Node<T> *targetNodeLeft = targetNode->left;
    targetNode->left = targetNodeLeft->right;
    if (targetNodeLeft->right) targetNodeLeft->right->parent = targetNode;
    targetNodeLeft->right = targetNode;
    targetNodeLeft->parent = targetNode->parent;
    targetNode->parent = targetNodeLeft;
    if (targetNodeLeft->parent) {
        if (targetNodeLeft->parent->left && targetNodeLeft->parent->left->value == targetNode->value) {
            targetNodeLeft->parent->left = targetNodeLeft;
        } else {
            targetNodeLeft->parent->right = targetNodeLeft;
        }
    }
    return targetNodeLeft;
}

/**
 * @brief Rota al lado izquierdo.
 * 
 * @param targetNode Nodo a rotar.
 * @return Node<T>* Nodo.
 */
template<class T>
Node<T> *Node<T>::rot_left(Node<T> *targetNode) {
    Node<T> *targetNodeRight = targetNode->right;
    targetNode->right = targetNodeRight->left;
    if (targetNodeRight->left) targetNodeRight->left->parent = targetNode;
    targetNodeRight->left = targetNode;
    targetNodeRight->parent = targetNode->parent;
    targetNode->parent = targetNodeRight;
    if (targetNodeRight->parent) {
        if (targetNodeRight->parent->left && targetNodeRight->parent->left->value == targetNode->value) {
            targetNodeRight->parent->left = targetNodeRight;
        } else {
            targetNodeRight->parent->right = targetNodeRight;
        }
    }
    return targetNodeRight;
}

template<class T>
class SplayTree {
private:
    Node<T> *root;
    uint size = 0;

public:
    SplayTree();

    bool empty() const;

    void add(T);

    void remove(T);

    bool find(T);

    string inorder() const;

    string preorder() const;

    uint getSize();
};

/**
 * @brief Construct a new Splay Tree< T>:: Splay Tree object
 * 
 */
template<class T>
SplayTree<T>::SplayTree() : root(nullptr) {}

/**
 * @brief Verifica si el Splay Tree está vacío.
 * 
 */
template<class T>
bool SplayTree<T>::empty() const {
    return root == nullptr;
}

/**
 * @brief Agrega un nuevo nodo al Splay Tree.
 * 
 * @param val Valor del nuevo nodo.
 */
template<class T>
void SplayTree<T>::add(T val) {
    if (root != nullptr) {
        Node<T> *newNode = root->add(val);
        root = root->splay(root, newNode);
    } else {
        root = new Node<T>(val);
    }
    size++;
}

/**
 * @brief Elimina un nodo del Splay Tree.
 * 
 * @param val Valor del nodo a eliminar.
 */
template<class T>
void SplayTree<T>::remove(T val) {
    if (root != nullptr) {
        if (root->value == val) {
            Node<T> *succ = root->succesor();
            if (succ != nullptr) {
                succ->left = root->left;
                succ->right = root->right;
                succ->parent = nullptr;
                if (succ->left) succ->left->parent = succ;
                if (succ->right) succ->right->parent = succ;
            }
            delete root;
            root = succ;
        } else {
            Node<T> *p = root->remove(val);
            root = root->splay(root, p);
        }
        size--;
    }
}

/**
 * @brief Encuentra un nodo en el Splay Tree.
 * 
 * @param val Valor del nodo a buscar.
 * @return true El nodo fué encontrado.
 * @return false El nodo no fué encontrado.
 */
template<class T>
bool SplayTree<T>::find(T val) {
    if (root != nullptr) {
        Node<T> *foundNode = root->find(val);
        root = root->splay(root, foundNode);
        return root->value == val;
    }
    return false;
}

/**
 * @brief Imprime el Splay Tree en orden.
 * 
 * @return string 
 */
template<class T>
string SplayTree<T>::inorder() const {
    stringstream aux;
    aux << "[";
    if (!empty()) root->inorder(aux);
    aux << "]";
    return aux.str();
}

/**
 * @brief Imorime el Splay Tree en preorder.
 * 
 * @return string 
 */
template<class T>
string SplayTree<T>::preorder() const {
    stringstream aux;
    aux << "[";
    if (!empty()) root->preorder(aux);
    aux << "]";
    return aux.str();
}

/**
 * @brief Obtiene el tamaño del Splay Tree.
 * 
 * @return uint 
 */
template<class T>
uint SplayTree<T>::getSize() {
    return size;
}

#endif  //SPLAY_H_
