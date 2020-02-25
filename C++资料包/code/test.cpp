#include <iostream>
using namespace std;
string expand(){
    string s="",X;
    char c;
    int D;
    while(cin>>c){
        if(c=='['){
            cin>>D;
            X=expand();
            while(D--)
                s+=X;
        }
        else if(c==']')
            return s;
        else
            s+=c;
    }
}
int main(){
    cout<<expand();
}

