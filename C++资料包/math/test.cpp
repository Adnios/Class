#include<bits/stdc++.h>
using namespace std;
int n,m,v[30005],dp[30005];

int main(){
    cin>>n>>m;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            dp[j]=dp[j]+dp[j-v[i]];
        }
    }
    cout<<dp[m];
}
