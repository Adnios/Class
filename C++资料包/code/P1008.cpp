#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	for(int i=123;i<=334;i++){
		int flag=1;
		memset(a,0,sizeof(a));
		//ͳ��ÿ�����ֳ��ָ���
		for(int j=1;j<=3;j++){
			int temp=i*j;//ѭ�����Σ��ֱ��ʾi,2*i,3*i;
			a[temp%10]++;a[temp/10%10]++;a[temp/100]++;
		}
		for(int l=1;l<=9;l++){
			//���1��9���ָ�����һ�Σ�������Ҫ��
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
