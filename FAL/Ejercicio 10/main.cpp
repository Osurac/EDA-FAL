﻿// Nombre y apellidos del estudiante
// Álvaro Miguel Rodríguez Mateos
// Usuario del juez
// A64

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado

// Recorremos el vector hasta el final buscando las posiciones en las que el valor es par, y vamos sustituyendo en el mismo vector los datos que si lo son.
// En i = 0 en caso de ser par se sobreescribe a sí mismo y luego ajustamos el tamaño del vector con resize y el número de datos actualizados.


// Coste del algoritmo utilizado

// Como recorremos todo el vector y operamos sobre los datos con operaciones de coste lineal, el orden de complejidad al que pertenece la función resolver sería O(n)


// Esta función recibe un vector con los números de matricula de los alumnos
// Modifica el vector de entrada eliminando los valores impares
void resolver(std::vector<int>& v) {
    // Codigo del alumno
    int cont = 0;

    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 == 0) {
            v[cont] = v[i];
            cont++;
        }
    }

    v.resize(cont);

}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
bool resuelveCaso() {
    // Leer datos de entrada
    int numElem;
    std::cin >> numElem;
    if (numElem == -1) return false;
    std::vector<int> v(numElem);
    for (int i = 0; i < numElem; ++i) {
        std::cin >> v[i];
    }
    // LLamada a la función resolver
    resolver(v);
    // Escribir el vector resultado
    if (v.size() > 0) std::cout << v[0];
    for (int i = 1; i < v.size(); ++i)
        std::cout << ' ' << v[i];
    std::cout << '\n';
    return true;
}

int main() {
    // Para la entrada por fichero. Comentar para acepta el reto
//#ifndef DOMJUDGE
//    std::ifstream in("datos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif

    return 0;
}