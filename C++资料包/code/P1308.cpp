#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    //输入带空格字符串
    getline(cin,a);
    getline(cin,b);
    //转换大小写
    for (int i=0;i<a.length();++i){
        a[i]=tolower(a[i]);
    }
    for (int i=0;i<b.length();++i){
        b[i]=tolower(b[i]);
    }
    //因为连起来的不算，所以要在前后加几个空格，一定要是同样多的，同量减同量，等于同量
    //例如to toooo这样的不属于匹配
    a=' '+a+' ';
    b=' '+b+' ';
    //先看看会不会找不到，用a.find(),如果没有找到会返回b.npos
    if (b.find(a)==b.npos){
        cout<<b.npos;
        cout<<-1<<endl;
    }
    //如果找得到
    else {
        int index=b.find(a);
        int index2=b.find(a),s=0;//计数器初始化为0
        while (index2!=b.npos){
            ++s;//计数器
            index2=b.find(a,index2+1);//从字符串b 下标index2+1开始
        }
        cout<<s<<" "<<index<<endl;//输出第一个和总共有几个
    }
}
