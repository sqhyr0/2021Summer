#include<stdio.h>

int Euclidean_Algorithm(int a,int b);

int main()
{
    int A;
    int B;
    scanf("%d %d",&A,&B);
    int temp;
    if(A<B)
    {
        temp=A;
        A=B;
        B=temp;
    }
    printf("%d",Euclidean_Algorithm(A,B));
}

int Euclidean_Algorithm(int a,int b)//递归
{
    if(!(a%b))return b;
    else return Euclidean_Algorithm(b,a%b);
}