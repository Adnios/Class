#include <bits/stdc++.h>
using namespace std;
const int mod=10005;
long long t,n,num,maxx;
vector<int> Hash[10005];
int read(){
    int w=1,q=0;
	char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=getchar();
    return w*q;
}
bool check(int val){
	long long pos=(val%mod + mod) %mod;
	maxx=max(pos,maxx);
	for(int k=0;k<Hash[pos].size();k++){
		if(Hash[pos][k]==val)
			return false;
	}
	Hash[pos].push_back(val);
//	cout<<val<<endl;
	return true;
}
int main(){
	t=read();
	while(t--){
		n=read();
		for(int i=0;i<=maxx;i++){
			Hash[i].clear();
		}
		for(int i=1;i<=n;i++){
			num=read();
			if(check(num))
				cout<<num<<" "; 
		} 
		cout<<endl; 
	}
	
}
