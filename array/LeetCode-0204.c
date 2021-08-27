//计数质数
//利用筛选法
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int countPrimes(int n){
    if(n<=2)return 0;
    int res=1;//1不是素数，循环从2开始，故初始时将非素数的个数设为1个
    int* arr=(int*)calloc(n+1,sizeof(int));
    for(int i=2;i<=sqrt(n);i++)
    {
        if(!arr[i])
        {
            for(int j=2;i*j<n;j++)
            {
                if(!arr[i*j])
                {
                    arr[i*j]=1;
                    res++;
                }
            }
        }
    }
    return n-res-1;//计数范围为[1,n)，故减去一个1
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",countPrimes(n));
}