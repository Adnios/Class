#include <bits/stdc++.h>
using namespace std;
const int maxx=2005;
int n,m,graph[maxx][maxx],dis[maxx],visit[maxx];
void dijs(int s){
    for(int i=1;i<=n;i++)
        dis[i]=graph[s][i];
    dis[s]=0;
    visit[s]=1;
    for(int i=1;i<n;i++){
        int mindis=maxx,temp=0;
        for(int j=1;j<=n;j++){
            if(visit[j]==0&&dis[j]<mindis){
                mindis=dis[j];
                temp=j;
            }
        }
        visit[temp]=1;
        for(int j=1;j<=n;j++)
            if(dis[j]>dis[temp]+graph[temp][j])
                dis[j]=dis[temp]+graph[temp][j];
    }
}
int main(){
    cin>>n>>m;
    memset(graph,maxx,sizeof(graph));
    for(int i=1;i<=n;i++)
        graph[i][i]=0;
    for(int i=1;i<=m;i++){
        int x,y,v;
        cin>>x>>y>>v;
        graph[x][y]=graph[y][x]=v;
    }
    dijs(1);
    if(dis[n]==maxx)
        cout<<"-1";
    else
        cout<<dis[n];
}
