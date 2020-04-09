#include <bits/stdc++.h>
using namespace std;
int n,m,a[5005],ans;
bool dfs(int x,int sum,int a[]){
    if(sum==n){
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=j+1;k<=n;k++){
                    if(a[i]+a[j]<=a[k]){
                        return false;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        ans++;
        ans%=m;
        return true;
    }
    for(int i=x;i<=n;i++){
        a[sum+1]=i;
        if(dfs(i,sum+1,a)==false)
            break;
    }
    return true;
}
int main(){
    cin>>n>>m;
    if(n==1){
        cout<<1;
    }
    else if(n==2){
        cout<<3;
    }
    else{
        for(int i=1;i<=n;i++){
            a[1]=i;
            dfs(i,1,a);
        }
        cout<<ans%m;
    }
}
