/**************************************************************************************
-Nombre: Gabriel Jaramillo Cuberos
-Fecha: 2 de abril, 2025
-Materia: Estructuras de datos
-Tema: Árboles, Programación modular, Automatización de Compilación
**************************************************************************************/

#include "arbolrb.h"

// Constructor del nodo de Árbol Rojo-Negro
Node::Node(int data) {
    this->data = data;
    left = right = parent = NULL; // Inicializa los punteros como nulos
    color = RED; // Un nuevo nodo siempre es rojo por defecto
}

// Constructor del Árbol Rojo-Negro
RBTree::RBTree() {
    root = NULL; // Inicializa la raíz como nula
}

// Función auxiliar para realizar un recorrido inorden (izquierda, raíz, derecha)
void inorderHelper(Node *root) {
    if (root == NULL) return; // Caso base: árbol vacío
    inorderHelper(root->left); // Visita el subárbol izquierdo
    cout << root->data << "  "; // Imprime el dato del nodo
    inorderHelper(root->right); // Visita el subárbol derecho
}

// Función auxiliar para realizar un recorrido por niveles (BFS)
void levelOrderHelper(Node *root) {
    if (root == NULL) return; // Caso base: árbol vacío
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front(); // Obtiene el nodo al frente de la cola
        cout << temp->data << "  "; // Imprime el dato del nodo
        q.pop(); // Elimina el nodo de la cola
        if (temp->left != NULL) q.push(temp->left); // Agrega el hijo izquierdo si existe
        if (temp->right != NULL) q.push(temp->right); // Agrega el hijo derecho si existe
    }
}

// Función para insertar un nodo en un BST estándar (sin considerar balanceo)
Node* BSTInsert(Node* root, Node *pt) {
    if (root == NULL) return pt; // Si el árbol está vacío, el nuevo nodo es la raíz
    if (pt->data < root->data) { // Inserción en el subárbol izquierdo
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    } else if (pt->data > root->data) { // Inserción en el subárbol derecho
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }
    return root;
}

// Rotación a la izquierda para balancear el árbol Rojo-Negro
void RBTree::rotateLeft(Node *&root, Node *&pt) {
    Node *pt_right = pt->right; // Nodo derecho que se convertirá en nueva raíz de la subestructura
    pt->right = pt_right->left;
    if (pt->right != NULL) pt->right->parent = pt;
    pt_right->parent = pt->parent;
    if (pt->parent == NULL) root = pt_right;
    else if (pt == pt->parent->left) pt->parent->left = pt_right;
    else pt->parent->right = pt_right;
    pt_right->left = pt;
    pt->parent = pt_right;
}

// Rotación a la derecha para balancear el árbol Rojo-Negro
void RBTree::rotateRight(Node *&root, Node *&pt) {
    Node *pt_left = pt->left; // Nodo izquierdo que se convertirá en nueva raíz de la subestructura
    pt->left = pt_left->right;
    if (pt->left != NULL) pt->left->parent = pt;
    pt_left->parent = pt->parent;
    if (pt->parent == NULL) root = pt_left;
    else if (pt == pt->parent->left) pt->parent->left = pt_left;
    else pt->parent->right = pt_left;
    pt_left->right = pt;
    pt->parent = pt_left;
}

// Corrige violaciones de las propiedades del Árbol Rojo-Negro tras la inserción
void RBTree::fixViolation(Node *&root, Node *&pt) {
    Node *parent_pt = NULL;
    Node *grand_parent_pt = NULL;
    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;
        
        // Caso cuando el padre del nodo es hijo izquierdo del abuelo
        if (parent_pt == grand_parent_pt->left) {
            Node *uncle_pt = grand_parent_pt->right;
            if (uncle_pt != NULL && uncle_pt->color == RED) { // Caso 1: el tío es rojo
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt; // Se sube al abuelo para continuar la corrección
            } else {
                if (pt == parent_pt->right) { // Caso 2: rotación izquierda
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                // Caso 3: rotación derecha y recoloreo
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        } else { // Caso cuando el padre del nodo es hijo derecho del abuelo
            Node *uncle_pt = grand_parent_pt->left;
            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) { // Caso 1: el tío es rojo
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt; // Se sube al abuelo para continuar la corrección
            } else {
                if (pt == parent_pt->left) { // Caso 2: rotación derecha
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                // Caso 3: rotación izquierda y recoloreo
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
    root->color = BLACK; // La raíz siempre debe ser negra
}

// Función para insertar un nodo en el Árbol Rojo-Negro
void RBTree::insert(const int &data) {
    Node *pt = new Node(data); // Crea un nuevo nodo con el valor dado
    root = BSTInsert(root, pt); // Inserta en el árbol como un BST normal
    fixViolation(root, pt); // Corrige cualquier violación de las reglas Rojo-Negro
}

// Método público para realizar recorrido inorden
void RBTree::inorder() { inorderHelper(root); }

// Método público para realizar recorrido por niveles
void RBTree::levelOrder() { levelOrderHelper(root); }
