#include <iostream>
using namespace std;
int main()
{
    int a[100010] = {0};//这里有一个数组a,你打算怎样使用?
    //处理所有三角形数
    for (int i = 1; i*(i+1)/2 <= 100000; i++){
        a[i*(i+1)/2]++;
    }
    //处理所有四边形数
    for (int i = 1; i*i <= 100000; i++){
        a[i*i]++;
    }
    //处理所有五边形数
    for (int i = 1; i*(3*i-1)/2 <= 100000; i++){
        a[i*(3*i-1)/2]++;
    }
    //处理所有六边形数
    for (int i = 1; i*(2*i-1) <= 100000; i++){
        a[i*(2*i-1)]++;
    }
    //哪些数是我们要的呢?
    for (int i = 1; i <= 100000; i++){
        if(a[i]==2)
            cout << i << endl;
    }
    return 0;
}