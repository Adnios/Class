#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
int n;
long long dp[maxn];//dp[j],�Ӽ�֮��Ϊjʱ�ķ����� 
//14(���������)����1����ʹ��Ʒ���������Ʒ��ֵ����2��3��4��5��6��7��
int main(){
	cin>>n;
	int m=(1+n)*n/2;//20*39
	if(m%2==1){
		cout<<0;
		return 0;
	}
	m=m/2;	
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=i;j--){
			dp[j]=dp[j-i]+dp[j];
		}
	}
	cout<<dp[m]/2;
} 
for(int i=1;i<=m;i++){
		for(int j=t;j>=v[i];j--){
			dp[j]=max(dp[j-v[i]]+c[i],dp[j]);
		}
	}
	
for(int i=1;i<=m;i++){
		for(int j=v[i];j<=t;j++){
			dp[j]=max(dp[j],dp[j-v[i]]+c[i]);
		}
	}


