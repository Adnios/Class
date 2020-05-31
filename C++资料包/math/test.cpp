#include<bits/stdc++.h>
using namespace std;
const int maxn=11001;
int t;
int m;
int v[maxn],c[maxn];
int dp[maxn][maxn];
int main()
{
    scanf("%d %d",&t,&m);
    for(int i=1;i<=m;++i)
        scanf("%d %d",&v[i],&c[i]);
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<=t;j++)
        {
            if(j<v[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-v[i]]+c[i]);
        }
    }
    printf("%d\n",dp[m][t]);
    return 0;
}
