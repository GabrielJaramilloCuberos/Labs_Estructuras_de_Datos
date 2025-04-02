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
    int data;         // Valor almacenado en el nodo
    bool color;       // Color del nodo (Rojo o Negro)
    Node *left, *right, *parent; // Punteros a los nodos hijo izquierdo, derecho y al nodo padre
    Node(int data);   // Constructor del nodo
};

// Clase para representar el Árbol Rojo-Negro
class RBTree {
private:
    Node *root;  // Raíz del árbol
protected:
    void rotateLeft(Node *&, Node *&);  // Rotación a la izquierda
    void rotateRight(Node *&, Node *&); // Rotación a la derecha
    void fixViolation(Node *&, Node *&);// Corrección de violaciones tras la inserción
public:
    RBTree();  // Constructor del árbol
    void insert(const int &n);  // Inserta un nuevo nodo
    void inorder();  // Recorre el árbol en inorden
    void levelOrder(); // Recorre el árbol por niveles
};

#include "arbolrb.cpp"

#endif // ARBOLRB_H
