//http://www.joyoi.cn/problem/noip2017-treasure  noip2017���� 
#include<iostream>
#include<fstream>
inline bool isSub(int x,int y)  { return (x&y)==y; }
using namespace std;
ifstream fin("treasure2.in");
//ofstream fout("treasure1.out");
const int INF=100000000;
const int STATENUM=4096;
int n,m;
int g[13][13];
int deep[13];
long cost[STATENUM];
long ans;
void dfs(int s){
	for(int i=1;i<=n;i++)
		if (isSub(s,1<<(i-1))){//״̬s����i����״̬ 
			for(int j=1;j<=n;j++)
				if (!isSub(s,1<<(j-1))&&(g[i][j]<INF)){
					long temp=cost[s]+(deep[i]+1)*g[i][j];
					int s1=s|(1<<(j-1));
					if (temp<cost[s1]){
						cost[s1]=temp;
						int tempDeep=deep[j];
						deep[j]= deep[i]+1;
						dfs(s1);
						deep[j]=tempDeep;
					}
				}
			
		}
}
int main(){
	fin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) g[i][j]=INF;		 
	int a,b,v;
	for(int i=0;i<m;i++){
		fin>>a>>b>>v;
		//���ڱ�������ߣ������������������ 
		g[a][b]=min(g[a][b],v);
		g[b][a]=min(g[b][a],v);
	}
	ans=INF;
	for(int i=1;i<=n;i++){//iΪԴ�� 
		for(int s=0;s<=(1<<n)-1;s++) cost[s]=INF;//1<<n��Ϊ2^n��sΪ״̬ 
		deep[i]=0;
		int si=1<<(i-1);//1<<(i-1)Ϊ��i��״̬ 
		cost[si]=0;
		dfs(si); 
		ans=min(ans,cost[(1<<n)-1]);
	}
	cout<<ans<<endl;
}
