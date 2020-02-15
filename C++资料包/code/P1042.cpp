#include <bits/stdc++.h>
using namespace std;
int f[2]={11,21};
int a[25*2500+10],n=0;
int main(){
	char tmp;
	while(1){
		cin>>tmp;
		if(tmp=='E') break;
		else if(tmp=='W') a[n++]=1;
		else if(tmp=='L') a[n++]=0;
	}
	for(int k=0;k<2;k++){
		int w=0,l=0;
		for(int i=0;i<n;i++){
			w+=a[i];
			l+=1-a[i];
			if((max(w,l)>=f[k])&&abs(w-l)>=2){
				cout<<w<<":"<<l<<endl;
				w=l=0;
			}
		}
		cout<<w<<":"<<l<<endl;
		cout<<endl;
	}
	return 0;
} 
