#include <bits/stdc++.h>
using namespace std;
const int maxn=100;
int a[maxn],n,ans=0;
int b1[maxn],b2[maxn],b3[maxn];
void dfs(int x){
	if(x>n){
		ans++;
		if(ans<=3){
			for(int i=1;i<=n;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		return ;
	}
	for(int y=1;y<=n;y++){
		if(b1[y]==0&&b2[x+y]==0&&b3[x-y+n]==0){
			a[x]=y;
			b1[y]=1;b2[x+y]=1;b3[x-y+n]=1;
			dfs(x+1);
			b1[y]=0;b2[x+y]=0;b3[x-y+n]=0;
		}
	}
}
int main(){
	cin>>n;
	dfs(1);
	cout<<ans<<endl;
}

