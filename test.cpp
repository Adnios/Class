#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[10]={1,2,2,3,3,3,5,5,5,6};
	//寻找3
	cout<<lower_bound(a,a+10,9)-a<<","<<upper_bound(a,a+11,9)-a<<endl;
	return 0;
} 
