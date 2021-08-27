//筛法取素数
/*
给定一个正整数N，筛出[2,N]中所有的素数
取每轮筛取后的集合中最小的那个数作为新一轮的筛取基准(第一轮以2为基准，基准最大为sqrt(N))，该元素必为素数
在每轮筛取中，设基准值为a，集合中任意元素值为i，将满足i=a*n且i<=N的元素筛走
本算法中，同一元素可能会被多次筛选，这是因为a*n的值可能出现相等，例如3*5与5*3，在以3为基准时已将15筛去一次，而在以5为基准时再次将其筛去一次
改进：
已知任意非素数可因式分解成多个素数的乘积，将该因式分解式改写成k=p*q^n的形式(k为非素数，q为k的因式分解式中最小的素数，易知p>q)
若以k为筛取基准的变形，对每个基准q,当p*q<=N时有一系列的k<N使得每个k互不相同，集合中各个元素只会被筛选一次
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int N;
    scanf("%d",&N);
    int *arr=(int*)calloc(N+1,sizeof(int));//初始时数组中各值设置为0,0->素数，1->非素数
    arr[1]=arr[0]=1;//分别对应数字0和1，bool值改为1表示非素数

    for(int i=2;i<=sqrt(N);i++)
    {
        if(!arr[i])//每次从留下的数组元素中最小的那个开始用作筛选基准
        {
            for(int j=i;i*j<=N;j++)
                for(int k=i*j;k<=N;k*=i)//k=q*p^n,每个非素数元素只被筛出一次
                    arr[k]=1;
        }
    }

    for(int num=0,i=2;i<=N;i++)
    {
        if(!arr[i])
        {
            printf("%-4d",i);
            num++;
            if(num%5==0)printf("\n");
            else printf(" ");
        }
    }
    
}