#include<bits/stdc++.h>
using namespace std;
long long n,m,rec,sqr;
int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++)//ѭ������n-0��n-(n-1)
        for(int j=0; j<m; j++) {//ѭ������m-0��m-(m-1)
            if(i==j) sqr+=(n-i)*(m-j);//���i==j��˵����������
            else rec+=(n-i)*(m-j);//�������˵���Ǿ���
        }
    cout<<sqr<<" "<<rec<<endl;//���
    return 0;
}
