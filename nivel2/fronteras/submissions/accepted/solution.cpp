#include <iostream>
#include <list>
#include <map>
#include <set>
using namespace std;

int main(int argc, char *argv[]) {

	map<string, string> paises;
	map<string, list<string>> vecindades;
	int N, M;
	string C, P, A, B;
	cin >> N;
	for (int i=0; i<N; ++i) {
		cin >> C >> P;
		paises[C] = P;
	}

	cin >> M;
	for (int i=0; i<M; ++i) {
		cin >> A >> B;
		if (!vecindades.count(A))
			vecindades[A] = list<string>();
		if (!vecindades.count(B))
			vecindades[B] = list<string>();
		vecindades[A].push_back(B);
		vecindades[B].push_back(A);
	}

	cin >> P;
	set<string> vecinos;
	list<string> ciudadesP;
	for (map<string,string>::iterator CP=paises.begin(); CP!=paises.end(); ++CP) {
		// busco las ciudes del pais P
		if (CP->second == P) {
			string c = CP->first;
			// busco las ciudades limitrofes a c
			for (list<string>::iterator cl=vecindades[c].begin(); cl!=vecindades[c].end(); ++cl) {
				if (paises[*cl] == P) continue;
				// agrego el pais de cada ciudad
				vecinos.insert(paises[*cl]);
			}
		}
	}

	if (vecinos.empty()) {
		cout << "NO" << endl;
	} else {
		for (set<string>::iterator it=vecinos.begin(); it!=vecinos.end(); ++it) {
			cout << *it << endl;
		}
	}

	return 0;
}

