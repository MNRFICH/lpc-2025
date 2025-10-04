#include <iostream>
#include <vector>
using namespace std;

struct titan{
	string nombre;
	int altura;
	bool c=0;
};

int main() {
	int n, w;
	cin>>n>>w;
	vector<titan>v(n);
	for(int i=0;i<n;i++) { 
		cin>>v[i].nombre>>v[i].altura;
		if(v[i].altura>w) v[i].c=1;
	}
	for(int i=0;i<n;i++) { 
		if(v[i].c==1) cout<<v[i].nombre<<endl;
	}
	return 0;
}

