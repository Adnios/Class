#include <iostream>
#include <algorithm>
using namespace std;
int count(int ai,int bi){
    int cnt=0;
    for(int i=ai;i<=bi;i++){//计算素数个数
        int j;
        for(j=2;j<ai;j++)
            if(ai%j==0)
                break;
        if(j==ai)
            cnt++;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int id,ai,bi;
    int ans=3000000000,temp=0;
    while(n--){
        cin>>id>>ai>>bi;
        if(temp<count(ai,bi)){
            temp=count(ai,bi);
            ans=id;
        }
        if(temp==count(ai,bi))
            ans=min(ans,id);
    }
    cout<<ans<<endl;
}
