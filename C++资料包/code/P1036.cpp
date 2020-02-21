#include <bits/stdc++.h>
using namespace std;
int a[30];
bool check(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
} 
int count(int S){
	int sum=0;
	while(S!=0){
		if(S&1==1){
			sum++;
		}
		S=S>>1;
	}
	return sum;
}
int main(){
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int U=1<<n;
	for(int S=0;S<U;S++){
		if(count(S)==k){
			int sum=0;
			for(int i=0;i<n;i++){
				if(S&(1<<i)){
					sum+=a[i];
				}
			}
			if(check(sum)==1){
				ans++;
			}
		}
	}
	cout<<ans;
}
