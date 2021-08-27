#include<stdio.h>
/*
买卖股票的最佳时机
动态规划
对于i∈[0,priceSize]，设f(i)第i天售出股票时的最大利润
设low=min{0<=j<i|prices[j]}，则f(i)=prices[i]-low
对于f(i)，f(i)<0，则prices[i]成为新的low
将每个f(i)与待返回变量res相比较，若f(i)>res,则f(i)成为新的low
*/
int maxProfit(int* prices, int pricesSize){
    int res=0;
    int low=prices[0];
    for(int i=1;i<pricesSize;i++)
    {
        int temp=prices[i]-low;
        if(temp>0)res=res>temp?res:temp;
        else low=prices[i];
    }
    return res;
}
int main()
{
    int prices[100];
    int priceSize=0;
    while(scanf("%d",&prices[priceSize])!=EOF)priceSize++;
    printf("%d",maxProfit(prices,priceSize));
}