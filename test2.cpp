#include <bits/stdc++.h>
using namespace std;
int f[100005],n,p,g[10005][400];
int main(){
	cin>>n>>p;
	int m=sqrt(n)+1;
	f[0]=1;
	//n*m,m=n^0.5
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){
			f[j]=(f[j]+f[j-i])%p;
		}
	}
	m++;
	g[0][0]=1;
	//(n-m)*m
	for(int i=m;i<=n;i++){
		g[i][1]=1;
		for(int j=2;j<=m;j++){
			g[i][j]=(g[i-j][j]+g[i-m][j-1])%p;
		}
	}
	int ans=0;
	//n===>i,n-i 
	//n*m
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			ans=(ans+f[i]*g[n-i][j])%p;
		}
	}
	cout<<ans;
}

