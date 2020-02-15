#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn],b[maxn],c[maxn],flag=1;
int main(){
    string A,B;
    cin>>A>>B;
    int la=A.length(),lb=B.length();
    if(la<lb||(la==lb&&A[0]<B[0])){
    	swap(A,B);
    	swap(la,lb);
    	cout<<"-";
    }
    int j=1;
    for(int i=la-1;i>=0;i--)
        a[j++]=A[i]-'0';
    j=1;
    for(int i=lb-1;i>=0;i--)
        b[j++]=B[i]-'0';
    for(int i=1;i<=la;i++){
    	if(a[i]<b[i]){
    		a[i]+=10;
    		a[i+1]--;
    	}
    	c[i]=a[i]-b[i];
    }
    while(c[la]==0&&la>1){
    	la--;
    }
    for(int i=la;i>=1;i--)
        printf("%d",c[i]);
}
