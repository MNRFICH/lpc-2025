#include <iostream>
#include <map>
using namespace std;

int factorial(int &x){
	int aux=1;
	for(int i=1; i<=x; ++i){
		aux*=i;
	}
	return aux;
}
	
	int main() {
		string s;
		int d=1, aux=0, n;
		map<char,int>m;
		cin>>s;
		for(int i=0;i<s.size();i++) { 
			m[s[i]]++;
		}
		for(auto it=m.begin(); it!=m.end(); it++){
			if(it->second%2!=0) aux++;
			if(aux==2){
				cout<<"No es posible!"<<endl;
				return 0;
			}
		}
		n=(s.size()/2);
		n=factorial(n);
		for(auto it=m.begin(); it!=m.end(); it++){
			aux=it->second/2;
			d*=factorial(aux);
		}
		cout<<n/d<<endl;
		return 0;
	}
	
	
	
	
	
	
	
	
