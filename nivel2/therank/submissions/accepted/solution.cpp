#include <iostream>
#include <vector>
using namespace std;

struct nota{
	int a, b, c, d, e;
};

int main() {
	int n, mayores=1;
	cin>>n;
	vector<nota>v(n);
	for(size_t i=0;i<v.size();i++) { 
		cin>>v[i].a>>v[i].b>>v[i].c>>v[i].d;
		v[i].e=v[i].a+v[i].b+v[i].c+v[i].d;
	}
	for(int i=0; i<v.size(); ++i){
		if(v[i].e>v[0].e) mayores++;
	}
	cout<<mayores<<endl;
	return 0;
}

