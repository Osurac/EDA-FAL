
// Nombre y apellidos del estudiante
// Álvaro Miguel Rodríguez Mateos
// Usuario del juez
// A64

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <utility>

// Explicación del algoritmo utilizado

// Recorremos el vector una vez, chequeamos si la altura del edificio es estrictamente mayor a la altura del coche y empezamos a contar el numero de edificios que lo cumplen. 
// Una vez salimos de la condición de serlo, comprobamos si este contador es el máximo encontrado, si es así, actualizamos la variable del máximo y los punteros a las posiciones que nos han llegado por la cabecera. Actualizamos el contador a 0 para futuras iteraciones.

// Coste del algoritmo utilizado
// Como recorremos el vector una sola vez y solo realizamos operaciones de coste lineal sobre el vector y las variables (comparaciones, incrementos...) el orden de complejidad de la funcion es O(n)

// La función recibe un vector con las alturas de los edificios, y la altura de la nave que realizará el rescate
// Devuelve las posiciones de inicio y fin del segmento máximo encontrado.
void resolver(std::vector<int> const& v, int alturaNave, int & posIni, int& posFin) {

// Codigo del alumno

    int cont = 0, max = 0;

    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] > alturaNave) {
            cont++;
        }
        else {
            
            if (cont > max) {
                max = cont;
                posFin = i - 1;
                posIni = i - cont;
            }

            cont = 0;
        }
    }

}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
void resuelveCaso() {
    // Lectura de los datos de entrada
    int numElem, alturaNave;
    std::cin >> numElem >> alturaNave;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamada a la función resolver
    int p, q;
    resolver(v, alturaNave, p, q);
    // Escribir el resultado
    std::cout << p << ' ' << q << "\n";
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
    //    
    return 0;
}

