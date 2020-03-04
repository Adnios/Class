# P3916 图的遍历

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxx=1000;
int n,m;
vector<int> graph[maxx];
int visit[maxx];
void dfs(int x){
    cout<<x<<" ";
    visit[x]=1;
    for(int i=0;i<graph[x].size();i++){
        if(visit[graph[x][i]]==0)
            dfs(graph[x][i]);
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
        for(int i=0;i<graph[a].size();i++){
            if(visit[graph[a][i]]==0){
                visit[graph[a][i]]=1;
                Q.push(graph[a][i]);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    bfs(1);
    cout<<endl;
    memset(visit,0,sizeof(visit));
    dfs(1);
    cout<<endl;
}
```
```cpp
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

```

```cpp
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> p[100005];
int a[100005];
void solve(int x,int v){
    a[x]=v;
    for(int i=0;i<p[x].size();i++){
        if(a[p[x][i]]==0)
            solve(p[x][i],v);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        p[v].push_back(u);
    }
    for(int i=n;i>=0;i--){
        if(a[i]==0)
            solve(i,i);
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
}
```

# P1113杂物
```cpp
#include<iostream>
using namespace std;
int n,num,len,father,dp[10005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num>>len;
        int tmp=0;
        while(cin>>father){
            if(father==0)
                break;
            tmp=max(dp[father],tmp);
        }
        dp[i]=tmp+len;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}

```

