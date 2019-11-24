# 合并果子
```c++
#include <iostream>
#include <queue>
using namespace std;
int main(){
	int n;
	cin>>n;
	priority_queue<string,vector<string>,greater<string> > q;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		q.push(s);
	}
	string str;
	cin>>str;
	for(int i=0;i<n;i++){
		string temp=q.top();
		q.pop();
		int j=0;
		int len=str.size();
		for(j=0;j<len;j++){
			if(temp[j]!=str[j])
				break;
		}
		if(j==len)
			cout<<temp<<endl;
	}
}
```
# 一笔画问题
```c++
#include <iostream>
using namespace std;
#define maxn 1001
int g[maxn][maxn];
int du[maxn];
int circuit[maxn];
int n,e,circuitpos=0,i,j,x,y,start;
void find_circuit(int i){
    int j;
    for(j=1;j<=n;j++){
        if(g[i][j]==1){
            g[i][j]=g[j][i]=0;
            find_circuit(j);
        }
    }
    circuit[++circuitpos]=i;
}
int main(){
    cin>>n>>e;
    for(i=1;i<=e;i++){
        cin>>x>>y;
        g[x][y]=g[y][x]=1;
        du[x]++;
        du[y]++;
    }
    start=1;
    for(i=1;i<=n;i++){
        if(du[i]%2==1)
            start=i;
    }
    find_circuit(start);
    for(i=1;i<=circuitpos;i++){
        cout<<circuit[i]<<" ";
    }
    cout<<endl;
    return 0;
}
```
# 家庭问题
```c++
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
```
