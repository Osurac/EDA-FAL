
// Nombre y apellidos del alumno
//A64 Álvaro Miguel Rodríguez Mateos
// Usuario del juez de clase

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado

// Funcion que lee de la entrada, resuelve el problema y escribe la salida
void resuelveCaso() {

    // Declaración de variables
    int n;
    int cont = 0;
    std::cin >> n;
    int max = n;

    // Codigo del alumno

    while (n != 0) {

        // Aqui codigo del alumno

        if (n > max) {
            max = n;
            cont = 1;
        }
        else if(n == max) {
            cont++;
        }

        std::cin >> n;

    }

    // Escribir el resultado
    std::cout << max << " " << cont << std::endl;
   
    // Codigo del alumno
    cont = 0; 
    max = 0;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
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
