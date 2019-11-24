#include <queue>
#include <iostream>
using namespace std;
const int N=200;
int n,k;
int s[N];
int mapp[N][N];
int vis[N];
int maxn;
int sum;
void bfs(int x){
    int cnt=1;
    vis[x]=1;
    queue<int> Q;
    Q.push(x);
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        for(int i=1;i<=n;i++){
            if((!vis[i])&&mapp[a][i]){
                vis[i]=1;
                Q.push(i);
                cnt++;
            }
        }
    }
    if(cnt>maxn) maxn=cnt;
}
int main(){
    cin>>n>>k;
    int a,b;
    for(int i=1;i<=k;i++){
        cin>>a>>b;
        mapp[a][b]=mapp[b][a]=1;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bfs(i);
            sum++;
        }
    }
    cout<<sum<<" "<<maxn<<endl;
    return 0;
}
