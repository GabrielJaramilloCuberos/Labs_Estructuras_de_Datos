/**************************************************************************************
-Nombre: Gabriel Jaramillo Cuberos
-Fecha: 2 de abril, 2025
-Materia: Estructuras de datos
-Tema: Arboles, Programacion modular, Automatizacion de Compilacion
**************************************************************************************/
#include <bits/stdc++.h>
#include "arbolrb.h"

int main() {
    RBTree tree;
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    cout << "Inorder Traversal of Created Tree\n";
    tree.inorder();
    cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();
    cout << "\n";
    return 0;
}

