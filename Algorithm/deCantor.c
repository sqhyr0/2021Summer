#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int factorial(int n)
{
    int res=1;
    for(int i=1;i<=n;i++)res*=i;
    return res;
}
int main()
{
    int length;
    int Cantor;
    scanf("%d %d",&length,&Cantor);
    Cantor--;
    int* arr=(int*)malloc(sizeof(int)*length);
    int a=Cantor,b,c;
    int* arr2=(int*)malloc(sizeof(int*)*length);
    memset(arr2,0,sizeof(int)*length);
    for(int i=length-1;i>=0;i--)
    {
        b=a/factorial(i);
        c=a%factorial(i);
        a=c;
        for(int j=0;j<length;j++)
        {
            if(arr2[j]==1)continue;
            if(b==0)
            {
                arr2[j]=1;
                arr[length-i-1]=j+1;
            }
            b--;

        }
    }
    for(int i=0;i<length;i++)printf("%d ",arr[i]);
}