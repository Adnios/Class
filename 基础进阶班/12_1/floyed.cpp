#include <bits/stdc++.h>
using namespace std;
const int maxx=1100;
int n,m,graph[maxx][maxx];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            graph[i][j]=(i==j)?0:maxx;
        }
    }
    for(int i=1;i<=m;i++){
        int x,y,v;
        cin>>x>>y>>v;
        graph[x][y]=graph[y][x]=v;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(graph[i][j]>graph[i][k]+graph[k][j])
                    graph[i][j]=graph[i][k]+graph[k][j];
    int ans=0,flag=0;
    for(int i=2;i<=n;i++){
        ans=max(ans,graph[1][i]);
        if(graph[1][i]==maxx){
            flag=1;
            break;
        }
    }
    if(flag)
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;
}
