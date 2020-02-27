#include <bits/stdc++.h>
using namespace std;
const int maxn=100010;
int ans;
int main(){
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.size();i++){
        for(int j=1;j<b.size();j++){
            if(a[i]==b[j]&&a[i+1]==b[j-1])
                ans++;
        }
    }
		cout<<(1<<ans);
}
