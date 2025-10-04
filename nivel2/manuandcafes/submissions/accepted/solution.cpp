#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int m, n, min=500, id;
	cin>>m>>n;
	vector<int>v(n);
	map<int,int>cafes;
	for(int i=0;i<v.size();i++) { 
		cin>>v[i];
		cafes[v[i]]++;
	}
	for(auto it=cafes.begin(); it!=cafes.end(); ++it){
		if(it->second<min){
			id=it->first;
			min=it->second;
		}
	}
	cout<<id<<endl;
	return 0;
}
