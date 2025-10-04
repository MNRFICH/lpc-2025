#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int n, c=0;
	int a=0;
	cin>>n;
	vector<string>s1(n), s2(n);
	for(int i=0;i<n;i++) { 
		cin>>s1[i];
	}
	for(int i=0;i<n;i++) { 
		cin>>s2[i];
	}
	for(int i=0;i<n;i++) { 
		if(s1[i]==s2[i])c++;
	}
	a=(c*100)/(n);
	cout<<fixed<<setprecision(2)<<a<<"%"<<endl;
	if(a>=90) cout<<"A ritmo!"<<endl;
	else cout<<"Debe mejorar!"<<endl;
	return 0;
}
