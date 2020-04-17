#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,cnt=1,s=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a+s<=m)
            s+=a;
        else{
            cnt++;
            s=a;
        }        
    }
    cout<<cnt;
}
