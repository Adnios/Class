#include <bits/stdc++.h>
using namespace std;
const int maxn=310;
struct p{
	int x,y;
};
queue<p> Q;
int ans[maxn][maxn];
int walk[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int main(){
	int n,m,sx,sy;
	memset(ans,-1,sizeof(ans));
	cin>>n>>m>>sx>>sy;
	p tmp={sx,sy};
	Q.push(tmp);
	ans[sx][sy]=0;
	while(!Q.empty()){
		p u=Q.front();
		int ux=u.x,uy=u.y;
		Q.pop();
		for(int k=0;k<8;k++){
			int x=ux+walk[k][0],y=uy+walk[k][1];
			int d=ans[ux][uy];
			if(x<1||x>n||y<1||y>m||ans[x][y]!=-1){
				continue;
			}
			ans[x][y]=d+1;
			p tmp={x,y};
			Q.push(tmp);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-5d",ans[i][j]);
		}
		cout<<endl;
	}
}
