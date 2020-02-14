#include <bits/stdc++.h>
using namespace std;
const int maxn=520;
int a[maxn],b[maxn],c[maxn];
int main(){
    string A,B;
    cin>>A>>B;
    int len=max(A.length(),B.length());
    int j=1;
    for(int i=A.length()-1;i>=0;i--)
        a[j++]=A[i]-'0';
    j=1;
    for(int i=B.length()-1;i>=0;i--)
        b[j++]=B[i]-'0';
    for(int i=1;i<=len;i++){
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]=c[i]%10;
    }
    if(c[len+1]!=0)
        len++;
    for(int i=len;i>=1;i--)
        printf("%d",c[i]);
}
