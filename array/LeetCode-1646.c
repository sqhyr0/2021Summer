#include<stdio.h>
#include<stdlib.h>
//获取生成数组中的最大值
//化简整理得：arr[i]=arr[i/2]+(i%2)*arr[i/2+1];
int getMaximumGenerated(int n)
{
    if(!n)return 0;
    int *arr=(int*)malloc(sizeof(int)*(n+1));
    arr[0]=0,arr[1]=1;
    int res=0;
    for(int i=2;i<=n;i++)
    {
        arr[i]=arr[i/2]+(i%2)*arr[i/2+1];
        res=res>arr[i]?res:arr[i];
    }
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",getMaximumGenerated(n));
}