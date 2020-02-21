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
