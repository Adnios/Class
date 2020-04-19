#include <bits/stdc++.h>
using namespace std;
int n,m,sum,g[100][100],vis[100],dis[100];

int main(){
    cin>>n>>m;
    memset(g,0x3f3f3f3f,sizeof(g));
    for(int i=1;i<=n;i++)
        g[i][i]=0;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y]=z;
        g[y][x]=z;
    }
    for(int i=1;i<=n;i++)
        dis[i]=g[1][i];
    for(int i=1;i<=n;i++){
        if(i==1)
            vis[i]=1;
        cout<<vis[i]<<endl;
    }
    for(int i=1;i<=n-1;i++){
        int min=0x3f3f3f3f,minIndex;
        //寻找最近的点
        for(int j=1;j<=n;j++){
            if(vis[i]==0&&dis[j]<min){
                min=dis[j];
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
