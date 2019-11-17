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
