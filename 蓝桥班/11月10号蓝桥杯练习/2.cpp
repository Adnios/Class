#include <iostream>
using namespace std;
int main()
{
    int n, m, a[110] = {0};//这里有一个数组a,你打算怎样使用?   哈希的思想，a[i]代表第i小猴的得分
    cin >> n >> m;
    for (int i = 1; i <= m; i++)//对每一场比赛,你打算怎样计分?
    {
        cin >> a[0];
        a[a[0]]++;
    }
    //你需要更多的变量吗?
    int maxx=0;
    for (int i = 1; i <= n; i++)//对每一只小猴,他得了几分呢?
    {
        cout << a[i] << endl;
        //他能成为"蕉王"吗?
        maxx=maxx<a[i] ? a[i]:maxx;
    }
    //"蕉王"得到了几根香蕉呢?
    cout << maxx << endl;
    return 0;
}