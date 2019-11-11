#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    //请用或(||),且(&&),非(!)运算符与括号补充代码
    if ((n % 5 == 0||n % 7 == 0)&&!(n % 11 == 0))//n能被5或7整除，并且不能被11整除
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
