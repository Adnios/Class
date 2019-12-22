#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL m=1e9+7;
LL n,k;
struct matrix{
    LL data[105][105];
};
matrix mul(matrix a,matrix b){
}
matrix quickpow(matrix a,LL k){
}

int main(){
    scanf("%lld%lld", &n,&k);
    matrix a;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",&a.data[i][j]);
    matrix ans=quickpow(a,k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans.data[i][j]<<" ";
        }cout<<endl;
    }

}
