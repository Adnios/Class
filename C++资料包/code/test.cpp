#include <bits/stdc++.h>
using namespace std;
const int maxx=20005;
int n,m,p,q,father[maxx];
int getfather(int v){
    if(father[v]==v)
        return v;
    else{
        father[v]=getfather(father[v]);
        return father [v];
    }
}
bool Merge(int x,int y){
    int fx,fy;
    fx=getfather(x);
    fy=getfather(y);
    if(fx==fy)
        return true;
    else{
        father[fx]=fy;
        return false;
    }
}
int getNum(int x,int n,int p){
    for(int i=1;i<=n;i++)
        father[i]=i;
    for(int i=1;i<=p;i++){
        int x,y;
        cin>>x>>y;
        int tx=abs(x),ty=abs(y);
        Merge(tx,ty);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(getfather(x)==getfather(i))
            ans++;
    }
    return ans;
}
int main(){
    cin>>n>>m>>p>>q;
    int a1=getNum(1,n,p);
    int a2=getNum(1,m,q);
    cout<<min(a1,a2);
}
