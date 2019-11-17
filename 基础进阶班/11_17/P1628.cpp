#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n;
	cin>>n;
	priority_queue<string,vector<string>,greater<string> > q;
	for(int i=1;i<=n;i++){
		string word;
		cin>>word;
		q.push(word);
	}
	string t;
	cin>>t;
	for(int i=1;i<=n;i++){
		string temp=q.top();
		q.pop();
		int flag=0;
		for(int j=0;j<t.size();j++){
			if(temp[j]!=t[j]){
				flag=1;
				break;
			}
		}
		if(flag==1)
			continue;
		else
			cout<<temp<<endl;
	}
}
