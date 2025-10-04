#include <iostream>
using namespace std;

int main() {
	char c;
	int N, L, d=0, j=0;
	cin>>c>>N>>L;
	if(c=='D'){
		for(int i=1;i<=N;i+=2) { 
			d++;
		}
		d*=L;
		cout<<d<<endl;
	}
	if(c=='I'){
		for(int i=2;i<=N;i+=2) { 
			j++;
		}
		j*=L;
		cout<<j<<endl;
	}
	
	return 0;
}

