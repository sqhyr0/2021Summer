#include<stdio.h>
#include<stdlib.h>
/*int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    //设置一个用来表示线性时间的数组，长度为最后timeSeries[i]中的最大值+duration(为使timeSeries[i]的数值与arr[j]的序号j对齐)
    int length=timeSeries[timeSeriesSize-1]+duration;
    int* arr=(int*)calloc(length,sizeof(int));
    int res=0;
    for(int i=0;i<timeSeriesSize;i++)//依次遍历每个动作节点
    {
        int temp=timeSeries[i];
        for(int j=0;j<duration&&temp+j<length;j++){
            if(arr[temp+j]==1)continue;
            arr[temp+j]=1;
            res++;
        }
    }
    return res;
}
*/

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration)
{
    int res=0,num=0;
    for(int i=1;i<timeSeriesSize;i++)
    {
        if(timeSeries[i]<=timeSeries[i-1]+duration-1)res+=timeSeries[i]-timeSeries[i-1];
        else res+=duration;
    }
    return res+duration;
}
int main()
{
    int nums[1000];
    int numsSize=0;
    while(scanf("%d",nums+numsSize)!=EOF)numsSize++;
    int duration;
    scanf("%d",&duration);
    printf("%d",findPoisonedDuration(nums,numsSize,duration));
}