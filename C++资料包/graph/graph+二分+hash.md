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
//只讲第一种
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
```cpp
#include <bits/stdc++.h>
using namespace std;
int n,x,y,t,ans,len[10010],vis[10010];
vector<int> g[10010];
int dfs(int x){
    if(vis[x])
        return vis[x];
    for(int i=0;i<g[x].size();i++){
        vis[x]=max(vis[x],dfs(g[x][i]));
    }
    vis[x]+=len[x];
    return vis[x];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>len[i];
        while(cin>>y){
            if(y==0)
                break;
            else
                g[y].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dfs(i));
    }
    cout<<ans;
}
//只能得80分
#include <bits/stdc++.h>
using namespace std;
int n,x,y,t,ans,len[10010],vis[10010];
int g[1001][1001];
int dfs(int x){
    if(vis[x])
        return vis[x];
    for(int i=1;i<=n;i++){
    	if(g[x][i]==1) 
            vis[x]=max(vis[x],dfs(i));
    }
    vis[x]+=len[x];
    return vis[x];
}
int main(){
    cin>>n;
    memset(g,0,sizeof(g));
    for(int i=1;i<=n;i++){
        cin>>x>>len[i];
        while(cin>>y){
            if(y==0)
                break;
            else
                g[y][x]=1;
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dfs(i));
    }
    cout<<ans;
}


```

# P4017最大食物链计数
```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int maxm=500005;
const int mod=80112002;
int n,m,ans;
vector<int> g[maxn];
queue<int> q;
int f[maxn],in[maxn],out[maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        out[x]++;
        in[y]++;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
            f[i]=1;
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<g[x].size();i++){
            int y=g[x][i];
            f[y]=(f[x]+f[y])%mod;
            in[y]--;
            if(in[y]==0)
                q.push(y);
        }
    }
    for(int i=1;i<=n;i++){
        if(out[i]==0)
            ans=(ans+f[i])%mod;
    }
    cout<<ans<<endl;
}
```

# P1182 数列分段 Section II(二分)
```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],l,r,mid,ans;
 bool check(int x)
{
    int tot=0,num=0;
    for(int i=1;i<=n;i++)
    {
        if(tot+a[i]<=x)tot+=a[i];
        else tot=a[i],num++;
    }
    return num>=m;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l=max(l,a[i]);
        r+=a[i];
    }
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}
```

# P3370 【模板】字符串哈希
```cpp
#include<bits/stdc++.h>
using namespace std;
const int base=10;
const int mod=23330;
int n,ans;
string s;
vector<string> v[mod];
void convert(string s){
    int hash=1;
    for(int i=0;i<s.size();i++){
        hash=(hash*base+s[i]-'0')%mod;
    }
    string t=s;
    for(int i=0;i<v[hash].size();i++){
        if(v[hash][i]==s)
            return;
    }
    v[hash].push_back(s);
    ans++;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        convert(s);
    }
    cout<<ans<<endl;
}
```
# P1364 医院设置

```c++
#include <bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,l,r,ans=0x3f3f3f3f,a[maxn],g[maxn][maxn];
int main(){
    cin>>n;
    memset(g,0x3f3f3f3f,sizeof(g));
    for(int i=1;i<n;i++)
        g[i][i]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>l>>r;
        if(l>0)
            g[i][l]=g[l][i]=1;
        if(r>0)
            g[i][r]=g[r][i]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(g[i][k]+g[k][j]<g[i][j])
                    g[i][j]=g[i][k]+g[k][j];
            }
        }
    }
    /* for(int i=1;i<=n;i++){ */
    /*     for(int j=1;j<=n;j++){ */
    /*         cout<<g[i][j]<<" "; */
    /*     } */
    /*     cout<<endl; */
    /* } */
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            sum+=g[i][j]*a[j];
        }
        if(sum<ans)
            ans=sum;
    }
    cout<<ans;
}
```

# P3371 【模板】单源最短路径（弱化版） 
```c++
#include <bits/stdc++.h>
using namespace std;
const int maxx=1005;
int n,m,s,g[maxx][maxx],dis[maxx],vis[maxx];
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
    cin>>n>>m>>s;
    memset(g,0x3f3f3f3f,sizeof(g));
    for(int i=1;i<=n;i++){
        g[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int x,y,v;
        cin>>x>>y>>v;
        g[x][y]=min(g[x][y],v);
    }
    dijs(s);
    for(int i=1;i<n;i++){
    	if(dis[i]==0x3f3f3f3f)
		    cout<<(2<<30)-1<<" ";
    	else
       	cout<<dis[i]<<" ";
    }
    if(dis[n]==0x3f3f3f3f)
	      cout<<(2<<30)-1<<" ";
    else
       	cout<<dis[n]<<" ";
    
}
```
