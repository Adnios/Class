#include <bits/stdc++.h>
using namespace std;
const int maxx=1000;
int n,m,graph[maxx][maxx],visit[maxx];
void dfs(int x){
    cout<<x<<" ";
    visit[x]=1;
    for(int i=1;i<=n;i++){
        if(graph[x][i]==1&&visit[i]==0)
            dfs(i);
    }
}
void bfs(int x){
    queue<int> Q;
    Q.push(x);
    visit[x]=1;
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        cout<<a<<" ";
        for(int i=1;i<=n;i++){
            if(graph[a][i]==1&&visit[i]==0){
                visit[i]=1;
                Q.push(i);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        graph[x][y]=graph[x][y]=1;
    }
    bfs(1);
    cout<<endl;
    memset(visit,0,sizeof(visit));
    dfs(1);
    cout<<endl;
}
