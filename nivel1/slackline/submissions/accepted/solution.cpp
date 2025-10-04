#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int L, D, M, N;
	if (!(cin >> L >> D >> M >> N)) return 0;
	
	vector<vector<int>> A(M, vector<int>(N));
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			cin >> A[i][j];
			
			// recopilar coordenadas de árboles
			vector<pair<int,int>> trees;
			for (int i = 0; i < M; ++i)
				for (int j = 0; j < N; ++j)
					if (A[i][j] == 1)
						trees.emplace_back(i, j);
			
			vector<int> dists; 
			dists.reserve(trees.size()*trees.size()/2);
			
			auto gcd_int = [](int a, int b){
				if (a < 0) a = -a;
				if (b < 0) b = -b;
				while (b) { int t = a % b; a = b; b = t; }
				return a;
			};
			
			int T = trees.size();
			for (int i = 0; i < T; ++i) {
				for (int j = i+1; j < T; ++j) {
					int r1 = trees[i].first, c1 = trees[i].second;
					int r2 = trees[j].first, c2 = trees[j].second;
					
					int dr = r2 - r1;
					int dc = c2 - c1;
					int adr = abs(dr), adc = abs(dc);
					
					// comprobar si hay árbol intermedio exactamente sobre la recta
					int g = gcd_int(adr, adc);
					bool blocked = false;
					if (g > 1) { // hay puntos equidistantes entre ellos
						int step_r = dr / g;
						int step_c = dc / g;
						for (int t = 1; t < g; ++t) {
							int rr = r1 + t * step_r;
							int cc = c1 + t * step_c;
							if (A[rr][cc] == 1) { blocked = true; break; }
						}
					}
					if (blocked) continue;
					
					// según el enunciado/ejemplos: usamos (|dx|+1, |dy|+1)
					double xdist = double(adr + 1);
					double ydist = double(adc + 1);
					double realDist = D * sqrt(xdist*xdist + ydist*ydist);
					// convertir a entero por floor (coincide con los ejemplos)
					int intDist = int(floor(realDist + 1e-9));
					dists.push_back(intDist);
				}
			}
			
			if (dists.empty()) {
				cout << 0 << "\n";
				return 0;
			}
			
			bool exact = false;
			for (int v : dists) if (v == L) { exact = true; break; }
			if (exact) {
				cout << L << "\n";
				return 0;
			}
			
			int bestLess = INT_MIN;
			int bestGreater = INT_MAX;
			for (int v : dists) {
				if (v < L && v > bestLess) bestLess = v;
				if (v > L && v < bestGreater) bestGreater = v;
			}
			
			if (bestLess != INT_MIN) cout << bestLess << "\n";
			else if (bestGreater != INT_MAX) cout << bestGreater << "\n";
			else cout << 0 << "\n";
			
			return 0;
}
