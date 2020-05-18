#include <bits/stdc++.h>
using namespace std;
int n,a[200005],dp[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	dp[0]=0;
	int maxx=-999; 
	for(int i=1;i<=n;i++){
		int A=dp[i-1]+a[i];
		int B=a[i];
		dp[i]=max(A,B); 
		maxx=max(dp[i],maxx);
	}
	cout<<maxx;
}
