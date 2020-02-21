#include <bits/stdc++.h>
using namespace std;
const int maxx=20005;
int n,m,father[maxx];
int getfather(int v){
    if(father[v]==v)
        return v;
    else{
        father[v]=getfather(father[v]);
        return father[v];
    }
}
bool Merge(int x,int y){
    int fx=getfather(x);
    int fy=getfather(y);
    if(fx==fy)
        return true;
    else{
        father[fx]=fy;
        return false;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        father[i]=i;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        Merge(x,y);
    }
    int Q;
    cin>>Q;
    for(int i=1;i<=Q;i++){
        int x,y;
        cin>>x>>y;
        if(getfather(x)==getfather(y)){
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
}
