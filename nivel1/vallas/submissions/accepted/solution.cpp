#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
	int n, k, A=INT_MAX, c=0, s=0, p;
	cin>>n>>k;
	vector<int>V(n);
	for(size_t i=0;i<V.size();i++) { cin>>V[i]; }
	for(size_t i=0;i<V.size();i++) { 
		if(c<k){
			s+=V[i];
			c++;
		}
		else{
			s+=V[i]-V[i-k];
		}
		if(c==k){
			if(s<A){
				A=s; p=i-k+2;
			}
		}
	}
	cout<<p<<endl;
	return 0;
}
