/**************************************************************************************
-Nombre: Gabriel Jaramillo Cuberos
-Fecha: 2 de abril, 2025
-Materia: Estructuras de datos
-Tema: Arboles, Programacion modular, Automatizacion de Compilacion
**************************************************************************************/
#include <bits/stdc++.h>
#include "arbolrb.h"

int main() {
    // Creación de un Árbol Rojo-Negro
    RBTree tree;
    
    // Inserción de nodos en el árbol
    tree.insert(11);
    tree.insert(19);
    tree.insert(7);
    tree.insert(14);
    tree.insert(17);
    tree.insert(31);
    tree.insert(26);
    tree.insert(45);
    tree.insert(70);
    
    // Mostrar el recorrido en inorden (izquierda, raíz, derecha)
    cout << "Inorder Traversal of Created Tree\n";
    tree.inorder();
    
    // Mostrar el recorrido por niveles (nivel por nivel)
    cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();
    
    cout << "\n";
    return 0;
}
