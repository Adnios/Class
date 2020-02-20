#include <bits/stdc++.h>
using namespace std;
int a[30];
int count(int S){
	int sum=0;
	while(S!=0){
		if(S&1==1){
			sum++;
		}
		S=S>>1;
	}
	return sum;
}
int main(){
	int n,r;
	cin>>n>>r;
	int k=0;
	for(int S=0;S<=(1<<n)-1;S++){
		if(count(S)==r){
			for(int i=0;i<n;i++){
				if(S&(1<<i)){
					a[k]=a[k]*10+i+1;
				}
			}
			k++;
		} 
	}
	sort(a,a+k);
	for(int i=0;i<k;i++){
		int t[r+5],l=0;
		while(a[i]!=0){
			t[l]=a[i]%10;
			l++;
			a[i]=a[i]/10;
		}
		for(int j=l-1;j>=0;j--){
			printf("%3d",t[j]);
		}
		cout<<endl;
	}
} 
