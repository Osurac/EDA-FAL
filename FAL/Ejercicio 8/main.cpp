
// Nombre y apellidos del estudiante
// Álvaro Miguel Rodríguez Mateos
// Usuario del juez
// A64

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado

// Recibe un vector con los datos de entrada del problema
// Debe contar el número de veces que aparece cada valor usando un vector auxiliar.
// Devuelve un vector con los valores que se repiten el número máximo de veces
// para que la función resuelveCaso solo tenga que escribirlos. 
// Si solo hay un valor que se repite el número máximo de veces el vector de salida
// tendrá solo ese valor 
std::vector<int> resolver(std::vector<int> const& v, int maximoValores) {
    // Aqui codigo del estudiante
  
    std::vector<int> sol(maximoValores+1, 0);
    int max = 0;

    for (int k = 0; k < v.size(); k++)
    {
        sol[v[k]] += 1;

        if (sol[v[k]] > max) {
            max = sol[v[k]];
        }

    }

    sol[0] = max;

    return sol;
}

// Entrada y salida de datos
bool resuelveCaso() {
    int numTiradas, valorMax;
    std::cin >> numTiradas;
    if (numTiradas == -1) { return false; }
    else {
        std::cin >> valorMax;
    }
    // Entrada con centinela
    std::vector<int> v(numTiradas);
    std::vector<int> result;
    for (int& i : v) std::cin >> i;

    // LLamada a la funcion resolver para calcular los valores que 
    // aparecen más veces

    result = resolver(v, valorMax);

    // Escribir los valores del vector que ha calculado resolver

    for (size_t i = result.size()-1; i > 0 ; i--)
    {
        if (result[i] == result[0]) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return true;
}

int main() {

//#ifndef DOMJUDGE
//    std::ifstream in("datos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt    
//#endif

    while (resuelveCaso())
        ;

//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif

    return 0;
}
