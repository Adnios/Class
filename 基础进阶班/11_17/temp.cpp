#include <iostream>
using namespace std;
const int maxx=1e6+5;
long long n,k,a[maxx],q[maxx],id[maxx],le=1,ri=0;
int main(){
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=1;i<=n;i++){
		while(le<=ri&&a[ri]<q[i])
			ri--;
		ri++;
		q[ri]=a[i];
		id[ri]=i;
		if(id[le]+k<=i)
			le++;
		if(i>=k)
			cout<<q[le]<<" ";
	}
	cout<<endl;
	le=1;ri=0;
	for(long long i=1;i<=n;i++){
		while(le<=ri&&a[i]>q[ri])
			ri--;
		ri++;
		q[ri]=a[i];
		id[ri]=i;
		if(id[le]+k<=i)
			le++;
		if(i>=k)
			cout<<q[le]<<" ";
	}
	cout<<endl;
}
