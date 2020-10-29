
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

// función que resuelve el problema
std::vector<int> resolver(std::vector<int> const& cjt1, std::vector<int> const& cjt2) {

    std::vector<int> sol;

    int i = 0, j = 0;

    if (!cjt1.empty() && !cjt2.empty()) {

        while (i < cjt1.size() -1 || j < cjt2.size() -1) {

            if (cjt1[i] > cjt2[j]) {
                j++;
            }
            else if (cjt1[i] < cjt2[j]) {
                i++;
            }
            else {
                sol.push_back(cjt1[i]);
                //Aqui hacemos esto para poder recorrer hasta el final los dos vectores
                if (i + 1 < cjt1.size()) {
                    i++;
                }
                if (j + 1 < cjt2.size()) {
                    j++;
                }
            }

        }

    }

    return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int valor;
    std::vector<int> cjt1;
    std::vector<int> cjt2;
    std::vector<int> sol;

    std::cin >> valor;

    while (valor != 0) {
        cjt1.push_back(valor);
        std::cin >> valor;
    }

    std::sort(cjt1.begin(), cjt1.end());


    std::cin >> valor;

    while (valor != 0) {
        cjt2.push_back(valor);
        std::cin >> valor;
    }

    std::sort(cjt2.begin(), cjt2.end());

    // escribir sol
    sol = resolver(cjt1, cjt2);


    for (int k = 0; k < (int)sol.size(); k++)
    {
        std::cout << sol[k] << " ";
    }

    std::cout << std::endl;

    cjt1.clear();
    cjt2.clear();
    sol.clear();

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
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif

    return 0;
}