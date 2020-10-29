
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

using lli = long long int;
// Calcula un vector con los valores acumulados
// Recibe un vector a con los datos de entrada
// Devuelve en un vector diferente v los datos de entrada acumulados
// Postcondicion de la función para todo i: 0 <= i < v.size(): v[i] = Sum k : 0 <= k <= i: a[i]
void resolver(std::vector<int> const& a, std::vector<lli>& v)
{
    // Aqui codigo del estudiante
    lli sum = 0;

    for (int i = 0; i < (int)a.size(); i++)
    {
        sum += a[i];
        v.push_back(sum);
    }

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // Lee las dos fechas entre las que tenemos datos
    int a1, a2, n;

    std::vector<lli> acumulados;
    std::vector<int> datos;

    std::cin >> a1 >> a2;
    if (a1 == 0 && a2 == 0) return false;

    // Lee el resto de los datos en un vector

    // Aqui código del estudiante

    for (int i = 0; i < a2 - a1 + 1; i++)
    {
        std::cin >> n;
        datos.push_back(n);
    }

    // calcula el vector de acumulados llamando a la funcion resolver

    resolver(datos, acumulados);

    // Aqui código del estudiante

    // Lectura de las preguntas
    int m; std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int f1, f2;
        std::cin >> f1 >> f2;

        // Escribir la respuesta

        // Aqui codigo del estudiante
        if (a1 <= f1 <= a2 && a1 <= f2 <= a2) {
            if (f1 - a1 == 0) {
                std::cout << acumulados[acumulados.size() - (a2 - f2 + 1)] << std::endl;
            }
            else {
                std::cout << acumulados[acumulados.size() - (a2 - f2 + 1)] - acumulados[f1 - a1 - 1] << std::endl;
            }
        }
    }
    std::cout << "---\n";
    acumulados.clear();

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

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



