#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v;
int main(){
    cin>>n>>k;
    int a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-k+1;i++){
        int temp[n+5];
        int s1=0;
        for(int k=1;k<=n;k++){
            temp[k]=a[k];
        }
        sort(temp+i,temp+i+k);
        for(int j=1;j<=n;j++){
            s1=s1*10+temp[j];
        }
        v.push_back(s1);
    }
    int ans=1;
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++){
        if(v[i]!=v[i-1])
            ans++;
    }
    cout<<ans;
}
