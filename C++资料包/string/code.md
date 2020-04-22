# P1603 斯诺登密码

```c++
#include <bits/stdc++.h>
using namespace std;
string a[]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","a","both","another","first","second","third"};
int b[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,1,2,1,1,2,3};
int c[7],n;
string t;
int main(){
    for(int i=1;i<=6;i++){
        cin>>t;
        for(int j=0;j<26;j++){
            if(t==a[j]){
                c[++n]=b[j];
                c[n]*=c[n];
                c[n]%=100;
            }
        }
    }
    sort(c+1,c+n+1);
    if(n==0){
        cout<<0;
        return 0;
    }
    cout<<c[1];
    for(int i=2;i<=n;i++){
        if(c[i]<10)
            cout<<0;
        cout<<c[i];
    }
}
```

# P1071 潜伏者

```c++
#include <bits/stdc++.h>
using namespace std;
string x,y;
char a[100],b[100];
int len,cnt;
int main(){
    memset(a,'?',sizeof(a));
    memset(b,'?',sizeof(b));
    cin>>x>>y;
    len=x.length();
    for(int i=0;i<len;i++){
        if(a[x[i]]=='?'&&b[y[i]]=='?'){
            a[x[i]]=y[i];
            b[y[i]]=x[i];
            cnt++;
        }
        else if(a[x[i]]!=y[i]){
            cout<<"Failed";
            return 0;
        }
    }
    if(cnt<26){
        cout<<"Failed";
        return 0;
    }
    string t;
    cin>>t;
    for(int i=0;i<t.length();i++){
        cout<<a[t[i]];
    }
    return 0;
}
```

# P1012 拼数

```c++
#include <bits/stdc++.h>
using namespace std;
//8123 7 812
bool cmp(string x,string y){
    return x+y<y+x;
}
int main(){
    int n;
    cin>>n;
    string a[n+10];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=n;i>=1;i--){
        cout<<a[i];
    }
}
```

