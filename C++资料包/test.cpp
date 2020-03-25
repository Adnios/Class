#include <bits/stdc++.h>
using namespace std;
long long n,m,mod,res=1;
int main(){
    int a;
    cin>>a;
    cin>>n>>m>>mod;
    for(int i=n-2*m+2;i<=n-m+1;i++)
        res=res*i%mod;
    cout<<res;
}
