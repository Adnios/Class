#include <bits/stdc++.h>
using namespace std;
string A,B;
int a[10005],b[10005],c[10005];
int main(){
	cin>>A>>B;
	if(A=="0"||B=="0"){
		cout<<0;
		return 0;
	}
	int la=A.length(),lb=B.length();
	int j=1;
	for(int i=A.length()-1;i>=0;i--){
		a[j++]=A[i]-'0';
	}
	j=1;
	for(int i=B.length()-1;i>=0;i--){
		b[j++]=B[i]-'0';
	}
	int len=la+lb;
	for(int i=1;i<=la;i++){
		for(int j=1;j<=lb;j++){
			c[i+j-1]+=a[i]*b[j];
		}
	}
	for(int i=1;i<=len;i++){
		c[i+1]=c[i+1]+c[i]/10;
		c[i]=c[i]%10;
	}
	while(c[len]==0){
		len--;
	}
	for(int i=len;i>=1;i--){
		cout<<c[i];
	}
} 
