#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n,m,x,y;
int t;
int f[5005][5005];
int main(){
	scanf("%d%d%d%d",&m,&n,&x,&y);
	for(int i=1;i<=n+2;i++){
		f[i][1]=1;
		for(int j=2;j<=m+1;j++){
			f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
		}
	}
	if(x<=n&&y>n){
		int ans=0;
		for(int i=1;i<=m;i++){
			ans=(ans+((ll)f[x][i]*f[n-x+1][m-i+1]%mod*f[y-n][m-i+1]%mod*f[n*2-y+1][i]%mod))%mod;
		}
		printf("%d",ans);
	}
	else{
		printf("%d",(ll)f[n+1][m]*f[x+n-y+1][m]%mod);
	}
	return 0;
}
