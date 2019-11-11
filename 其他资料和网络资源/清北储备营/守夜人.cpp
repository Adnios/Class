#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,q;
struct node{
	char type;
	int k;
	int a,b,v;
	int l[30];
}; 
node work[50005];
int father[50005];
int w[50005];
int getfather(int x){
	if(x!=father[x]){
		int root=getfather(father[x]);
		w[x]^=w[father[x]];
		return father[x]=root;
	}
	else return x;
}
void solve(){
	int i,j,k;
	int cnt=0,ans=0;
	int vis[50005];
	memset(vis,0,sizeof(vis));
	bool flag=true;
	for(i=1;i<=q;i++){
		if(work[i].type=='I'){
			cnt++;
			int fx=getfather(work[i].a);
			int fy=getfather(work[i].b);
			if(fx==n)swap(fx,fy);
			if(fx==fy){
				if((w[work[i].a]^w[work[i].b])!=work[i].v){
					printf("The first %d facts are conflicting.\n",cnt);  
            		return;
				}
			}
			else{
				father[fx]=fy;
				w[fx]=(w[work[i].a]^w[work[i].b]^work[i].v);
			}
		}
		else{
			memset(vis,0,sizeof(vis));
			ans=0;
			flag=true;
			for(j=1;j<=work[i].k;j++){
				int fx=getfather(work[i].l[j]);
				if(fx!=n)vis[fx]^=1;
				ans^=w[work[i].l[j]];
			}
			for(j=1;j<=work[i].k;j++){
				if(vis[father[work[i].l[j]]]){
					flag=false;
				}
			}
			if(flag)printf("%d\n",ans);
			else printf("I don't know.\n");
		}
	}
}
int main(){
	int Case=0;
	while(cin>>n>>q&&n!=0&&q!=0){
		printf("Case %d:\n",++Case); 
		memset(work,0,sizeof(work));
		memset(father,0,sizeof(father));
		memset(w,0,sizeof(w));
		int i,j,k;
		char s[1005];
		for(i=0;i<=n;i++)father[i]=i;
		for(i=1;i<=q;i++){
			int a,b,v;
			scanf("%s",s);
			work[i].type=s[0];
			if(s[0]=='I'){
				gets(s);
				if(sscanf(s,"%d%d%d",&a,&b,&v)==2){
					v=b;
					b=n;
				}
				work[i].a=a;work[i].b=b;work[i].v=v;
			}
			else if(s[0]=='Q'){
				scanf("%d",&work[i].k);
				for(j=1;j<=work[i].k;j++){
					scanf("%d",&work[i].l[j]);
				}
			}
		}
		solve();
		puts("");
	}
}

