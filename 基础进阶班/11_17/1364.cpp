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
