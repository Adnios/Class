 

# 1标题统计

https://www.luogu.org/problem/P5015

如何输入带空格的字符串

- gets(字符数组名)

  ```c++
  #include <iostream>
  #include <cstdio> 
  using namespace std;
  
  const int N = 20;
  char x[N+1]; 
  
  int main(){
  	gets(x);
  	cout<<x<<endl;
  	printf ("%s\n",x);
  	return 0;
  }
  
  ```

- ```scanf("%[^\n]]",str)```

  ```c++
  #include <iostream>
  #include <cstdio> 
  using namespace std;
  
  const int N = 20;
  char x[N+1]; 
  
  int main(){
  	scanf ("%[^\n]]",x);
  	cout<<x<<endl;
  	printf ("%s\n",x);
  	return 0;
  }
  ```

- getline(cin,string str)

  ```c++
  #include <iostream>
  using namespace std;
  
  string s;
  
  int main(){
  	getline (cin,s);
  	cout<<s<<endl;
  	return 0;
  }
  ```

- cin.getline(char *str, int maxnum)

  ```c++
  #include <iostream>
  using namespace std;
  
  const int N = 20;
  char x[N+1];
  
  int main(){
  	cin.getline (x,N+1); //这里最好写N+1，因为字符串末尾的的'\0'也包含在这个长度之内.
  	cout<<x<<endl;
  	printf ("%s\n",x);
  	return 0;
  }
  
  ```

  

```c++
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
    int ans=0;
    char c[100];
//    scanf("%[^\n]]",c);
//    gets(c);
    cin.getline(c,100);
    int length=strlen(c);
    for(int i=0;i<length;i++){
        if(c[i]!=' ')
            ans++;
    }
    cout<<ans;
    return 0;
}
```

# 2龙虎斗

```c++
#include<cstdio>
#include<algorithm>
#define N 100010
#define lls long long
using namespace std;
lls n,c[N],m,p1,s1,s2,ans1,ans2,mins,mark;
int main()
{
    scanf("%lld",&n);
    for(lls i=1;i<=n;i++)
        scanf("%lld",&c[i]);
    scanf("%lld%lld%lld%lld",&m,&p1,&s1,&s2);
    c[p1]+=s1;
    for(lls i=1;i<m;i++)
        ans1+=c[i]*(m-i);
    for(lls i=m+1;i<=n;i++)
        ans2+=c[i]*(i-m);
    mark=0;
    mins=1e19;
    for(lls i=1;i<m;i++)
    {
        if(abs(ans1+s2*(m-i)-ans2)<mins)
        {
            mark=i;
            mins=abs(ans1+s2*(m-i)-ans2);
        }
    }
    for(lls i=m+1;i<=n;i++)
    {
        if(abs(ans1-ans2-s2*(i-m))<mins)
        {
            mark=i;
            mins=abs(ans1-ans2-s2*(i-m));
        }
    }
    if(mins<abs(ans1-ans2))
        printf("%lld",mark);
    else 
        printf("%lld",m);
}

```

# 4对称二叉树

https://www.luogu.org/problem/P5018

什么是对称二叉树？

任意一棵对称二叉树，以根节点为轴，是轴对称的

DFS深搜，size[ x ] 记录以 x 为根的树的大小（也就是以 x 为根的树的所有节点的总数）

当前节点左儿子非空，继续递归左儿子，右儿子非空，继续递归右儿子

size[ x ]就等于它自己+左子树大小+右子树大小

当我们判断对称二叉树的时候，可以用到一个**check函数**

对于当前节点

如果左右子树都空，那么一定是对称二叉树

如果左右子树都非空，而且左右儿子权值相等，继续判断他左儿子的右儿子和右儿子的左儿子是否相等，以及左儿子的左儿子和右儿子的右儿子是否相等，不断递归check，全部满足条件才是对称二叉树，才有机会成为候选答案

否则的话就不会成为对称二叉树了 



```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,ans=-1;
int tree[maxn],son[maxn][3],size[maxn];

void dfs(int x){
    size[x]=1;
    if(son[x][1]!=-1)
    {
        dfs(son[x][1]);
        size[x]+=size[son[x][1]];
    }
    if(son[x][2]!=-1)
    {
        dfs(son[x][2]);
        size[x]+=size[son[x][2]];
    }

}

bool check(int l,int r){
    if(l==-1&&r==-1)
        return true;
    if(l!=-1&&r!=-1&&tree[l]==tree[r]&&check(son[l][2],son[r][1])&&check(son[l][1],son[r][2]))
        return true;
    return false;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&tree[i]);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&son[i][1],&son[i][2]);
    dfs(1);
    for(int i=1;i<=n;i++)
        if(check(son[i][1],son[i][2]))
            ans=max(ans,size[i]);
    printf("%d\n",ans);
    return 0;
}
```

# 成绩

```c++
#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<a*0.2+b*0.3+c*0.5<<endl;
}
```

# 图书管理员

## 把需求码与图书编码配对 = 求图书编码的后 X 位

## 求图书编码的后 X 位 = 把前面的都去掉。

如何把前面的无关数字去掉呢？这时候我们想起了 % 运算（没学过的出门左转回娘胎重造）。

对于一个数a，很显然要取它个位数的方法就是：

## 对a mod 10

但是这是我们人工计算出的结果，而各个需求码的位数不同，这时候就需要找出一个规律。

## 对此我们发现了规律：对一个数a取其后n位，就是对a mod 10^n

然后你就会发现题目给的这个位数是真·仁慈 啊。

#### 而cmath函数中带有专门执行幂运算的函数

# pow

### 其中有一个要注意的点是，pow函数并不能直接进行 mod 运算，需要将其带入一个变量进行运算。



```c++
#include<iostream>
#include<cmath>
#include <algorithm>
using namespace std;
int n,q,book[6666],len[6666],num[6666];
int main(){
    cin>>n>>q;
    for(int i=1; i<=n; i++)
        cin>>book[i];
    sort(book+1,book+n+1);
    for(int i=1; i<=q; i++) {
        cin>>len[i]>>num[i];
        int tmp = pow(10,len[i]),min = 10000001;
        for(int j=1; j<=n; j++)
            if(book[j] % tmp == num[i] ) {
                min=book[j];
                break;
            }

        if(min != 10000001)
            cout<<min<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
```

