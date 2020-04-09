# 1
```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,d;
    cin>>m>>d;
    if(m==1&&d<=24)
        cout<<"Pig";
    else
        cout<<"Mouse";
}
```

# 2
```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1||i==n||i+j==n+1){
                cout<<'*';
            }
            else{
                cout<<' ';
            }
        }
        cout<<endl;
    }
}
```

# 3
```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,r,s,c;
    string t,t2;
    cin>>n>>k>>r>>s>>c>>t;
    int ans=0;
    for(int i=0;i<t.size();i++){
        if(i<k){
            if(t[i]=='r'){
                t2+='c';
                ans+=c;
            }
            else if(t[i]=='s'){
                ans+=r;
                t2+='r';
            }
            else{
                ans+=s;
                t2+='s';
            }
        }
        else{
            if(t[i]=='r'&&t2[i-k]!='c'){
                ans+=c;
                t2+='c';
            }
            else if(t[i]=='s'&&t2[i-k]!='r'){
                ans+=r;
                t2+='r';
            }
            else if(t[i]=='c'&&t2[i-k]!='s'){
                ans+=s;
                t2+='s';
            }
            else{
                ans+=0;
                t2+=t[i];
            }
        }
        cout<<ans<<endl;
    }
    cout<<ans;
}

```

# 4
```c++
#include <bits/stdc++.h>
using namespace std;
int n,k,a[105],b[105];
int ans[105];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n-k+1;i++){
        for(int j=1;j<=n;j++)
            b[j]=a[j];
        sort(b+i,b+i+k);
        int num=0;
        for(int k=1;k<=n;k++){
            num=num*10+b[k];
        }
        ans[i]=num;
    }
    sort(ans+1,ans+n-k+1);
    int sum=1;
    for(int i=1;i<n-k+1;i++){
        if(ans[i]!=ans[i+1])
            sum++;
    }
    cout<<sum;
}

```

# 5
```c++
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

```

