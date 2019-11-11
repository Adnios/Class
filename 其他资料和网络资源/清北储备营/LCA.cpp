#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 500005;
const int maxe = 1000005;
int n,m,root;

struct line{
	int from,to;
	line(){}//�չ��캯�� line p; 
	line(int A,int B){
		//���캯�� line L=line(1,2);
		from=A;to=B;
	}
};
line edge[maxe];
int last[maxn],_next[maxe],e; 
//last[x]��ʾ��xΪ�������һ���ߣ��ı�ţ� 
//_next[i]��ʾ���i���������ͬ����һ���ߣ��ı�ţ� 
void add_edge(int x,int y){
	edge[++e]=line(x,y);
	_next[e]=last[x];
	last[x]=e;
}
int Fa[maxn][35],Dep[maxn];
void dfs(int x,int fa){
	int i,k,y;
	Fa[x][0]=fa;
	Dep[x]=Dep[Fa[x][0]]+1;                       //��¼��ǰ�ڵ����� 
	k=ceil(log(Dep[x])/log(2));                      //x���ϱ��������� 
	for(i=1;i<=k;i++)Fa[x][i]=Fa[Fa[x][i-1]][i-1];  //������������ 
	for(int i=last[x];i;i=_next[i]){
		int v=edge[i].to;
		if(v!=fa)dfs(v,x); 
	}
}
int LCA(int x,int y){
	int i,k,s;
	s=ceil(log(n)/log(2));                 //�������������ܵ����� 
	if(Dep[x]<Dep[y])swap(x,y);      //����x��y��ֵ 
	/////////////x������k�㣬��x��y����ͬһ�� //////////
	k=Dep[x]-Dep[y];
	for(i=0;i<=s;i++)
	    if(k&(1<<i))x=Fa[x][i];
	if(x==y)return x;                     //x==yʱ��x��������������� 
	///////////////////////////////////////////////////
	s=ceil(log(Dep[x])/log(2));           //�������ϱ��������� 
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
