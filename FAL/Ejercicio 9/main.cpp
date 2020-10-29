
// Nombre y apellidos del estudiante
// Álvaro Miguel Rodríguez Mateos
// Usuario del juez
// A64

# include <iostream>
# include <fstream>
# include <vector>


// Funcion que resuelve el problema
void resolver(std::vector <int> valla, int metros ) {

    int max = 0, pos=-1, ceros = 0;
    bool check = false;

    for (int i = 0; i < metros; i++)
    {
        if (valla[i] == 0) {
            max++;
        }

        if (max > 0) {
            pos = 0;
            check = true;
        }
    }

    //// Bucle principal

    for (size_t k = metros; k <= valla.size()- metros; k++)
    {

        for (int j = k; j < k+metros; j++)
        {
            if (valla[j] == 0) {
                ceros++;
                check = true;
            }
        }

        if (check && (ceros >= max)) {
            max = ceros;
            pos = k;
        }

        ceros = 0;
    }

    if (pos >= 0) {
        std::cout << pos << std::endl;
    }
    else {
        std::cout << "No hace falta" << std::endl;
    }

}

// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
    int tamValla, metrosTela, dato;

    std::cin >> tamValla;

    if (tamValla > 0) {

        std::cin >> metrosTela;

        std::vector <int> valla(tamValla);

        for (int i = 0; i < tamValla; i++)
        {
            std::cin >> dato;
            valla[i] = dato; 
        }

        resolver(valla, metrosTela);

    }
    else {
        return false;
    }

    return true;
}
int main() {
    // Para la entrada por fichero .
    /*ifndef DOMJUDGE
    std::ifstream in(" datos .txt ");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    # endif*/


    // Entrada con centinela
    while (resuelveCaso());


    // Para restablecer entrada .
    /*ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system(" PAUSE ");
    # endif*/

    return 0;
}