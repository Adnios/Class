# freopen
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    freopen("test.in","r",stdin);
    freopen("test.out","a",stdout);
    cin>>a>>b;
    cout<<a<<" "<<b<<endl;
}

```

# P1143
```cpp
#include <bits/stdc++.h>
using namespace std;
string s;
int n,k;
int sum=0;
stack<char> st;
void n_10(){
    for(int i=0;i<s.size();i++){
        int e=pow(n,s.size()-i-1);
        if(s[i]<'A'){
            e*=(s[i]-'0');
            sum+=e;
        }
        else{
            e*=(s[i]-'A'+10);
            sum+=e;
        }
    }
}
void ten_k(){
    while(sum){
        int temp=sum%k;
        char t;
        if(temp<10)
            t='0'+temp;
        else
            t='A'+(temp-10);
        st.push(t);
        sum/=k;
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}
int main(){
    cin>>n>>s>>k;
    n_10();
    /* cout<<sum<<endl; */
    ten_k();
}

```

# P1100 高地位转换
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    cout<<((x&0x0000ffff)<<16|(x&0xffff0000)>>16)<<endl;
}

```

# P1029 最大公约数和最小公倍数问题
```cpp
#include<bits/stdc++.h>
using namespace std;
int m,n,ans;
int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
int main(){
    cin>>m>>n;
    if(m==n)ans--;
    n*=m;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0&&gcd(i,n/i)==m) ans+=2;
    }
    cout<<ans;
    return 0;
    }
```
# P1866 编号
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a[100];
    long long ans=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        ans*=a[i]-i+1;
        ans%=1000000007;
    }
    cout<<ans;
}

```
# P5520 [yLOI2019] 青原樱
```cpp
#include <bits/stdc++.h>
using namespace std;
long long n,m,mod,res=1;
int main(){
    int a;
    cin>>a;
    cin>>n>>m>>mod;
    for(int i=n-2*m+2;i<=n-m+1;i++)
        res=res*i%mod;
    cout<<res;
}
```
# P1044 栈
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a[20]={1};
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            a[i]+=a[j]*a[i-1-j];
        }
    }
    cout<<a[n];
}

```
# P1744 矩阵II
```cpp
#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    int a[1000]={1};
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            a[i]+=a[j]*a[i-1-j];
            a[i]%=100;
        }
    }
    cout<<a[n]%100;
}

```
# P1976 鸡蛋饼
```cpp
#include <bits/stdc++.h>
using namespace std;
int n;
const long long mod = 100000007;
long long a[3333];//用int会有错误
int main(){
    cin>>n;
    a[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            a[i]+=a[j]*a[i-1-j];
            a[i]%=mod;
        }
    }
    cout<<a[n]%mod;
}


```

# P3390 【模板】矩阵快速幂
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL m=1e9+7;
LL n,k;
struct matrix{
    LL data[105][105];
};
matrix mul(matrix a,matrix b){
    matrix c;
    memset(c.data,0,sizeof(c.data));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                c.data[i][j]=(c.data[i][j]+a.data[i][k]*b.data[k][j]%m)%m;
            }
        }
    }
    return c;
}
matrix quickpow(matrix a,LL k){
    matrix c;
    memset(c.data,0,sizeof(c.data));
    for(int i=1;i<=n;i++)
        c.data[i][i]=1;
    while(k){
        if(k&1)
            c=mul(c,a);
        k>>=1;
        a=mul(a,a);
    }
    return c;
}

int main(){
    scanf("%lld%lld", &n,&k);
    matrix a;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",&a.data[i][j]);
    matrix ans=quickpow(a,k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans.data[i][j]<<" ";
        }cout<<endl;
    }

}
```

# P1963 #
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL m=1e9+7;
LL n=2,k;
struct matrix{
    LL data[105][105];
};
matrix mul(matrix a,matrix b){
    matrix c;
    memset(c.data,0,sizeof(c.data));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                c.data[i][j]=(c.data[i][j]+a.data[i][k]*b.data[k][j]%m)%m;
            }
        }
    }
    return c;
}
matrix quickpow(matrix a,LL k){
    matrix c;
    memset(c.data,0,sizeof(c.data));
    for(int i=1;i<=n;i++)
        c.data[i][i]=1;
    while(k){
        if(k&1)
            c=mul(c,a);
        k>>=1;
        a=mul(a,a);
    }
    return c;
}

int main(){
    scanf("%lld",&k);
    if(k<=2){
        cout<<1<<endl;
        return 0;
    }
    matrix a;
    a.data[1][1]=a.data[1][2]=a.data[2][1]=1;
    a.data[2][2]=0;
    matrix f;
    f.data[1][1]=f.data[2][1]=f.data[1][2]=f.data[2][2]=1;
    matrix ans=quickpow(a,k-2);
    ans=mul(ans,f);
    cout<<ans.data[1][1]<<endl;

}
```
# P2196 挖地雷 #
![题解](./pic/P2196.png)
```cpp
#include <bits/stdc++.h>
using namespace std;
int n,a[30],p[30],g[30][30],f[30];
int maxx,maxi;
void dg(int x){
    if(x==0)
        return ;
    dg(p[x]);
    cout<<x<<" ";
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(g[j][i]==1){
                if(f[i]<f[j]+a[i]){
                    p[i]=j;
                    f[i]=f[j]+a[i];
                }
            }
        }
        if(maxx<f[i]){
            maxx=f[i];
            maxi=i;
        }
    }
    dg(maxi);
    cout<<endl<<maxx<<endl;
}

```
```cpp
#include <bits/stdc++.h>
using namespace std;
int n,a[30],g[30][30];
int maxx,m;
void dfs(int x,int sum,int p){
    if(maxx<sum){
        maxx=sum;
        m=p;
    }
    for(int i=1;i<=n;i++){
        if(x==0||g[x][i]==1){
            dfs(i,sum+a[i],p+(1<<(i-1)));
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    dfs(0,0,0);
    for(int i=1;i<=n;i++){
        if(m%2==1)
            cout<<i<<" ";
        m/=2;
    }
    cout<<endl<<maxx<<endl;
}

```
# P1802 5倍经验日 #
```cpp
#include <bits/stdc++.h>
using namespace std;
int n,x,win[1010],lose[1010],use[1010];
long long f[1010];
int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>lose[i]>>win[i]>>use[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=x;j>=0;j--){
            if(j>=use[i]){
                f[j]=max(f[j]+lose[i],f[j-use[i]]+win[i]);
            }
            else{
                f[j]=f[j]+lose[i];
            }
        }
    }
    cout<<f[x]*5;
}

```
# P1048 采药

裸的背包
```cpp
#include <iostream>
using namespace std;
int m,t,c[105],v[105],dp[1005];
int main(){
     cin>>t>>m;
     for(int i=1;i<=m;i++){
         cin>>c[i]>>v[i];
     }
     for(int i=1;i<=m;i++){
         for(int j=t;j>=c[i];j--){
             dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
         }
     }
     cout<<dp[t];
}

```

```cpp
#include <iostream>
using namespace std;
int m,t,c,v,dp[1005];
int main(){
     cin>>t>>m;
     for(int i=1;i<=m;i++){
         cin>>c>>v;
         for(int j=t;j>=c;j--){
             dp[j]=max(dp[j],dp[j-c]+v);
         }
     }
     cout<<dp[t];
}

```

```cpp
#include<bits/stdc++.h>
using namespace std;
const int dong_bao_cheng=1100,dongbaocheng=110;
int dong;
int bao;
int cheng[dongbaocheng],ch[dongbaocheng];
int cheng2[dong_bao_cheng][dongbaocheng];
int main()
{
    scanf("%d %d",&dong,&bao);
    for(int i=1;i<=bao;++i)
        scanf("%d %d",&cheng[i],&ch[i]);
    for(int i=1;i<=bao;++i)
    {
        for(int v=dong;v>=0;--v)
        {
            if(cheng[i]<=v)
                cheng2[i][v]=max(cheng2[i-1][v],cheng2[i-1][v-cheng[i]]+ch[i]);
            else
                cheng2[i][v]=cheng2[i-1][v];
        }
    }
    printf("%d\n",cheng2[bao][dong]);
    return 0;
}
```

# P1060 开心的金明

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,v[30],p[30],dp[30005];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>v[i]>>p[i];
        p[i]*=v[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=n;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+p[i]);
        }
    }
    cout<<dp[n];
}
```

# P1049 装箱问题

物体的价值和体积一样

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,v[30],p[30],dp[30005];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>v[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=n;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
    }
    cout<<n-dp[n];
}
```

# P1164 小A点菜

> dp[n],当有n元钱是，正好花完的方案数

```cpp
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
```
