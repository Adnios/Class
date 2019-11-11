#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
#define CLEAR(xxx) memset(xxx,0,sizeof(xxx))
using namespace std;
 
const int maxn=500000+5,inf=1e9;
int n,m;
 
inline void _read(int &x)
{
	char ch=getchar(); bool mark=false;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')mark=true;
	for(x=0;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(mark)x=-x;
}
inline int getmax(int x,int y,int z){
	if(x>=z&&x>=y) return x;
	if(y>=z) return y;  return z;
}
 
struct node{
	int a,b,Lmax,Rmax,Max,Sum;
}tree[maxn*5];
 
int s[maxn],sum[maxn],ql,qr,p;
 
void maintain(int o,int L,int R){  
	int mid=(L+R)>>1,ls=o*2,rs=o*2+1;
	tree[o].Sum=tree[ls].Sum+ tree[rs].Sum;
	tree[o].Lmax=max(tree[ls].Lmax ,tree[ls].Sum+tree[rs].Lmax);
	tree[o].Rmax=max(tree[rs].Rmax ,tree[rs].Sum+tree[ls].Rmax);
	tree[o].Max=getmax(tree[ls].Max,tree[rs].Max,tree[rs].Lmax+tree[ls].Rmax);	
}
 
void build(int o,int L,int R){
	tree[o].a=L;tree[o].b=R;
	if(L==R) tree[o].Lmax=tree[o].Rmax=tree[o].Max=tree[o].Sum=s[L];
	else {
		int mid=(L+R)>>1;
		build(o*2,L,mid); build(o*2+1,mid+1,R);
		maintain(o,L,R);
	}
}
 
void update(int o,int L,int R){
	if(L==R) tree[o].Lmax=tree[o].Rmax=tree[o].Max=tree[o].Sum=s[L];
	else {
		int mid=(L+R)>>1;
		if(p<=mid) update(o<<1,L,mid);
		else update(o*2+1,mid+1,R);
		maintain(o,L,R);   
	}
}
 
node query(int o,int L,int R){  
	if(ql<=tree[o].a&&qr>=tree[o].b) return tree[o];   
	int mid=(L+R)>>1; 
	if(qr<=mid) return query(o<<1,L,mid);  
	else if(ql>mid) return query(o*2+1,mid+1,R);   
	else if(ql<=mid&&qr>mid)
	{     
		int ls=o*2,rs=ls+1;         
		node l=query(ls,L,mid); 
		node r=query(rs,mid+1,R);  
		node ans;
		ans.Sum=l.Sum+r.Sum;
		ans.Lmax=max(l.Lmax, l.Sum+r.Lmax);
		ans.Rmax=max(r.Rmax, r.Sum+l.Rmax);
		ans.Max=getmax(l.Rmax+r.Lmax, l.Max, r.Max);
		return ans;
	}
}
 
int main()
{
	int i,k,S;
	_read(n); _read(m);
	for(i=1;i<=n;i++){
		_read(s[i]);
		sum[i]=sum[i-1]+s[i];
	}
	build(1,1,n);
	while(m--)
	{
		_read(k);
		if(k==1){
			_read(ql); _read(qr);
			if(ql>qr) swap(ql,qr);  
			printf("%d\n",query(1,1,n).Max);
		}
		else {
			_read(p) ;_read(S);
			s[p]=S;
			update(1,1,n);
		}
	}
	return 0;
}

