//Grupo 07
//David Cantador Piedras
//Alvaro Miguel Rodriguez Mateos
#include <algorithm>
#include <iostream>

using namespace std;


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
   P = { n >= 0  a[i]< a[i+1]} El vector a tiene que ser estricamente creciente

*/
unsigned int num_k_emparejados(int v[], unsigned int n, unsigned int k);
/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'

  (1) Definiciones auxiliares (si procede):
	int abs(n) //


  (2) Postcondici�n
	Q= result: PARA_TODO i : 0< i <n: PARA_TODO j : i <= j < n abs(a[i] - a[j]) = k}

 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el
 --- algoritmo


PASO 1. Variables
	int  i;
	int j;
	int result;

PASO 2. Invariante
Lo que hace el código es comprobar todo el vector, desde la posición a[i] hasta la posición a[n-1] para ver si son k-emparejados hasta que i=n
si k = 0 todo número es k-emparejado consigo mismo por eso j se inicializa a i;
result: PARA_TODO i : 0< i <n: PARA_TODO j : i <= j < n abs(a[i] - a[j]) = k} 


PASO 3. Inicializaci�n:
	i = 0;
	j = i;
	result = 0;
PASO 4: Continuaci�n y finalizaci�n:
	i <  n;
	i++;

PASO 5: Cuerpo del bucle
	Si i y j son menores que n  se compara los terminos desde i hasta n del array para comprobar si son k-emparejados
	Entonces se comprueba si la diferencia en valor absoluto desde i consigo misma hasta n-1 es k

PASO 6: Terminaci�n
 La cota seria cuando i = |n| y eso indica que ya no hay mas elementos.

*/


unsigned int num_k_emparejados(int v[], unsigned int n, unsigned int k) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	unsigned int result = 0;
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = i; j < n; j++) {
			if (abs(v[i] - v[j]) == k) result++;
		}
	}
	return result;
}

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo:

*/



bool procesa_caso() {
	int v[100];
	int n, k;
	cin >> n;
	if (n != -1) {
		cin >> k;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << num_k_emparejados(v, n, k) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (procesa_caso());
}