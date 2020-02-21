#include <iostream>  
#include <algorithm>  
using namespace std;  
int main()  
{  
    int num[3]={2,1,3};  
    do  
    {  
        cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<endl;  
    }while(next_permutation(num,num+3));  
    return 0;  
}

