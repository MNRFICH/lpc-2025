#include <iostream>
#include <set>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n%3==0)cout<<"Cesar"<<endl;
		else cout<<"Pablo"<<endl;
	}
	return 0;
}
