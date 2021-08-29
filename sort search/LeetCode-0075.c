/*
颜色分类
涂色法，时间复杂度为O(n)，空间复杂度为O(1)，只进行一趟遍历
颜色的排序为红白蓝，我们可以先将所有元素全部涂成蓝色，
再在蓝色区域中将本来的红色和白色区域涂成白色，
最后在白色区域中将本来的红色区域涂成红色
这样做的原因是，白色区域排在最后，而按照遍历的习惯是从前往后遍历
设置三个指针，red，white，blue，初始位置在0处
blue从前往后遍历，将每个元素涂成蓝色，而在此之前，申请一个临时变量储存每个元素的初始颜色
初始非蓝，则white指针所指元素改为白色，指针进1
在上一步完成后，再作一次判断，初始为红，则red指针所指元素改为红色，指针进1
这样，若将原始数组中各色元素的个数分别设为r,w,b，则r+w+b=n
在blue指针遍历结束后
所有元素先变为蓝色，蓝色数量为n
白色又将蓝色从前往后覆盖非蓝元素个，白色数量为r+w,蓝色数量为n-r-w=b
红色又将白色从前往后覆盖红色元素个，红色数量为r，白色数量为r+w-r=w
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void sortColors(int* nums, int numsSize){
    if(numsSize<2)return ;
    int red,white,blue;
    red=white=blue=0;
    for(blue;blue<numsSize;blue++)
    {
        int temp=nums[blue];
        nums[blue]=2;
        if(temp^2)//异或判断比或判断更简洁
        {
            nums[white]=1;
            white++;
        }
        if(!temp)
        {
            nums[red]=0;
            red++;
        }
    }
}

int main()
{
    int nums[100];
    int numsSize=0;
    while(scanf("%d",&nums[numsSize])!=EOF)numsSize++;
    sortColors(nums,numsSize);
    for(int i=0;i<numsSize;i++)printf("%d ",nums[i]);
}