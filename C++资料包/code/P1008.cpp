#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	for(int i=123;i<=334;i++){
		int flag=1;
		memset(a,0,sizeof(a));
		//统计每个数字出现个数
		for(int j=1;j<=3;j++){
			int temp=i*j;//循环三次，分别表示i,2*i,3*i;
			a[temp%10]++;a[temp/10%10]++;a[temp/100]++;
		}
		for(int l=1;l<=9;l++){
			//如何1到9数字各出现一次，则满足要求
			if(a[l]!=1){
				flag=0;
				break;
			} 
		}
		if(flag==1){
			cout<<i<<" "<<i*2<<" "<<i*3<<endl;
		}
	}
}
