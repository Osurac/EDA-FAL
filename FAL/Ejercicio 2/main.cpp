// Nombre del alumno 
// Álvaro Miguel Rodríguez Mateos
// Usuario del Juez 
// A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> const& datos, int posicion, int n) {

    int maxIz = datos[0];
    bool esSolucion = true;

    for (int j = 1; j <= posicion; j++) {
        maxIz = std::max(maxIz, datos[j]);
    }

    for (int k = posicion + 1; k < n && esSolucion; k++) {
        if (maxIz >= datos[k]) {
            esSolucion = false;
        }
    }
 
    return esSolucion;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    int posicion, n, valor;
    bool check;

    std::cin >> n;
    std::cin >> posicion;
    std::vector<int> v(n); //Como conocemos el numero de elementos del vector usamos esta constructora

    // leer los datos de la entrada

    for (int i = 0; i < n; i++) { //Rellenamos el vector

        std::cin >> valor;
        v[i] = valor;
    }

    if (posicion != n - 1) {

        // escribir sol
        check = resolver(v, posicion, n);

        if (check) {
            std::cout << "SI" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }


    }
    else {
        std::cout << "SI" << std::endl;
    }

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
   std::ifstream in("datos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif

    return 0;
}