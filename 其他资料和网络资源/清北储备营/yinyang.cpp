#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int edges;
int fir[2222222];
int nex[4444444];
int tar[4444444];
int pop[2222222];
int q[2222222];
int d[2222222];
int yin;
int yang;

void edgeins(int u,int v)
{
	nex[edges]=fir[u];
	fir[u]=edges;
	tar[edges]=v;
	edges++;
	nex[edges]=fir[v];
	fir[v]=edges;
	tar[edges]=u;
	edges++;
}

int main()
{
	freopen("yinyang.in","r",stdin);
	freopen("yinyang.out","w",stdout);
	
	int n,i,u,v;
	int h,t,e;
	
	scanf("%d",&n);
	edges=2;
	
	for (i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		edgeins(u,v); 
	}
	
	for (i=1;i<=n;i++)
		scanf("%d",pop+i);
	
	yin=yang=0;
	d[1]=2;
	q[0]=1; t=1;
	for (h=0;h<t;h++)
	{
		u=q[h];
		for (e=fir[u];e!=0;e=nex[e])
		{
			v=tar[e];
			if (d[v]) continue;
			d[v]=d[u]^1;
			q[t++]=v;
		}
		
		while (pop[u]>0)
		{
			pop[u]-=(pop[u]&-pop[u]);
			d[u]^=1;
		}
		if (d[u]==2) yin++;
		else yang++;
	}
	
	printf("%I64d\n",1ll*yin*yang);
	
	return 0;
}
