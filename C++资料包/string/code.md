# find()

```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int i=0;
    while(i<s1.size()){
        if(s1.find(s2,i)==s1.npos)
            break;
        cout<<1+s1.find(s2,i)<<endl;
        i=s1.find(s2,i)+1;
    }
}
```


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

# P3805 manacher

```c++
#include <bits/stdc++.h>
using namespace std;
int expandAroundCenter(string s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
}
string longestPalindrome(string s) {
    if (s.length() < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i); //从一个字符扩展
        int len2 = expandAroundCenter(s, i, i + 1); //从两个字符之间扩展
        int len = max(len1, len2);
        //根据 i 和 len 求得字符串的相应下标
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}

int main(){
    string s;
    cin>>s;
    cout<<longestPalindrome(s).size();
}
```

```c++
#include <bits/stdc++.h>
#define maxn 51000100
using namespace std;
int n,hw[maxn],ans;
char a[maxn],s[maxn<<1];
void manacher()
{
    int maxright=0,mid;
    for(int i=1;i<n;i++)
    {
        if(i<maxright)
            hw[i]=min(hw[(mid<<1)-i],hw[mid]+mid-i);
        else
            hw[i]=1;
        for(;s[i+hw[i]]==s[i-hw[i]];++hw[i]);
        if(hw[i]+i>maxright)
        {
            maxright=hw[i]+i;
            mid=i;
        }
    }
}
void change()
{
    s[0]=s[1]='#';
    for(int i=0;i<n;i++)
    {
        s[i*2+2]=a[i];
        s[i*2+3]='#';
    }
    n=n*2+2;
    s[n]=0;
}
int main()
{
    scanf("%s",a);
    n=strlen(a);
    change();
    manacher();
    ans=1;
    for(int i=0;i<n;i++)
        ans=max(ans,hw[i]);
    printf("%d",ans-1);
    return 0; 
}
```

# 匈牙利算法

```c++
#include <bits/stdc++.h>
#define maxn 600
using namespace std;
int line[maxn][maxn],used[maxn],nxt[maxn];
int e,n,m;
bool Find(int x){
    for(int i=1;i<=m;i++){
        if(line[x][i]==1&&!used[i]){
            used[i]=1;
            if(nxt[i]==0||Find(nxt[i])){
                nxt[i]=x;
                return true;
            }
        }
    }
    return false;
}
int match(){
    int sum=0;
    for(int i=1;i<=n;i++){
        memset(used,0,sizeof(used));
        if(Find(i)){
            sum++;
        }
    }
    return sum;
}
int main(){
    cin>>n>>m>>e;
    memset(nxt,0,sizeof(nxt));
    memset(line,0,sizeof(line));
    while(e--){
        int u,v;
        cin>>u>>v;
        line[u][v]=1;
    }
    cout<<match();
}
/*
7
1 1
1 2
2 2
2 3
3 1
3 2
4 3
 */
```


