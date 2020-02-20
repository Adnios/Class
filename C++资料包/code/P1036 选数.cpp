#include <bits/stdc++.h>
using namespace std;
int n,k,a[25],ans;

bool isprime(int a){
    for(int i=2;i*i<=a;i++)
        if(a%i==0)
            return false;
    return true;
}
void dfs(int m,int sum,int startx){//m 累加的个数，sum 累加的和 
    if(m==k){
        if(isprime(sum))
            ans++;
        return ;
    }
    for(int i=startx;i<n;i++)
        dfs(m+1,sum+a[i],i+1);
    return ;
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    dfs(0,0,0);
    cout<<ans;
    return 0;
}

