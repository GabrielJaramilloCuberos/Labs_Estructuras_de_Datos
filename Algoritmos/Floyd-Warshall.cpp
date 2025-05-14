/*************************************************************************************************************************
-Nombre: Gabriel Jaramillo Cuberos
-Fecha: 14 de mayo, 2025
-Materia: Estructuras de datos
-Tema: Algoritmo de Floyd-Warshall
-Resumen: Programa que crea un grafo con vértices a partir de una matriz de adyacencia y evalúa la distancia mínima entre el vértice 0 y los demás vértices.
*************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void floyds(vector<vector<int>> &b)
{
    int i, j, k; // Se declaran las variables de los bucles

    //Bucle para vertice intermedio
    for (k = 0; k < b.size(); k++)
    {
        //Bucle para vertice de origen
        for (i = 0; i < b.size(); i++)
        {
            //Bucle para vertice destino
            for (j = 0; j < b.size(); j++)
            {
                // Se evalua si existe un camino desde i hasta k y desde k hasta j y que i y j sean distintos
                if ((b[i][k] * b[k][j] != 0) && (i != j))
                {
                    // Si no existe un camino directo de i a j o si se encuentra uno mas corto pasando por k
                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
                    {
                        // Se actualiza el valor con el nuevo camino mas corto
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }

    // Se imprimen las distancias minimas desde cada nodo hacia los demás
    for (i = 0; i < b.size(); i++)
    {
        cout << "Minimum Cost With Respect to Node:" << i << ":" << endl;
        for (j = 0; j < 3; j++)
        {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> grafo; // Se declara la matriz de adyacencia para un grafo

    // Se inician todos los elementos en 0
    for (int i = 0; i < grafo.size(); i++)
    {
        for (int j = 0; j < grafo.size(); j++)
        {
            grafo[i][j] = 0;
        }
    }

    cout<<"Defina las conexiones: ";
    int op =-1;
    while(op != 0){
        cout<<"0 = Salir, Agregar arista = 1"<<endl;
        cin>>op;
        if(op==1){
            int origen, destino, costo;
            cout<<"Ingrese origen: "<<endl;
            cin>>origen;
            cout<<"Ingrese destino: "<<endl;
            cin>>destino;
            cout<<"Ingrese costo: "<<endl;
            cin>>costo;
            grafo[origen][destino] = costo;
        }
    }

    floyds(grafo); // Se llama a la funcion que ejecuta el algoritmo de Floyd-Warshall

    return 0; // Fin del programa
}
