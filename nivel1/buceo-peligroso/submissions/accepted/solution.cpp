#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n, r, aux;
	cin >> n;
	cin >> r;

	vector<bool> volvio(n,false), vo;
	bool volvieronTodos = true;
	map<int, int> M;

	for (int i = 0; i < r; i++)
	{
		cin >> aux;
		volvio[aux-1] = true;
	}

	for (int i = 0; i < n; i++)
	{
		if (!volvio[i]) {
			if (volvieronTodos) {
				cout << i+1;
				volvieronTodos = false;
				continue;
			}
			cout << ' ' << i+1;
		}
	}
	if (volvieronTodos)
		cout << '*';
	cout << endl;

	return 0;
}
