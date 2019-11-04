/*
N? GRUPO: 07
AUTORES DE LA PRACTICA (Nombres y Apellidos):
David Cantador Piedras
Alvaro Miguel  Rodriguez Mateos
*/

#include <iostream>

using namespace std;

const unsigned int MAX_LON = 1000;

/*
  PASO 1. Describe el o los casos base y justifica
		  resultados asociados.


  PASO 2. Describe el o los casos recursivos, y justifica
		  los resultados asociados.


*/

bool isDigit(char a) {
	if (a >= 40 && a <= 58) {
		return true; 
	}
	else { 
		return false; 
	}
}

int nValores(char a) {

	if (a >= 40 && a <= 47) {
		return -1;
	}
	else if((a >= 48 && a <= 57)) {
		return 1;
	}

}

int exp_prefija(char a[], int n, int i) {
	/* A IMPLEMENTAR */

	int cont = 0;

	if (i != n) {

		for (int j = 0; j <= i; j++) {
			cont += nValores(a[j]);
		}

		if (!isDigit(a[0])) {
			return -1;
		}
		else {
			if (isDigit(a[i])) {
					return exp_prefija(a, n, i + 1);
			}
			else {	
				return i;
			}
		}
	}
	else {

		for (int j = 0; j < n; j++) {
			cont += nValores(a[j]);
		}

		if (cont == 1) {
			return i;
		}
		else {
			int ret = 0;
			if (cont < 0) {
				
				while (cont != 0) {
					ret++;
					cont++;
				}
				return ret;
			}
			else {

				while (cont != 0) {
					ret++;
					cont--;
				}
				return ret;

			}

		}

	}

}

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	else {
		char a[MAX_LON];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << exp_prefija(a, n, 0) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());

}