# P1177 快速排序

```c++
#include <bits/stdc++.h>
using namespace std;
int n,a[1000001];
void qsort(int l,int r)
{  
    int i,j,mid,p;
    i=l;  j=r; 
    mid=a[(l+r) / 2];            //将当前序列在中间位置的数定义为分隔数
    do
    {
       while (a[i]<mid) i++;  //在左半部分寻找比中间数大的数
       while (a[j]>mid) j--;    //在右半部分寻找比中间数小的数
       if (i<=j) 
        {                                //若找到一组与排序目标不一致的数对则交换它们
            p=a[i];
            a[i]=a[j];
            a[j]=p;
            i++;   j--;                //继续找
        }
    }
    while (i<=j);                  //注意这里不能有等号
    if (l<j)  qsort(l,j);           //若未到两个数的边界，则递归搜索左右区间
    if (i<r)  qsort(i,r);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    qsort(1,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}
```

# P1923 求第k个数

```c++
#include <bits/stdc++.h>
using namespace std;
int n,a[5000001],k;
void qsort(int l,int r)
{  
    int i,j,mid,p;
    i=l;  j=r; 
    mid=a[(l+r) / 2];            //将当前序列在中间位置的数定义为分隔数
    do
    {
       while (a[i]<mid) i++;  //在左半部分寻找比中间数大的数
       while (a[j]>mid) j--;    //在右半部分寻找比中间数小的数
       if (i<=j) 
        {                                //若找到一组与排序目标不一致的数对则交换它们
            swap(a[i],a[j]);
            i++;   j--;                //继续找
        }
    }
    while (i<=j);                  //注意这里不能有等号

    if(k<=j)  qsort(l,j);
    else if(i<=k) qsort(i,r);
    else{
        printf("%d",a[j+1]);
        return ;
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(0,n-1);
}
```

