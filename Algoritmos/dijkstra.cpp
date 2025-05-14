/*************************************************************************************************************************
-Nombre: Gabriel Jaramillo Cuberos
-Fecha: 14 de mayo, 2025
-Materia: Estructuras de datos
-Tema: Algoritmo de Dijkstra
-Resumen: Programa que crea un grafo con 9 vértices a partir de una matriz de adyacencia y evalúa la distancia mínima entre el vértice 0 y los demás vértices.
*************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

// Función auxiliar para encontrar el vertice con la menor distancia que aún no ha sido procesado
int minDistance(int dist[], bool sptSet[], int V)
{
    int min = INT_MAX;
    int min_index;

    //Se recorre vertice por vertice.
    for(int v = 0; v < V; v++)
    {
        // Si el vertice no está en el conjunto de los ya procesados y tiene una distancia menor o igual al mínimo actual
        if(sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];        // Se actualiza el valor minimo
            min_index = v;        // Se guarda el indice de ese vertice
        }
    }
    return min_index; // Retorna el vertice con la menor distancia
}

// Función para imprimir las distancias mínimas desde la fuente a cada vertice
void printSolution(int dist[], int V)
{
    cout << "Vértice \t Distancia desde la Fuente" << endl;
    for(int i = 0; i < V; i++)
    {
        cout << i << " \t\t\t\t" << dist[i] << endl;
    }
}

// Funcion que implementa el algoritmo de Dijkstra
void dijkstra(vector<vector<int>> graph, int src, int V)
{
    int dist[V]; // dist[i] almacena la distancia mínima desde la fuente hasta el vertice i
    bool sptSet[V]; // sptSet[i] es verdadero si el vertice i ya fue incluido en el camino más corto

    // Se inicializan todas las distancias como valor maximo posible y todos los vertices como aun no analizados
    for(int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0; // Se establece la distancia entre el origen hacia si mismo en 0

    // Bucle que encuentra la menor distancia entre vertices
    for(int count = 0; count < V - 1; count++)
    {

        int u = minDistance(dist, sptSet, V); // Se asigna el vertice con la menor distancia entre los que no han sido analizados

        sptSet[u] = true; // Se marca el vertice como analizado

        // Bucle que actualiza valores de distancia de los vértices adyacentes al vertice u
        for(int v = 0; v < V; v++)
        {
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v]; // Se actualiza la distancia
            }
        }
    }

    printSolution(dist, V); // Se imprime el resultado
}

int main()
{
    // Se crea la matriz de adyacencia del grafo con 9 vértices
    vector<vector<int>> grafo =
    {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0,11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9,14, 0, 0, 0 },
        { 0, 0, 0, 9, 0,10, 0, 0, 0 },
        { 0, 0, 4,14,10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8,11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    dijkstra(grafo, 0, 9); // Se ejecuta el algoritmo de Dijkstra desde el vertice 0

    return 0; // Fin del programa
}
