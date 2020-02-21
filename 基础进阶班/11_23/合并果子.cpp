#include <iostream>
#include <queue>
using namespace std;
int main(){
	int n;
	cin>>n;
	priority_queue<string,vector<string>,greater<string> > q;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		q.push(s);
	}
	string str;
	cin>>str;
	for(int i=0;i<n;i++){
		string temp=q.top();
		q.pop();
		int j=0;
		int len=str.size();
		for(j=0;j<len;j++){
			if(temp[j]!=str[j])
				break;
		}
		if(j==len)
			cout<<temp<<endl;
	}
}
