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
 
inline void _read(int &x){//非常快 
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
 
void maintain(int o){   //维护节点的信息 
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
     //返回的是所询问的区间的一系列答案， 包括Lmax,Rmax,Sum,Max 
	if(ql<=tree[o].a&&qr>=tree[o].b) return tree[o];   //完全包含 
	int mid=(L+R)>>1; 
	if(qr<=mid) return query(o<<1,L,mid);  //只在左区间 
	else if(ql>mid) return query(o*2+1,mid+1,R);  //只在右区间 
	else if(ql<=mid&&qr>mid){      //与左右区间都有交集 
		int ls=o*2,rs=ls+1;         
		node l=query(ls,L,mid);    //左边 
		node r=query(rs,mid+1,R);  //右边 
		node ans;
		ans.Sum=l.Sum+r.Sum;
		ans.Lmax=max(l.Lmax, l.Sum+r.Lmax);
		ans.Rmax=max(r.Rmax, r.Sum+l.Rmax);
		ans.Max=getmax(l.Rmax+r.Lmax, l.Max, r.Max);
		return ans;
	}
}
 
int main(){
	int i,k,S;
	_read(n); _read(m);
	for(i=1;i<=n;i++){
		_read(s[i]);
		sum[i]=sum[i-1]+s[i];
	}
	build(1,1,n);
	while(m--){
		_read(k);
		if(k==1){
			_read(ql); _read(qr);
			if(ql>qr) swap(ql,qr);  //注意题目中没有保证ql<=qr 
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

