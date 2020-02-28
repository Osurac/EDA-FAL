/*
GRUPO: 7
COMPONENTES DEL GRUPO:
Álvaro Miguel Rodríguez Mateos
David Cantador Piedras
*/


#include <iostream>


using namespace std;


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  P= n =<0

*/
bool es_sobrado(int n);

/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'

  (1) Definiciones auxiliares (si procede):
	int i;
	int a;
	int b;

  (2) Postcondici�n
	Q={ok = es_sobrado(n)} Donde es_sobrado(n) = a,b i: 0<=i<n :   a = i%10 ^ i/10, b = i%10 ^ i/10;

 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el
 --- algoritmo

 PASO 1. Variables
	int i; variable donde guardamos n y lo modificamos para obtener las cifras.
	bool ok; variable que indica si el num es sobrado y se devuelve.

 PASO 2. Invariante
	ok=es_sobrado(n) ^ n < 0 ^ i: 0<=i<n : a < b;


 PASO 3. Inicializaci�n:
	ok = true;
	i=n;
	a=0;
	b=0;

 PASO 4: Continuaci�n y finalizaci�n:
  i > 0 ya que cuando i = 0 termina el bucle porque ya no hay mas digitos. y si 

 PASO 5: Cuerpo del bucle
	Si a es menor que b entonces es creciente por lo cual el bucle sigue hasta que i sea 0 que indicaria que ya no hay mas cifras.

PASO 6: Terminaci�n
		Cuando ya no queden mas cifras para comparar o solo quede 1 hay que salir.

*/


bool es_sobrado(int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	bool ok=true, exit=false;
	int i = n,ant=0,sig=0;

	
		while (ok && !exit) {
			ant = i % 10;
			i /= 10;
			if (i > 0) {
				sig = i % 10;
				ok = ant < sig;
			}
			else {
				exit = true;
			}
		}
	return ok;
}

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo
La complejidad es o(n) donde n es el número de cifras que tiene el número a comparar.

*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */


int main() {
	int n_casos;
	cin >> n_casos;
	while (n_casos > 0) {
		int n;
		cin >> n;
		if (es_sobrado(n)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		n_casos--;
	}
	return 0;
}