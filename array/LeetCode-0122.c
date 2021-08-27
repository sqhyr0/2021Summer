//买卖股票的最佳时机Ⅱ，低买高卖
#include<stdio.h>
int maxProfit(int* prices, int pricesSize){
    int res=0;
    //for(int i=0;i<pricesSize-1;i++)res+=prices[i+1]-prices[i]>0?prices[i+1]-prices[i]:0;进行了两次加法运算，耗时翻倍，故舍去
    int temp=0;
    for(int i=0;i<pricesSize-1;i++)
    {
        temp=prices[i+1]-prices[i];
        if(temp>0)res+=temp;
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