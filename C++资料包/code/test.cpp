#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct apple{
	int a,b;
}ap[50005];
int cmp(apple x,apple y){
	return x.b<y.b;
}
int cnt=0;
int main()
{
	int geshu,liqi,denggao,shougao,ans=0;
	cin>>geshu>>liqi>>denggao>>shougao;
	for(int i=1;i<=geshu;i++)
	{
		int a,b,n=0,m=0;
		cin>>a>>b;
		if(a<=(denggao+shougao)){
			cnt++;
			ap[cnt].a=a;ap[cnt].b=b;
		}
	}
	sort(ap+1,ap+cnt+1,cmp);//按照苹果b的大小，从小到大排序 
	for(int i=1;i<=cnt;i++){
		if(liqi>=ap[i].b){
			ans++;
			liqi=liqi-ap[i].b;
		} 
		else
		    break;
		
	} 
	cout<<ans;
	return 0;
}
