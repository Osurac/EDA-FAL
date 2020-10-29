// Nombre y apellidos del alumno
//Álvaro Miguel Rodríguez Mateos
// Usuario del juez de clase
//A64

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado

struct solucion {
    int suma;
    int valor;
};

// Función que resuelve el problema
// Recibe un vector con los datos
// Devuelve suma de los valores y número de sumandos de la suma
solucion resolver(std::vector<int> const& v) {
    // Inicialización de variables
    // Codigo del alumno
    int cnt=1, min=v[0], sum = v[0], res=0;
    solucion sol;

    for (int i = 1; i < v.size(); ++i) {

            if (v[i] < min) {
                min = v[i];
                cnt = 1;
            }
            else if (v[i] == min) {
                cnt++;
            }
           
            sum = sum + v[i];

    }

    res = min * cnt;
    sum =  (sum - res) ;

    if (cnt == v.size()) {
        sol.suma = 0;
        sol.valor = 0;
    }
    else {
        sol.suma = sum;
        sol.valor = v.size() - cnt;

    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de los datos
    int numElem;
    std::cin >> numElem;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamar a la función resolver
    solucion s = resolver(v);
    // Escribir los resultados
    std::cout << s.suma << ' ' << s.valor << '\n';
}

int main() {
    // Para la entrada por fichero. Comentar para mandar a acepta el reto
//#ifndef DOMJUDGE
//    std::ifstream in("sample03.in");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // Para restablecer entrada. Comentar para mandar a acepta el reto

//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif

    return 0;
}
