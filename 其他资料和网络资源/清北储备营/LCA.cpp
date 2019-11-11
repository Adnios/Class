#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 500005;
const int maxe = 1000005;
int n,m,root;

struct line{
	int from,to;
	line(){}//空构造函数 line p; 
	line(int A,int B){
		//构造函数 line L=line(1,2);
		from=A;to=B;
	}
};
line edge[maxe];
int last[maxn],_next[maxe],e; 
//last[x]表示以x为起点的最后一条边（的编号） 
//_next[i]表示与第i条边起点相同的上一条边（的编号） 
void add_edge(int x,int y){
	edge[++e]=line(x,y);
	_next[e]=last[x];
	last[x]=e;
}
int Fa[maxn][35],Dep[maxn];
void dfs(int x,int fa){
	int i,k,y;
	Fa[x][0]=fa;
	Dep[x]=Dep[Fa[x][0]]+1;                       //记录当前节点的深度 
	k=ceil(log(Dep[x])/log(2));                      //x往上倍增的上限 
	for(i=1;i<=k;i++)Fa[x][i]=Fa[Fa[x][i-1]][i-1];  //倍增计算祖先 
	for(int i=last[x];i;i=_next[i]){
		int v=edge[i].to;
		if(v!=fa)dfs(v,x); 
	}
}
int LCA(int x,int y){
	int i,k,s;
	s=ceil(log(n)/log(2));                 //该树倍增最大可能的上限 
	if(Dep[x]<Dep[y])swap(x,y);      //交换x和y的值 
	/////////////x往上走k层，让x与y处于同一层 //////////
	k=Dep[x]-Dep[y];
	for(i=0;i<=s;i++)
	    if(k&(1<<i))x=Fa[x][i];
	if(x==y)return x;                     //x==y时，x就是最近公共祖先 
	///////////////////////////////////////////////////
	s=ceil(log(Dep[x])/log(2));           //计算向上倍增的上限 
	for(i=s;i>=0;i--)
	    if(Fa[x][i]!=Fa[y][i]){ x=Fa[x][i]; y=Fa[y][i]; }
	return Fa[x][0];
}

int main(){
	int i,j,k;
	cin>>n>>m>>root;
	for(i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	dfs(root,0);
	for(i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",LCA(x,y));
	}
		
} 
