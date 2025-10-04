#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<vector<float>>v(n,vector<float>(n));
	for(size_t i=0;i<v.size();i++) { 
		for(size_t j=0;j<v[i].size();j++) { 
			cin>>v[i][j];
		}
	}
	for(size_t i=0;i<v.size();i++) { 
		for(size_t j=0;j<v[i].size();j++) { 
			v[i][j]=v[i][j]/n;
			cout<<fixed<<setprecision(2)<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

