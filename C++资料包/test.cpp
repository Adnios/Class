#include <bits/stdc++.h>
using namespace std;
const int maxx=1000;
int n,m,ans;
vector<int> graph[maxx];
int visit[maxx];
void dfs(int x){
    ans=max(ans,x);
    visit[x]=1;
    for(int i=0;i<graph[x].size();i++){
        if(visit[graph[x][i]]==0)
            dfs(graph[x][i]);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        ans=0;
        memset(visit,0,sizeof(visit));
        dfs(i);
        cout<<ans<<" ";
    }
}
