#include <bits/stdc++.h>
using namespace std;
int a[10010],n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m--){
		next_permutation(a+1,a+n+1);
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
}
