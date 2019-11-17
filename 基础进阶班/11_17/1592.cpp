#include <bits/stdc++.h>
using namespace std;
const long long maxx=1e7+5;
long long n,k;
long long a[maxx],dl[maxx],id[maxx],le=1,ri=0;
int main(){
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long i=1;i<=n;i++){
		while(le<=ri&&a[i]<dl[ri])
			ri--;
		ri++;
		dl[ri]=a[i];
		id[ri]=i;
		if(id[le]+k<=i)
			le++;
		if(i>=k)
			printf("%lld ",dl[le]);
	}
	printf("\n");
	memset(dl,0x3f3f3f3f,sizeof(dl));
	le=1;
	ri=0;
	for(long long i=1;i<=n;i++){
		while(le<=ri&&a[i]>dl[ri])
			ri--;
		ri++;
		dl[ri]=a[i];
		id[ri]=i;
		if(id[le]+k<=i)
			le++;
		if(i>=k)
			printf("%lld ",dl[le]);
	}
	printf("\n");
}
