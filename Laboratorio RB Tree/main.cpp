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
    tree.insert(11);
    tree.insert(19);
    tree.insert(7);
    tree.insert(14);
    tree.insert(17);
    tree.insert(31);
    tree.insert(26);
    tree.insert(45);
    tree.insert(70);
    cout << "Inorder Traversal of Created Tree\n";
    tree.inorder();
    cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();
    cout << "\n";
    return 0;
}

