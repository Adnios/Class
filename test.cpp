#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define L 500005
using namespace std;
int Size,n;
int flag=0; 
int binary_Search(int *S,int x,int low ,int high)
{
    int mid = (low+high)/2;
    if(x<S[0]) return 0;
    else if(S[Size-1]<=x) return Size-1;
//    cout<<low<<" "<<high<<endl;
    if(low>=high) return -1;
    else{
        if(S[mid] == x) return mid;
        else if(x>S[mid]&&x<S[mid+1]) {
        	flag++;
        	return mid;
		}
        else if(S[mid] < x) return binary_Search(S,x,mid,high);
        else if(S[mid] > x) return binary_Search(S,x,low,mid);
    }
}

void quick_sort(int *S,int low,int high)
{
    if(low<high)
    {
        int i = low;
        int j = high;
        int x = S[low];
        while(i<j)
        {
            while(i<j && S[j] >= x) j--;
            if(i<j) S[i++] = S[j];
            while(i<j && S[i] <= x) i++;
            if(i<j) S[j--] = S[i];
        }
        S[i] = x;
        quick_sort(S,low,i-1);
        quick_sort(S,i+1,high);
    }
}
int main()
{

    int S[L];
    scanf("%d%d",&Size,&n);
    for(int i=0;i<Size;i++)
        scanf("%d",&S[i]);
    quick_sort(S,0,Size-1);
    int l,r;
    for(int i=0;i<n;i++)
    {
    	flag=0;
        scanf("%d%d",&l,&r);
        int num1 = binary_Search(S,l,0,Size-1);
        int num2 = binary_Search(S,r,0,Size-1);
//        cout<<num1<<" "<<num2<<" "<<flag<<endl; 
        
        if(flag==2||flag==1)
        	printf("%d\n",num2-num1);
        else
        	printf("%d\n",num2-num1+1);
    }

    return 0;
}
/**
5 3
1 3 7 9 11
4 6
7 12 
8 9
**/ 

