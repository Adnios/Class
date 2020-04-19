# 求路径为2的路径条数

```c++
#include <bits/stdc++.h>
using namespace std;
int g[100][100],n,m,ans[100][100];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        g[x][y]=1;
        g[y][x]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans[i][j]+=g[i][k]*g[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
```

# P3366 最小生成树

```c++
#include <bits/stdc++.h>
using namespace std;
int n,m,ans,tot,f[100000];
struct edge{
    int start,to,val;
}a[2000005];
bool cmp(edge a,edge b){
    return a.val<b.val;
}
int findfather(int x){
    if(f[x]==x)
        return x;
    else{
        f[x]=findfather(f[x]);
        return f[x];
    }
}
void kruskal(){
    for(int i=1;i<=m;i++){
        int u=findfather(a[i].start);
        int v=findfather(a[i].to);
        if(u==v)
            continue;
        else{
            ans+=a[i].val;
            f[u]=v;
            tot++;
            if(tot==n-1)
                break;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
        cin>>a[i].start>>a[i].to>>a[i].val;
    sort(a+1,a+m+1,cmp);
    kruskal();
    cout<<ans;
}
```

