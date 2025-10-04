#include <iostream>
#include <vector>
using namespace std;

int mejor_periodo(
	size_t &ini,
	size_t &fin,
	vector<int> balance,
	int M
) {
	// caso trivial
	if (M >= balance.size()) {
		ini = 0;
		fin = balance.size();
		int suma = 0;
		for (int i=0; i<balance.size(); ++i) {
			suma += balance[i];
		}
		return suma;
	}

	// inicializar
	ini = 0;
	fin = 1;
	int suma = balance[ini];
	for (int i=1; i<M; ++i) {
		suma += balance[fin];
		++fin;
	}

	// recorrer el balance con el periodo
	int suma_aux = suma;
	size_t ini_aux = ini,
	fin_aux = fin;
	while(fin_aux != balance.size()) {
		suma_aux = suma_aux - balance[ini_aux] + balance[fin_aux];
		++ini_aux;
		++fin_aux;
		if (suma_aux > suma) {
			suma = suma_aux;
			ini = ini_aux;
			fin = fin_aux;
		}
	}

	return suma;
}

int main() {
	// meses totales
	int N;
	cin >> N;

	// meses por periodo
	int M;
	cin >> M;

	vector<int> balance(N);
	for (int i=0; i<N; ++i) {
		cin >> balance[i];
	}

	// encontrar mejor periodo
	size_t ini, fin;
	int suma = mejor_periodo(ini, fin, balance, M);

	// encontrar mejor dentro del periodo
	int mejor = ini;
	for (size_t i = ini; i!=fin; ++i) {
		if (balance[i] > balance[mejor])
			mejor = i;
	}

	cout << ini+1 << ' ' << fin << endl;
	cout << suma << endl;
	cout << mejor-ini+1 << endl;

	return 0;
}

