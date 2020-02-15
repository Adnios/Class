#include <bits/stdc++.h>
using namespace std;
const int maxn=5010;
int a[maxn],b[maxn],c[maxn];
int main(){
    string A,B;
    cin>>A>>B;
    int lena=A.length(),lenb=B.length();
    int j=1;
    for(int i=A.length()-1;i>=0;i--){
        a[j++]=A[i]-'0';
    }
    j=1;
    for(int i=B.length()-1;i>=0;i--){
        b[j++]=B[i]-'0';
    }
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            c[i+j-1]=c[i+j-1]+a[i]*b[j];
        }
    }
    int len=lena+lenb;
    for(int i=1;i<=len;i++){
        c[i+1]=c[i+1]+c[i]/10;
        c[i]=c[i]%10;
    }
    while(c[len]==0){
        len--;
    }
    for(int i=max(len,1);i>=1;i--){
        cout<<c[i];
    }
}
