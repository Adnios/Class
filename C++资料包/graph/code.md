# 求路径为2的路径条数

```c++
#include <bits/stdc++.h>
using namespace std;
int g[100][100],n,m,ans[100][100];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        g[x][y]=1;
        g[y][x]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans[i][j]+=g[i][k]*g[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
```

# P3366 最小生成树

kruskal

```c++
#include <bits/stdc++.h>
using namespace std;
int n,m,ans,tot,f[100000];
struct edge{
    int start,to,val;
}a[2000005];
bool cmp(edge a,edge b){
    return a.val<b.val;
}
int findfather(int x){
    if(f[x]==x)
        return x;
    else{
        f[x]=findfather(f[x]);
        return f[x];
    }
}
void kruskal(){
    for(int i=1;i<=m;i++){
        int u=findfather(a[i].start);
        int v=findfather(a[i].to);
        if(u==v)
            continue;
        else{
            ans+=a[i].val;
            f[u]=v;
            tot++;
            if(tot==n-1)
                break;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
        cin>>a[i].start>>a[i].to>>a[i].val;
    sort(a+1,a+m+1,cmp);
    kruskal();
    cout<<ans;
}
```

prim

```c++
#include <bits/stdc++.h>
using namespace std;
const int maxx=99999;
int n,m,sum,g[100][100],vis[100],dis[100];

int main(){
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(i==j)
    			g[i][j]=0;
    		else
    			g[i][j]=maxx;
		}
	}
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y]=z;
        g[y][x]=z;
    }
    for(int i=1;i<=n;i++)
        dis[i]=g[1][i];
    vis[1]=1;

    for(int i=1;i<=n-1;i++){
        int minn=maxx,minIndex;
        //寻找最近的点
        for(int j=1;j<=n;j++){
            if(vis[j]==0&&dis[j]<minn){
                minn=dis[j];
                minIndex=j;
            }
        }
        vis[minIndex]=1;
        sum+=dis[minIndex];
        for(int j=1;j<=n;j++){
            if(vis[j]==0&&g[minIndex][j]<dis[j]){
                dis[j]=g[minIndex][j];
            }
        }
    }
    cout<<sum;
}
```

```c++
#include<bits/stdc++.h>
using namespace std;
#define inf 123456789
const int maxn=5005;
const int maxm=200005;
struct edge{
    int next,to,dis;
}e[maxm<<1];
int head[maxn],dis[maxn],cnt,n,m,tot,now=1,ans;
//已经加入最小生成树的的点到没有加入的点的最短距离，比如说1和2号节点已经加入了最小生成树，那么dis[3]就等于min(1->3,2->3)
bool vis[maxn];
void add(int from,int to,int dis){
    e[++cnt].next=head[from];
    e[cnt].to=to;
    e[cnt].dis=dis;
    head[from]=cnt;
}

void prim(){
    //先把dis数组附为极大值
    for(int i=2;i<=n;++i){
        dis[i]=inf;
    }
    //这里要注意重边，所以要用到min
    for(int i=head[1];i;i=e[i].next){
        dis[e[i].to]=min(dis[e[i].to],e[i].dis);
    }
    while(++tot<n){//最小生成树边数等于点数-1
        int minn=inf;//把minn置为极大值
        vis[now]=1;//标记点已经走过
        //枚举每一个没有使用的点
        //找出最小值作为新边
        //注意这里不是枚举now点的所有连边，而是1~n
        for(int i=1;i<=n;++i){
            if(!vis[i]&&minn>dis[i]){
                minn=dis[i];
                now=i;
            }
        }
        ans+=minn;
        //枚举now的所有连边，更新dis数组
        for(int i=head[now];i;i=e[i].next){
            int to=e[i].to;
            if(dis[to]>e[i].dis&&!vis[to]){
                dis[to]=e[i].dis;
            }
        }
    }
    cout<<ans;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    	int x,y,z;
    	cin>>x>>y>>z;
    	add(x,y,z);
    	add(y,x,z);
	}
	prim();
    return 0;
}
```

# P1195 口袋的天空

```c++
#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans,tot,f[100000];
struct edge{
    int start,to,val;
}a[2000005];
bool cmp(edge a,edge b){
    return a.val<b.val;
}
int findfather(int x){
    if(f[x]==x)
        return x;
    else{
        f[x]=findfather(f[x]);
        return f[x];
    }
}
void kruskal(){
    for(int i=1;i<=m;i++){
        int u=findfather(a[i].start);
        int v=findfather(a[i].to);
        if(u==v)
            continue;
        else{
            ans+=a[i].val;
            f[u]=v;
            tot++;
            if(tot==n-k)
                break;
        }
    }
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
        cin>>a[i].start>>a[i].to>>a[i].val;
    sort(a+1,a+m+1,cmp);
    kruskal();
    cout<<ans;
}
```

用prim有一个测试用例过不了

```c++
#include<bits/stdc++.h>
using namespace std;
#define inf 123456789
const int maxn=5005;
const int maxm=200005;
struct edge{
    int next,to,dis;
}e[maxm<<1];
int head[maxn],dis[maxn],cnt,n,m,k,tot,now,ans,temp=inf;
//已经加入最小生成树的的点到没有加入的点的最短距离，比如说1和2号节点已经加入了最小生成树，那么dis[3]就等于min(1->3,2->3)
bool vis[maxn];
void add(int from,int to,int dis){
    e[++cnt].next=head[from];
    e[cnt].to=to;
    e[cnt].dis=dis;
    head[from]=cnt;
}

void prim(){
    //先把dis数组附为极大值
    for(int i=2;i<=n;++i){
        dis[i]=inf;
    }
    //这里要注意重边，所以要用到min
    for(int i=head[now];i;i=e[i].next){
        dis[e[i].to]=min(dis[e[i].to],e[i].dis);
    }
    while(++tot<n-k+1){//最小生成树边数等于点数-1
        int minn=inf;//把minn置为极大值
        vis[now]=1;//标记点已经走过
        //枚举每一个没有使用的点
        //找出最小值作为新边
        //注意这里不是枚举now点的所有连边，而是1~n
        for(int i=1;i<=n;++i){
            if(!vis[i]&&minn>dis[i]){
                minn=dis[i];
                now=i;
            }
        }
        ans+=minn;
        //枚举now的所有连边，更新dis数组
        for(int i=head[now];i;i=e[i].next){
            int to=e[i].to;
            if(dis[to]>e[i].dis&&!vis[to]){
                dis[to]=e[i].dis;
            }
        }
    }
    cout<<ans;
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	int x,y,z;
    	cin>>x>>y>>z;
        if(temp>z){
            temp=z;
            now=x;
        }
    	add(x,y,z);
    	add(y,x,z);
	}
    cout<<now<<endl;
    now=1;
	prim();
    return 0;
}
```

# P1194 买礼物

```c++
#include <bits/stdc++.h>
using namespace std;
int A,B,cnt,ans,tot,f[100000];
struct edge{
    int start,to,val;
}a[2000005];
bool cmp(edge a,edge b){
    return a.val<b.val;
}
int findfather(int x){
    if(f[x]==x)
        return x;
    else{
        f[x]=findfather(f[x]);
        return f[x];
    }
}
void kruskal(){
    for(int i=1;i<=cnt;i++){
        int u=findfather(a[i].start);
        int v=findfather(a[i].to);
        if(u==v)
            continue;
        else{
            ans+=a[i].val;
            f[u]=v;
            tot++;
            if(tot==B-1)
                break;
        }
    }
}
int main(){
    cin>>A>>B;
    for(int i=1;i<=B;i++)
        f[i]=i;
    for(int i=1;i<=B;i++)
        for(int j=1;j<=B;j++){
            int temp;
            cin>>temp;
            a[++cnt].start=i;
            a[cnt].to=j;
            if(temp==0)
                a[cnt].val=1234567;
            else
                a[cnt].val=temp;
        }
    sort(a+1,a+cnt+1,cmp);
    kruskal();
    cout<<min(ans+A,A*B);
}
```

```c++
#include<bits/stdc++.h>
using namespace std;
long long A,B,a,N,ans,G[505][505],w[505],k,sum;
bool pd[505];
int main(){
    cin>>A>>B;
    for(int i=1;i<=B;i++){
        for(int j=1;j<=B;j++){
            cin>>G[i][j];
            if(G[i][j]==0)G[i][j]=A;
            if(G[i][j]>A)G[i][j]=A;
        }
    }
    for(int i=1;i<=B;i++){
        w[i]=G[1][i];
    }
    k=1;
    pd[1]=true;
    sum=2;
    while(sum<=B){
        long long mmin=1e9;
        for(int i=2;i<=B;i++){
            if(pd[i]==false&&mmin>w[i]){
                mmin=w[i];
                k=i;
            }
        }
        /* if(mmin==1e9)break; */
        ans+=mmin;
        pd[k]=true;
        for(int i=2;i<=B;i++){
            if(pd[i]==false&&w[i]>G[i][k])w[i]=G[i][k];
        }
        sum++;
    }
    cout<<ans+A<<endl;
    return 0;
}
```

