# 邻接表
```c++
#include <iostream>
using namespace std;
const int maxx=100001;
struct Edge{
    int next,to,dis;
}edge[maxx];
int head[maxx],cnt,n,m;
void add_edge(int from,int to,int dis){
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].dis=dis;
    head[from]=cnt;
}

int main()
{
    cin>>n>>m;
    for (int i = 0;i<m;i++) {
        int a, b, c;
        cin>>a>>b>>c;
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    for(int i=1;i<=n;i++){
        cout<<i<<"  ";
        for(int j=head[i];j!=0;j=edge[j].next){
            cout<<edge[j].to<<" ";
        }
        cout<<endl;
    }
}
```
# dijstra
```c++
#include <bits/stdc++.h>
using namespace std;
const int maxx=2005;
int n,m,g[maxx][maxx],dis[maxx],vis[maxx];
void dijs(int s){
    for(int i=1;i<=n;i++)
        dis[i]=g[s][i];
    dis[s]=0;
    vis[s]=1;
    for(int i=1;i<n;i++){
        int mindis=0x3f3f3f3f,temp=0;
        for(int j=1;j<=n;j++){
            if(vis[j]==0&&dis[j]<mindis){
                mindis=dis[j];
                temp=j;
            }
        }
        vis[temp]=1;
        for(int j=1;j<=n;j++){
            if(dis[j]>dis[temp]+g[temp][j])
                dis[j]=dis[temp]+g[temp][j];
        }
    }
}
int main(){
    cin>>n>>m;
    memset(g,0x3f3f3f3f,sizeof(g));
    for(int i=1;i<=n;i++)
        g[i][i]=0;
    for(int i=1;i<=m;i++){
        int x,y,v;
        cin>>x>>y>>v;
        g[x][y]=g[y][x]=v;
    }
    dijs(1);
    if(dis[n]==0x3f3f3f3f)
        cout<<-1;
    else
        cout<<dis[n];
}

```
# spfa
```c++
#include <bits/stdc++.h>
using namespace std;
const int maxx=3200000;
const int inf=0x3f3f3f3f;
struct edge{
    int next,to,dis;
}edge[maxx];
int n,m,cnt,head[maxx],dis[maxx],vis[maxx];
void add_edge(int from,int to,int dis){
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].dis=dis;
    head[from]=cnt;
}
void spfa(){
    memset(dis,inf,sizeof(dis));
    vis[1]=1;
    dis[1]=0;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        vis[u]=0;
        for(int i=head[u];i!=0;i=edge[i].next){
            int to=edge[i].to;
            int di=edge[i].dis;
            if(dis[to]>dis[u]+di){
                dis[to]=dis[u]+di;
                if(!vis[to]){
                    vis[to]=1;
                    Q.push(to);
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,v;
        cin>>x>>y>>v;
        add_edge(x,y,v);
        add_edge(y,x,v);
    }
    spfa();
    cout<<dis[n]<<endl;
}
```
# 并查集
```c++
#include <bits/stdc++.h>
using namespace std;
const int maxx=20005;
int n,m,father[maxx];
int getfather(int v){
    if(father[v]==v)
        return v;
    else{
        father[v]=getfather(father[v]);
        return father[v];
    }
}
bool Merge(int x,int y){
    int fx=getfather(x);
    int fy=getfather(y);
    if(fx==fy)
        return true;
    else{
        father[fx]=fy;
        return false;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        father[i]=i;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        Merge(x,y);
    }
    int Q;
    cin>>Q;
    for(int i=1;i<=Q;i++){
        int x,y;
        cin>>x>>y;
        if(getfather(x)==getfather(y)){
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
}
```

