#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a,long long b,long long k){
}
int main(){
    long long a,b,k;
    cin>>a>>b>>k;
    cout<<a<<'^'<<b<<' '<<"mod"<<' '<<k<<'='<<binpow(a,b,k)%k<<endl;
    return 0;
}
