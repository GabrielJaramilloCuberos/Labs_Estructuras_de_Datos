/**************************************************************************************
-Nombre: Gabriel Jaramillo Cuberos
-Fecha: 2 de abril, 2025
-Materia: Estructuras de datos
-Tema: Arboles, Programacion modular, Automatizacion de Compilacion
**************************************************************************************/
#ifndef ARBOLRB_H
#define ARBOLRB_H

#include <bits/stdc++.h>
using namespace std;

// Definición de colores para los nodos del árbol
enum Color {RED, BLACK};

// Estructura para representar un nodo del árbol
struct Node {
    int data;
    bool color;
    Node *left, *right, *parent;
    Node(int data);
};

// Clase para representar el Árbol Rojo-Negro
class RBTree {
private:
    Node *root;
protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);
public:
    RBTree();
    void insert(const int &n);
    void inorder();
    void levelOrder();
};

#include "arbolrb.cpp"

#endif // ARBOLRB_H
