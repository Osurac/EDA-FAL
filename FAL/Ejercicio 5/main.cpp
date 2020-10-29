// Nombre y apellidos del alumno
// Álvaro Miguel Rodríguez Mateos
// Usuario del juez de clase
// A64


#include <iostream>
#include <fstream>
#include <vector>



// función que resuelve el problema
std::vector<int> resolver(std::vector<int>const& datos, int anoI, int anoF) {
    std::vector<int> sol;
    int max = datos[0];

    for (int j = 1; j < datos.size(); j++) {


        if (datos[j] > max) {

            if ((anoI + j) <= anoF) {
                sol.push_back(anoI + j);
                max = datos[j];
            }
        }

    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int anoI, anoF, count, venta;
    std::vector<int> datos;

    std::cin >> anoI >> anoF;
    count = anoF - anoI + 1;

    for (int i = 0; i < count; i++) {
        std::cin >> venta;
        datos.push_back(venta);
    }

    std::vector<int> sol = resolver(datos, anoI, anoF);
    // escribir sol

    for (int k = 0; k < sol.size(); k++)
    {
        std::cout << sol[k] << " ";
    }
    std::cout << std::endl;

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