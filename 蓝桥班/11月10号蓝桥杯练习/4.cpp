#include<iostream>
#include <cmath>
using namespace std;
long long aa,bb,cc;//边长平方后数字可能很大，所以用long long
int n,a,b,c;
long long find(){
    for(c=n;c>=5;c--){
        cc=c*c;
        for(a=c/sqrt(2);a>=1;a--){//边长a，b越靠近c/根号2，周长越大
            aa=a*a;
            b=sqrt(cc-aa);
            if(b*b+aa==cc)
                return a+b+c;
        }
    }
    return 0;
}
int main(){

    cin>>n;
    cout<<find();
    return 0;
}