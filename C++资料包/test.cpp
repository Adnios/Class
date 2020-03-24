#include <bits/stdc++.h>
using namespace std;
string s;
int n,k;
int sum=0;
stack<char> st;
void n_10(){
    for(int i=0;i<s.size();i++){
        int e=pow(n,s.size()-i-1);
        if(s[i]<'A'){
            e*=(s[i]-'0');
            sum+=e;
        }
        else{
            e*=(s[i]-'A'+10);
            sum+=e;
        }
    }
}
void ten_k(){
    while(sum){
        int temp=sum%k;
        char t;
        if(temp<10)
            t='0'+temp;
        else
            t='A'+(temp-10);
        st.push(t);
        sum/=k;
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}
int main(){
    cin>>n>>s>>k;
    n_10();
    /* cout<<sum<<endl; */
    ten_k();
}
