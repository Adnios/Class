# 模板题

![pic alt](https://raw.githubusercontent.com/Adnios/Picture/master/img/20200509222707-kmp.png "opt title")

next转移函数（pre前缀函数）

表示最长前缀长度，i,以字符串ababcabaa为例

ptr[len]==ptr[i]		len++;next[i]=len;i++;

ptr[len]!=ptr[i]		len=next[len-1];

![pic alt](https://raw.githubusercontent.com/Adnios/Picture/master/img/20200509224108.png "opt title")

![pic alt](https://raw.githubusercontent.com/Adnios/Picture/master/img/20200509224255.png "opt title")



```c++
#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int nextt[1000005],nextt2[1000005],n,m;
void getNext(){
    nextt[0]=0;
    int len=0;
    int i=1;
    while(i<m){
        if(s2[i]==s2[len]){
            len++;
            nextt[i]=len;
            i++;
        }
        else{
            if(len>0){
                len=nextt[len-1];
            }
            else{//避免死循环len==0
                nextt[i]=len;
                i++;
            }
        }
    }
}
void move_next(){
    for(int i=m-1;i>0;i--){
        nextt2[i]=nextt[i-1];
    }
    nextt2[0]=-1;
}
void kmp(){
    int j=0;
    int i=0;
    while(i<n){
        if(s1[i]==s2[j]){
            i++;j++;
        }
        else{
            j=nextt2[j];
            if(j==-1){//j到了-1
                i++;
                j++;
            }
        }
        if(j==m){
            j=0;
            cout<<i-m+1<<endl;
            i=i-m+1;
        }
    }
}
int main(){
    cin>>s1;
    n=s1.size();
    cin>>s2;
    m=s2.size();
    getNext();
    move_next();
    kmp();
    for(int i=0;i<m;i++){
        cout<<nextt[i]<<" ";
    }
    cout<<endl;
}
```

```c++
#include <iostream>
#include <vector>
#include <cstdio>
#define mod 100007
using namespace std;

vector<int> Hash[100007];
long long maxx, t, n, num;

int read(){
    int w=1,q=0;
	char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=getchar();
    return w*q;
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

bool check(int val) {
    int pos = (val % mod + mod) % mod;
    maxx = max(maxx, pos);
    for (int k = 0; k < Hash[pos].size(); k++) {
        if (Hash[pos][k] == val) {
            return true;
        }
    }
    Hash[pos].push_back(val);
    return false;
}

int main() {
    t=read();
    while (t--) {
        n=read();
        for (int i = 0; i <= maxx; i++) Hash[i].clear();
        maxx = 0;
        for (int i = 1; i <= n; i++) {
            num=read();
            if(!check(num))
                printf("%lld ",num);
        }
        cout << "\n";
    }
    return 0;
}
```

