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
