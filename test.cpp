#include <bits/stdc++.h>
#include <iostream>
#define maxn 600
using namespace std;
string x,y;
char a[100],b[100];
int main(){
	memset(a,'?',sizeof(a));
	memset(b,'?',sizeof(b));
	cin>>x>>y;
	int len=x.length(),cnt=0;
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
