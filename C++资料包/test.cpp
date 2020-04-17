#include <bits/stdc++.h>
using namespace std;
int n,t;
double s;
struct Node{
    int m,v;
}a[110];
bool cmp(Node x,Node y){
    return x.v*y.m>y.v*x.m;
}
int main(){
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i].m>>a[i].v;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(t>=a[i].m){
            s+=a[i].v;
            t-=a[i].m;
        }
        else{
            s+=1.0*t*a[i].v/a[i].m;
            break;
        }
    }
    printf("%.2lf",s);
}
