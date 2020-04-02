#include <bits/stdc++.h>
using namespace std;
int n;
const long long mod = 100000007;
long long a[3333];//用int会有错误
int main(){
    cin>>n;
    a[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            a[i]+=a[j]*a[i-1-j];
            a[i]%=mod;
        }
    }
    cout<<a[n]%mod;
}

