#include <iostream>
using namespace std;

bool es_primo(int &x){
	if(x==2) return true;
	for(int i=2; i<x; ++i){
		if(x%i==0)return false;
	}
	return true;
}
	
	int main() {
		int n, aux1=0;
		cin>>n;
		for(int i=n-1; i>0; --i){
			if(es_primo(i)){
				aux1=i-2;
				if(es_primo(aux1)){
					cout<<i-2<<" "<<i<<endl;
					break;
				}
			}
			
		}
		return 0;
	}
	
