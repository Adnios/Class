# P1181 数列分段

```c++
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
```

# P1094 纪念品分组

```c++
#include <bits/stdc++.h>
using namespace std;
int n,w,a[30010],L=1,cnt;
int main(){
    cin>>w>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(L<=n){
        if(a[n]+a[L]<=w){
            L++;
            n--;
        }
        else{
            n--;
        }
        cnt++;
    }
    cout<<cnt;
}
```

# P1208 牛奶

不完全背包

```c++
#include <bits/stdc++.h>
using namespace std;
int n,m,s;
struct cow{
    int x,y;
}a[5005];
bool cmp(cow e,cow f){
    return e.x<f.x;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(n>=a[i].y){
            s+=a[i].y*a[i].x;
            n-=a[i].y;
        }
        else{
            s+=n*a[i].x;
            break;
        }
    }
    cout<<s<<endl;
}
```

# P1223 排队接水

```c++
#include <bits/stdc++.h>
using namespace std;
int n,a[1010];
long long sum;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=a[i]*1001+i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        cout<<a[i]%1001<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        sum+=a[i]/1001*(n-i);
    }
    printf("%.2lf",1.0*sum/n);
}
```

# P1803

```c++
#include <bits/stdc++.h>
using namespace std;
int n,cur=0,cnt=0;
struct yyy{
    int s,t;
}a[1000100];
bool cmp(yyy x,yyy y){
    return x.t<y.t;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].t;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(a[i].s>=cur){
            cur=a[i].t;
            cnt++;
        }
    }
    cout<<cnt;
}
```

# 2240 部分背包


