#include <bits/stdc++.h>
using namespace std;
const int maxx=2005;
int n,m,g[maxx][maxx],dis[maxx],vis[maxx];
void dij(int s){
    for(int i=1;i<=n;i++)
        dis[i]=g[s][i];
    dis[s]=0;
    vis[s]=1;
    for(int i=1;i<n;i++){
        int mindis=0x3f3f3f3f,temp=0;
        for(int j=1;j<=n;j++){
            if(vis[j]==0&&dis[j]<=mindis){
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
    dij(1);
    if(dis[n]==0x3f3f3f3f)
        cout<<-1;
    else
        cout<<dis[n];
}
