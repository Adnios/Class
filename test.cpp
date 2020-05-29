#include <bits/stdc++.h>
#include <iostream>
#define maxn 600
using namespace std;
int line[maxn][maxn],used[maxn],nxt[maxn];
int e,n,m;
bool Find(int x){
    for(int i=1;i<=m;i++){
        if(line[x][i]==1&&!used[i]){
            used[i]=1;
            if(nxt[i]==0||Find(nxt[i])){
                nxt[i]=x;
                return true;
            }
        }
    }
    return false;
}
int match(){
    int sum=0;
    for(int i=1;i<=n;i++){
        memset(used,0,sizeof(used));
        if(Find(i)){
            sum++;
        }
    }
    return sum;
}
int main(){
    cin>>n>>m>>e;
    memset(nxt,0,sizeof(nxt));
    memset(line,0,sizeof(line));
    while(e--){
        int u,v;
        cin>>u>>v;
        line[u][v]=1;
    }
    cout<<match();
}
