# NOI Online入门组
## 第一题：未了(endless)

```c++
#include <bits/stdc++.h>
using namespace std;
/*
s=vt,二分   upper_bound,lower_bound
n=1    只有一种魔法
魔法相当于增加了路程
*/
int n,L,v,q;
int sum[200005],a[200005];
int main(){
    cin>>n>>L>>v;
    sum[0]=L;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    for(int i=0;i<n;i++){
        sum[i+1]=sum[i]+a[i];
    }
    cin>>q;
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        long long s=1ll*t*v;
        int ans=upper_bound(sum,sum+n+1,s)-sum;
        if(ans==n+1)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
}
```

## 荆轲刺秦王 


## 建设城市

> dp[i][j]:长度为i,末尾为<=j的单调增序列个数,dp[i][j]=dp[i][j-1]+dp[i-1][j]

# 另一套

## 跑步

```c++
#include <bits/stdc++.h>
using namespace std;
int dp[100001+5];
int main(){
	int n,p;
	cin>>n>>p;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[j]=(dp[j-i]+dp[j])%p;
		}
	}
	cout<<dp[n];
} 
/*
  0 1 2 3 4 5(sum) 
0 1 0 0 0 0 0 
1 1 1 1 1 1 1(可利用的数有{0，1}) 
2
3
4
5
(可利用的数)
考虑现在的新数和不考虑 
https://zhuanlan.zhihu.com/p/111760454
https://studyingfather.blog.luogu.org/pentagonal-number-and-number-partitions
*/
```

