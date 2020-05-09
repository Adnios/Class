#include <iostream>
#include <vector>
#include <cstdio>
#define mod 100007
using namespace std;

vector<int> Hash[100007];
long long maxx, t, n, num;

int read(){
    int w=1,q=0;
	char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=getchar();
    return w*q;
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

bool check(int val) {
    int pos = (val % mod + mod) % mod;
    maxx = max(maxx, pos);
    for (int k = 0; k < Hash[pos].size(); k++) {
        if (Hash[pos][k] == val) {
            return true;
        }
    }
    Hash[pos].push_back(val);
    return false;
}

int main() {
    t=read();
    while (t--) {
        n=read();
        for (int i = 0; i <= maxx; i++) Hash[i].clear();
        maxx = 0;
        for (int i = 1; i <= n; i++) {
            num=read();
            if(!check(num))
                printf("%lld ",num);
        }
        cout << "\n";
    }
    return 0;
}
