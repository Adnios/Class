# freopen
```c++
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
```c++
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
```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    cout<<((x&0x0000ffff)<<16|(x&0xffff0000)>>16)<<endl;
}

```

# P1029 最大公约数和最小公倍数问题 
```c++
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
```c++
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
```c++
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
```c++
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
```c++
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
```c++
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

