#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
	int n, m, k;
	map<string, float> receta;
	string s;
	float f;

	// Ingredientes por persona
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s >> f;
		receta[s] = f;
	}

	// Asistentes e ingredientes comprados
	cin >> m >> k;
	map<string, float> comprados;
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> f;
		comprados[s] = f;
	}
	
	// ingredientes faltantes
	bool faltan = false;
	map<string, float> faltantes;
	for (auto it = receta.begin(); it!=receta.end(); ++it) {
		if (!comprados.count(it->first)) {
			faltan = true;
			faltantes[it->first] = k*it->second;
		} else if (comprados[it->first] < k*it->second)
		{
			faltan = true;
			faltantes[it->first] = k*it->second - comprados[it->first];
		}
	}

	if (!faltan)
	{
		cout << "Un guiso muy rico!" << endl;
	}
	else
	{
		for (auto i = faltantes.begin(); i != faltantes.end(); ++i)
		{
			cout << i->first << " " << fixed << setprecision(1) << i->second << endl;
		}
	}

	return 0;
}
