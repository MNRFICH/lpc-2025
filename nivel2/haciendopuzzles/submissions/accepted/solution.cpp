#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	char r, d;
	cin>>n;
	vector<vector<char>>v(n, vector<char>(n));
	string s;
	map<char,int>m;
	for(int i=0; i<n; ++i){
		cin>>s;
		for(int j=0;j<n;j++) { 
			v[i][j]=s[j];
			m[v[i][j]]++;
			
		}
	}
	for(auto it=m.begin(); it!=m.end(); it++){
		if(it->second==1){
			d=it->first;
		}
		if(it->second==n-1){
			r=it->first;
		}
	}
	for(int i=0;i<n;i++) { 
		for(int j=0;j<n;j++) { 
			if(v[i][j]==d){
				cout<<i+1<<" "<<j+1<<" "<<r<<endl;
			}
		}
	}

	return 0;
}

