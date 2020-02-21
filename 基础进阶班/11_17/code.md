中序+层次
```c++
#include <iostream>
using namespace std;
string s1,s2;
void cal(int l1,int r1,int l2,int r2){
	int i,j;
	for(i=l2;i<=r2;i++){
		int flag=0;
		for(j=l1;j<=r1;j++){
			if(s2[i]==s1[j]){
				cout<<s1[j];
				flag=1;
				break;
			}
		}
		if(flag!=0)
			break;
	}
	if(j>l1)
		cal(l1,j-1,0,r2);
	if(j<r1)
		cal(j+1,r1,0,r2);
}
int main(){
	cin>>s1>>s2;
	cal(0,s1.size()-1,0,s2.size()-1);
	cout<<endl;
}
```
单调队列
```c++
#include <bits/stdc++.h>
using namespace std;
const long long maxx=1e7+5;
long long n,k;
long long a[maxx],dl[maxx],id[maxx],le=1,ri=0;
int main(){
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long i=1;i<=n;i++){
		while(le<=ri&&a[i]<dl[ri])
			ri--;
		ri++;
		dl[ri]=a[i];
		id[ri]=i;
		if(id[le]+k<=i)
			le++;
		if(i>=k)
			printf("%lld ",dl[le]);
	}
	printf("\n");
	memset(dl,0x3f3f3f3f,sizeof(dl));
	le=1;
	ri=0;
	for(long long i=1;i<=n;i++){
		while(le<=ri&&a[i]>dl[ri])
			ri--;
		ri++;
		dl[ri]=a[i];
		id[ri]=i;
		if(id[le]+k<=i)
			le++;
		if(i>=k)
			printf("%lld ",dl[le]);
	}
	printf("\n");
}
```
合并果子
```c++
#include <iostream>
#include <queue>
using namespace std;
int n;
priority_queue<int,vector<int>,greater<int> > h;
int main(){
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		h.push(x);
	}
	for(int i=1;i<n;i++){
		int t1=h.top();h.pop();
		int t2=h.top();h.pop();
		ans=ans+t1+t2;
		h.push(t1+t2);
	}
	cout<<ans<<endl;
}
```
合并序列
```c++
#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n;
	cin>>n;
	priority_queue<string,vector<string>,greater<string> > q;
	for(int i=1;i<=n;i++){
		string word;
		cin>>word;
		q.push(word);
	}
	string t;
	cin>>t;
	for(int i=1;i<=n;i++){
		string temp=q.top();
		q.pop();
		int flag=0;
		for(int j=0;j<t.size();j++){
			if(temp[j]!=t[j]){
				flag=1;
				break;
			}
		}
		if(flag==1)
			continue;
		else
			cout<<temp<<endl;
	}
}
```
